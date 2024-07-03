/*
Ahmed Abdelaziz
Robotics Corner
Session 17:
Templates, Generic Programming
*/
#include <iostream>
#include <array>
#include <vector>

// 1- Template. (test01.exe)
template <typename T>
T sum(T x, T y)
{
    return x + y;
}
// Swap (test01a.exe)
template <typename T>
void swap(T *a, T *b)
{
    T temp = *a;
    *a = *b;
    *b = temp;
}
// struct (Pair)
template <typename T1, typename T2>
struct Pair
{
    T1 first;
    T2 second;
    void Display()
    {
        std::cout << first << " " << second << std::endl;
    }
};
// Make Pair F(n).
template<typename T1, typename T2>
Pair<T1,T2> make_pair(T1 first, T2 second)
{
    Pair<T1,T2> P;
    P.first=first;
    P.second=second;
    return P;
}
// make pair in Pair struct
/*
template <typename T1, typename T2>
struct Pair
{
    T1 first;
    T2 second;
    void Display()
    {
        std::cout << first << " " << second << std::endl;
    }
    template <typename T3, typename T4>
    Pair<T3, T4> make_pair(T3 first, T4 second)
    {
        Pair<T3, T4> P;
        P.first = first;
        P.second = second;
        return P;
    }
};
*/
//3 typenames
// struct (Pair)
template <typename T1, typename T2, typename T3 >
struct Pairtrio
{
    T1 first;
    T2 second;
    T3 third;
    Pairtrio(T1 fr,T2 sc ,T3 tr ) : first (fr), second (sc), third (tr)
    {

    }
    void Display()
    {
        std::cout << first << " " << second << " "<< third<< std::endl;
    }
};
// Make Pair F(n).
template<typename T1, typename T2, typename T3>
Pairtrio<T1,T2,T3> make_Trio(T1 first, T2 second, T3 third)
{
   // Pairtrio<T1,T2,T3> P;
    Pairtrio<T1,T2,T3>P(first,second,third); // Right Syntax.
    P.first=first;
    P.second=second;
    P.third=third;
    return P;
}

int main()
{
    int x = 5.6, y = 6.5;
    // 1-Template (Test01.exe)
    /*
    std::cout<< sum(x,y)<<std::endl;
    */
    // 2-swap (test02.exe)
    /*
    swap(&x,&y);
    std::cout<< x<< "  "<<y<<std::endl;
    */
    // 3- Pair (test03.exe)
    /*
    Pair <int,Pair<std::string,int>> P={1, {"Omar",123}};
    //P.Display();
    std::cout<< P.first<< " "<< P.second.first<< " "<<P.second.second<<std::endl;
    */
    // 4- Vectors (test04.exe)
    /*
    Pair<int, std::string> P1;
    std::vector<Pair<int, std::string>> P = {{1, "Ahmed"}, {2, "Karim"}, {3, "Mohssen"}};
    P.push_back(make_pair<int, std::string>(4, "Omar"));
    P.push_back({5, "Mohamed"});
    for (int i = 0; i < P.size(); i++)
    {
        std::cout << P[i].first << " " << P[i].second << std::endl;
    }
    return 0;
    */
    // make pair in Pair strut (test05.exe)
    /*   Pair<int, std::string> P1;
   std::vector<Pair<int, std::string>> P={{1, "Ahmed"},{2,"Karim"},{3,"Mohssen"}};
   P.push_back(P1.make_pair<int, std::string>(4, "Omar"));
   P.push_back({5, "Mohamed"});
   for (int i = 0; i < P.size(); i++)
   {
       std::cout<< P[i].first<< " "<< P[i].second<<std::endl;
   }
   return 0;
   */
  //3 typenames  (test06.exe)
    std::vector<Pairtrio<int, std::string,char>> P = {{1, "Ahmed",'A'}, {2, "Karim",'K'}, {3, "Mohssen",'M'}};
    P.push_back(make_Trio<int, std::string>(4, "Omar",'O'));
    P.push_back({5, "Mohamed",'M'});
    for (int i = 0; i < P.size(); i++)
    {
        std::cout << P[i].first << " " << P[i].second << " "<< P[i].third<<std::endl;
    }
    return 0;

}