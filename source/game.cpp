#include<iostream>
#include<string>

#include "game.h"

using namespace std;

// start the game when app gets started
void Game::start() {

    menu();

}

// update the game
void Game::update() {

}

// menu
void Game::menu() {

    // print menu
    cout << endl << "MINE SWEEPER -- by Florian Hagemann" << endl << endl;
    cout << "1 - Start Game" << endl;
    cout << "2 - Exit Game" << endl;
    cout << endl;

    // get input
    string input;
    cin >> input;

    // process input
    if(input == "2") {
        exit(0);
    } else if(input != "1") {
        cout << "Vro can't even type 1 or 2... It's jover... Time to ropemaxx!" << endl;
        cout << "Or just try again but please type either 1 OR 2 and nothing else!!!!" << endl;
        menu();
    }

}