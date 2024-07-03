/*
 */
#include <iostream>
// 2- Proxy. libraries used
#include <thread>
#include <chrono>
// 1- Stratgy Interface. (test01.exe)
class SortingStrategy
{
public:
    virtual void Sort(int arr[], int size) const = 0;
    virtual ~SortingStrategy() = default;
};
// Concrete Strategy -Bubble Sort
class BubbleSort : public SortingStrategy
{
public:
    void Sort(int arr[], int size) const override
    {
        for (int i = 0; i < size - 1; ++i)
        {
            for (int j = 0; j < size - 1; ++j)
            {
                if (arr[j] > arr[j + 1])
                {
                    std::swap(arr[j], arr[j + 1]);
                }
            }
        }
    }
};
// concrete Strategy -Quick Sort
class QuickSort : public SortingStrategy
{
public:
    void Sort(int arr[], int size) const override
    {
        QuickSortRecursive(arr, 0, size - 1);
    }

private:
    void QuickSortRecursive(int arr[], int low, int high) const
    {
        if (low < high)
        {
            int pivot = Partition(arr, low, high);
            QuickSortRecursive(arr, low, pivot - 1);
            QuickSortRecursive(arr, pivot + 1, high);
        }
    }
    int Partition(int arr[], int low, int high) const
    {
        int pivot = arr[high];
        int i = low - 1;
        for (int j = low; j <= high - 1; ++j)
        {
            if (arr[j], pivot)
            {
                ++i;
                std::swap(arr[i], arr[j]);
            }
        }
        std::swap(arr[i + 1], arr[high]);
        return i + 1;
    }
};
// selectionsort (modifyed easily)
class SelectionSort : public SortingStrategy
{
public:
    void Sort(int arr[], int size) const
    {
        int i, j, min_idx;
        for (i = 0; i < size - 1; i++)
        {
            min_idx = i;
            for (j = i + 1; j < size; j++)
            {
                if (arr[j] < arr[min_idx])
                {
                    min_idx = j;
                }
            }
            std::swap(arr[min_idx], arr[i]);
        }
    }
};
// context class
class Sorter
{
private:
    SortingStrategy *sortingstrategy;

public:
    Sorter(SortingStrategy *strategy) : sortingstrategy(strategy)
    {
    }
    void SetStratrgy(SortingStrategy *strategy)
    {
        sortingstrategy = strategy;
    }
    void PerformSort(int arr[], int size) const
    {
        sortingstrategy->Sort(arr, size);
    }
};

// 2- Proxy. (test02.exe)
///< summary>
/// creating a subject class that is dealing with the user while proxy and real subject inheret from subject ro be protected from client
///</summary>
// a- Subject class
class Subject
{
public:
    virtual void Request() = 0;
};
// b- RealSubject class
class RealSubject : public Subject
{
public:
    void Request() override
    {
        std::cout << "RealSubject: Handling Request...." << std::endl;
    }
};
// c- Proxy class.
class Proxy : public Subject
{
private:
    RealSubject *realsub; // Has a : strong containment (composition)
public:
    Proxy()
    {
        realsub = new RealSubject();
    }
    ~Proxy()
    {
        delete realsub;
    }
    void Request() override
    {
        using namespace std::literals::chrono_literals;
        std::cout << "Proxy: CHecking Access Before Forwarding Request...." << std::endl
                  << "Proxy: Logging the Request..." << std::endl
                  << "Proccessing the Request...." << std::endl;
        //   std::this_thread::sleep_for(5s); //unknown error
        realsub->Request();
    }
};

// 3- bounus Proxy Simple Pattern. (test03.exe)
// a- Intf 1
class Ibox
{
public:
    virtual void Open() = 0;
    virtual ~Ibox() {}
};
// b- Intf 2
class SimpleBox : public Ibox
{
public:
    void Open() override
    {
        std::cout << "Ready to Open" << std::endl;
    }
};
// c- real class
class ProxyBox : public Ibox
{
private:
    std::string m_Username;
    std::string m_Password;
    SimpleBox m_Box;

public:
    ProxyBox(std::string name, std::string password) : m_Username(name), m_Password(password)
    {
    }
    void Open() override
    {
        if (authenticate())
        {
            std::cout << "Success" << std::endl;
            m_Box.Open();
            std::cout << "Open the Box" << std::endl;
        }
        else
        {
            std::cout << "Box Can't be Opened" << std::endl;
        }
    }
    bool authenticate()
    {
        bool permission = false;
        if (m_Username == "Ahmed Abdelaziz" && m_Password== "123456789")
        {
            permission = true;
        }
        return permission;
    }
};
int main()
{
    // 1- Stratgy Interface. (test01.exe)
    /*
    int arr[] = {5, 2, 8, 1, 9, 4};
    int size = sizeof(arr) / sizeof(arr[0]);
    BubbleSort Bubblesort;
    QuickSort Quicksort;
    SelectionSort Selection;

    Sorter sorter(&Bubblesort);
    sorter.PerformSort(arr, size);
    std::cout << "Array After Bubble Sort: ";
    for (int i = 0; i < size; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    sorter.SetStratrgy(&Quicksort);
    sorter.PerformSort(arr, size);
    std::cout << "Array After Quick Sort: ";
    for (int i = 0; i < size; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    sorter.SetStratrgy(&Selection);
    sorter.PerformSort(arr, size);
    std::cout << "Array After Selection Sort: ";
    for (int i = 0; i < size; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    */
    // 2- Proxy. (test02.exe)
    /*
    Proxy proxy;
    proxy.Request(); // client calls the proxy.
    */
    // 3- bounus Proxy Simple Pattern. (test03.exe)
    ProxyBox open("Ahmed Abdelaziz", "123456789");
    open.Open();
    return 0;
}