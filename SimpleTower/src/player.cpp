#include "player.h"

void player::add_money(size_t _m)  {
    score += (10 * _m);
    money += _m;
}

void player::remove_money(size_t _m) {
    money -= _m;
}

size_t player::get_cur_money() const { return money; }

size_t player::get_cur_score() const  { return score; }

void player::set_money(size_t _m) {
    money = _m;
}
