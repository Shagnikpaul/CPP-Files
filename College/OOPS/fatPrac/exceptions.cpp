#include <iostream>
using namespace std;

class NegativeRadiusException
{
public:
    int radius;
    NegativeRadiusException(int r)
    {
        this->radius = r;
    }
};

int main()
{
    int n = -1;
    try
    {
        // if (n < 0)
        // {
        //     throw "bruh";
        // }

        if (n < 0)
        {
            throw NegativeRadiusException(4);
        }
    }

    catch (NegativeRadiusException r)
    {
        cout << "Radius given " << r.radius;
    }
    catch (int k)
    {
        cout << "Numerial eroor " << k << endl;
    }

    catch (const char *msg)
    {
        cout << msg << " NOOOOOOOOOOOOOOOOOOO" << endl;
    }

    catch (...)
    {
        cout << "None";
    }
}