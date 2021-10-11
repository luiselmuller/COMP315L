#ifndef ID_H
#define ID_H

#include "ID.cpp"

class ID   
{   
    public:   
        ID();   
        ID(int, int, int);   
        void display();   
    private:   
        int left;   
        int middle;   
        int right;   
};

#endif