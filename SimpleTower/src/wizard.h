#ifndef SRC_WIZARD_H
#define SRC_WIZARD_H
#include "abstract_tower.h"
/**
 * @file
 * @author  Kirill Gubarkov <gubarkir@cvut.cz>
 * @version 1.0
 */
/**
 * The class, which represents a wizard tower
 */
class wizard : public abstract_tower{
public:
/**
 * Constructor that sets the current position
 * @param coord pair<int,int> tower position
 */
    wizard(std::pair<int, int> coord){
        coordinates = coord;
        type = 'e';
        reset_at();
        if(!get_tower_attributes()) throw bad_read();
    }
/**
 * The method, to get move debuff, if it exists
 * @return size_t debuff
 */
    size_t enemy_move_debaff() override;
protected:
    size_t enemy_debaff = 1;
};
#endif //SRC_WIZARD_H