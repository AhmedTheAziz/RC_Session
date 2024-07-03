/*
Ahmed Abdelaziz
Robotics Corner
Session 14
Subjects: OverRide, types of Inheritence, Operator Overloading
*/
#include <iostream>
#include <string>
#include<ostream>

class A  // 1- OverRide (test01.exe)
{
    public:
    virtual void display() // virtual!!
    {
        std::cout<<"HI"<<std::endl;
    }

};

class B : public A  // 1- OverRide (test01.exe)
{
    public:
    void display() override // override !!
{
    std::cout<<"Bye Bye"<<std::endl;
}

};

class Complex 
{
private:
float real;
float imaginary;
public:
Complex(float m_real =0, float m_imaginary =0): real(m_real), imaginary(m_imaginary)
{}
Complex operator+( Complex &rhs)
{
    Complex temp;
    temp.real = real + rhs.real;
    temp.imaginary= imaginary+ rhs.imaginary;
    return temp;
}
friend std::ostream& operator<<(std::ostream &output,Complex &inp);


};   

std::ostream& operator<<(std::ostream &output,Complex &inp)
{
    output << inp.real<< " "<<inp.imaginary;
    return output;
}


int main ()
{
    // 1- OverRide (test01.exe)
    /*A a;
    B b;
    a.display();
    b.display();
    */
   //2- OP OverLoading
    
}
