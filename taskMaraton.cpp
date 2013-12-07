#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    char data[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> data[i][j];
        }
    }

    //check row
    char win = (char) 0;
    for (int row = 0; row < n; row++)
    {
        char curchar = data[row][0];
        if (curchar == '.')
            continue;
        int samecnt = 0;
        for (int col = 0; col < n; col++)
        {
            if (curchar == data[row][col])
                samecnt++;
        }
        if (samecnt == n)
        {
            cout << curchar << endl;
            return 0;
        }
    }
    //check column
    for (int col = 0; col< n; col++)
    {
        char curchar = data[col][0];
        if (curchar == '.')
            continue;
        int samecnt = 0;
        for (int row = 0; row < n; row++)
        {
            if (curchar == data[row][col])
                samecnt++;
        }
        if (samecnt == n)
        {
            cout << curchar << endl;
            return 0;
        }
    }
    //check diagnol left
    for (int row = 0; row < n; row++)
    {
        for (int col = 2; col < n; col++)
        {
            char curchar = data[row][col];
            if (curchar == '.')
                continue;
            int samecnt = 0;
            for (int i = 1; i < 3; i++)
            {
                if (curchar = data[row-i][col-i])
                    samecnt ++;
            }

            if (samecnt == n)
            {
                cout << row << " " << col << endl;
                cout << curchar << endl;
                return 0;
            }
        }
    }

    //check diagnol right
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n-2; col++)
        {
            char curchar = data[row][col];
            if (curchar == '.')
                continue;
            int samecnt = 0;
            for (int i = 1; i < 3; i++)
            {
                if (curchar = data[row-i][col+i])
                    samecnt ++;
            }

            if (samecnt == n)
            {
                cout << curchar << endl;
                return 0;
            }
        }
    }
    cout << "ongoing" << endl;
}
