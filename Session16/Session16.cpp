/*
Ahmed Abdelaziz
Robotics Corner
Session 16 :
Composition,
*/
#include <iostream>
#include <string>
#include <vector>
// 1-Composition.
class Room;
class House
{
private:
    Room *LivingRoom;
    Room *Kitchen;

public:
    House() : LivingRoom(new Room()), Kitchen(new Room())
    {
    }
    ~House()
    {
        delete LivingRoom;
        delete Kitchen;
    }
};
class Room
{
private:
    int size;

public:
    Room() : size(0) {}
    /*Size Setter
    Void SetSize()
    {
      std::cin>>size;
    }*/
};
// 2-Aggregation.
class Department;
class Employee
{
private:
    std::string name;
    Department *department;

public:
    Employee() : name(name), department(nullptr)
    {
    }
    void setDepartment(Department* newdep)
    {
        department = newdep;
    }
};
class Department
{
    private:
    std::string dep;
    std::vector<Employee*>emps;
    public:
    Department(std::string name) :dep(dep) {}
    //add employee
    void addemployee(Employee *emp)
    {
        emps.push_back(emp);
        emp->setDepartment(this);
    }
};
