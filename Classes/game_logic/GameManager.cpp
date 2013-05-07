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
    
    // Drawing 5 cards to initialize player's hand
    
    int i;
    
    for (i=0;i < 5;i++)
        players_[0].draw();
}

void GameManager::run()
{
    while (!isFinished())
    {
        runPlayerTurn(uis_[0], players_[0], players_[1]);
        runPlayerTurn(uis_[1], players_[1], players_[0]);
    }
}

void GameManager::runPlayerTurn(UserInterface* ui, Player& p, Player& o)
{
    bool play = true;
    int action_count=0;
    while (play)
    {
        Action action;
        ui->getAction(action, p, o, action_count);
        switch (action.getT())
        {
            case Action::DRAW:
                p.draw();
            break;
            case Action::INVOKE_MONSTER_FROM_HAND:
                p.invokeMonsterFromHand(action.getData(0), action.getData(1));
            break;
            case Action::SWAP_HAND_CARDS:
                p.swapHandCards(action.getData(0), action.getData(1));
            break;
            case Action::SWAP_MONSTER_CARDS:
                p.swapMonsterCards(action.getData(0), action.getData(1));
            break;
            case Action::START_BATTLE:
                // launch the battle !
                // write here a special flow to handle battle phases
            break;
            case Action::END_TURN:
                // end of turn, break the loop
                play = false;
            break;
            case Action::NONE:
            default:
                // by default do nothing, shall we raise an exception ?
            break;
        }
        ui->afterAction(action, p, o, action_count);
        ++action_count;
    }
}

bool GameManager::isFinished() const
{
    return false;
}




