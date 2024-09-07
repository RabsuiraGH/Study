#include <iostream>
#include <string>

using namespace std;

template <typename T> T SafeInput(const string& inputMessage, const string& errorMessage)
{
    T tempValue;

    while (true)
    {
        cout << inputMessage << endl;

        if (!(cin >> tempValue) || (cin.peek() != '\n'))
        {
            cout << errorMessage << endl << "Restarting process" << endl << endl;
            cin.ignore(1000, '\n');
            cin.clear();
            continue;
        }
        return tempValue;
    }
};

int main()
{
#pragma region VARIABLES

    int R = 0, C = 0;
    int maxInColumnRowIndex;
    bool minInRow;

#pragma endregion
    
#pragma region MATRIX CREATION

    cout << "Input size N (columns): ";
    cin >> C;
    cout << "Input size M (rows): ";
    cin >> R;

    // init matrix
    double** matrix = new double* [C];
    for (int i = 0; i < R; i++) matrix[i] = new double[C];

    cout << "Inpuut matrix elements:" << endl;

    // matrix input
    for (int i = 0; i < R; ++i)
    {
        for (int j = 0; j < C; ++j)
        {
            matrix[i][j] = SafeInput<double>("Input array element [" + to_string(i) + "][" + to_string(j) + "]", "Value should be number");
        }
        cout << endl;
    }

    // matrix output
    for (int i = 0; i < R; ++i)
    {
        for (int j = 0; j < C; ++j)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
#pragma endregion

#pragma region SEARCHING ALGORITHM

    for (int col = 0; col < C; col++)
    {
        // search for max in colum element
        maxInColumnRowIndex = 0;
        for (int row = 0; row < R; row++)
        {
            if (matrix[row][col] > matrix[maxInColumnRowIndex][col])
                maxInColumnRowIndex = row;
        }

        minInRow = true;

        // checking if this element is min in row
        for (int col_1 = 0; col_1 < C; col_1++)
        {
            if (col_1 != col && matrix[maxInColumnRowIndex][col_1] <= matrix[maxInColumnRowIndex][col])
            {
                minInRow = false;
                break;
            }
        }

        if (minInRow)
            cout << "Gratz " << matrix[maxInColumnRowIndex][col] << " is right. Position: " << maxInColumnRowIndex << " " << col << endl;
    }

#pragma endregion

#pragma region CLEARING MEMORY

    // deleting instances of matrix 
    for (int i = 0; i < R; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;

#pragma endregion

    return 0;
}
