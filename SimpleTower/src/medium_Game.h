#ifndef SRC_MEDIUM_GAME_H
#define SRC_MEDIUM_GAME_H
#include "default_Game.h"
/**
 * @file
 * @author  Kirill Gubarkov <gubarkir@cvut.cz>
 * @version 1.0
 */
/**
 * The medium_Game class which represents a low difficulty game.
 */
class medium_Game : public default_Game{
protected:
public:
    medium_Game(){}
/**
 * The copy constructor which changes parameters by difficulty level
 * @param a pointer to current game
 */
    medium_Game(default_Game* a){
        current_game_stage = a->current_game_st();
        game_map = a->get_cur_map();
        if(current_game_stage == 3)
            cur_player = new player(a->player_name, 750);
        else {
            cur_player = new player(a->get_cur_player());
            current_game_stage = 6;
        }
        lvl = a->lvl;
        game_map.fill_t();
        difff = a->difff;
    }
/**
 * The method, to get the current player.
 * @return player class
 */
    player * get_cur_player() const override;
/**
 * The method to generate enemies.
 */
    void generate_enemy() override;
/**
 *  The method, to build a wall in a random place.
 */
    void rand_wall() override;
};

#endif //SRC_MEDIUM_GAME_H