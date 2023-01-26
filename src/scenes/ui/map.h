#ifndef TIKTAKTOE_MAP_H
#define TIKTAKTOE_MAP_H

class Map
{

    char map[3][3];

public:
    static constexpr char C_CROSS = 'X';
    static constexpr char C_CIRCLE = 'O';

    Map();

    bool setAt(int x, int y, char type);

    char getAt(int x, int y);

    char getWinner();

    void reset();

    bool isFull();
};

#endif // TIKTAKTOE_MAP_H
