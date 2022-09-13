#ifndef SRC_ROGUE_H
#define SRC_ROGUE_H
#include "abstract_enemy.h"
/**
 * @file
 * @author  Kirill Gubarkov <gubarkir@cvut.cz>
 * @version 1.0
 */
/**
 * The class, which represents an rogue enemy
 */
class rogue : public abstract_enemy{
public:
/**
 * Constructor that sets the current position
 * @param start_pos pair<int,int> the start position of enemy
 */
    rogue(std::pair<int, int> start_pos){
        type = 2;
        current_pos = start_pos;
        if(!get_enemy_attributes()) throw badread();
        current_move_speed = max_move_speed;
        health = max_health;
    }
};
#endif //SRC_ROGUE_H