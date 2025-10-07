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

    int x,y;

    for(int i = 0; i < bombCount; i++) {

        x = rand() % (width + 1);
        y = rand() % (height + 1);

        if(map[x][y].isBomb == true)

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

            map[i][j] = empty;

        }

    }
}