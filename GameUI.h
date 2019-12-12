#ifndef GAMEUI_H
#define GAMEUI_H
#include <iostream>
#include <string>
#include <vector>
#include "HangmanPlay.h"
#include "PlayerInput.h"
#include "MainUI.h"

class GameUI
{
    public:
        GameUI();
        virtual ~GameUI();
        void startUI();
        void mainGameUI(string name);
        void endOfGame(string playerName, int playerPoints);
        int getTries();

    protected:

    private:
        HangmanService hms;
};

#endif // GAMEUI_H
