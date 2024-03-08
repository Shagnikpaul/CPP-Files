#include <iostream>

using namespace std;







class ABC
{
public:
	int i;

public:
    ABC(int id)
    {
        i = id;
    }

public:
    ~ABC()
    {
        cout << "BYE BYE 🗣️🗣️🗣️🗣️🗣️🗣️";
    }
	// destructor cannot be overloaded !!!
};

int main()
{
    ABC c(6);
	return 0;
}
