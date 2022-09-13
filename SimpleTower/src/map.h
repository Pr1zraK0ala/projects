#ifndef SRC_MAP_H
#define SRC_MAP_H
#include "player.h"
#include "cannon.h"
#include "archer.h"
#include "crossbow.h"
#include "wizard.h"
#include "inferno.h"
#include "barbarian.h"
#include "rogue.h"
#include "shieldman.h"
#include "giant.h"
#include "hash_pair.h"
#include <set>
#include <vector>
#include <unordered_set>
#include <cstdlib>
#include <fstream>
#include <deque>
#include <unordered_map>

/**
 * @file
 * @author  Kirill Gubarkov <gubarkir@cvut.cz>
 * @version 1.0
*/
/**
 * The class to catch the map loading error.
 */
class badload {};

/**
 * The map class, which represents a current map.
 */
class map{
protected:
/**
 * The struct, which represent a tower.
 */
    struct tower{
        /**
         * Constructor, to set the tower's coordinate.
         * @param coor
         */
        tower(const std::pair<int,int>& coor){
            position = coor;
            is_empty = true;
            tower_type = 5;
        }
        std::pair<int, int> position;
        bool is_empty;
        size_t tower_type;
    };
    /**
     * Struct, which represent an enemy.
     */
    struct _enemy{
        /**
         * Constructor, to set the enemies coordinate and type.
         * @param new_pos coordinate
         * @param n_type type of enemy
         */
        _enemy(const std::pair<int,int> new_pos, size_t n_type){
            position = new_pos;
            type = n_type;
        }
        ~_enemy() = default;
        std::pair<int,int> position;
        size_t type;
    };
    std::unordered_map<std::pair<int, int>, std::pair<int, int>, hash_pair> road;
    std::pair<int, int> enter;
    std::pair<int, int> exit;
    std::string map_name;
    std::deque<_enemy> enemy;
    size_t current_enemy;
/**
 * The method to generate a random integer.
 * @param first from
 * @param sec to
 * @return int
 */
    int rand_int(int first, int sec);
/**
 * The method generate the new map for game.
 */
    void generate_map();
/**
 * The method, to find out if a coordinate is a road.
 * @param C coordinate.
 * @return true, or false.
 */
    bool find_road(std::pair<int,int> C);
/**
 * The method, to find out if a coordinate is a tower.
 * @param C coordinate.
 * @return true, or false.
 */
    bool find_tower(std::pair<int,int> C);
/**
 * The method, to get the next road position.
 * @param tmp current coordinate
 */
    void get_next(std::pair<int,int>& tmp);
/**
 * The method to get the 4 possible coordinate(up - down - left - right) from the current coordinate.
 * @param v_pos vector of possible coordinates
 * @param coord the current coordinate
 */
    void posible_coord(std::vector<std::pair<int,int>>& v_pos, const std::pair<int,int>& coord);
/**
 * The method to generate the shortest path.
 */
    void BFS();
/**
 * The method, to draw enemy.
 * @param enemy_type enemy type
 * @return char - enemy
 */
    char draw_enemy(size_t enemy_type);
/**
 * The method, to find out if any enemy is in the coordinate.
 * @param position coordinate
 * @return true, in case if any enemy is in this coordinate
 */
    bool find_enemy(std::pair<int,int> position);
/**
 * The method to load the map.
 * @return true, in successful case
 */
    bool load_map();
public:
    std::vector<tower> tower_positions;
    std::string directory;
    std::unordered_set<std::pair<int,int>, hash_pair> walls;
    std::unordered_map<int, abstract_tower*> towers;
/**
 * Default map constructor.
 */
    map(){
        map_name = "Default";
    }
/**
 * Map constructor, which set the name and generate the map.
 * @param _name
 */
    map(std::string _name){
        generate_map();
        map_name = _name;
    }
/**
 * Map constructor, which set the name and load the map.
 * @param dist map directory
 * @param f parameter, to distinguish from the constructor which generate the map
 */
    map(std::string dist, bool f){
        directory = dist;
        if(!load_map()) throw badload();
    }
    ~map(){
        for(size_t i = 0; i < tower_positions.size(); i++){
            if(!tower_positions[i].is_empty && towers[i] != nullptr) {
                delete towers[i];
            }
        }
    }
    friend std::ostream& operator << (std::ostream& out, const std::pair<int,int> &a);
    friend std::istream& operator >> (std::istream& in, std::pair<int,int> &a);
/**
 * The method generate tower positions.
 */
    void generate_tower_position();
/**
 * The method generate a road.
 */
    void generate_road();
/**
 * The method return the position where the enemies will appear.
 * @return pair<int,int> enter position
 */
    std::pair<int, int> get_enter_position();
/**
 * The method return the position upon reaching which the player will lose.
 * @return pair<int,int> exit position
 */
    std::pair<int, int> get_exit_position();
/**
 * The method return the position to which the enemy will move.
 * @param cur_pos current position
 * @return pair<int,int> next position
 */
    std::pair<int, int> get_next_position(std::pair<int, int> cur_pos);
/**
 * The method for build a tower of a given type at a given position.
 * @param position coordinate
 * @param tower_t tower type
 * @param c_player pointer to current player class
 * @return false, if the position or type is incorrect
 */
    bool build_tower(std::pair<int, int> position, size_t tower_t, player * c_player);
/**
 * The method, to draw the map.
 */
    void draw_map();
/**
 * The method, which write the possible position to build a tower.
 */
    void posible_tower_position() const;
/**
 * The method, to add an enemy to deque.
 * @param en pointer to enemy class
 */
    void add_enemy(const abstract_enemy* en);
/**
 * The method, to clean enemy deque
 */
    void remove_enem();
/**
 * The method, to copy number of position, where is some tower.
 * @param t deque with numbers of towers
 */
    void copy_t_pos(std::deque<int>& t);
/**
 * The method, to get the tower class pointer, by the tower number.
 * @param num tower number
 * @return pointer to tower, if the number is valid, or nullptr
 */
    abstract_tower* find_T(int num);
/**
 * The method to create the tower object, by the tower type
 * @param type tower type
 * @return pointer to the tower object
 */
    abstract_tower* make_t(size_t type, std::pair<int, int> position);
/**
 * The method, to reset attack of towers.
 */
    void reset_attack();
/**
 * The method, to save the generated map.
 * @param dir map directory
 * @return true, in case of success
 */
    bool save_map(std::string dir);
/**
 * The method, to reset the towers buffs.
 */
    void reset();
/**
 * The method to generate tower's objects, when loading map.
 */
    void fill_t();
};

#endif //SRC_MAP_H
