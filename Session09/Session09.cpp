/*
Name: Ahmed Abdelaziz
Robotics Corner 
Session09
Pointers & Array
*/

#include <iostream>
#include <array> // (test06.exe)
#include <algorithm> // (test07e1.exe)

void swap(int *a, int *b); // (test01.exe)

void swap2(int &x, int &y); // (test05.exe)

void inputarray(std::array<int,3> &input); // (test06.exe)

void printarray(const std::array<int,3> &input); // (test07.exe)

int main ()
{
//1- Pointers. (ptrs.exe)
/*
int x=3;
std::cout << "x = "<< x<<std::endl;
int *ptr =&x; 
std::cout << "ptr = "<< ptr<< std::endl; // adress of x
std::cout << "*ptr = "<< *ptr<< std::endl; // value inside the address of x
std::cout << "&x = "<<&x<<std::endl; // adress of x
*/
// 1.1- Swaping.(test01.exe)
/*
int x=3 ,y=5;
std::cout<< " x = "<< x<< " y = "<<y<<std::endl;
swap(&x,&y);
std::cout<< " x = "<< x<< " y = "<<y<<std::endl;
*/
//1.2 swap alias (references ) (test02.exe)
/*
int a=3          ;
int &r = a;
std::cout<< "adresss of r "<< &r<<" adress of a "<< &a <<std::endl;
r=5;
std::cout << "a = "<< a<< std::endl;
// int *ptr = nullptr; it's okay to be a null pointer.
// int &r; must be a copy of something.    
*/ 
//2- Grades (test03.exe)
/*
while (1) // not zero, zero stops the loop. or for(;;) {}
{
int grade;
std::cout<< " Please Enter your Grade!"<<std::endl;
std::cin>>grade;

if (grade < 50)
{
 std::cout << " Failed !! \n" ;
}
else if (grade >= 50 && grade < 65)
{
std::cout << "Passed ! \n";
}
else if ( grade >=65 && grade < 75)
{
std::cout << " GOOD !\n";
}
else if (grade >= 75 && grade < 85)
{
std::cout << " Very Good !\n";
}
else if (grade >= 85 && grade <=100)
{
 std::cout << " Excellent !!\n";
}
 else
 {
    std::cout << "Error!!! \n";
 }
}
*/
//3- Prefix (increments) (test04.exe) (test04e2.exe) (test04e3.exe)
/*
int x=1;
//x=x+1;
//x+=1;
//int y = x++; //postfix.
int y = ++x; //prefix.
std::cout << " y = "<< y << " x = "<< x << std::endl;
int z=x++;
std::cout<< " z = "<< z<< std::endl;

//4  ?:

//return_statement condition ? true_condition : false_condition
int w =          x==1        ?       y        :       x          ;
*/
//5- swap 3 (test05.exe)
/*
int a =3, b=5;
std::cout<< " a = " << a<< " b = " << b << std::endl;
swap2(a,b);
std::cout<< " a = " << a<< " b = " << b << std::endl;
*/
//6- Arrays  (test06.exe) (test07.exe) (test07e1.exe) algorithms
/*
constexpr int x=3;
std::array<int,x> arr;
std::array<int,x> array;
std::cout<<"  enter Array 1 "<< std::endl;
inputarray(arr);
std::cout<<" enter Array 2 "<< std::endl;
inputarray(array);
std::cout<<" Array 1 before swap "<< std::endl;
printarray(arr);
std::cout<<" Array 2 before swap "<< std::endl;
printarray(array);
arr.swap(array);
std::cout<<" Array 1 after swap"<< std::endl;
printarray(arr);
std::cout<<" Array 2 after swap "<< std::endl;
printarray(array);
*/
return 0;
}


void swap(int *a, int *b)
{
    int temp=*a;
    *a=*b;
    *b = temp;  
}

void swap2(int &x, int &y)
{
    int temp = x;
    x=y;
    y=temp;
}

void inputarray(std::array<int,3> &input)
{
    std::cout << " Input "<< std::endl;
    for (int &element : input )
    {
        std::cin>>element;
    }

}

void printarray(const std::array<int,3> &input) // if const is used dont use &element cause its adress is constant
{
    std::cout << " Input "<< std::endl;
    for (int element : input )
    {
        std::cout<< "Value = "<< element << std::endl;;
    }
}