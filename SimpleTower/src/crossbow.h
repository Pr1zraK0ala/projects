#ifndef SRC_CROSSBOW_H
#define SRC_CROSSBOW_H
#include "abstract_tower.h"
/**
 * @file
 * @author  Kirill Gubarkov <gubarkir@cvut.cz>
 * @version 1.0
 */
/**
 * The class, which represents a crossbow tower
 */
class crossbow : public abstract_tower{
public:
/**
 * Constructor that sets the current position
 * @param coord pair<int,int> tower position
 */
    crossbow(std::pair<int, int> coord){
        coordinates = coord;
        type = 'd';
        reset_at();
        if(!get_tower_attributes()) throw bad_read();
    }

};
#endif //SRC_CROSSBOW_H