/*
 */
#include <iostream>
#include <memory> //Dynamic Memory Managment Library
#include <vector>
// Rvalue & Lvalue (test01.exe)
class Myclass
{
public:
    Myclass()
    {
        std::cout << "Constructor Invoked \n";
    }
    ~Myclass()
    {
        std::cout << "destructor Invoked \n";
    }
};
int fun()
{
    int i = 5;
    return i;
}
// Rvalue (test02.exe)
template <class T>
void printvector(std::vector<T> v)
{
    for (auto it = v.begin(); it != v.end(); ++it)
    {
        std::cout << *it << " ";
    }
}
// move constructor ptrs (test03.exe)
class moveclass
{
private:
    int size;
    int *data;

public:
    // Default Constructor
    moveclass() : size(0), data(nullptr)
    {
        std::cout << "Default Constructor Called" << std::endl;
    }
    // Parameterized constructor
    moveclass(int size) : size(size), data(new int[size])
    {
        std::cout << "Parameterized Constructor Called" << std::endl;
    }
    // copy constructor.
    moveclass(moveclass &obj) : size(obj.size), data(new int[*obj.data]) // data(new  int[obj.data])//Lvalue refrence
    {
        std::cout << "Copy Constructor" << std::endl;
    }
    // move Constructor
    moveclass(moveclass &&other) : size(other.size), data(new int[*other.data]) // Rvalue refrence..
    {
        std::cout << "Move Constructor Called\n";
        other.size = 0;
        other.data = nullptr;
    }
    // move assignmet operator
    moveclass &operator=(moveclass &&other)
    {
        if (this != &other)
        {
            delete[] data; // release current resources
            std::cout << "Move assignment operator called" << std::endl;
            size = other.size;
            data = new int[*other.data];
            // reset the source object.
            other.size = 0;
            other.data = nullptr;
        }
        return *this;
    }
    // Destructor
    ~moveclass()
    {
        delete[] data;
        std::cout << "Destructor Called!!!!" << std::endl;
    }
};
// Shared_ptr (test04.exe)
class Rectangle
{
private:
    int length;
    int width;

public:
    Rectangle(int l, int w)
    {
        length = l;
        width = w;
    }
    int area()
    {
        int a = length * width;
        return a;
    }
};
//weak ptr (test05.exe)

int main()
{
    // Rvalue & Lvalue (test01.exe)
    /*
    std::unique_ptr<int> ptr(new int(5));
   std::cout<<*ptr<<std::endl;
   std::unique_ptr<int> ptr2(std::move(ptr));
   //std::cout<<*ptr<<std::endl; system crashing
   std::cout<<*ptr2<<std::endl;
   int i=5;
   //int &x=i; //reference. (lvalue ref.)
   //fun();
   int &&x=6; //Rvalue ref / move().
   */
    // Rvalue (test02.exe)
    /*
    std::vector<int> v1;
    std::vector<int> v2;
for(auto i=0;i<5;i++)
{
    v1.push_back(i);
}
for(auto i=10;i<15;i++)
{
    v2.push_back(i);
}
printvector(v1);
std::cout<<std::endl;
printvector(v2);
std::cout<<std::endl;
v2= std::move(v1);
printvector(v1);
std::cout<<std::endl;
printvector(v2);
std::cout<<std::endl;
*/
    // move constructor ptrs (test03.exe)
    /*
    moveclass source(5);
    moveclass des(source); // copy
    // std::cout << "des= " << des.data<<std::endl << " Source= " &source.data << std::endl;
    //  use std::move to transfer ownership from source to destination.
    // moveclass destination(std::move(source));
    moveclass destination;
    destination = std::move(source);
    */
    // Shared_ptr (test04.exe)
    // smart ptr
    /*by using Shared ptr more than one pointer can point to this one object at a time
    it'll maintain a refrence counter using the use_count() method.*/
    /*
    std::shared_ptr<Rectangle> p1(new Rectangle(10, 5));
    std::cout << "p1 area = " << p1->area() << std::endl;
    std::shared_ptr<Rectangle> p2(p1); // p2=p1
    {
        std::shared_ptr<Rectangle> p3(p1);
        std::cin.get();
        std::cout << "p3 area = " << p3->area() << std::endl;
        std::cout << "p1 .use count = " << p1.use_count() << std::endl;
    }
    std::cin.get();
    // std::cout<<"cin.get() = "<<std::cin.get()<<std::endl;
    std::cout << "p2 area = " << p2->area() << std::endl;
    std::cout << "p1 area = " << p1->area() << std::endl;
    std::cout << "p1 use count = " << p1.use_count() << std::endl;
    */
    //weak ptr (test05.exe)
    std::shared_ptr<Rectangle> P1(new Rectangle(10,5));
    std::weak_ptr<Rectangle>P2(P1);
    std::cout<<P1->area()<<std::endl;
    std::cout<<P1.use_count()<<std::endl;

    return 0;
}