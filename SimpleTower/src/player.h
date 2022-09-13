#ifndef SRC_PLAYER_H
#define SRC_PLAYER_H
#include <iostream>

/**
 * @file
 * @author  Kirill Gubarkov <gubarkir@cvut.cz>
 * @version 1.0
*/
/**
 * The player class, which represents a current player.
 */
class player{
protected:
    size_t score;
    std::string player_name;
    size_t money;
public:
/**
 * Constructor, which set the player's name, and player's money
 * @param _n player's name
 * @param init_money player's money
 */
    player(std::string _n, size_t init_money){
        player_name = _n;
        score = 0;
        money = init_money;
    }
/**
 * Constructor, which set the player's name, player's score, and player's money
 * @param _n player's name
 * @param init_money player's money
 * @param _score player's score
 */
    player(std::string _n, size_t init_money, size_t _score){
        player_name = _n;
        score = _score;
        money = init_money;
    }
/**
 * Copy constructor
 * @param a pointer to player
 */
    player(player* a){
        player_name = a->player_name;
        score = a->score;
        money = a->money;
    }
    ~player(){}
    std::string get_name(){
        return player_name;
    }
/**
 * The method, to set the current money
 * @param _m value
 */
    void set_money(size_t _m);
/**
 * The method to deduct from current player's money, money value
 * @param _m money
 */
    void remove_money(size_t _m);
/**
 * The method to add to current player's money, money value
 * @param _m money
 */
    void add_money(size_t _m);
/**
 * The method return current money
 * @return size_t current player's money
 */
    size_t get_cur_money() const;
/**
 * The method return current player's score
 * @return size_t current player's score
 */
    size_t get_cur_score() const;
};

#endif //SRC_PLAYER_H
