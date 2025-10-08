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

    cout << "Starting map generation" << endl;

    // Here starts the generation
    emptyMap();
    cout << "Emptied and resized map" << endl;
    mineMap();
    cout << "Placed the mines" << endl;
    calcBombCount();
    cout << "Calculated the tile numbers" << endl;

}

void Map::display() {

    for(int i = 0; i < height; i++) {    

        for(int j = 0; j < width; j++) {

            if(map[j][i].isBomb) {
                cout << " B ";
            } else {
                cout << " " << map[j][i].mines << "";
            }

        }
        
        cout << endl << endl;

    }

}

// Calculate the number of the tile (you know... how to make the game playable)
void Map::calcBombCount() {

    for(pair<int,int> bomb : bombCoordinates) {

        for(int i = -1; i < 2; i++) {

            if(bomb.second + i >= 0 && bomb.second + i < width) {

                for(int j = -1; j < 2; j++) {

                    if(bomb.first + j >= 0 && bomb.first + j < height) {

                        map[bomb.first + j][bomb.second + i].mines++;

                    }

                }

            }

        }

    }

}

// Generate mine coordinate where there isn't already a mine
pair<int, int> Map::generateMineCoordinate() {

    int x,y;
    x = rand() % width;
    y = rand() % height;
    cout << "x : " << x << " |  y : " << y << endl;

    if(map[x][y].isBomb) {
        generateMineCoordinate();
    }

    cout << "x : " << x << " |  y : " << y << endl;
    pair<int, int> coordinates = make_pair(x, y);
    return coordinates;

}

// Spreads the mines
void Map::mineMap() {

    srand(time(0));
    pair<int, int> coordinates;

    for(int i = 0; i < bombCount; i++) {

        coordinates = generateMineCoordinate();
        bombCoordinates.push_back(coordinates); // * This is for calcBombCount()
        try {
            map.at(coordinates.second).at(coordinates.first).isBomb = true;
        } catch(int err) {
            cout << err << endl;
        }

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