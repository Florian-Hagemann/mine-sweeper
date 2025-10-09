#pragma once

#include<string>

class Game {
    public:
        void start();
        void update();
    
    private:
        bool playing;
        std::string input;
        void help();
        void menu();
        void setupMatch();
};