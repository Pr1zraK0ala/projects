#include "low_Game.h"
#include "medium_Game.h"
#include "hard_Game.h"
#include <ctime>

int main() {
    srand(time(NULL));
    default_Game* cur_game = new medium_Game();
    cur_game->welcome();
    while(!cur_game->is_finish()) {
        cur_game->instruction();
        if(cur_game->current_game_st() != 11)
            cur_game->get_msg();
        cur_game->do_smth();
        if (abs(cur_game->current_game_st()) == 3) {
            if (cur_game->difff == 1) {
                low_Game *tmp = new low_Game(&(*cur_game));
                delete cur_game;
                cur_game = tmp;
            } else if (cur_game->difff == 2) {
                medium_Game *tmp = new medium_Game(&(*cur_game));
                delete cur_game;
                cur_game = tmp;
            } else if (cur_game->difff == 3) {
                hard_Game *tmp = new hard_Game(&(*cur_game));
                delete cur_game;
                cur_game = tmp;
            }
        }
    }
    delete cur_game;
    return 0;
}
