#include "abstract_enemy.h"

std::pair<int,int> abstract_enemy::get_position() const { return current_pos; }

size_t abstract_enemy::get_cost() const { return cost; }

void abstract_enemy::make_damage(size_t damage) { health -= damage; }

int abstract_enemy::get_health() const { return health; }

void abstract_enemy::slow_down(size_t sl) {
    if(max_move_speed - sl >= current_move_speed)
        current_move_speed -= sl;
}

size_t abstract_enemy::get_move_speed() const { return current_move_speed; }

void abstract_enemy::change_position(std::pair<int,int> new_position) { current_pos = new_position; }

size_t abstract_enemy::get_type() const { return type; }

bool abstract_enemy::get_enemy_attributes() {
    std::ifstream ifs("examples/enemies.game");
    if(!ifs.is_open()){
        return false;
    }
    char ch = '?', ty;
    switch (type) {
        case 1:
            ty = 'a';
            break;
        case 2:
            ty = 'b';
            break;
        case 3:
            ty = 'd';
            break;
        case 4:
            ty = 'e';
            break;
        default:
            ty = '!';
            break;
    }
    ifs >> ch;
    std::string tmp;
    while(ch != ty){
        getline(ifs, tmp);
        ifs >> ch;
        if(!ifs.good()) return false;
    }
    if(ch != ty) return false;
    ifs >> tmp;
    if(tmp != "max_move_speed:") return false;
    ifs >> max_move_speed;
    ifs >> tmp;
    if(tmp != "health:") return false;
    ifs >> max_health;
    ifs >> tmp;
    if(tmp != "reward:") return false;
    ifs >> cost;
    ifs.close();
    return true;
}