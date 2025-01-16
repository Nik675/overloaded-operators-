#pragma once

#include <iostream>

using namespace std;

class Point {
    private:
        int x;
        int y;

    public:
        Point() { x = 0; y = 0; }

        Point(int x, int y) : x( x ), y ( y ) {

        }

        Point operator+( const Point & );
        Point operator+=( const Point & );

        Point operator-( const Point &);
        Point operator-=( const Point & );

        friend ostream &operator<<( ostream &os, 
                                   const Point &p );
        friend istream &operator>>(istream &is, 
                                   Point &p);
};

Point Point::operator+(const Point &toAdd) {

    return Point(x + toAdd.x,
                 y + toAdd.y);
}

Point Point::operator+=(const Point &toAdd) {
    
    x += toAdd.x;
    y += toAdd.y;

    return *this;
}

Point Point::operator-(const Point &toSubtract) {

    return Point(x - toSubtract.x,
                 y - toSubtract.y);
}

Point Point::operator-=(const Point &toSubtract) {

    x -= toSubtract.x;
    y -= toSubtract.y;

    return *this;
}

ostream &operator<<(ostream &out, const Point &point) {
    out << "[" << point.x << ", " << point.y << "]" << endl;
    return out;
}

istream &operator>>(istream &in, Point &point) {
    cout << "enter x and y coordinates: " << endl;
    in >> point.x >> point.y;
    return in;
}

