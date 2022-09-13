#ifndef SRC_ARCHER_H
#define SRC_ARCHER_H
#include "abstract_tower.h"
/**
 * @file
 * @author  Kirill Gubarkov <gubarkir@cvut.cz>
 * @version 1.0
 */
/**
 * The class, which represents an archer tower
 */
class archer : public abstract_tower{
public:
/**
 * Constructor that sets the current position
 * @param coord pair<int,int> tower position
 */
    archer(std::pair<int, int> coord){
        coordinates = coord;
        type = 'b';
        reset_at();
        if(!get_tower_attributes()) throw bad_read();
    }
};
#endif //SRC_ARCHER_H