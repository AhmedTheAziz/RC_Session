#include <iostream>
#include <vector>
#include <functional>

// 1- default arg (test01)
int sum(int x, int y = 5, int z = 10)
{
    return x + y + z;
}
// 2-inline func() (test02)
inline void print(std::string s)
{
    std::cout << s << std::endl; // grab the same function from main
}
// 3-static keyword (test03)
void fun()
{
    static int x = 0;
    x++;
    std::cout << "Value of x is : " << x << std::endl;
}
// 4- Func() PTR (test04)
void hello(int x)
{
    std::cout << "Hello World! " << x << std::endl;
}
// 5-example on pointer func() (test05)
void printvalue(int value)
{
    std::cout << " Value is : " << value << std::endl;
}
void ForEach(const std::vector<int> &val, std::function<void(int)> funnc)
{
    for (int value : val)
        funnc(value);
}
// 6- Lambda Expr. (test06)
// 7-struct (test07)
struct Car
{
    std::string name;
    std::string color;
    int model;
    int maxSpeed;

    void printmodel()
    {
        std::cout << "Car Model is " << model << std::endl;
    }
};
void inputcar(Car &c)
{
    std::cin >> c.name >> c.color >> c.model >> c.maxSpeed;
    // return c;
}
void printcar(Car x)
{
    std::cout << x.name << " " << x.color << " " << x.model << " " << x.maxSpeed << std::endl;
}

int main()
{
    // 1- default arg (test01)
    /*
    std::cout<<sum(10)<<std::endl;
    */
    // 2-inline func() (test02)
    /*
    std::string s="Buddha";
    print(s);
    print(s);
    print(s);
    print(s);
    print(s);
    print(s);
    */
    // 3-static keyword (test03)
    /*
    fun();
    fun();
    fun();
    fun();
    */
    // 4- Func() PTR. (test04)
    /*
   auto function = &hello; // Adressing
       function(5);
   void (*funprt)(int) = hello; // func() pointer syntax.
       // funprt = hello; // when void (*funprt)(int);
       funprt(10);
   */
    // 5- example on pointer func() (test05)
    /*
    std::vector<int> values = {1, 2, 5, 4, 9, 3};
    ForEach(values, printvalue);
    */
    // 6- Lambda Expr. (test06)
    //[] (int value){}
    /*
    std::vector<int> values = {1, 2, 5, 4, 9, 3};
    int i = 10;
    auto lambda = [=](int value) mutable
    {
        i =3;
        std::cout << " Value is : " << value * i << std::endl;
    }; // &i >refrence cap , i >copy , & every varible is refrenced , = every var is copied
    ForEach(values, lambda);
    std::cout<< "i = " << i<< std::endl;
    */
    // 7- Struct. (test07)
    /*
    Car x = {" Mini Copper ", " Red ", 2020, 180};
    Car y;
    Car *h;
    y.name =" BMW ";
    y.color=" Black ";
    y.model=2019;
    y.maxSpeed=270;
    y.printmodel();
    std::cout<< x.name << x.color << " "<<x.model << " "<< x.maxSpeed<< std::endl;
    std::cout<< y.name << y.color << " "<<y.model << " "<< y.maxSpeed<< std::endl;
    inputcar(x);
    h =&x;
printcar(x);
std::cout<< h ->name << std::endl;
*/
}