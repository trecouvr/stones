#pragma once


class Player;
class Action;

class UserInterface
{
    public:
        UserInterface();
        virtual ~UserInterface();
        
        /**
         * Fonction appellée par le class:`GameManager`. Le but est de
         * renvoyer une action valide (piocher, poser un monstre, etc...)
         * qui sera exécutée par le GameManager.
         * Note: le retour se fait via la référence sur class:`Action`.
         * @param   action          la fonction doit modifier cette action
         * @param   player          le joueur courant
         * @param   other           le joueur adverse
         * @param   action_ccount   le nombre d'actions depuis le début du tour
         */
        virtual void getAction(Action& aaction, const Player& player,
                            const Player& other, int action_count) = 0;
        
        /**
         * Fonction appellée par la class:`GameManager` après que
         * l'action est été effectuée.
         * @param   action          l'action qui vient d'être effectuée
         * @param   player          le joueur courant
         * @param   other           le joueur adverse
         * @param   action_ccount   le nombre d'action depuis le début du tour
         * @param   my_turn         est-ce que c'est pendant mon tour ?
         */
        virtual void afterAction(const Action& action, const Player& player,
                            const Player& other, int action_count, bool my_turn) = 0;
};

