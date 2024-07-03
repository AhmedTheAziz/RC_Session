/*
 */
#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>
#include <string> // DI example

// 1- Singleton. (test01.exe)
class SingletonClass //(test01.exe)
{
private:
    SingletonClass()
    {
        // count = 0;
        std::cout << "Singleton Construct is Created!!\n"
                  << "Counter Constructor = " << count << std::endl;
    }
    static SingletonClass *Instance;
    static int count;

public:
    static SingletonClass *GetInstance()
    {
        if (!Instance)
        {
            Instance = new SingletonClass(); // Creation of Object. calling constructor
        }
        return Instance;
    }
    int getcount()
    {
        if (Instance)
        {
            count++;
            std::cout << "counter = " << count << std::endl;
        }

        return 0;
    }
    void Showmsg()
    {
        std::cout << " Welcome to The Singelton House!!\n";
    }
    ~SingletonClass()
    {
        delete Instance;
    }
};
SingletonClass *SingletonClass::Instance = nullptr;
int SingletonClass::count = 0;

// 2- Observer. (test02.exe)
class Subject;
class Observer
{
    ///< summary>
    /// Observer is an Interface using an object from Subject Class.
    ///</summary>
public:
    virtual ~Observer() = default; // Virtual Destructor
    virtual void Update(Subject &) = 0;
};
///< summary>
/// Making Class Subject .
///</summary>
class Subject
{
private:
    std::vector<Observer *> observer; // using an object from observer class.
public:
    virtual ~Subject() = default;
    void Attach(Observer &o)
    {
        observer.push_back(&o);
    }
    void Detach(Observer &o)
    {
        observer.erase(std::remove(observer.begin(), observer.end(), &o));
    }
    void Notify()
    {
        for (auto *o : observer)
        {
            o->Update(*this);
        }
    }
};
class ClockTimer : public Subject
{
private:
    int hrs;
    int mins;
    int secs;

public:
    void setTime(int hours, int minutes, int seconds)
    {
        this->hrs = hours;
        this->mins = minutes;
        this->secs = seconds;
        Notify();
    }
    int GetHrs() const
    {
        return this->hrs;
    }
    int GetMins() const
    {
        return this->mins;
    }
    int GetSecs() const
    {
        return this->secs;
    }
};
class DigitalCLK : public Observer
{
private:
    ClockTimer &subject;

public:
    explicit DigitalCLK(ClockTimer &s) : subject(s) /// INjection of Clocktimer obj into constructor.
    {
        subject.Attach(*this);
    }
    ~DigitalCLK()
    {
        subject.Detach(*this);
    }
    void Update(Subject &changedSubject) override
    {
        if (&changedSubject == &subject)
        {
            Draw();
        }
    }
    void Draw()
    {
        int hrs = subject.GetHrs();
        int mins = subject.GetMins();
        int secs = subject.GetSecs();
        std::cout << "Digital Time is " << hrs << ":" << mins << ":" << secs << std::endl;
    }
};
class AnalogCLK : public Observer
{
private:
    ClockTimer &subject;

public:
    explicit AnalogCLK(ClockTimer &s) : subject(s) /// INjection of Clocktimer obj into constructor.
    {
        subject.Attach(*this);
    }
    ~AnalogCLK()
    {
        subject.Detach(*this);
    }
    void Update(Subject &changedSubject) override
    {
        if (&changedSubject == &subject)
        {
            Draw();
        }
    }
    void Draw()
    {
        int hrs = subject.GetHrs();
        int mins = subject.GetMins();
        int secs = subject.GetSecs();
        std::cout << "Analog Time is " << hrs << ":" << mins << ":" << secs << std::endl;
    }
};

// 3- Depindncy Injection (tets03.exe)
///< summary>
/// Wrong Method.
/// UserService class without Dependency Injection
///</summary>
/*
class Logger
{
    public:
    void log(const std::string& message)
    {
        std::cout<<"Logging: "<<message<<std::endl;
    }
};
class UserService
{
    private:
    Logger logger;
    public:
    void PerformAction(const std::string& username, const std::string& action)
    {
        logger.log(username+" Performed action "+action);
    }
};
*/
/// <summary>
/// Right Method
/// using Dependency Injection add Interface.
/// </summary>
class ILogger
{
public:
    virtual void log(const std::string &message) = 0; // pure virtual Function
    virtual ~ILogger() = default;
};
class Logger : public ILogger
{
public:
    void log(const std::string &message)
    {
        std::cout << "Logging: " << message << std::endl;
    }
};
class Logger2 : public ILogger
{
public:
    void log(const std::string &message)
    {
        std::cout << "Logging: " << message <<" Welcome to the App" <<std::endl;
    }
};
class UserService
{
private:
    ILogger &m_logger;

public:
    // constuctor
    UserService(ILogger &logger) : m_logger(logger) {}
    // Functions
    void PerformAction(const std::string &username, const std::string &action)
    {
        m_logger.log(username + " Performed action " + action);
    }
};

int main()
{
    // 1- Singleton. (test01.exe)
    /*
        SingletonClass *Obj1 = SingletonClass::GetInstance();
        Obj1->getcount();
        SingletonClass *Obj2 = SingletonClass::GetInstance();
        Obj2->getcount();
        Obj1->getcount();
        SingletonClass *Obj3 = SingletonClass::GetInstance();
        Obj3->getcount();
        if (Obj1 == Obj2 && Obj1 == Obj3)
        {
            std::cout << "All OBJECTS are EQUAL\n";
        }

    */
    // 2- Observer. (test02.exe)
    /*
    ClockTimer time;
    DigitalCLK digTime(time);
    AnalogCLK ananlogTime(time);
    time.setTime(4,22,20);
    */
    // 3- Depindncy Injection (tets03.exe)
    //create Logger instance
    /*
    Logger logger;
    Logger2 logger2;
    UserService userService(logger2);
    userService.PerformAction("Jhon", "Login");
    */
    return 0;
}