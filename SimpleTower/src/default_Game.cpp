#include "default_Game.h"

void default_Game::welcome() {
    clear_win();
    std::cout << "Welcome to SimpleTower!" << std::endl;
}

void default_Game::exit() {
    clear_win();
    if(cur_player == nullptr && player_name == "default")
        std::cout << "Thank you for the game!" << std::endl;
    else if (player_name != "default")
        std::cout << "Thank you for the game '" << player_name << "'!" << std::endl;
    else
        std::cout << "Thank you for the game, '" << cur_player->get_name() << "'!\nYour final score: " << cur_player->get_cur_score() << std::endl;
}

void default_Game::exit(bool f) {
    clear_win();
    if(f) {
        std::cout << "You lose!" << std::endl;
        exit();
        current_game_stage = 0;
    }else{
        std::cout << "You completed " << lvl-1 << " level. Your score: " << cur_player->get_cur_score() << std::endl;
        game_map.draw_map();
    }
    sleep(5);
}

void default_Game::faq() {
    try{
        barbarian b({0, 0});
        rogue r({0, 0});
        shieldman sh({0, 0});
        giant g({0, 0});
        try {
            cannon cn({0, 0});
            archer ar({0, 0});
            crossbow cr({0, 0});
            wizard w({0, 0});
            inferno in({0, 0});
            std::cout << "Simple Tower is a turn-based endless tower defense.\n"
                         "The game consists of two phases, the construction phase and the combat phase. In the construction phase, you can build towers on the selected fields('*'), and during the battle phase, you will no longer be able to do this, enemies will appear in start('s') field. The goal of the game is not to let the enemy reach the exit('E'). They can only go along road fields('x'). "
                         "\nThere are walls(#) on the game map, these fields block and complicate the path of the enemy. You can build it by yourself, and you will get the full cost of the towers back, after every 5 round 3-5(depends on the difficulty of the game) walls will appear automatically (if the number of walls does not exceed half of the possible positions for their appearance), after it your towers will be destroyed and you get back only the half of cost of the towers back.\n"
                         "\n\nTower characteristics: \n"
                         "------------------------------------------------------------------------------\n"
                         "Cannon: \n"
                         "        Cost: " << cn.get_cost() << "        Attack speed: " << cn.get_attack_speed()
                      << "        Range: " << cn.get_range() << "        Attack: " << cn.get_attack() << "\n"
                                                                                                         "------------------------------------------------------------------------------\n"
                                                                                                         "Archer: \n"
                                                                                                         "        Cost: "
                      << ar.get_cost() << "        Attack speed: " << ar.get_attack_speed() << "        Range: "
                      << ar.get_range() << "        Attack: " << ar.get_attack() << "\n"
                                                                                    "------------------------------------------------------------------------------\n"
                                                                                    "Crossbow:\n"
                                                                                    "        Cost: " << cr.get_cost()
                      << "        Attack speed: " << cr.get_attack_speed() << "        Range: " << cr.get_range()
                      << "        Attack: " << cr.get_attack() << "\n"
                                                                  "------------------------------------------------------------------------------\n"
                                                                  "Wizard: \n"
                                                                  "        Cost: " << w.get_cost()
                      << "        Attack speed: " << w.get_attack_speed() << "        Range: " << w.get_range()
                      << "        Attack: " << w.get_attack() << "\n"
                                                                 "* The Wizard slows down the enemies. \n"
                                                                 "------------------------------------------------------------------------------\n"
                                                                 "Inferno: \n"
                                                                 "        Cost: " << in.get_cost()
                      << "        Attack speed: " << in.get_attack_speed() << "        Range: " << in.get_range()
                      << "        Attack: " << in.get_attack()/2 << "-1000\n"
                                                                  "* Inferno increases attack over time. \n"
                                                                  "------------------------------------------------------------------------------\n"
                                                                  "\nAttack speed - how many times the tower attacks in one turn of the enemy\n"
                                                                  "\n\nEnemy characteristics: \n"
                                                                  "------------------------------------------------------------------------------\n"
                                                                  "Barbarian: \n"
                                                                  "        Max speed: " << b.get_move_speed()
                      << "        Health: " << b.get_health() << "\n"
                                                                 "------------------------------------------------------------------------------\n"
                                                                 "Rogue: \n"
                                                                 "        Max speed: " << r.get_move_speed()
                      << "        Health: " << r.get_health() << "\n"
                                                                 "------------------------------------------------------------------------------\n"
                                                                 "Shield man: \n"
                                                                 "        Max speed: " << sh.get_move_speed()
                      << "        Health: " << sh.get_health() << "\n"
                                                                  "------------------------------------------------------------------------------\n"
                                                                  "Giant: \n"
                                                                  "        Max speed: " << g.get_move_speed()
                      << "        Health: " << g.get_health() << "\n"
                                                                 "------------------------------------------------------------------------------\n"
                      << std::endl;
        }catch (const bad_read& e){
            std::cout << "File towers.game content error" << std::endl;
            current_game_stage = 0;
        }
    }catch (const badread& e){
        std::cout << "File enemies.game content error" << std::endl;
        current_game_stage = 0;
    }


}

bool default_Game::is_finish() const{
    return current_game_stage == 0;
}

void default_Game::instruction() const{
    switch (current_game_stage) {
        case -3:
            std::cout << "Please, enter the directory with the game save name,\nlike 'saves/new_save/n.save', where\n'saves/new_save/' - folders\n'n' - file name\n'.save' - Filename extension." << std::endl;
            break;
        case -2:
            std::cout << "\nTo start the game, enter 'start'.\nTo load the game, enter 'load'.\nTo see the instruction, enter 'faq'.\nTo set the player name, enter 'name', it will be '" << player_name << "' if you don't change it. You are not able to change it during the game.\nTo exit, enter 'exit'.\n" << std::endl;
            break;
        case -1:
            std::cout << "Please, enter your name." << std::endl;
            break;
        case 1:
            std::cout << "Ok, lets set the difficult: 1-3 (low, medium, hard)." << std::endl;
            break;
        case 3:
            std::cout << "To generate a map, enter 'make map'\nTo select a ready-made map, enter 'set map'.\n" << std::endl;
            break;
        case 4:
            std::cout << "Please, enter the directory with the map name,\nlike 'map/new_map/m.game_map', where\n'map/new_map/' - folders\n'm' - map name\n'.game_map' - Filename extension." << std::endl;
            break;
        case 5:
            std::cout << "If you like this map, write 'OK', or 'again', if you want to regenerate it\nTo save the current map, enter 'save'.\n" << std::endl;
            break;
        case 6:
            std::cout << "To launch enemies, write 'run'\nTo build a tower, write 'build tower'.\nTo save the game, write 'save game'\nTo build a wall, write 'build wall'" << std::endl;
            break;
        case 7:
            std::cout << "Your money: " << cur_player->get_cur_money() << "\nEnter the number of tower position, possible tower position:" << std::endl;
            game_map.posible_tower_position();
            break;
        case 9:
            std::cout << "Please enter the directory to save the map." << std::endl;
            break;
        case 10:
            std::cout << "Please enter the directory to save the current game. The game will be named 'playername'.save" << std::endl;
            break;
        case 11:
            std::cout << "To build a wall, write the coordinates, format 'x,y', x,y must be more than 2, and less than 22, where the wall will be built, all the towers will be removed, the money for them will be returned to you.\nIf you finished with building, write 'ok'" << std::endl;
            break;
        default:
            break;
    }

}

void default_Game::set_name() {
    instruction();
    get_msg();
    player_name = cur_command;
    current_game_stage = -2;
}

void default_Game::mistake() {
    std::cout << "I'm really sorry, but I don't know your command: " << cur_command << " try again, please" << std::endl;
}

void default_Game::clear_win() {
    system("clear");
}

bool default_Game::set_cur_stage() {
    std::transform(cur_command.begin(), cur_command.end(), cur_command.begin(), [](unsigned char c) {return std::tolower(c);});
    if (cur_command == "start") {
        if (current_game_stage == -2 || current_game_stage == 2 || current_game_stage == -1)
            current_game_stage = 1;
        else {
            mistake();
            return false;
        }
    } else if (cur_command == "exit")
        current_game_stage = 0;
    else if (cur_command == "faq") {
        if(current_game_stage < 0)
            current_game_stage = 2;
        else{
            mistake();
            return false;
        }
    }
    else if (cur_command == "name"){
        if(current_game_stage == -2)
            current_game_stage = -1;
    }
    else if(cur_command == "set map"){
        if(current_game_stage == 3)
            current_game_stage = 4;
    }
    else if(cur_command == "make map") {
        if (current_game_stage == 3)
            current_game_stage = 5;
        else {
            mistake();
            return false;
        }
    }
    else if(cur_command == "again" && current_game_stage == 5);
    else if(cur_command == "ok" && (current_game_stage == 5 || current_game_stage == 7))
        current_game_stage = 6;
    else if(cur_command == "run" && (current_game_stage == 6 || current_game_stage == 7))
        current_game_stage = 8;
    else if(cur_command == "build tower")
        current_game_stage = 7;
    else if(cur_command == "save" && current_game_stage == 5)
        current_game_stage = 9;
    else if(cur_command == "save game" && current_game_stage == 6)
        current_game_stage = 10;
    else if(cur_command == "load" && current_game_stage == -2)
        current_game_stage = -3;
    else if(cur_command == "build wall" && current_game_stage == 6)
        current_game_stage = 11;
    else{
        mistake();
        return false;
    }
    return true;
}

void default_Game::clear_cin_int() {
    std::cin . clear ();
    std::cin.ignore(INT_MAX, '\n' );
    if(!std::cin.good()){
        std::clearerr(stdin);
        std::cin.clear(std::ios::goodbit);
    }
}

void default_Game::load_game(std::string directory) {
    for(size_t i = 0; i < directory.size(); i++){
        if(i > 0 && directory[i-1] == '/')
            player_name = directory[i];
        else if(directory[i] == '.')
            break;
        else
            player_name += directory[i];
    }
    std::ifstream ifs(directory);
    if(ifs.is_open()){
        size_t score, money;
        char ch = '?';
        std::cout << "File with game save opened!\n";
        ifs >> difff >> ch;
        if(ch != '\a')
            throw badload();
        ifs >> lvl >> ch;
        if(ch != '\a')
            throw badload();
        std::string map_dir;
        ifs >> map_dir >> ch;
        if(ch != '\a')
            throw badload();
        ifs >> score >> ch;
        if(ch != '\a')
            throw badload();
        ifs >> money >> ch;
        if(ch != '\b')
            throw badload();
        try {
            game_map = map(map_dir, true);
        }catch (const bad_read& e){
            std::cout << "File towers.game content error" << std::endl;
            current_game_stage = 0;
        }
        cur_player = new player(player_name, money, score);
        std::cout << "Succesfull load" << std::endl;
    }else{
        std::cout << "Invalid filename or directory!" << std::endl;
        throw badload();
    }
}

void default_Game::do_smth() {
    if(!set_cur_stage()) return;
    clear_win();
    switch (current_game_stage) {
        case -3: {
            std::string dir;
            instruction();
            if(!getline(std::cin, dir).good()){
                std::clearerr(stdin);
                std::cin.clear(std::ios::goodbit);
            }
            try {
                load_game(dir);
            }
            catch (const badload & f){
                std::cout << "Invalid filename, directory, or file has incorrect information!\n" << std::endl;
                current_game_stage = -2;
            }
            break;
        }
        case -1:
            set_name();
            break;
        case 0:
            exit();
            break;
        case 1:
            while(true){
                int i = 0;
                instruction();
                while ( ! (std::cin >> i ) )
                {
                    std::cout << "Invalid command" << std::endl;
                    clear_cin_int();
                }
                if(i >= 1 && i <= 3) {
                    std::cout << "You chose: " << (i == 1 ? "low" : i == 2 ? "medium" : "hard") << std::endl;
                    difff = i;
                    break;
                }
                else
                    std::cout << "You set invalid game difficult " << i << ", please write the correct (1-3)" <<std::endl;;
            }
            get_msg();
            current_game_stage = 3;
            break;
        case 2:
            current_game_stage = -2;
            faq();
            break;
        case 4: {
            instruction();
            std::string dir;
            if(getline(std::cin, dir).good()){
            }else{
                std::clearerr(stdin);
                std::cin.clear(std::ios::goodbit);
            }
            clear_win();
            try {
                game_map = map(dir, true);
                game_map.fill_t();
                current_game_stage = 6;
            }
            catch (const badload & f){
                std::cout << "Invalid filename, directory, or file has incorrect information!\n" << std::endl;
                current_game_stage = 3;
            }
            break;
        }
        case 5: {
            std::cout << "Enter the name for new map. " << std::endl;
            std::string name;
            if(getline(std::cin, name).good()){
            }else{
                std::clearerr(stdin);
                std::cin.clear(std::ios::goodbit);
            }
            game_map = map(name);
            game_map.draw_map();
            break;
        }
        case 6:
            game_map.draw_map();
            break;
        case 7:
            instruction();
            int position, tower_type;
            while (true) {
                while (!(std::cin >> position)) {
                    std::cout << "Invalid position number" << std::endl;
                    clear_cin_int();
                }
                if (position >= 0 && position < (int)game_map.tower_positions.size() && game_map.tower_positions[position].is_empty) {
                    break;
                }
                else
                    std::cout << "Invalid position number: " << position << ". Please enter the correct position"<< std::endl;
            }
            std::cout << "Please enter the tower type." << std::endl;
            while (true) {
                std::cout << "Valid tower types:\n0 - cannon\n1 - archer\n2 - crossbow\n3 - wizard\n4 - inferno" << std::endl;
                while (!(std::cin >> tower_type)) {
                    std::cout << "Invalid tower type" << std::endl;
                    clear_cin_int();
                }
                if (tower_type >= 0 && tower_type < 5) {
                    break;
                }
                else
                    std::cout << "Invalid tower type: " << tower_type << std::endl;
            }
            try {
                if (!game_map.build_tower(game_map.tower_positions[position].position, tower_type, cur_player)) {
                    std::cout << "You haven't enough money to build this tower" << std::endl;
                } else {
                    std::cout << "Successful build, your current money: " << cur_player->get_cur_money() << std::endl;
                }
                current_game_stage = 6;
                game_map.draw_map();
                get_msg();
            }catch (const bad_read& e){
                std::cout << "File towers.game content error" << std::endl;
                current_game_stage = 0;
            }
            break;
        case 8:
            current_game_stage = 6;
            if(!game()) exit(true);
            else exit(false);
            break;
        case 9: {
            instruction();
            std::string m;
            if (getline(std::cin, m).good()) {
            } else {
                std::clearerr(stdin);
                std::cin.clear(std::ios::goodbit);
            }
            if (game_map.save_map(m)) {
                std::cout << "Successful save!" << std::endl;
            } else {
                std::cout << "Something went wrong!" << std::endl;
            }
            sleep(2);
            clear_win();
            game_map.draw_map();
            current_game_stage = 5;
            break;
        }
        case 10:
            instruction();
            if(!save_game())
                std::cout << "Something went wrong!" << std::endl;
            current_game_stage = 6;
            break;
        case 11:
            build_wall();
            break;
    }
}

size_t default_Game::reset_towers() {
    size_t money = 0;
    for(size_t i = 0; i < game_map.tower_positions.size(); i++){
        if(!game_map.tower_positions[i].is_empty){
            money += game_map.towers[i]->get_cost();
            auto tmp = game_map.towers[i];
            game_map.towers.erase(i);
            delete tmp;
        }
    }
    game_map.tower_positions.clear();
    return money;
}

void default_Game::build_wall() {
    std::string com, xs = "", ys = "";
    size_t money = reset_towers();
    cur_player->set_money(money + cur_player->get_cur_money());
    int x,y;
    while(true) {
        instruction();
        if(getline(std::cin, com).good()){
        }else{
            std::clearerr(stdin);
            std::cin.clear(std::ios::goodbit);
        }
        if(com == "ok" && !game_map.tower_positions.empty()) break;
        else{
            reset_towers();
            size_t i = 0;
            for(; i < com.size(); i++){
                if(com[i] == ',') {
                    i++;
                    break;
                }
                xs += com[i];
            }
            for(; i < com.size(); i++){
                ys += com[i];
            }
            if(xs.size() > 0 && ys.size() > 0){
                x = std::stoi(xs);
                y = std::stoi(ys);
                if (x >= 23 || y >= 23 || x <= 1 || y <= 1) {
                    std::cout << "Incorrect format!" << std::endl;
                } else
                    game_map.walls.insert({x, y});
            }
        }
        game_map.generate_road();
        game_map.generate_tower_position();
        game_map.draw_map();
        xs = "";
        ys = "";
    }
    current_game_stage = 6;
}

bool default_Game::save_game() {
    std::string m;
    if(getline(std::cin, m).good()){
    }else{
        std::clearerr(stdin);
        std::cin.clear(std::ios::goodbit);
    }
    if(game_map.save_map(m)) {
        std::string directory = ( m + cur_player->get_name() + ".save");
        std::ofstream of(directory);
        if(of.is_open()) {
            of << difff <<'\a'<< lvl << '\a' << game_map.directory << '\n' << '\a' << cur_player->get_cur_score() << '\a' << cur_player->get_cur_money() << '\b';
        } else
            return false;
        of.close();
        std::cout << "Successful save!" << std::endl;
        game_map.draw_map();
        return true;
    }else{
        return false;
    }
}

int default_Game::current_game_st() const {
    return current_game_stage;
}

void default_Game::get_msg() {
    if(getline(std::cin, cur_command).good()){
    }else{
        std::clearerr(stdin);
        std::cin.clear(std::ios::goodbit);
    }
}

map default_Game::get_cur_map() const{
    return game_map;
}

abstract_enemy* default_Game::get_enemy(size_t type) {
    abstract_enemy * en = nullptr;
    try {
        switch (type) {
            case 0:
                en = new barbarian({0, 0});
                break;
            case 1:
                en = new rogue({0, 0});
                break;
            case 2:
                en = new shieldman({0, 0});
                break;
            case 3:
                en = new giant({0, 0});
                break;
            default:
                en = nullptr;
        }
    }catch (const badread& e){
        std::cout << "File enemies.game content error" << std::endl;
        if(en != nullptr)
            delete en;
        current_game_stage = 0;
    }
    return en;
}

void default_Game::delete_enemy(size_t i) {
    v_num_e.erase(v_num_e.find(i));
    delete v_enemy[i];
    v_enemy.erase(v_enemy.find(i));
}

bool default_Game::game() {
    generate_enemy();
    if(v_enemy.empty()) {
        sleep(3);
        return false;
    }
    std::cout<<"Enemy generated! Number of enemies: "<< v_enemy.size() << std::endl;
    while(!v_enemy.empty()){
        clear_win();
        std::cout<<"Number of enemies: "<< v_enemy.size() << ". Your current score: " << cur_player->get_cur_score() << std::endl;
        std::deque<int> t_position;
        game_map.copy_t_pos(t_position);
        for(size_t i = 0; i < game_map.tower_positions.size(); i++){
            abstract_tower * ptr = game_map.find_T(i);
            auto j = v_num_e.begin();
            while(j != v_num_e.end() && v_enemy[*j]->get_position() != std::pair<int,int>{0,0}){
                if(ptr != nullptr) {
                    int dist_e = abs(ptr->get_position().first - v_enemy[*j]->get_position().first) +
                                 abs(ptr->get_position().second - v_enemy[*j]->get_position().second);
                    int dist_t = ptr->get_range();
                    if (dist_e <= dist_t) {
                        while (ptr->get_attack_speed() > 0) {
                            auto attack = ptr->get_attack();
                            std::cout << (game_map.tower_positions[i].tower_type == 0 ? "Cannon " : game_map.tower_positions[i].tower_type == 1 ? "Archer " :
                            game_map.tower_positions[i].tower_type == 2 ? "Crossbow " : game_map.tower_positions[i].tower_type == 3 ? "Wizard " : "Inferno ")
                            << "hit " << (v_enemy[*j]->get_type() == 1 ? "barbarian " : v_enemy[*j]->get_type() == 2 ? "rogue " :
                            v_enemy[*j]->get_type() == 3 ? "shieldman " : "giant " ) << " remain: "<< ((size_t)v_enemy[*j]->get_health() > attack ?
                            v_enemy[*j]->get_health() - attack : 0)<< "HP." << std::endl;
                            v_enemy[*j]->make_damage(attack);
                            v_enemy[*j]->slow_down(ptr->enemy_move_debaff());
                            if (v_enemy[*j]->get_health() <= 0) {
                                cur_player->add_money(v_enemy[*j]->get_cost());
                                std::cout << (v_enemy[*j]->get_type() == 1 ? "Barbarian" : v_enemy[*j]->get_type() == 2 ? "Rogue" :
                                          v_enemy[*j]->get_type() == 3 ? "Shieldman" : "Giant")
                                          << " is dead. You get " << v_enemy[*j]->get_cost() << " coins." << std::endl;
                                delete_enemy(*j);
                                break;
                            }
                        }
                    }
                }
                j++;
            }
        }
        game_map.reset_attack();
        for(auto i = v_num_e.begin(); i != v_num_e.end(); i++){
            if(v_enemy[*i]->get_position() == std::pair<int,int>{0,0}){
                v_enemy[*i]->change_position(game_map.get_enter_position());
                game_map.add_enemy(v_enemy[*i]);
                break;
            }
            for(size_t k = 0; k < v_enemy[*i]->get_move_speed(); k++) {
                std::pair<int, int> new_pos = game_map.get_next_position(v_enemy[*i]->get_position());
                if (new_pos == game_map.get_exit_position())
                    return false;
                v_enemy[*i]->change_position(new_pos);
            }
            game_map.add_enemy(v_enemy[*i]);
        }
        game_map.draw_map();
        sleep(1);
        game_map.remove_enem();
    }
    game_map.reset();
    if(lvl % 5 == 0) {
        clear_win();
        rand_wall();
        std::cout << std::endl;
        game_map.draw_map();
        sleep(5);
    }
    lvl++;
    return true;
}

void default_Game::build_wall(std::pair<int, int> coord) {
    auto money = reset_towers();
    cur_player->set_money(money/2 + cur_player->get_cur_money());
    if(money > 0){
        std::cout << "Your towers were destroyed but you got back " << money/2 << "\n" << std::endl;
    }
    game_map.walls.insert(coord);
    game_map.generate_road();
    game_map.generate_tower_position();
    std::cout << "New wall appeared on [" << coord.first << ',' << coord.second << ']' << std::endl;
}