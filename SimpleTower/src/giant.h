#ifndef SRC_GIANT_H
#define SRC_GIANT_H
#include "abstract_enemy.h"
/**
 * @file
 * @author  Kirill Gubarkov <gubarkir@cvut.cz>
 * @version 1.0
 */
/**
 * The class, which represents an giant enemy
 */
class giant : public abstract_enemy{
public:
/**
 * Constructor that sets the current position
 * @param start_pos pair<int,int> the start position of enemy
 */
    giant(std::pair<int, int> start_pos){
        type = 4;
        current_pos = start_pos;
        if(!get_enemy_attributes()) throw badread();
        current_move_speed = max_move_speed;
        health = max_health;
    }
};

#endif //SRC_GIANT_H