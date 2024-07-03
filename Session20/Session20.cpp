/*
Ahmed Abdelaziz
Robotics Corner
Session 20
Data Structure :
(Stack, Linked List)
*/

#include <iostream>
#include <vector>

// Stack. (test01.exe)
const int Max_size = 100;

template <class T>
class Stack
{
private:
    int top;
    T item[Max_size];
    int n;
    std::vector<T> vec;


public:
    // Constructor.
    Stack() : top(-1) 
    {
    }
    //constructor vector
    Stack(int s): n(s), top(-1),vec(n)
    {
        std::cout<<"Vec Constructor is Activated...."<<std::endl;
    }
    // Pushing element
    void push(T element)
    {
        if (top >= Max_size)
        {
            std::cout << "Stack is Full" << std::endl;
        }
        else
        {
            top++;
            item[top] = element;
        }
    }
    //pushing vector
    void pushv(T element)
    {
        if (top >= n-1)
        {
            std::cout << "Stack is Full" << std::endl;
        }
        else
        {
            top++;
            vec[top] = element;
        }
    }
    // Popping.
    bool is_empty() // 1 when top < 0
    {

        return top < 0;
    }
    void pop()
    {
        if (!is_empty()) // 0
        {
            top--;
        }
        else // 1
        {
            std::cout << "Stack is Empty to pop" << std::endl;
        }
    }
    void pop(T &element)
    {
        if (!is_empty()) // 0
        {
            element = item[top];
            top--;
        }
        else // 1
        {
            std::cout << "Stack is Empty to pop to save" << std::endl;
        }
    }
// pop vec element
    void popv(T &element)
    {
        if (!is_empty()) // 0
        {
            element = vec[top];
            top--;
        }
        else // 1
        {
            std::cout << "Stack is Empty to pop to save" << std::endl;
        }
    }
    // Getting.
    void gettop(T &stacktop)
    {
        if (!is_empty())
        {
            stacktop = item[top];
            std::cout << stacktop << std::endl;
        }
        else
        {
            std::cout << "top is Empty";
        }
    }
    // Getting vec.
    void gettopv(T &stacktop)
    {
        if (!is_empty())
        {
            stacktop = vec[top];
            std::cout << stacktop << std::endl;
        }
        else
        {
            std::cout << "top is Empty";
        }
    }
    // Print.
    void print()
    {
        std::cout << "[ ";
        for (int i = top; i >= 0; i--)
        {
            std::cout << item[i] << ", ";
        }
        std::cout << "] ";
        std::cout << std::endl;
    }
    // Print vec.
    void printv()
    {
        std::cout << "[";
        for (int i = top; i >= 0; i--)
        {
            std::cout << " "<<vec[i];
            if(i!=0)
            {
                 std::cout<< ",";
            }
        }
        std::cout << " ]";
        std::cout << std::endl;
    }
};
// Linked List. (test02.exe)
template <typename T>
class linkStack
{
private:
    struct node
    {
        T item;
        node *next;
    };
    node *top, *current;

public:
    // Constructor.
    linkStack() : top(NULL) {}
    // Pushing.
    void push(T value)
    {
        node *newitem = new node;
        if (newitem == NULL)
        {
            std::cout << "stack push Cannot allocate memory" << std::endl;
        }
        else
        {
            newitem->item = value;
            newitem->next = top;
            top = newitem;
        }
    }
    // Popping.
    bool empty()
    {
        return top == NULL;
    }
    void pop()
    {
        if (empty())
        {
            std::cout << "cannot allocate Memory " << std::endl;
        }
        else
        {
            node *temp = top;
            top = top->next;
            temp->next = NULL;
            delete temp;
        }
    }
    void pop(T &stacktop)
    {
        if (empty())
        {
            std::cout << "cannot allocate Memory " << std::endl;
        }
        else
        {
            stacktop = top->item;
            node *temp = top;
            top = top->next;
            temp->next = NULL;
            delete temp;
        }
    }
    // Getting.
    T gettop(T &topitem)
    {
        if (empty())
        {
            std::cout << "cannot allocate memory" << std::endl;
        }
        else
        {
            topitem = top->item;
            return topitem;
        }
        return -1;
    }
    // Display.
    void Display()
    {
        current = top;
        std::cout << " item Stacked are" << std::endl;
        std::cout << "[ ";
        while (current != NULL)
        {
            std::cout << current->item << ", ";
            current = current->next;
        }
        std::cout << "]" << std::endl;
    }
};
// Q (TASK) (test03.exe)
template <typename T>
class Q
{
private:
    int front, rear;
    int size;
    T *item;

public:
    // Constructor.
    Q(int s) : front(-1), rear(-1), size(s), item(new T[s]) {}
    // Pushing.
    void push(T e)
    {
        if ((front == 0 && rear == size - 1) || ((rear + 1) % size == front))
        {
            std::cout << "Queue is Full!!\n";
        }
        else if (front == -1) 
        {
            front = rear = 0;
            // item[front] = e;
            item[rear] = e;
        }

        /*else if (rear == front - 1)
        {
            std::cout << "rear: " << rear << " "
                      << "front: " << front << std::endl
                      << "Queue is Full!!\n";
        }*/
        else if (rear == size - 1 && front != 0)
        {
            rear = 0;
            // rear = (rear + 1) % size;
            item[rear] = e;
        }
        else
        {
            rear++; /*rear=(rear + 1) % size;*/
            item[rear] = e;
            //  std::cout << "rear: " << rear << " item rear: " << item[rear] << std::endl;
            // std::cout << "front: " << front << " item front: " << item[front] << std::endl;
        }
    }

    // Is Empty
    /*bool is_empty() // 1 when front ==-1
    {
        return front = -1;
    }*/
    // Popping.
    void pop()
    {
        if (front == -1) // is_empty =0
        {
            // rear = front = -1;
            std::cout << "Queue is Empty!!" << std::endl;
        }

        T temp = item[front];
        item[front] = -1;
        // front = (front + 1) % (size + 1);
        // item[front]=-1;
        if (front == rear)
        {
            front = rear = -1;
        }
        else if (front == size - 1)
        {
            front = 0;
        }
        else
        {
            front++;
            std::cout << "Element Popped is: " << temp << std::endl;
        }

        //  std::cout << "rear: " << rear << " item rear: " << item[rear] << std::endl;
        // std::cout << "front: " << front << " item front: " << item[front] << std::endl;
    }
    void pop(T &e)
    {

        if (front == -1) // 0
        {
            //  front = rear = -1;
            std::cout << "Queue is Empty!!" << std::endl;
        }
        e = item[front];
        item[front] = -1;
        //  front = (front + 1) % (size + 1);

        if (front == rear)
        {
            front = rear = -1;
        }
        else if (front == size - 1)
        {
            front = 0;
        }
        else
        {
            front++;
            std::cout << "Element Popped is: " << e << std::endl;
        }
    }
    // Getting.
    void
    getfront(T &Qf)
    {
        if (front != -1) // 0
        {
            Qf = item[front];
            std::cout << Qf << std::endl;
        }
        else
        {
            std::cout << "Queue is Empty!!" << std::endl;
        }
    }
    // Display.
    void display()
    {

        if (front = -1)
        {
            std::cout << "Queue is Empty!!" << std::endl;
        }
        if (front <= rear)
        {
            std::cout << "[ ";
            for (int i = front; i <= rear; i++)
            {
                // std::cout << "i: " << i << " ";
                std::cout /*<< "item[i]: " */ << item[i] << " ";
            }
            std::cout << "]" << std::endl;
        }
        else if (front > rear)
        {

            // std::cout << "Test" << std::endl;
            std::cout << "[ ";
            for (int i = front; i < size; i++)
            {
                // std::cout << "i: " << i << " ";
                std::cout /*<< "item[i]: " */ << item[i] << " ";
            }
            for (int i = 0; i <= rear; i++)
            {
                // i = ((i++) + 1) % (size + 1);
                //  std::cout << "i: " << i << " ";
                std::cout /*<< "item[i]: "*/ << item[i] << " ";
            }
            std::cout << "]" << std::endl;
        }
    }
};
int main()
{       
    // Stack. (test01.exe)
    /*
    Stack<int> arr;
    arr.push(20);
    arr.push(50);
    arr.push(12);
    arr.push(1);
    arr.push(3);
    arr.push(16);
    arr.pop();

    int y = 0;
    arr.pop(y);
    arr.print();
std::cout<<y<<std::endl;
    arr.gettop(y);
    int x=0;


    //string
    Stack<std::string> strings;
    strings.push("AHmed");
    strings.push("Samir");
    strings.push("Kamel");
    strings.print();
    */
    // Stack vector. (test04.exe)
    
    Stack<int> arr(5);
    arr.pushv(20);
    arr.pushv(50);
    arr.pushv(12);
    arr.pushv(1);
    arr.pushv(3);
    arr.pushv(16);
    arr.printv();
    std::cout<<"popping..."<<std::endl;
    arr.pop();
    arr.printv();

    int y = 0;
    arr.popv(y);
    arr.printv();
std::cout<<y<<std::endl;
    arr.gettopv(y);
    std::cout<<"gett top y ="<<y<<std::endl;


    //string
    Stack<std::string> strings(5);
    strings.pushv("Ahmed");
    strings.pushv("Samir");
    strings.pushv("Kamel");
    strings.printv();
    

    // Linked List (test02.exe)
    /*
    linkStack<int> list;
    list.push(20);
    list.push(50);
    list.push(73);
    list.push(80);
    list.push(90);
    list.pop();
    list.Display();
    int top=0;
    auto val=list.gettop(top);
    std::cout<<top<<std::endl;
    int y=0;
    list.pop(y);
    std::cout<<y<<std::endl;
    list.Display();
*/
    // Q (test03.exe)
    // Q(task) (test03.exe)
 /*
    Q<int> q(7);
    // Push & Display
    q.push(0);
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.push(7);
    q.display();
    // Pop and display.
    q.pop();
    q.display();
    // Pointer Pop & Dispaly
    int x = 0;
    q.pop(x);
    std::cout << "x = " << x << std::endl;
    q.display();
    // Getting Front.
    std::cout << "Getfront: ";
    q.getfront(x);
    // Circular test
    q.push(8);
    q.pop();
    q.pop();
    q.display();
    q.push(9);
    q.push(10);
    q.display();
    q.push(11);
    q.push(12);
    q.push(13);
    q.display();
*/
    
}