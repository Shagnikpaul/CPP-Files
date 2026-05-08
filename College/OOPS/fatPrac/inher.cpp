#include <iostream>
using namespace std;
class Shape
{
public:
    double getArea() { return 0; }
};

Shape::Shape()
{
    cout << "joe";
}

class Color
{
public:
    string getColor() { return "none"; }
};
class Square : public Shape, public Color
{
private:
    double side;

public:
    Square(double s) : side(s) {}
    double getArea() { return side * side; }
    string getColor() { return "red"; }
};

int main()
{
    Square s(2.9);
    s.Color::getColor();
}