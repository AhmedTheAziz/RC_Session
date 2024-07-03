/*
Ahmed Abdelaziz
Robotics Corner
Session 18 :
Data Structure (Algorithms,
*/
#include <iostream>
#include <array>

// Linear Search (test01.exe)(test01a.exe)
void linear(std::array<int, 6> list, int key)
{
    for (int i = 0; i < list.size(); i++)
        if (key == list[i])
        {
            std::cout << "The key value " << list[i] << " found at " << i << std::endl;
            break; // test01: with break | test01a: without break to keep searching for duplicates.
        }
}
// Binary Search (test02.exe)
int Binary(int arr[],int left, int right, int key )
   {
       int mid =(left+right)/2;
       while (left<=right)
   {
       if (arr[mid]==key)
       {
           return mid;
       }
       if (key<= arr[mid])
       {
           right =mid -1;
           mid=(left+right)/2;
       }
       else
       {
           left=mid+1;
           mid=(left+right)/2;
       }
   }
   return -1;
   }
// Method to Recurssion (test02a.exe)
int binary(int arr[], int left, int right, int key)
{
    if (left <= right)
    {
        int mid = (left + right) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        if (key <= arr[mid])
        {
            return binary(arr, left, mid - 1, key); // calling
        }
        else
        {
            return binary(arr, mid + 1, right, key); // calling
        }
    }
    return -1;
}

int main() 
{
    // Linear Search  (test01.exe)(test01a.exe)
    /*
        std::array<int, 6> list = {3, 5, 9, 8, 1, 9};
        int key = 0;
        std::cout << "enter element \n";
        std::cin >> key;
        linear(list, key);
    */
    // Binary Search (test02.exe) (test02a.exe)
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 20, 30, 40};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key;
    int left = 0, right = size - 1;
    std::cout << "Pleas Enter Key number..\n";
    std::cin >> key;
    // int result=Binary(arr,left,right,key);//calling (test02.exe)
    int result = binary(arr, left, right, key); // calling (test02a.exe)
    if (result == -1)
    {
        std::cout << "Key is not Found!! \n";
    }
    else
    {
        std::cout << "The Key (" << arr[result] << ")"
                  << " is found in index (" << result << ")" << std::endl;
    }

    return 0;
}