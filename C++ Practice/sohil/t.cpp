#include <iostream>
using namespace std;

// Base class Animal
class Animal {
public:
    void eat() {
        cout << "Animal is eating.\n";
    }
};

// Base class Bird, inheriting from Animal
class Bird : public Animal {
public:
    void fly() {
        cout << "Bird is flying.\n";
    }
};

// Base class Mammal, inheriting from Animal
class Mammal : public Animal {
public:
    void run() {
        cout << "Mammal is running.\n";
    }
};

// Derived class Bat, inheriting from both Bird and Mammal
class Bat : public Bird, public Mammal {
public:
    void flap() {
        cout << "Bat is flapping.\n";
    }
};

int main() {
    Bat bat;
    //bat.eat(); // This is ambiguous because Bat has two paths to Animal
    bat.Bird::eat(); // Calls the eat() function from Bird
    bat.fly();
    bat.run();
    bat.flap();
    return 0;
}