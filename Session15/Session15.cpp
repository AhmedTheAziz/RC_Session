/*
Ahmed Abdelaziz
Robotics Corner
Session 15:
 Virtual Functions, Final, This ptr
*/
#include <iostream>

class Shape
{
private:
    float len = 5;
    float wid = 9;

public:
    virtual void area() = 0; // =0; Pure Virtual Func()
    /*
    {
        std::cout << "The Area of Shape is " << len * wid << std::endl;
    }
    */
    // virtual void display() final //final
};
class Rectangle : public Shape
{
public:
    float len = 5;
    float wid = 10;

private:
    void area()
    {
        std::cout << "The Area of Rectangle is " << len * wid << std::endl;
    }
};
class Box : public Shape
{
public:
    float len = 5;
    float wid = 8;

private:
    void area()
    {
        std::cout << "The Area of Box is " << len * wid << std::endl;
    }
};
class Circle : public Shape
{
public:
    float len = 5;
    float wid = 9;

private:
    void area()
    {
        std::cout << "The Area of Circle is " << 2 * 3.14 * len << std::endl;
    }
};
class Square : public Shape
{
public:
    float len = 5;
    float wid = 5;

private:
    void area()
    {
        std::cout << "The Area of Square is " << len * wid << std::endl;
    }
};

class A
{
    private:
    std::string name;
    public:
    void show(std::string name)
    {
        this->name;
        std::cout<<this<<std::endl;
    }
};
class B
{
    public:
    void show()
    {
        std::cout<<this<<std::endl;
    }
};

int main()
{
    // 1- Virtual Func() (test01.exe)
    /*
    Shape *ptr_Shape;
    Shape sh;
    Rectangle rec;
    Box b;
    Circle c;
    Square sq;
    ptr_Shape = &sh;
    ptr_Shape->area();
    ptr_Shape = &rec;
    ptr_Shape->area();
    ptr_Shape = &b;
    ptr_Shape->area();
    ptr_Shape = &c;
    ptr_Shape->area();
    ptr_Shape = &sq;
    ptr_Shape->area();
    */
    // 2- pure Virtual Func() (test02.exe)
    /*
    Shape *ptr_Shape;
    Rectangle rec;
    Box b;
    Circle c;
    Square sq;
    ptr_Shape = &rec;
    ptr_Shape->area();
    ptr_Shape = &b;
    ptr_Shape->area();
    ptr_Shape = &c;
    ptr_Shape->area();
    ptr_Shape = &sq;
    ptr_Shape->area();
    */
   //3- This PTR (test03.exe)
   A a;
   B b;
   a.show("AHMED");
   std::cout<<&a<<std::endl;
    b.show();
   std::cout<<&b<<std::endl;
}