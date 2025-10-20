#include<iostream>
#include<string>
#include <ctype.h>

#include "game.h"
#include "map.h"

using namespace std;

// start the game when app gets started
void Game::start() {

    menu();

    cout << "Starting game!" << endl;
    
    map.generate(16, 9, 10);

    flags = 10;

    playing = true;
    update();

}

// update the game
void Game::update() {

    while(playing) {

        map.display();
        cout << endl;

        cin >> input;
        
        cout << endl;

        if(input == "exit") {
            playing = false;
        } else if(input == "help") {
            help();
        } else if(input == "menu") {
            start();
        } else {
            processInput(input);
        }

        cout << endl;

    }

}

void Game::reveal(pair<int,int> coordinate) {

    map.map.at(coordinate.second).at(coordinate.first).revealed = true;
    pair<int,int> neighbor;

    for(int i = -1; i < 2; i++) {

            if(coordinate.second + i >= 0 && coordinate.second + i < map.height) {

                for(int j = -1; j < 2; j++) {

                    if(coordinate.first + j >= 0 && coordinate.first + j < map.width) {

                        if(!map.map.at(coordinate.second + i).at(coordinate.first + j).revealed && !map.map.at(coordinate.second + i).at(coordinate.first + j).isBomb) {
                            if(map.map.at(coordinate.second + i).at(coordinate.first + j).mines != 0 && map.map.at(coordinate.second).at(coordinate.first).mines != 0) {
                                return;
                            }
                            neighbor = make_pair(coordinate.first + j, coordinate.second + i);
                            reveal(neighbor);
                        }

                    }

                }

            }

        }

}

void Game::processInput(string input) {

    int x, y;
    string inputX, inputY;

    int dots = 0; // count when dots are passed to know what to do
    bool flag = false;

    if(!isdigit(input.at(0))) {
        
        cout << "Invalid input! try 'help' for help" << endl;
    
    } else {

        for(int i = 0; i < input.length(); i++) {

            if(input.at(i) == '.') {
                dots++;
            } else {
                switch (dots)
                {
                case 0:
                    inputX += input.at(i);
                    break;
                case 1:
                    inputY += input.at(i);
                    break;
                case 2:
                    if(input.at(i) == 'f') {
                        flag = true;
                    }
                    break;
                default:
                    break;
                }
            }
        }

        try {

            x = stoi(inputX);
            y = stoi(inputY);

            if(flag) {

                if(!map.map.at(y).at(x).isFlaged) {
                    map.map.at(y).at(x).isFlaged = true;
                    flags--;
                } else {
                    map.map.at(y).at(x).isFlaged = false;
                    flags++;
                }

            } else {
                if(map.map.at(y).at(x).isBomb) {
                    loose();
                } else {
                    reveal(make_pair(y,x));
                }
            }
        } catch(int err) {
            cout << "We dont accept hexadecimal!!! only integers for coordinates obviously!" << endl;
        }

    }

}

void Game::loose() {

    cout << "BOOOOOM! You lost!" << endl << endl;

    menu();

}

// help screen
void Game::help() {

    cout << "exit       exit the game" << endl;
    cout << "menu       get back to the menu" << endl;
    cout << "[x].[y]    reveal tile at x,y" << endl;
    cout << "[x].[y].f  place a flag at x,y" << endl;

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
