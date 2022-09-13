#include "abstract_tower.h"

std::pair<int, int> abstract_tower::get_position() { return coordinates; }

size_t abstract_tower::get_attack_speed() { return cur_attack < attack_speed ? attack_speed - cur_attack : 0; }

size_t abstract_tower::get_cost() { return cost; }

size_t abstract_tower::get_range() { return range; }

size_t abstract_tower::get_attack() {
    cur_attack++;
    return attack;
}

size_t abstract_tower::enemy_move_debaff() { return 0; }

void abstract_tower::reset_at() {
    cur_attack = 0;
}

void abstract_tower::reset_b_d() {}

bool abstract_tower::get_tower_attributes() {
    std::ifstream ifs("examples/towers.game");
    if(!ifs.is_open()){
        return false;
    }
    char ch = '?';
    ifs >> ch;
    std::string tmp;
    while(ch != type){
        getline(ifs, tmp);
        ifs >> ch;
        if(!ifs.good()) throw bad_read();
    }
    if(ch != type) return false;
    ifs >> tmp;
    if(tmp != "Cost:") throw bad_read();
    ifs >> cost;
    ifs >> tmp;
    if(tmp != "attack_speed:") throw bad_read();
    ifs >> attack_speed;
    ifs >> tmp;
    if(tmp != "range:") throw bad_read();
    ifs >> range;
    ifs >> tmp;
    if(tmp != "attack:") throw bad_read();
    ifs >> attack;
    ifs.close();
    return true;
}