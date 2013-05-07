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
         * @param   a   la fonction doit modifier cette action
         * @param   p   le joueur courant
         * @param   o   la joueur adverse
         */
        virtual void getAction(Action& a, const Player& p, const Player& o) = 0;
        
        /**
         * Fonction appellée par la class:`GameManager` après que
         * l'action est été effectuée.
         * @param   a   l'action qui vient d'être effectuée
         * @param   p   le joueur courant
         * @param   o   le joueur adverse
         */
        virtual void afterAction(const Action& a, const Player& p, const Player& o) = 0;
};

