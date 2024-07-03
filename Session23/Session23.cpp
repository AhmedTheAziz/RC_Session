/*
Ahmed AbdelAziz
Robotics Corner
Session 23:
()
*/

#include <iostream>
#include <map>           //(test01.exe)
#include <unordered_set> // (test02.exe)
#include <unordered_map> //(test03.exe)
#include <memory>        //(test05.exe)
template <typename T>
class Smart_ptr // Smart Pointers (test04.exe)
{
private:
    T *ptr;

public:
    // constructor
    explicit Smart_ptr(T *p = NULL) // explicit
    {
        ptr = p;
    }
    // copy constructor
    explicit Smart_ptr(Smart_ptr<T> &s) = delete; // explicit

    // Operator
    T &operator*()
    {
        return *ptr;
    }
    // Destructor
    ~Smart_ptr()
    {
        delete ptr;
    }
};
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

int main()
{
    // 1- revision on map (test01.exe)
    /*
    std::map<std::string,float> GradeByName;
    GradeByName.insert({"omar",90.42});
    GradeByName.insert({"samer",91.90});
    GradeByName.insert({"karem",98.30});
    GradeByName.insert({"ahmed",89.69});
    GradeByName.insert({"mohamed",70.30});
    GradeByName.insert({"sayed",50.42});
    std::string name;
    std::cout<<"Enter Name: \n";
    std::cin>>name;
    int count =0;
    for(auto it =GradeByName.begin();it!=GradeByName.end();++it)
    {
        if(it->first==name)
        {
            std::cout<<"Your Grade is: \n"<< it->second<<std::endl;
            count++;
            break;
        }
    }
    if (count ==0)
    {
        std::cout << "Name Doesn't Exist!!\n";
    }
    */
    // 2- Un-Ordered Set (test02.exe)
    /*
    std::unordered_multiset<std::string> us({"Sun","Mon","Tue","Wed","Thu","Fri","Sat"});
    for(auto set:us)
    {
        std::cout<<set<<": "
        << us.bucket(set)<<std::endl;
    }
    std::cout<<us.bucket_count()<<std::endl;
    auto count=us.bucket_count();
    for(int i=0; i<  count;i++)
    {
        std::cout<<"Bucket: #"<<i<<" Which Contains: ";
        for(auto it=us.begin(i);it!=us.end(i);it++)
        {
            std::cout<<*it<<" ";
        }
    std::cout<<std::endl;
    }

    us.clear();
    */
    // 3- Un-Ordered Map (test03.exe)
    /*
    std::unordered_map<std::string, int> um{{"Kia", 2019}, {"Honda", 2020}, {"BMW", 2016}};
    // um[Kia]=2020;
    um["Mercedes"] = 2020;

    um.insert_or_assign("Kia", 2021);
   um.try_emplace("Daihatsu",2007);

   // um.insert(it);
    for (auto map : um)
    {
        std::cout << map.first << ": " << map.second << std::endl;
    }
    */
    // 4- Smart Pointers (test04.exe)
    /*
    Smart_ptr ptr(new int(10));
    std::cout<<"new int: "<<*ptr<<std::endl;
    *ptr = 20;
    std::cout <<"*ptr: " <<*ptr << std::endl;
    */
    // 5-Unique Pointer (test05.exe)
    /*std::unique_ptr<int> ptr1(new int(10));
    std::cout << "Unique Ptr: " << *ptr1 << std::endl;
    ptr1 = std::make_unique<int>(25);
    std::cout << "Make Unique: " << *ptr1 << std::endl;
    // std::unique_ptr<int>ptr2 =ptr1; cannot be copied
    std::unique_ptr<int> ptr2 = move(ptr1);
    //   std::cout << "ptr1: " << *ptr1 << std::endl;
    std::cout << "move ptr: " << *ptr2 << std::endl;
    std::unique_ptr<Myclass> ptr = std::make_unique<Myclass>();
    */
}