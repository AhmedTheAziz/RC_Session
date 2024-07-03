/*
Ahmed Abdelaziz
Robotics Corner
Seassion 21:
STL (Standard Template Library):
(Vector's f(n)'s, Iterator, deQ, List, Forward List )
*/
#include <iostream>
#include <vector>
#include <deque>        // (test12.exe)
#include <list>         //(test13.exe)
#include <forward_list> //(test15.exe)
#include <algorithm>    // find func.

int main()
{
    // 1- Vectors v.push_back() (test01.exe)
    /*
    std::vector<int> v(20);
    std::cout << "V[0] =" << v[0] << std::endl;
    v[0] = 5;
    std::cout << "V[0] =" << v[0] << std::endl;
    v.push_back(10);
    for (int i = 0; i < v.size(); i++)
    {
        std::cout << "V["<<i<<"] =" << v[i] << std::endl;
    }
    std::cout << "Size of Vector: " << v.size() << std::endl
              << "Capacity of Vector: " << v.capacity() << std::endl
              << "Maximum Size of Vector: " << v.max_size() << std::endl;

   */
    // 2- v.front() & v.back() (test02.exe)
    /*
    std::vector<int> v(20);
    v[0] = 5;
    v.push_back(10);
    std::cout <<"Front: "<< v.front() << std::endl;
    std::cout << "Back: "<<v.back() << std::endl;
    */
    // 3- *(v.begin()) & *(v.end()) (test03.exe)
    /*
    std::vector<int> v(20);
     v[0] = 5;
     v.push_back(10);
     std::cout <<"Begin: "<< *(v.begin()) << std::endl;
     std::cout << "End: "<<*(v.end()) << std::endl;
     */
    // 4- v.size(), v.capacity & v.max_size() (test04.exe)
    /*
    std::vector<int> v(20);
    v[0] = 5;
    v.push_back(10);
    std::cout <<"Size: "<< v.size() << std::endl;
    std::cout << "Capacity: "<<v.capacity() << std::endl;
    std::cout << "Max. Size: "<<v.max_size() << std::endl;
    */
    // 5- v.shrink_to_fit()  & v.resize() (test05.exe)
    /*
    std::vector<int> v(20);
    v[0] = 5;
    v.push_back(10);
    std::cout << "Size: " << v.size() << std::endl;
    std::cout << "Capacity: " << v.capacity() << std::endl;
    v.resize(22);
    v.shrink_to_fit();
    std::cout << "Shrink to Fit Capacity: " << v.capacity() << std::endl;
    v.resize(22);
    std::cout << "re-Size: " << v.size() << std::endl;
    std::cout << "re-Size Capacity: " << v.capacity() << std::endl;
    */
    // 6- Iterators.. (test06.exe)
    /*
    std::vector<int> v = {1, 6, 5, 5, 6, 2};
    // std::cout << v.front() << std::endl;
    // std::vector<int>::iterator it = v.begin();

    std::cout<< *it <<std::endl;
   it++;
    std::cout<<*it<<std::endl;
    */
    /*
     auto it = v.begin();
     auto ite = v.end();
     v.insert(it + 3, 55);
     v.insert(v.end(), 50);
     // std::cout<< *it2<<std::endl;
     v.emplace(v.begin() + 3, 10);
     v.emplace_back(80);
     for (it = v.begin(); it != v.end(); it++)
     {
         std::cout << "Element: " << *it << std::endl;
     }
     std::cout << v.at(4) << std::endl; //O(1)
     std::cout << v[4] << std::endl; //O(1)
     */
    // 7- Iterators rbegin and rend (test07.exe)
    /*std::vector<int> v = {1, 6, 5, 5, 6, 2};
    auto it = v.rbegin();
    for (it = v.rbegin(); it != v.rend(); it++)
    {
        std::cout << "Element: " << *it << std::endl;
    }
    // auto itcb=v.cbegin(); // constant cannot be changed
    // auto itcrb=v.crbegin(); // constant right begin
    // auto itcre=v.crend();// constant right End.
    */
    // 8- Vector Example ONe (test08.exe)
    /*
    std::vector<int> v(5);
    for (int i = 0; i < v.size(); i++)
    {
        std::cout << "Insert a Number!" << std::endl;
        std::cin >> v[i];
        if (i == v.size() - 1)
        {
            std::cout << "You've Reached The Limit" << std::endl
                      << "If You want to add more, Please press i key, and if you want to get out of the loop, please press any key: " << std::endl;
            char press;
            std::cin>>press;
            if(press =='i')
            {
                std::cout<<"Please Enter the Number of Elements you want to add:"<<std::endl;
                 int n;
                 std::cin>>n;
                 v.resize(v.size()+n);
            }
        else
        {
            break;
        }
        }
    }
    v.shrink_to_fit();
    auto it=v.begin();
    for(;it!=v.end();it++)
    {
        std::cout<<*it<< " ";
    }
    */
    // 9- *(std::find(v.begin(),v.end(), n)) (test09.exe)
    /*
    std::vector<int> v = {1, 6, 5, 5, 6, 2};
    std::cout << *(std::find(v.begin(), v.end(), 5)) << std::endl;
    */
    // 10- std::sort(v.begin(),v.end())    (test10.exe)
    /*
    std::vector<int> v = {1, 6, 5, 5, 6, 2,3,9,4};
    std::sort(v.begin(),v.end());
    for (auto it = v.begin(); it != v.end(); it++)
    {
        std::cout << "Element: " << *it << std::endl;
    }
    */
    // 11- v.swap(), v.clear() &v.erase() (test11.exe)
    /*
    std::vector<int> v = {1, 6, 5, 5, 6, 2,3,9,4};
    for (auto it = v.begin(); it != v.end(); it++)
    {
        std::cout << "Element: " << *it << std::endl;
    }
     std::vector<int>v2;
     v.swap(v2); //v is now empty and v2 has v's data.
        for (auto it = v2.begin(); it != v2.end(); it++)
    {
        std::cout << "Element: " << *it << std::endl;
    }
    */
    // 12- deQ (test12.exe)
    /*std::deque<char> d = {'r', 'o', 'g', 'r', 'a', 'm', 'm', 'e'};
    d.push_back('r');
    d.push_front('P');
    for (auto it : d)
    {
        std::cout << it;
    }
    std::cout << std::endl;
    std::reverse(d.begin(), d.end());
    for (auto it : d)
    {
        std::cout << it;
    }
    std::cout << std::endl;
    std::sort(d.begin(), d.end());
        for (auto it : d)
    {
        std::cout << it;
    }
    std::cout << std::endl;
    std::reverse(d.begin(), d.end());
    for (auto it : d)
    {
        std::cout << it;
    }
    std::cout << std::endl
              << d.max_size() << std::endl
              << d.empty() << std::endl;
    d.clear();
    std::cout << d.empty() << std::endl;
    */
    // 13- list (Double Linked List) (test13.exe)
    /*
    std::list<int>mylist;
    mylist.push_back(1);
    mylist.push_back(2);
    mylist.push_back(3);
    std::cout<<" Mylist: "<<std::endl;;

for(auto it =mylist.begin();it!=mylist.end();it++)
{
    std::cout<<*it<<" ";
}
std::cout<<std::endl;
mylist.push_front(0);
auto it1=mylist.begin();
std::cout<<"it1=mylist.begin(): "<<*it1<<std::endl;
++it1;
std::cout<<"++it1: "<<*it1<<std::endl;
++it1;
++it1;
std::cout<<"++it1 ++it1: "<<*it1<<std::endl;
++it1;
std::cout<<"it1 is incremented 3 times!!"<<std::endl;
mylist.insert(it1,4);
std::cout<<"mylist.insert(it1,4): "<<std::endl;

std::cout<<" Mylist: "<<std::endl;;
for(auto it =mylist.begin();it!=mylist.end();it++)
{
    std::cout<<*it<<" ";
}
std::cout<<std::endl;
std::list<int> l={1,2,3};
std::cout<<"l: "<<std::endl;
for(auto it =l.begin();it!=l.end();it++)
{
    std::cout<<*it<<" ";
}
std::cout<<std::endl;
std::list<int> li={4,5,6};
std::cout<<"li: "<<std::endl;
for(auto it =li.begin();it!=li.end();it++)
{
    std::cout<<*it<<" ";
}
std::cout<<std::endl;
l.merge(li);
std::cout<<"Merge: "<<std::endl;
for(auto it =l.begin();it!=l.end();it++)
{
    std::cout<<*it<<" ";
}
std::cout<<std::endl;
l.clear();
std::list<int> list(5);
list.assign(5,20);
std::cout<<"assign: ";
for(auto i:list)
{
    std::cout<<i<<" ";
}
std::cout<<std::endl;
*/
    // 14-  List  Example(test14.exe)
    /* std::list<std::string> el={"Ahmed","Mohamed","Shawky","Salma","Ramy","Holia","Nouran","Ibrahem","Sami"};
    el.sort(std::less<std::string>());
    std::cout<<"Employee Name \n";
    for(auto it:el)
    {
        std::cout<<it<<std::endl;
    }
    */
    // 15- Forward List(test15.exe)
    /*
    std::forward_list<int> firstlist(10),
        secondlist;
    firstlist.assign({1,2,3,4,5,6,7,8,9,10});
    secondlist.assign(11,20);
    secondlist.assign(firstlist.begin(),firstlist.end());
    for (auto element:secondlist)
    {
        std::cout<<element<<" ";
    }
    std::cout<<std::endl;
    */
    return 0;
}
