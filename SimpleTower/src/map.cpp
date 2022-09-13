#include "map.h"

int map::rand_int(int first, int sec) {
    return rand() % sec + first;
}

void map::posible_coord(std::vector<std::pair<int, int>> &v_pos, const std::pair<int, int> &coord) {
    for(int i = 0; i < 4; i++){
        std::pair<int,int> position = coord;
        if (i == 0) position.first++;
        if (i == 1) position.second++;
        if (i == 2) position.first--;
        if (i == 3) position.second--;
        if((position.first > 0 && position.second > 0 && position.first < 24 && position.second < 24 && walls.find(position) == walls.end()) || position == exit)
            v_pos.push_back(position);
    }
}

void map::BFS() {
    std::unordered_set<std::pair<int,int>, hash_pair> banned;
    for(auto i = walls.begin(); i != walls.end(); i++){
        banned.insert(*i);
    }
    std::unordered_map<std::pair<int,int>,std::pair<int,int>,hash_pair> contacts;
    std::deque<std::pair<int,int>> q;
    std::pair<int,int> c = enter;
    q.push_back(c);
    while(!q.empty()){
        c = q.front();
        q.pop_front();
        std::vector<std::pair<int,int>> pos;
        posible_coord(pos, c);
        for(size_t i = 0; i < pos.size(); i++){
            if(banned.find(pos[i]) == banned.end()) {
                q.push_back(pos[i]);
                banned.insert(pos[i]);
                contacts.insert({pos[i], c});
                if(c == exit) q.erase(q.begin(), q.end());
            }
        }
    }
    std::deque<std::pair<int,int>> res;
    res.push_back(exit);
    while (res.front() != enter){
        auto res_front = res.front();
        res.push_front(contacts[{res_front}]);
        road.insert({res.front(), res_front});
    }
}

void map::generate_road() {
    road.clear();
    BFS();
}

void map::get_next(std::pair<int,int>& tmp) {
    for(int i = 0; i < 5; i++){
        if(road[tmp] != exit && road[tmp] != std::pair<int,int>{0,0})
            tmp = road[tmp];
        else tmp = exit;
    }
}

void map::generate_tower_position() {
    auto tmp = enter;
    while(tmp != exit) {
        get_next(tmp);
        if(tmp == exit) break;
        std::vector<std::pair<int, int>> posible_tower_position;
        posible_coord(posible_tower_position, tmp);
        size_t i = 0;
        for(;i < posible_tower_position.size(); i++) {
           if(road[posible_tower_position[i]] == std::pair<int,int>{0,0}) {
               tower t(posible_tower_position[i]);
               tower_positions.push_back(t);
               posible_tower_position.erase(posible_tower_position.begin(), posible_tower_position.end());
               break;
           }
           else{
               posible_tower_position[i] = posible_tower_position[posible_tower_position.size()-1];
               posible_tower_position.pop_back();
           }
        }
    }
}

void map::generate_map() {
    int x = rand_int(1, 15), y = 0;
    enter = std::pair<int,int>{x, y};
    std::cout << "Enter generated" <<  '[' << x << ',' << y << ']' << std::endl;
    y = 24;
    x = rand_int(x, 23-x);
    exit = std::pair<int,int>{x,y};
    std::cout << "Exit generated" <<  '[' << x << ',' << y << ']' << std::endl;
    BFS();
    std::cout << "Road generated" << std::endl;
    generate_tower_position();
    std::cout << "Tower positions generated" << std::endl;
}

std::pair<int, int> map::get_enter_position() { return enter; }

std::pair<int, int> map::get_exit_position() { return exit; }

std::pair<int, int> map::get_next_position(std::pair<int, int> cur_pos) {
    if(road[cur_pos] != exit && road[cur_pos] != std::pair<int,int>{0,0})
        return road[cur_pos];
    else
        return exit;
}

abstract_tower *map::make_t(size_t type, std::pair<int, int> position) {
    switch (type) {
        case 0:
            return new cannon(position);
        case 1:
            return new archer(position);
        case 2:
            return new crossbow(position);
        case 3:
            return new wizard(position);
        case 4:
            return new inferno(position);
        default:
            return nullptr;
    }
}

bool map::build_tower(std::pair<int, int> position, size_t tower_t, player * c_player) {
    if(tower_t > 4) return false;
    size_t i = 0;
    for(; i < tower_positions.size(); i++){
        if(tower_positions[i].position == position) break;
    }
    abstract_tower* tower = make_t(tower_t, position);
    if(tower == nullptr){
        return false;
    }
    if(c_player->get_cur_money() < tower->get_cost()){
        delete tower;
        return false;
    }
    c_player->remove_money(tower->get_cost());
    if(i == tower_positions.size()) return false;
    tower_positions[i].is_empty = false;
    tower_positions[i].tower_type = tower_t;
    towers.insert({i, tower});
    std::cout << towers.size() << ' ' << towers[i]->get_cost() << std::endl;
    return true;
}

bool map::find_tower(std::pair<int, int> C) {
    for(size_t i = 0; i < tower_positions.size(); i++){
        if(tower_positions[i].position == C){
            char ch;
            switch (tower_positions[i].tower_type) {
                case 0:
                    ch = 'c';
                    break;
                case 1:
                    ch = 'A';
                    break;
                case 2:
                    ch = 'C';
                    break;
                case 3:
                    ch = 'W';
                    break;
                case 4:
                    ch = 'I';
                    break;
                default:
                    ch = '*';
                    break;
            }
            std::cout << ch;
            return true;
        }
    }
    return false;
}

bool map::find_road(std::pair<int, int> C) {
    if(road[C] != std::pair<int,int>{0,0}) return true;
    return false;
}

char map::draw_enemy(size_t enemy_type) {
    switch (enemy_type) {
        case 1:
            return 'B';
        case 2:
            return 'R';
        case 3:
            return 'S';
        case 4:
            return 'G';
        default:
            return 'x';
    }
}

bool map::find_enemy(std::pair<int,int> position) {
    for(size_t i = 0; i < enemy.size(); i++){
        if(enemy[i].position == position) {
            current_enemy = i;
            return true;
        }
    }
    return false;
}

void map::add_enemy(const abstract_enemy *en) {
    _enemy cur(en->get_position(), en->get_type());
    enemy.push_back(cur);
}

void map::remove_enem() {
    enemy.clear();
}

void map::copy_t_pos(std::deque<int>& t) {
    for(int i = 0; i < (int)tower_positions.size(); i++){
        if(!tower_positions[i].is_empty)
            t.push_back(i);
    }
}

abstract_tower* map::find_T(int num) {
    return tower_positions[num].is_empty ? nullptr : towers[num];
}

void map::draw_map() {
    std::cout << "Map " << map_name << ':' << std::endl;
    for(size_t i = 0; i < 25; i++){
        for(size_t j = 0; j < 25; j++){
            if(find_enemy({i,j}))
                std::cout << draw_enemy(enemy[current_enemy].type);
            else if(walls.find({i,j}) != walls.end())
                std::cout << '#';
            else if(enter == std::pair<int,int>{i, j})
                std::cout << 's';
            else if (exit == std::pair<int,int>{i, j})
                std::cout << 'E';
            else if(find_road({i,j}))
                std::cout << 'x';
            else if(find_tower({i,j}));
            else if(i == 0 || i == 24){
                if (j != 0 && j != 24)
                    std::cout << '-';
                else
                    std::cout << '+';
            }
            else if(j == 0 || j == 24)
                std::cout << '|';
            else std::cout<<' ';
        }
        std::cout<<'\n';
    }
}

std::ostream& operator<< (std::ostream& out, const std::pair<int,int>& a) {
    out << '[' << a.first << ',' << a.second << ']';
    return out;
}

std::istream& operator>> (std::istream& in, std::pair<int,int>& a) {
    char ch = '?';
    int x, y;
    while(true){
        in >> ch;
        if(ch == '['){
            in >> x;
            if(x > 25) throw badload();
        }
        else if(ch == ',') {
            in >> y;
            if(y > 25)
                throw badload();
        }
        else if(ch == ']')
            break;
    }
    a = std::pair<int,int>{x,y};
    return in;
}

void map::posible_tower_position() const{
    for(size_t i = 0; i < tower_positions.size(); i++){
        if(tower_positions[i].is_empty)
            std::cout << i << " - " << tower_positions[i].position << std::endl;
    }
}

void map::reset_attack() {
    for(size_t i = 0; i < tower_positions.size(); i++)
        if(!tower_positions[i].is_empty)
            towers[i]->reset_at();
}

bool map::load_map() {
    map_name = "";
    for(size_t i = 0; i < directory.size(); i++){
        if(directory[i] == '.')
            break;
        else if(directory[i] == '/')
            map_name = "";
        else
            map_name += directory[i];
    }
    std::ifstream ifs(directory);
    if(ifs.is_open()){
        char ch = '?';
        std::cout << "File with map opened!\n";
        int stage = -1, t_stage = 0;
        std::pair<int,int> coord;
        ifs >> ch;
        while(true){
            if(ch == '\b') stage++;
            else
                throw badload();
            switch (stage) {
                case 0:
                    ifs >> exit;
                    break;
                case 1:
                    ifs >> enter;
                    break;
                case 2: {
                    ch = '?';
                    size_t t_type;
                    while(ch != '\b') {
                        bool b;
                        switch (t_stage) {
                            case 0:
                                ifs >> coord;
                                break;
                            case 1:
                                ifs >> b;
                                break;
                            case 2:
                                ifs >> t_type;
                                break;
                        }
                        ifs >> ch;
                        if(ch == '\a' || ch =='\b') {
                            t_stage++;
                            if(t_stage == 3){
                                tower tow(coord);
                                tow.is_empty = b;
                                tow.tower_type = t_type;
                                tower_positions.push_back(tow);
                            }
                            t_stage %= 3;
                            if(ch == '\b')
                                break;
                        }
                    }
                }
                case 3:
                    while(true){
                        ifs >> ch;
                        if(ch == '\a') {
                            ifs >> coord;
                            walls.insert({coord});
                        }else if(ch == '\b')
                            break;
                        else
                            throw badload();
                    }
                    break;
            }
            if(stage >= 3) break;
            ifs >> ch;
        }
        BFS();
        std::cout << "Succesfull load" << std::endl;
        draw_map();
    }else{
        std::cout << "Invalid filename or directory!" << std::endl;
        return false;
    }
    return true;
}

void map::fill_t() {
    for(size_t i = 0; i < tower_positions.size(); i++){
        if(!tower_positions[i].is_empty)
            towers.insert({i, make_t(tower_positions[i].tower_type, tower_positions[i].position)});
    }
}

bool map::save_map(std::string dir) {
    directory = ( dir + map_name + ".game_map");
    std::ofstream of(directory);
    if(of.is_open()) {
        of << '\b' << exit << '\b' << enter << '\b';
        for (size_t i = 0; i < tower_positions.size(); i++) {
            of << tower_positions[i].position << '\a' << tower_positions[i].is_empty << '\a'
               << tower_positions[i].tower_type;
            if(i+1 == tower_positions.size())
                of << '\b';
            else
                of << '\a';
        }
        for(auto i = walls.begin(); i != walls.end(); i++){
            of << '\a' << *i;
        }
        of << '\b';
    } else
        return false;
    of.close();
    return true;
}

void map::reset() {
    for(size_t i = 0; i < tower_positions.size(); i++){
        if(!tower_positions[i].is_empty)
            towers[i]->reset_b_d();
    }
}
