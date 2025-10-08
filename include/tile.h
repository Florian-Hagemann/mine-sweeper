#pragma once

using namespace std;

struct Tile{
    bool revealed;
    int mines; // 0-8 mines can be arround a tile BTW
    bool isBomb; // BOOOM!
};