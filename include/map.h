#pragma once

#include<vector>

#include "tile.h"

using namespace std;

class Map {
    public:
        int width;
        int height;
        int bombCount;
        vector<vector<Tile>> map;

        void generate(int arg_width, int arg_height, int arg_bombCount);
    
    private:
        vector<pair<int,int>> bombCoordinates;
        void emptyMap();
        void mineMap();
        pair<int, int> generateMineCoordinate();
        void calcBombCount();
};