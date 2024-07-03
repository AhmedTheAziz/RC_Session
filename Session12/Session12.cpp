#include <iostream>
// #include "Rectangle.h" // 2- Class (test02.exe)

/*
Access Modifiers:   (KeyWords)
Private
Public
Protected
*/
// 1-Class (test01.exe)
/*
class Rectangle
{
private:
float length;
float width;
public:
void set_length(float l)
{
 if (l >=0)
 {
    length = l;
   // std::cout<<"DONE\n";
 }
 else{
    std::cout<< "Please Enter Positive Number!!\n";
 }
}

float get_length()
{
    return length;
}

void set_width(float w)
{
 if (w >=0)
 {
    width = w;
   // std::cout<<"DONE\n";
 }
 else{
    std::cout<< "Please Enter Positive Number!!\n";
 }
}

float get_width()
{
    return width;
}

float get_Area()
{
    float a =length*width;
return a;
}
};
*/
// 3-Constructor & Destructor (test03.exe)
class Rectangle
{
private:
    float length;
    float width;
public:
    Rectangle() : length(0), width(0) // 3-1 Constructor (test03e1.exe)

    {
        std::cout << " Constructor Created!!" << std::endl;
        // length=0;
        // width=0;
    }

    Rectangle(float l, float w) : length(l), width(w)
    {
        std::cout << " Parameterized Constructor Created!!" << std::endl;
    }

    void set_length(float l)
    {
        if (l >= 0)
        {
            length = l;
            // std::cout<<"DONE\n";
        }
        else
        {
            std::cout << "Please Enter Positive Number!!\n";
        }
    }

    float get_length()
    {
        return length;
    }

    void set_width(float w)
    {
        if (w >= 0)
        {
            width = w;
            // std::cout<<"DONE\n";
        }
        else
        {
            std::cout << "Please Enter Positive Number!!\n";
        }
    }

    float get_width()
    {
        return width;
    }

    float get_Area()
    {
        float a = length * width;
        return a;
    }

    void add(float l)
    {
        length += l;
    }

    void add(int w)
    {
        width += w;
    }

    ~Rectangle() // 3-2 Constructor (test03e2.exe)

    {
        std::cout << "Object LifeTime is Ended!!\n";
    }
};

int main()
{
    // 1-Class intro (test01.exe)
    /*
Rectangle rec; //Object -- Instance(copy)
rec.set_length(10);
//float len =rec.get_length();
//std::cout<<len<<std::endl;
std::cout<<"Lenght = "<<rec.get_length()<<std::endl;
rec.set_width(5);
std::cout<< "Width = "<<rec.get_width()<<std::endl;
std::cout<< "Area = "<<rec.get_Area()<<std::endl;
*/
    // 2-Class (test02.exe)
    /*
    Rectangle rec; // Object -- Instance(copy)
    rec.set_length(10);
    rec.set_width(5);
    std::cout << "Lenght = " << rec.get_length() << std::endl;
    std::cout << "Width = " << rec.get_width() << std::endl;
    std::cout << "Area = " << rec.get_Area() << std::endl;
    */
    // 3-Constructor & Destructor (test03.exe)
    // 3-1 Constructor (test03e1.exe)
    /*
    Rectangle rec(10, 5);
    std::cout << "Lenght = " << rec.get_length() << std::endl;
    std::cout << "Width = " << rec.get_width() << std::endl;
    std::cout << "Area = " << rec.get_Area() << std::endl;
    rec.set_length(5);
    rec.set_width(4);
    std::cout << "Lenght = " << rec.get_length() << std::endl;
    std::cout << "Width = " << rec.get_width() << std::endl;
    std::cout << "Area = " << rec.get_Area() << std::endl;
    */
    // 3-2 Destructor (test03e2.exe)
    /*
    std::cin.get(); //waiting for input
    */
}