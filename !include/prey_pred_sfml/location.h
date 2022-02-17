#ifndef LOCATION_H
#define LOCATION_H

struct Location{
    int row;
    int col;     //coordinate row col

    Location();   //CTOR
    Location(int _row, int _col);   //CTOR with coordinate
};

#endif // LOCATION_H
