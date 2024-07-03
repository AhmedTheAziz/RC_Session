/*
Ahmed AbdelAziz
Robotics Corner
Session 19:
(Sorting : Selection, Bubble, Merge )
*/

#include <iostream>
// Selecting Sorting (test01.exe)
void print(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}
void Swap(int *one, int *two)
{
    int temp = *one;
    *one = *two;
    *two = temp;
}
void SelectionSort(int arr[], int size)
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

        Swap(&arr[min_idx], &arr[i]);
    }
}
// BubbleSorting (test02.exe)
void BubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                Swap(&arr[j], &arr[j + 1]); // Swap if they are in the wrong order..
            }
        }
    }
}
// Insertion Sorting (test03.exe)
void InsertionSorting(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        std::cout << "i " << i << std::endl;
        int key = i + 1;
        for (int j = 0; j < size; j++)
        {
            std::cout << "j " << j << std::endl;
            while (arr[j] < arr[j - 1])
            {
                std::cout << "while " << j << std::endl;
                if (arr[j] < arr[j - 1])
                {
                    std::cout << "if " << j << std::endl;

                    key = j;
                }
                std::cout << "swap " << j << std::endl;

                Swap(&arr[key], &arr[j - 1]);
                print(arr, size);
            }
        }
    }
}
void Insertionpseudocode(int arr[],int size)
{
   for (int i=0;i<size;i++)
   {
    int key =arr[i];
    int j=i-1;
        while (j >=0 && arr[j] >key)
        {
            arr[j+1]=arr[j];
            //arr[j]=arr[j-1];
            j=j-1;
            arr[j+1]=key;
        }
   } 
}
// Merge Sorting
void merge(int arr[], int const left, int const mid, int const right)
{
    // finding the size of the new arrays
    const int subArrayOne = mid - left + 1;
    const int subArrayTwo = right - mid;

    // create temp Array
    auto *leftArray = new int[subArrayOne],
         *rightArray = new int[subArrayTwo];

    for (int i = 0; i < subArrayOne; i++)
    {
        leftArray[i] = arr[left + i];
    }

    for (int j = 0; j < subArrayTwo; j++)
    {
        rightArray[j] = arr[mid + 1 + j];
    }

    int i = 0,
        j = 0,
        k = left;

    while (i < subArrayOne && j < subArrayTwo)
    {
        if (leftArray[i] <= rightArray[j])
        {
            arr[k] = leftArray[i];
            i++;
        }
        else
        {
            arr[k] = rightArray[j];
            j++;
        }
        k++;
    }

    while (i < subArrayOne)
    {
        arr[k] = leftArray[i];
        i++;
        k++;
    }

    while (j < subArrayTwo)
    {
        arr[k] = rightArray[j];
        j++;
        k++;
    }

    delete[] leftArray;
    delete[] rightArray;
}
void mergeSort(int array[], const int begin, const int end)
{
    if (begin >= end)
    {
        return;
    }

    auto mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
}
// Merge Sorting written.
void Merge(int arr[], int const left, int const mid, int const right)
{
    // Determine the size of the new sub arrays.
    const int SubArrayOne = mid - left + 1;
    const int SubArrayTwo = right - mid;
    // Temp Array Creation
    auto *LeftArray = new int[SubArrayOne],
         *RightArray = new int[SubArrayTwo];
    for (int i=0;i<SubArrayOne;i++)
    {
        LeftArray[i]=arr[left+i];
    }
    for(int j=0;j<SubArrayTwo;j++)
    {
        RightArray[j]=arr[mid+1+j];
    }
    int indexSubArrayOne=0, //i
        indexSubArrayTwo=0, //j
        indexMergeArray=left; //k
    while (indexSubArrayOne<SubArrayOne&&indexSubArrayTwo<SubArrayTwo)
    {
        if(LeftArray[indexSubArrayOne]<=RightArray[indexSubArrayTwo])
        {
            arr[indexMergeArray]=LeftArray[indexSubArrayOne];
            indexSubArrayOne++;
        }
        else
        {
            arr[indexMergeArray]=RightArray[indexSubArrayTwo];
            indexSubArrayTwo++;
        }
        indexMergeArray++;
    }
    while (indexSubArrayOne<SubArrayOne)
    {
        arr[indexMergeArray]=LeftArray[indexSubArrayOne];
        indexSubArrayOne++;
        indexMergeArray++;
    }
    while(indexSubArrayTwo<SubArrayTwo)
    {
        arr[indexMergeArray]=RightArray[indexSubArrayTwo];
        indexSubArrayTwo++;
        indexMergeArray++;
    }
    delete[] LeftArray;
    delete[] RightArray;

}
void MergeSort(int arr[], const int begin, const int end)
{
    if(begin>=end)
    {
        return;
    }
    auto mid = begin+(end-begin)/2;
    MergeSort(arr,begin,mid);
    MergeSort(arr,mid+1,end);
    Merge(arr,begin,mid,end);
}
void PrintArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
}int main()
{
    // Selecting Sorting (test01.exe)
    /*
    int arr[] = {10, 4, 2, 3, 9, 5, 6,7,1};
    int size = sizeof(arr) / sizeof(arr[0]);
    print(arr, size);
    SelectionSort(arr, size);
    print(arr, size);
    return 0;
    */
    // BubbleSorting (test02.exe)
    /*
    int arr[]={64,34,25,12,22,11,90};
    //int arr[]={6,4,5,9,2,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    print (arr,n);
    BubbleSort(arr,n);
    print(arr,n);
    return 0;
    */
    // Insertion Sorting (test03.exe)
    /*
    int arr[]={64,34,25,12,22,11,90};
  // int arr[] = {4, 9, 10, 3, 5, 8};
   int n = sizeof(arr) / sizeof(arr[0]);
   print(arr, n);
   InsertionSorting(arr, n);
   print(arr, n);
   return 0;
   */
    // Merge Sorting
    /*
    int arr[] = {1, 5, 2, -5, 20, -3, 40};
    int sizeArr = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Given Array is : ";
    printArray(arr, sizeArr);

    mergeSort(arr, 0, sizeArr - 1);

    std::cout << "\nSorted Array is : ";
    printArray(arr, sizeArr);
    return 0;
    */
   // Merge Sorting written.
    /*
    int arr[]={1,5,2,-5,20,-3,40};
    int SizeArr=sizeof(arr)/sizeof(arr[0]);
    std::cout<<"Given Array is : ";
    PrintArray(arr,SizeArr);
    MergeSort(arr,0,SizeArr-1);
    std::cout<<"\nSorted Array is : ";
    PrintArray(arr,SizeArr);
    return 0;  
    */
//insersetion pseudocode
  //  int arr[]={64,34,25,12,22,11,90};
   int arr[] = {4, 9, 10, 3, 5, 8};
   int n = sizeof(arr) / sizeof(arr[0]);
   print(arr, n);
   Insertionpseudocode(arr, n);
   print(arr, n);
   return 0;

}