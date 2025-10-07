#include "map.h"

#include<iostream>
#include<vector>

void Map::generate(int arg_width, int arg_height, int arg_bombCount) {
    width = arg_width;
    height = arg_height;
    bombCount = arg_bombCount;
}