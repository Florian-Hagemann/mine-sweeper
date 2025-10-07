#pragma once

#include<vector>

using namespace std;

class Map {
    public:
        int width;
        int height;
        int bombCount;
        vector<vector<int>> map;

        Map(int arg_width, int arg_height, int arg_bombCount);
};