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



int main()
{
    string s = "A*(B+C)-D/E";
}