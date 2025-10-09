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
        void help();
        void menu();
        void setupMatch();
};