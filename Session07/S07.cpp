/*
23-02-2024
Ahmed Abdeilaziz
Robotics Corner
Session 07
INTRO
*/
// g++ -o name.exe file.cpp (Compile)
// ./name.exe (Run)
#include <iostream>
#include <cmath>

using namespace std;   //it's better to use std::  

// #define MtK 1.609 constexpr better than #define in compiling
constexpr double MtK =1.609; // compile time text replacment 
constexpr double pi =3.14;

int main ()

{
//1-Print Hello World (hi.exe)
  /* 
    cout << " Hello World !\n" ;
  */
//2- Get an Input Number then Show it (code2.exe)  
  /*
 cout << " Enter a Number, Please!\n" ;
 int x;
 cin >> x;
 cout << "Your Number is "<< x<< endl;
  */
//3- input miles out put km (code3.exe)
/*  
cout << "Hello, Please enter the distance in miles!\n";
float m=0;
cin>> m;
float k= MtK * m;
cout<< "The Distance in Km ="<< k<< "km"<<endl;
*/
//4- area of a circle, i/p r , o/p area (code4.exe)
/*
 cout << "Hello, Please enter the radius to compute the Area of the circle !\n";
 float r=0;
 cin>> r;
 float a= pi * pow(r,2);
 cout<< "The Area  = "<< a <<endl;
  */
//5- Conditions 
//5.1 if condition
//5.2 Switch case:  
    
    
    
    
    return 0 ;
}