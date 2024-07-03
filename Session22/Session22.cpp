/*
Ahmed Abdelaziz
Robotics Croner
Session22:
()
*/
#include <iostream>
#include <forward_list> //(test01.exe)
#include <set>          //(test02.exe)
#include <map>          //(test03.exe)
bool compare(int n)
{
    return n > 4;
}
//
/*template <typename T>
std::pair<T, bool> emplace(T value)
{
    std::pair<T, bool> p;
    // check for exisiting element.
    if (//Condition)
    {
        p.first = value;
        p.second = true;
    }
    else
    {
        return p;
    }
}
*/
int main()
{
    // Forward List (test01.exe)
    /*
    std::forward_list<int> list = {1, 2, 3, 4};
    // std::forward_list<int> list2 = {5,6,7};
    // list.merge(list2);
    for (auto l : list)
    {
        std::cout << l << std::endl;
    }
    std::forward_list<int> list2 = {5, 6, 7};
    list.merge(list2);
    std::cout << "MErging\n";
    for (auto l : list)
    {
        std::cout << l << std::endl;
    }
    std::cout << "Emplace after ite\n";
    auto itbb = list.before_begin();
    *itbb = 10;
    std::cout << "remove if\n";
    for (auto l : list)
    {
        std::cout << l << std::endl;
        list.remove_if(compare);
    }
        std::cout << "remove if lambda\n";
    for (auto l : list)
    {
        std::cout << l << std::endl;
        list.remove_if([](int n){return n>3;});
    }
    // auto ite =list.end();
    //*ite=5;
    //  list.emplace_after(ite);
        std::cout << "insert After itbb\n";
    list.insert_after(itbb, 10); // Position , Element
    list.emplace_after(itbb, 9); // Position , Element more effiecent
    for (auto l : list)
    {
        std::cout << l << std::endl;
    }
    std::cout << "erase After itbb and before begin \n";
    list.erase_after(itbb);                // O(1)
    list.erase_after(list.before_begin()); // O(n)
    for (auto l : list)
    {
        std::cout << l << std::endl;
    }
    std::cout << "Emplace 0\n";
    list.emplace_front(0);
    for (auto l : list)
    {
        std::cout << l << std::endl;
    }
    std::cout << "Assigning 5\n";
    list.assign({5});
    for (auto l : list)
    {
        std::cout << l << std::endl;
    }
    std::cout << "Assigning 6,7,8\n";
    list.assign({6, 7, 8});
    for (auto l : list)
    {
        std::cout << l << std::endl;
    }
    std::cout << "Max Size: " << list.max_size() << std::endl;
    list.clear();
    */
    // Binaray Tree (Set) (test02.exe)
    /*std::cout<<"Set \n";
    std::set<int> s{1, 2, 3, 4, 6};
    for (auto ss : s)
    {
        std::cout << ss << " ";
    }
    std::cout << std::endl;
    std::cout << "Insert 5\n";
    s.insert(5);
    for (auto ss : s)
    {
        std::cout << ss << " ";
    }
    std::cout << std::endl;
    std::cout << "emplace 7\n";
    s.emplace(7);
    for (auto ss : s)
    {
        std::cout << ss << " ";
    }
    std::cout << std::endl;
    auto it = s.begin();
    std::cout << "using iterator\n";
    s.insert(it, 8); // O(log n) => O(1)
    for (auto ss : s)
    {
        std::cout << ss << " ";
    }
    std::cout << std::endl;
    std::cout << "emplace hint\n";
    s.emplace_hint(it, 10); // O(1)
    for (auto ss : s)
    {
        std::cout << ss << " ";
    }
    std::cout << std::endl;
    std::cout << "it=emplace hint\n";
    it = s.emplace_hint(it, 9);
    for (auto ss : s)
    {
        std::cout << ss << " ";
    }
    std::cout << std::endl;
    std::cout << "set count\n";
    std::cout << s.count(3) << std::endl;
    auto iter = s.emplace(11);
    auto it2 = s.emplace(11);
    std::cout << "iter = " << std::endl;
    std::cout << *iter.first << " " << iter.second << std::endl;
    std::cout << "it2 = " << std::endl;
    std::cout << *it2.first << " " << it2.second << std::endl;
    std::cout << "erase 11\n";
    s.erase(11);
    for (auto ss : s)
    {
        std::cout << ss << " ";
    }
    std::cout << std::endl;
    std::cout << "erase iterrator incremented 3 times (++ ++ ++iterartor)\n";
    auto iterator = s.begin();
    ++ ++ ++iterator;
    s.erase(iterator);
    for (auto ss : s)
    {
        std::cout << ss << " ";
    }
    std::cout << std::endl;
    std::cout << "MultiSet:" << std::endl;
    std::multiset<std::string> set_str{"Ahmed", "Omar", "Abraham", "Ahmed"};
    for (auto ss : set_str)
    {
        std::cout << ss << " ";
    }
    std::cout << std::endl;
    std::cout << "MultiSet Greater:" << std::endl;
    std::multiset<std::string, std::greater<std::string>> set_strG{"Ahmed", "Omar", "Abraham", "Ahmed"};
    for (auto ss : set_strG)
    {
        std::cout << ss << " ";
    }
    std::cout << std::endl;
    std::cout<<"Count Ahmed\n"<<set_str.count("Ahmed")<<std::endl;
    */
    // Map (test03.exe)
    std::map<std::string, std::string> m = {{"Ahmed", "CS"}, {"Khaled", "CIS"}};
    std::map<int, std::string> map = {{1, "Omar"}, {2, "Ahmed"}};
    std::cout << "Search by key (map[1]): " << map[1] << std::endl;
    std::cout << "Adding map[0]\n";
    map[0] = "Karim";
   // map.at(3) = "Mohammed";
    for (auto m : map)
    {
        std::cout << m.first << "-" << m.second << ",  ";
    }
    std::cout << std::endl;
     std::cout<<"using Iterator\n";
    std::map<int,int> ma={{1,2},{2,1},{3,6},{4,10},{5,15},{15,7}};
    auto itlow = ma.lower_bound(1); // return iterator  not less the given key
    auto itup = ma.upper_bound(2);  // return iterator  greater than the given key
    std::cout<<"Lower Bound\n";
std::cout<<itlow->first<<" "<<itlow->second<<std::endl;
std::cout<<"Upper Bound\n"; 
std::cout<<itup->first<<" "<<itup->second<<std::endl;
    return 0;
}