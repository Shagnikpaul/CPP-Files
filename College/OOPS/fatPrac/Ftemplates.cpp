#include <iostream>
using namespace std;

template <class T>
class Box
{
    T b;

public:
    Box(T q);
    Box doSom(T q);
};

template <class T>
Box<T>::Box(T q)
{
    b = q;
}

template <class Z>
Box<Z> Box<Z>::doSom(Z q)
{
    return Box<Z>(q);
}

template <class T>
class ArOps
{
    T *arr;
    int s;

public:
    ArOps(T ar[], int ss)
    {
        arr = new T[ss];
        this->s = ss;
        for (int i = 0; i < ss; i++)
        {
            this->arr[i] = ar[i];
        }
    }

    T sum()
    {
        T sum = 0;
        for (int i = 0; i < this->s; i++)
        {
            sum += this->arr[i];
        }
        return sum;
    }
};

template <class T>
class Test
{
protected:
    T data;

public:
    Test(T x)
    {
        this->data = x;
    }

    T getData()
    {
        return data;
    }
};

template <class T>
void doSum(T a, T b)
{
    cout << "Sum  = " << (a + b) << endl;
}

template <typename T>
void doswap(T &a, T &b)
{
    T t = a;
    a = b;
    b = t;
}

template <class T, class X>
void printO(T x, X y)
{
    cout << x << ", " << y << endl;
}

template <class T>
void display(T x)
{
    cout << "Template display: " << x << "\n";
}

void display()
{
    cout << "Explicitly display:" << "\n";
}

void display(int x)
{
    cout << "Int display: " << x << "\n";
}

int main()
{
    doSum(3, 4);
    doSum(3.4, 4.5);
    int a = 3;
    int b = 5;
    cout << "before swap : " << a << " " << b << endl;
    doswap(a, b);
    cout << "after swap : " << a << " " << b << endl;
    printO(5.6, "Hellor bro");
    display(4.0);

    Test<int> t(6);
    Test<string> te("Helo");

    cout << t.getData() << endl;
    cout << te.getData() << endl;

    int k[] = {1, 2, 4};
    ArOps<int> ar(k, 3);
    cout << "sum = " << ar.sum() << endl;

    float l[] = {1.4, 2.7, 4.0};
    ArOps<float> ar2(l, 3);
    cout << "sum = " << ar2.sum() << endl;
}