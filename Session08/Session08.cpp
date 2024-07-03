#include <iostream>
//1
#include "cal_head.h"

//3 Arrays
#include <array> 
//using namespace std;

int main()
	{
//1- headers & imp func()
    /*
					std::cout << "Try a Mathimatical Eqn. between Two Numbers using (+,-,*,/,%)\n";
					std::cout << "..........................................................................\n";
					float x = 0, y = 0;
                        char op;
					std::cin >> x >> op >> y;
                    switch (op)
                    {
					case '+':
                    {
						std::cout << s(x,y) << std::endl;
						break;
					
                    }
                    case'-':
					{
                    	std::cout << sub(x,y) << std::endl;
						break;
					}
                    case'*':
					{
                    	std::cout << mp(x,y) << std::endl;
						break;
					}
                    case'/':
					{
                    	std::cout << divv(x,y) << std::endl;
						break;
					}
                    default:
                    {
						break;
					}
                }
*/

//2-Srings.
/*
std::string name;
const std::string addstring = " Corner "; //() or = or {} can be used coz its constructor.
std::cout << "Please Enter First name!!";
std::cin >>name;
name += addstring; // name = name = addstring 
std::cout<< "Name : " <<name << std::endl;
*/

//3- Arrays

std::array <int,5> arr ={1,2,3,4,5};
//method 1 (for loop)
/*
for(int i=0;i<=arr.size()-1;i++)
//for (int i =1:i<=size();i++)
{
std::cout << arr[i] << " ";
}
std::cout << std::endl;
*/
//method 2 (auto element)
/*
for (auto element : arr)
{
    std::cout << element <<" ";
}
std::cout << std::endl;
*/

    return 0;

				}


