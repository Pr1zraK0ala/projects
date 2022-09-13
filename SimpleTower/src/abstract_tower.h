#ifndef SRC_ABSTRACT_TOWER_H
#define SRC_ABSTRACT_TOWER_H
#include <iostream>
#include <fstream>

/**
 * @file
 * @author  Kirill Gubarkov <gubarkir@cvut.cz>
 * @version 1.0
 */
/**
 * The class to catch read errors from towers.game
 */
class bad_read{};
/**
 * The abstract_tower abstract class which represents a tower for SimpleTower game.
 */
class abstract_tower{
protected:
    std::pair<int, int> coordinates;
    size_t attack_speed;
    size_t cost;
    size_t range;
    size_t attack;
    size_t cur_attack;
    char type;
public:
    virtual ~abstract_tower() = default;
/**
 * The method, which return the tower position
 * @return pair<int,int>
 */
    std::pair<int, int> get_position();
/**
 * The method return the protected attribute attack speed
 * @return size_t attack speed
 */
    size_t get_attack_speed();
/**
 * The method return the protected attribute cost
 * @return size_t cost
 */
    size_t get_cost();
/**
 * The method return the protected attribute range
 * @return size_t range
 */
    size_t get_range();
/**
 * The method return the protected attribute attack
 * @return size_t attack
 */
    virtual size_t get_attack();
/**
 * The method, to reset the current number of attacks (cur_attack)
 */
    void reset_at();
/**
 * The method, to reset attack buff, if it exists
 */
    virtual void reset_b_d();
/**
 * The method, to get move debuff, if it exists
 * @return size_t debuff
 */
    virtual size_t enemy_move_debaff();
/**
 * The method, to get towers attributes.
 * @return true, in case of success, false, if the file with attributes was deleted, or has incorrect format.
 */
    bool get_tower_attributes();
};

#endif //SRC_ABSTRACT_TOWER_H