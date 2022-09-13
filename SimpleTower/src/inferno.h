#ifndef SRC_INFERNO_H
#define SRC_INFERNO_H
#include "abstract_tower.h"
/**
 * @file
 * @author  Kirill Gubarkov <gubarkir@cvut.cz>
 * @version 1.0
 */
/**
 * The class, which represents an inferno tower
 */
class inferno : public abstract_tower{
public:
/**
 * Constructor that sets the current position
 * @param coord pair<int,int> tower position
 */
    inferno(std::pair<int, int> coord){
        coordinates = coord;
        type = 'f';
        reset_at();
        if(!get_tower_attributes()) throw bad_read();
    }
/**
 * The method return the protected attribute attack
 * @return size_t attack
 */
    size_t get_attack() override;
/**
 * The method, to reset attack buff, if it exists
 */
    void reset_b_d() override;

protected:
/**
 * The method, which increase the attack of the tower
 */
    void change_attack();
};
#endif //SRC_INFERNO_H