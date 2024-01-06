#include <iostream>
#include <Windows.h>
using namespace std;

void gotoxy(int i, int j)
{
    COORD c = { i, j };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

int main()
{
    int rows;
    char a;
    cout << "Enter number of secounds : ";
    cin >> rows;
    cout << "Enter any character to represent sand : ";
    cin >> a;
    cout << endl;

    for (int i = 1; i <= rows; i++)                                         // prints upper hollow triangle.
    {
        for (int j = 1; j < i; j++)
        {
            cout << " ";
        }

        for (int j = 1; j <= (rows * 2 - (2 * i - 1)); j++)
        {
            /*
                   * Print star for first row(i==1),
                   * ith column (j==1) and for
                   * last column (rows*2-(2*i-1))
              */

            if (i == 1 || j == 1 || j == (rows * 2 - (2 * i - 1)))
            {
                cout << "-";
            }
            else
            {
                cout << a;
            }
        }
        cout << endl;
    }

    for (int i = 1; i <= rows; i++)                                          // prints lower hollow triangle
    {
        for (int j = i; j < rows; j++)
        {
            cout << " ";
        }

        for (int j = 1; j <= (2 * i - 1); j++)
        {
            /*
                 * Print star for last row (i==rows),
                 * first column(j==1) and for
                 * last column (j==(2*i-1)).
            */
            if (i == rows || j == 1 || j == (2 * i - 1))
            {
                cout << "-";
            }

            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }


    int n = (rows * 2) - 6, x1 = 2, y1 = 4, x2 = 2, y2 = (rows * 2) + 2, count = 1, k = 1;

    while (k < rows)
    {
        Sleep(1000);

        gotoxy(x1, y1);                                  // to control the movement of upper triangle.
        for (int i = 0; i <= n; i++)
        {
            cout << " ";
        }

        gotoxy(x2, y2);                                 // to control the movement of lower triangle.
        for (int i = 0; i <= n; i++)
        {
            cout << a;
        }

        n = n - 2;
        x1++;
        y1++;                                          // y1 is increasing to move downward.
        x2++;
        y2--;                                          // y2 is decreasing to move upward.
        count++;
        k++;
    }
    cout << endl;
    gotoxy(1, 28);                                   // To control the cursor of ending line.

    system("pause");
    return 0;
}