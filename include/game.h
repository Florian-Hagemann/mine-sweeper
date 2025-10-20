#pragma once

#include<string>
#include "map.h"

class Game {
    public:
        void start();
        void update();
    
    private:
        bool playing;
        std::string input;
        Map map;
        int flags;
        int flagedBombs;
        int bombs;
        void win();
        void loose();
        void reveal(pair<int,int> coordinates);
        void processInput(string input);
        void help();
        void menu();
        void setupMatch();
};