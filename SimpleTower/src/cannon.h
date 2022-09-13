#ifndef SRC_CANNON_H
#define SRC_CANNON_H
#include "abstract_tower.h"
/**
 * @file
 * @author  Kirill Gubarkov <gubarkir@cvut.cz>
 * @version 1.0
 */
/**
 * The class, which represents a cannon tower
 */
class cannon : public abstract_tower{
public:
/**
 * Constructor that sets the current position
 * @param coord pair<int,int> tower position
 */
    cannon(std::pair<int, int> coord){
        coordinates = coord;
        type = 'a';
        reset_at();
        if(!get_tower_attributes()) throw bad_read();
    }
};
#endif //SRC_CANNON_H