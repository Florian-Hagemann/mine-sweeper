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


    // Here starts the generation
    emptyMap();
    mineMap();
    calcBombCount();

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
    x = rand() % (width + 1);
    y = rand() % (height + 1);

    if(map[x][y].isBomb) {
        generateMineCoordinate();
    }

    pair<int, int> coordinates = make_pair(x, y);
    return coordinates;

}

// Spreads the mines
void Map::mineMap() {

    srand(time(0));
    pair<int, int> coordinates;

    for(int i = 0; i < bombCount; i++) {

        coordinates = generateMineCoordinate();
        bombCoordinates[i] = coordinates; // * This is for calcBombCount()
        map[coordinates.first][coordinates.second].isBomb = true;

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

    // Add the template to the map
    for(int i = 0; i < height; i++) {    

        for(int j = 0; j < width; j++) {

            map[j][i] = empty;

        }

    }
}