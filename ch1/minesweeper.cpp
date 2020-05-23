#include <iostream>

using namespace std;
int num_nbrs(string arr[], int i, int j, int n, int m)
{
    int res = 0;
    int possible[8][2] = {
        {1, 0},
        {-1, 0},
        {0, 1},
        {0, -1},
        {1, 1},
        {-1, -1},
        {1, -1},
        {-1, 1}};
    for (int k = 0; k < 8; k++)
    {
        int x = i + possible[k][0];
        int y = j + possible[k][1];
        //cout << x << " " << y;
        if (x > -1 && x < n && y > -1 && y < m && arr[x][y] == '*')
        {
            res++;
        }
    }

    return res;
}

int main()
{
    int n, m;
    int f = 0;
    cin >> n >> m;
    while (n + m != 0)
    {
        f++;
        int arr[100][100];
        string str[100];
        for (int i = 0; i < n; i++)
        {
            cin >> str[i];
        }
        cout << "Field #" << f << ":" << endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (str[i][j] == '*')
                {
                    cout << '*';
                }
                else
                {
                    int num = num_nbrs(str, i, j, n, m);
                    cout << num;
                }
            }
            cout << endl;
        }
        cin >> n >> m;
        if (n + m != 0)
        {
            cout << endl;
        }
    }
}