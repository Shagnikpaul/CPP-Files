#include <iostream>
using namespace std;

int stack[50];
int top = -1;
int max_size = 50;


int peek(){
    if(top != -1){
        return stack[top];
    }
    else {
        return -9999;
    }
}


void push(int x)
{
    if (top == (max_size - 1))
    {
        cout << "Overflow !!" << endl;
        return;
    }
    else
    {
        top++;
        stack[top] = x;
    }
}

int pop()
{
    if (top == -1)
    {
        cout << "Stack underflow !!!";
        return -9999;
    }
    int removedElement = stack[top];
    top--;
    return removedElement;
}

void display()
{
    if (top == -1)
    {
        cout << "Stack is empty !! " << endl;
        return;
    }
    for (int i = 0; i <= top; i++)
    {
        cout << stack[i] << ", ";
    }
    cout << endl;
}

int main()
{

    int choice;
    
    cout << "Type 1 to see the stack..." << endl;
    cout << "Type 2 to push an element to the stack..." << endl;
    cout << "Type 3 to pop one element from the stack..." << endl;
    cout << "Type anything else to exit the program..." << endl;
    int flag = 1;
    while (flag)
    {
        cout << "enter your choice : ";
        cin >> choice;
        if (choice == 1)
        {
            display();
        }
        else if (choice == 2)
        {
            cout << "Enter the element you want to insert :";
            int ele;
            cin >> ele;
            push(ele);
        }
        else if (choice == 3)
        {
            int x = pop();
            cout << "removed : " << x << endl;
        }
        else
        {
            flag = 0;
            cout << "Exited the program..." << endl;
        }
    }
}