#include "GameManager.h"


#include "Action.h"
#include "UserInterface.h"
#include "Deck.h"

GameManager::GameManager(UserInterface* ui1, UserInterface* ui2)
{
    uis_[0] = ui1;
    uis_[1] = ui2;
    Deck* d1 = new Deck(40);
    players_[0] = Player(d1, 2000);
    Deck* d2 = new Deck(40);
    players_[1] = Player(d2, 2000);
}

void GameManager::run()
{
    while (!isFinished())
    {
        runPlayerTurn(uis_[0], players_[0], players_[1]);
        runPlayerTurn(uis_[1], players_[1], players_[0]);
    }
}

void GameManager::runPlayerTurn(UserInterface* ui, Player& p1, Player& o)
{
    bool play = true;
    while (play)
    {
        Action action = ui->getAction(p1, o);
        switch (action.t)
        {
            case DRAW:
                p1.draw();
            break;
            case INVOKE_MONSTER_FROM_HAND:
                p1.invokeMonsterFromHand(action.data[0], action.data[1]);
            break;
            case SWAP_HAND_CARDS:
                p1.swapHandCards(action.data[0], action.data[1]);
            break;
            case SWAP_MONSTER_CARDS:
                p1.swapMonsterCards(action.data[0], action.data[1]);
            break;
            case START_BATTLE:
                // launch the battle !
                // write here a special flow to handle battle phases
            break;
            case END_TURN:
                // end of turn, break the loop
                play = false;
            break;
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




