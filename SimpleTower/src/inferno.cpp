#include "inferno.h"


size_t inferno::get_attack() {
    change_attack();
    cur_attack++;
    return attack;
}

void inferno::change_attack() {
    if(attack < 1000)
        attack *= 2;
}

void inferno::reset_b_d() {
    attack = 1;
}