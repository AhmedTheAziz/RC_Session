/*
Name: Ahmed Abdelaziz
Session10
Robotics Corner
Vectors ( Iterators)/ Vectors / Func() OverLoading /
*/

#include <iostream>
#include <array>
#include <vector>

void invec(std::vector<int> &vect);// Vectors (test02.exe)
void prinvec(const std::vector<int> &vect);// Vectors (test02.exe)
int add(int a, int b); // Functions OverLoading (test04.exe)
double add (double a, double b); // Functions OverLoading (test04)
int add (int a, int b, int c); // Functions OverLoading (test04)

int main()
{
//1.0- Iterators (test01.exe)
/*
std::array<int,5> list;
//std::array<int,5>::iterator iterator; // you can ignore this line by adding (auto) type in for loops
std::cout<< "enter list of elements \n";
for(auto iterator = list.begin(); iterator!=list.end(); ++iterator ) //iterator is pointing to adress.
{
    std::cin>> *iterator;
}
for( auto iterator = list.begin(); iterator!=list.end(); ++iterator ) //iterator is pointing to adress.
{
    std::cout<< *iterator;
}
*/
//1.1- iterator (test01e1.exe)
/*
std::array<int,5> list;
std::array<int,5>::iterator iterator; // you can ignore this line by adding (auto) type in for loops
std::cout<< "enter list of elements \n";
for(iterator = list.begin(); iterator!=list.end(); ++iterator ) //iterator is pointing to adress.
{
    std::cin>> *iterator;
}
for(iterator = list.begin(); iterator!=list.end(); ++iterator ) //iterator is pointing to adress.
{
    std::cout<< *iterator;
}
*/
// 2- vectors (test02exe)
/*
std::vector<int> vec(5,0);
std::cout <<  " input values"<< std::endl;
invec(vec);
std::cout<< " printing values "<< std::endl;
prinvec(vec);
std::cout<< " vector size "<< vec.size() << std::endl;
*/
//3- iterators + Vectors (test03.exe)
/*
std::vector<int> vector(5,0);
for(int i =0; i < vector.size(); i++)
{
    vector[i]=7;
}
prinvec(vector);
std::cout<<std::endl;
for(auto ite = vector.begin(); ite != vector.end();++ite)
{
    *ite =8;
}
prinvec(vector);
std::cout<<std::endl;
for (auto &element : vector)
{
    element=9;
}
prinvec(vector);
std::cout<<std::endl;
*/
//4- Functions OverLoading (test04.exe)
/*
int x=3;
int y=4;
int o=7;
double u=5.5;
double z=4.5;
std::cout<< " 2 intgers "<< add(x,y)<<std::endl;
std::cout<< " 3 intgers "<< add(x,y,o)<<std::endl;
std::cout<< " 2 doubles "<< add(u,z)<<std::endl;
*/
return 0;
}

void invec(std::vector<int> &vect)// Vectors (test02.exe)
{
    for(auto &element : vect)
    {
        std::cin>>element;
    }
}
void prinvec(const std::vector<int> &vect)// Vectors (test02.exe)
{
    for(auto &element : vect)
    {
        std::cout<<element<< " ";
    }
}

int add(int a, int b)// Functions OverLoading (test04)
{
    return a+b;
}
double add(double a, double b)// Functions OverLoading (test04)
{
    return a+b;
}
int add(int a, int b, int c)// Functions OverLoading (test04)
{
    return a+b+c;
}