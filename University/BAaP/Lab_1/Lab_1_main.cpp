#include <iostream>
#include <math.h>


using namespace std;

int lab_1()
{
    int choice = 1;
    double x;
    double y;
    double z;
    double s = 1.0;

    while (true)
    {
        if (choice == 1)
        {
            x = 0.03981;
            y = -1625;
            z = 0.512;
        }
        else if (choice == 2)
        {
            cout << "Write X variable" << endl;
            cin >> x;

            cout << "Write Y variable" << endl;
            cin >> y;

            cout << "Write Z variable" << endl;
            cin >> z;

        }
        else
        {
            cin.clear();
            cin.ignore(256, '\n');
            continue;
        }
        break;
    }

    s = pow(2, -x) * sqrt(x + pow(fabs(y), 1 / 4.)) * pow(exp(x - 1 / sin(z)), static_cast<double>(1) / 3);

    cout << "Result: " << s << endl;

    return 0;
}