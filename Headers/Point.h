#pragma once

#include <iostream>

using namespace std;

template <typename T>

class Point {
    private:
        T x;
        T y;

    public:
        Point() { x = 0; y = 0; }

        Point(T x, T y) : x( x ), y ( y ) {

        }

        template <typename U>
        friend ostream &operator<<( ostream &os, 
                                   const Point<U> &p );
        template <typename U>
        friend istream &operator>>(istream &is, 
                                   Point<U> &p);

        Point operator+( const Point & );
        Point operator+=( const Point & );

        Point operator-( const Point &);
        Point operator-=( const Point & );
};

template <typename T>
Point<T> Point<T>::operator+(const Point &toAdd) {

    return Point(x + toAdd.x,
                 y + toAdd.y);
}

template <typename T>

Point<T> Point<T>::operator+=(const Point &toAdd) {
    
    x += toAdd.x;
    y += toAdd.y;

    return *this;
}

template <typename T>

Point<T> Point<T>::operator-(const Point &toSubtract) {

    return Point(x - toSubtract.x,
                 y - toSubtract.y);
}

template <typename T>
Point<T> Point<T>::operator-=(const Point &toSubtract) {

    x -= toSubtract.x;
    y -= toSubtract.y;

    return *this;
}

template <typename T>

ostream &operator<<(ostream &out, const Point<T> &point) {
    out << "[" << point.x << ", " << point.y << "]" << endl;
    return out;
}

template <typename T>

istream &operator>>(istream &in, Point<T> &point) {
    cout << "enter x and y coordinates: " << endl;
    in >> point.x >> point.y;
    return in;
}