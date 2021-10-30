#ifndef PAIR_H
#define PAIR_H

#include <iostream>

using namespace std;

template<class T>
class Pair
{
public:
    Pair();
    Pair(T first_value, T second_value);
    void set_element(int position, T value);
    T get_element(int position) const;
    void display_pairs();

private:
    T first;
    T second;
};

//empty constructor initializes the pair as 0 in the case of int type and empty string in the case of string type
template<class T>
Pair<T>::Pair() : first(), second()
{
    //empty body
}

//constructor initializing the first and second values to the parameters the user chooses
template<class T>
Pair<T>::Pair(T first_value, T second_value) : first(first_value), second(second_value)
{
    //empty body
}

template<class T>
void Pair<T>::set_element(int position, T value)
{
    if (position == 1)
    {
        first = value;
    }   
    else if (position == 2)
    {
        second = value;
    }
    else
    {
        cout << "Error: Illegal pair position. \n";
        exit(1);
    }
}

template<class T>
T Pair<T>::get_element(int position) const 
{
    if (position == 1)
    {
        return first;
    }
    else if (position == 2)
    {
        return second;
    }
    else
    {
        cout << "Error: Illegal pair position. \n";
        exit(1);
    }
}

template<class T>
void Pair<T>::display_pairs()
{
    cout << first << "  -  " << second << "\n";
}

#endif 