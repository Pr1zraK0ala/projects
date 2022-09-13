#ifndef SRC_ABSTRACT_ENEMY_H
#define SRC_ABSTRACT_ENEMY_H
#include <iostream>
#include <fstream>

/**
 * @file
 * @author  Kirill Gubarkov <gubarkir@cvut.cz>
 * @version 1.0
*/
/**
 * The class to catch read errors from enemies.game
 */
class badread{};
/**
 * The abstract_enemy abstract class which represents an enemy for SimpleTower game.
 */
class abstract_enemy{
protected:
    std::pair<int, int> current_pos;
    size_t max_move_speed;
    size_t current_move_speed;
    int health;
    int max_health;
    size_t cost;
    size_t type = 0;
public:
    virtual ~abstract_enemy() = default;
/**
 * Get the current enemy type
 * @return size_t (0-4) 0 - abstract 1 - barbarian 2 - rogue 3 - shieldman 4 - giant
 */
    size_t get_type() const;
/**
 * Get the position of enemy
 * @return pair<int,int>
 */
    std::pair<int, int> get_position() const;
/**
 * The amount of the reward upon the death of an enemy
 * @return size_t
 */
    size_t get_cost() const;
/**
 * The method, to change the enemy health
 * @param damage represent the damage to the enemy
 */
    void make_damage(size_t damage);
/**
 * The method, to get the current health of the enemy
 * @return int (current health points)
 */
    int get_health() const;
/**
 * The method, to change the move speed
 * @param sl - the number of fields how much the enemy will slow down
 */
    void slow_down(size_t sl);
/**
 * Get current move speed
 * @return size_t move speed
 */
    size_t get_move_speed() const;
/**
 * The method, to change the current enemies position
 * @param new_position pair<int,int>
 */
    void change_position(std::pair<int, int> new_position);
/**
 * The method, to get enemies attributes.
 * @return true, in case of success, false, if the file with attributes was deleted, or has incorrect format.
 */
    bool get_enemy_attributes();
};
#endif //SRC_ABSTRACT_ENEMY_H