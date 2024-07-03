#include <iostream>
#include "Rectangle.h"

Rectangle::Rectangle() : length(0), width(0)
{
    std::cout << "Constructor Created!!\n";
}

void Rectangle::set_length(float l)
{
    if (l >= 0)
    {
        length = l;
    }
    else
    {
        std::cout << "Please Enter Positive Number!!\n";
    }
}

float Rectangle::get_length()
{
    return length;
}

void Rectangle::set_width(float w)
{
    if (w >= 0)
    {
        width = w;
    }
    else
    {
        std::cout << "Please Enter Positive Number!!\n";
    }
}

float Rectangle::get_width()
{
    return width;
}

float Rectangle::get_Area()
{
    float a = length * width;
    return a;
}
