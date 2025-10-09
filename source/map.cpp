#include "map.h"
#include "tile.h"

#include<iostream>
#include<vector>
#include<ctime>

void Map::generate(int arg_width, int arg_height, int arg_bombCount) {
    
    // Set the variables given when asked to generated.
    width = arg_width;
    height = arg_height;
    bombCount = arg_bombCount;
    
    cout << endl;
    cout << "Starting map generation" << endl;

    // Here starts the generation
    emptyMap();
    cout << "Emptied and resized map" << endl;
    mineMap();
    cout << "Placed the mines" << endl;
    calcBombCount();
    cout << "Calculated the tile numbers" << endl;
    cout << endl;

}

void Map::display() {

    for(int i = 0; i < height; i++) {    

        for(int j = 0; j < width; j++) {

            if(map.at(i).at(j).isBomb) {
                cout << "B";
            } else if(map.at(i).at(j).isFlaged) {
                cout << "F";
            } else {
                cout << map.at(i).at(j).mines;
            }

        }
        
        cout << endl;

    }

}

// Calculate the number of the tile (you know... how to make the game playable)
void Map::calcBombCount() {

    for(pair<int,int> bomb : bombCoordinates) {

        for(int i = -1; i < 2; i++) {

            if(bomb.first + i >= 0 && bomb.first + i < height) {

                for(int j = -1; j < 2; j++) {

                    if(bomb.second + j >= 0 && bomb.second + j < width) {

                        map[bomb.first + i][bomb.second + j].mines++;

                    }

                }

            }

        }

    }

}

// Generate mine coordinate where there isn't already a mine
pair<int, int> Map::generateMineCoordinate() {

    int x,y;
    x = rand() % (width - 1);
    y = rand() % (height - 1);

    if(map.at(y).at(x).isBomb) {
        generateMineCoordinate();
    }

    pair<int, int> coordinates = make_pair(y, x);
    return coordinates;

}

// Spreads the mines
void Map::mineMap() {

    srand(time(0));
    pair<int, int> coordinates;

    for(int i = 0; i < bombCount; i++) {

        coordinates = generateMineCoordinate();
        bombCoordinates.push_back(coordinates); // * This is for calcBombCount()

        map.at(coordinates.first).at(coordinates.second).isBomb = true;

    }

}

// Empties map and adjust the size
void Map::emptyMap() {

    map.clear();

    // Empty tile template
    Tile empty;
    empty.isBomb = false;
    empty.mines = 0;
    empty.revealed = false;
    empty.isFlaged = false;

    vector<Tile> line;

    // Add the template to the map
    for(int i = 0; i < height; i++) {    

        for(int j = 0; j < width; j++) {

            line.push_back(empty);

        }

        map.push_back(line);
        line.clear();

    }

}