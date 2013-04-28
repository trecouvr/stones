#include "GameManager.h"


#include "Action.h"
#include "Player.h"

GameManager::GameManager()
{
    players_[0] = nullptr;
    players_[1] = nullptr;
}

GameManager::GameManager(Player* p1, Player* p2)
{
    players_[0] = p1;
    players_[1] = p2;
}

void GameManager::run()
{
    while (!isFinished())
    {
        runPlayerTurn(players_[0], players_[1]);
        runPlayerTurn(players_[1], players_[0]);
    }
}

void GameManager::runPlayerTurn(Player* player, const Player* o)
{
    bool play = true;
    while (play)
    {
        Action_t action = player->doAction(*o);
        switch (action)
        {
            case START_BATTLE:
                // launch the battle !
                // write here a special flow to handle battle phases
            break;
            case END_TURN:
                // end of turn, break the loop
                play = false;
            break;
            case EMBEDDED:
                /* do nothing, action does not need manager. Note this 
                 * is for convenience, doAction should return only 
                 * START_BATTLE or END_TURN, since this is the only 
                 * cases manager is involved
                 */
            default:
                // by default do nothing, shall we raise an exception ?
            break;
        }
    }
}

bool GameManager::isFinished() const
{
    return false;
}




