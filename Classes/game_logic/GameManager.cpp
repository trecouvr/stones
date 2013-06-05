#include "GameManager.h"


#include "Action.h"
#include "UserInterface.h"
#include "Deck.h"
#include "BattleManager.h"


GameManager::GameManager(UserInterface* ui1, UserInterface* ui2)
{
    uis_[0] = ui1;
    uis_[1] = ui2;
    Deck* d1 = new Deck(100);
    players_[0] = Player(d1, 2000,J1);
    Deck* d2 = new Deck(100);
    players_[1] = Player(d2, 2000,J2);
    battle_manager_ = new BattleManager;
    
    // Drawing 5 cards to initialize player's hand
    
    int i;
    
    for (i=0;i < 5;i++) players_[0].draw();
}

GameManager::~GameManager ()
{
    delete battle_manager_;
}

void GameManager::run()
{
    while (!isFinished())
    {
        runPlayerTurn(uis_[0], uis_[1], players_[0], players_[1]);
        runPlayerTurn(uis_[1], uis_[0], players_[1], players_[0]);
    }
}

void GameManager::runPlayerTurn(UserInterface* ui, UserInterface* oui, Player& p, Player& o)
{
    bool play = true;
    int action_count=0;
    
    // increment player resources
    p.setResRed(p.getResRed()+2);
    p.setResGreen(p.getResGreen()+2);
    p.setResBlue(p.getResBlue()+2);
    p.setResYellow(p.getResYellow()+2);
    
    // the player do some actions
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
                
                // TODO
                //battle_manager_->run(p,o);
                // for now just remove the opponent monster
                o.rmMonsterCard(action.getData(1));
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
        ui->afterAction(action, p, o, action_count, true);
        oui->afterAction(action, o, p, action_count, false);
        ++action_count;
    }
}

bool GameManager::isFinished() const
{
    return false;
}




