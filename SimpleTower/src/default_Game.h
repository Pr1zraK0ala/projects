#ifndef SRC_DEFAULT_GAME_H
#define SRC_DEFAULT_GAME_H
#include <fstream>
#include "map.h"
#include <cstdlib>
#include <algorithm>
#include <unistd.h>
#include <climits>

/**
 * @file
 * @author  Kirill Gubarkov <gubarkir@cvut.cz>
 * @version 1.0
 */
 /**
  * The default_Game abstract class which represents a current game.
 */
class default_Game{
protected:
    std::unordered_map<int,abstract_enemy*> v_enemy;
    std::set<int> v_num_e;
    map game_map;
    std::string cur_command;
    int current_game_stage;
/**
 * The method, to clear the window.
 */
    void clear_win();
/**
 * The method, which set the current game stage by the current command.
 * @return true, if the command is valid, otherwise false.
 */
    bool set_cur_stage();
/**
 * The method, to write the exit message.
 */
    void exit();
/**
 * The method, to write the exit message, if the game was started.
 * @param f true, if the game was lost, otherwise false.
 */
    void exit(bool f);
/**
 * The method, to write the full game instructions.
 */
    void faq();
/**
 * The method, to write the error message.
 */
    void mistake();
/**
 * The method, to delete the enemy.
 * @param i index in v_enemy
 */
    void delete_enemy(size_t i);
/**
 * The function, to clear the cin stream, if the input int, was incorrect.
 */
    void clear_cin_int();
    player *cur_player = nullptr;
public:
    std::size_t lvl;
    std::string player_name = "default";
    default_Game(){
        current_game_stage = -2;
        difff = 0;
        lvl = 1;
    };
    virtual ~default_Game(){
        if(cur_player != nullptr)
            delete cur_player;
        auto tmp = v_num_e.begin();
        while(tmp != v_num_e.end() && v_enemy[*tmp] != nullptr){
            delete v_enemy[*tmp];
            v_enemy.erase(v_enemy.find(*tmp));
            tmp++;
        }
    }
/**
 * The method, to get the current game stage.
 * @return int - game stage
 */
    int current_game_st() const;
/**
 * The method, to get the message from player.
 */
    void get_msg();
/**
 * The method, to write the welcome message.
 */
    void welcome();
/**
 * The method, which represent game action depending on the current stage.
 */
    void do_smth();
/**
 * The method that shows if the game is over.
 * @return true if the current stage is 0, otherwise false
 */
    bool is_finish() const;
/**
 * The method to write the game instructions.
 */
    void instruction() const;
/**
 * The method, to get the current map.
 * @return map object
 */
    map get_cur_map() const;
/**
 * The method to set the player name.
 */
    void set_name();
/**
 * The method, to get the current player.
 * @return player class
 */
    virtual player * get_cur_player() const = 0;
/**
 * The logic of the game and the process itself are written in this method.
 * @return true, in case the player complete the current level, otherwise false
 */
    bool game();
/**
 * The method to generate enemies.
 */
    virtual void generate_enemy() = 0;
/**
 * The method, to make an enemy.
 * @param type type of enemy
 * @return pointer to abstract_enemy
 */
    abstract_enemy* get_enemy(size_t type);
/**
 * The method, to save the current game.
 * @return true, in case of success, otherwise false
 */
    bool save_game();
/**
 * The method, to load the game.
 * @param directory directory and file name of game
 */
    void load_game(std::string directory);
/**
 * The method, to build a wall.
 */
    void build_wall();
/**
 * The method, to delete all towers and return money.
 * @return size_t, value of money, to return
 */
    size_t reset_towers();
/**
 * The method, to build a wall in a random place
 */
    virtual void rand_wall() = 0;
/**
 * The method, to build wall in the specified position
 * @param coord position
 */
    void build_wall(std::pair<int,int> coord);
    int difff;
};
#endif //SRC_DEFAULT_GAME_H
