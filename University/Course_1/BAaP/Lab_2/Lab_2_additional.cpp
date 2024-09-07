#include <iostream>

using namespace std;

int main()
{
    double a;
    double b;
    double c;

    double max;
    double min;

    cout << "Enter A" << endl;
    cin >> a;
    cout << "Enter B" << endl;
    cin >> b;
    cout << "Enter C" << endl;
    cin >> c;

    max = a > b ? (a > c ? a : c) : (b > c ? b : c);
    min = a < b ? (a < c ? a : c) : (b < c ? b : c);

   /* if (a > b)
    {
        if (a > c)
            max = a;
        else
            max = c;
    }
    else
    {
        if (b > c)
            max = b;
        else
            max = c;
    }

    if (a < b)
    {
        if (a < c)
            min = a;
        else
            min = c;
    }
    else
    {
        if (b < c)
            min = b;
        else
            min = c;
    }*/

    cout << "Max - Min = " << max << "-" << min << "=" << max - min << endl;
 }

