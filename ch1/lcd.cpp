#include <iostream>

using namespace std;

int main()
{
    int s;
    string n;
    string nums[10][5] = {
        {
            {' ', '-', ' '},
            {'|', ' ', '|'},
            {' ', ' ', ' '},
            {'|', ' ', '|'},
            {' ', '-', ' '},
        },
        {
            {' ', ' ', ' '},
            {' ', ' ', '|'},
            {' ', ' ', ' '},
            {' ', ' ', '|'},
            {' ', ' ', ' '},
        },
        {
            {' ', '-', ' '},
            {' ', ' ', '|'},
            {' ', '-', ' '},
            {'|', ' ', ' '},
            {' ', '-', ' '},
        },
        {
            {' ', '-', ' '},
            {' ', ' ', '|'},
            {' ', '-', ' '},
            {' ', ' ', '|'},
            {' ', '-', ' '},
        },
        {
            {' ', ' ', ' '},
            {'|', ' ', '|'},
            {' ', '-', ' '},
            {' ', ' ', '|'},
            {' ', ' ', ' '},
        },
        {
            {' ', '-', ' '},
            {'|', ' ', ' '},
            {' ', '-', ' '},
            {' ', ' ', '|'},
            {' ', '-', ' '},
        },
        {
            {' ', '-', ' '},
            {'|', ' ', ' '},
            {' ', '-', ' '},
            {'|', ' ', '|'},
            {' ', '-', ' '},
        },
        {
            {' ', '-', ' '},
            {' ', ' ', '|'},
            {' ', ' ', ' '},
            {' ', ' ', '|'},
            {' ', ' ', ' '},
        },
        {
            {' ', '-', ' '},
            {'|', ' ', '|'},
            {' ', '-', ' '},
            {'|', ' ', '|'},
            {' ', '-', ' '},
        },
        {
            {' ', '-', ' '},
            {'|', ' ', '|'},
            {' ', '-', ' '},
            {' ', ' ', '|'},
            {' ', '-', ' '},
        }};

    while (cin >> s >> n && s != 0)
    {
        int len = n.length();
        int repeat = 0;
        int j = 0;
        while (j < 5)
        {
            int repp = 0;
            for (int i = 0; i < len; i++)
            {
                int dig = (int)(n[i] - '0');

                for (int k = 0; k < 3; k++)
                {
                    if (nums[dig][j][k] != '|')
                    {
                        if (k == 1)
                        {
                            for (int f = 0; f < s; f++)
                            {
                                cout << nums[dig][j][k];
                            }
                        }
                        else
                        {
                            cout << nums[dig][j][k];
                        }
                    }
                    else
                    {
                        cout << nums[dig][j][k];

                        //cout << repeat << repeat % s;
                        repp = 1;
                    }
                }
                // add space after number except for the last one
                if (i < len - 1)
                {
                    cout << " ";
                }
            }
            // found a character that needs to be repeated
            if (repp == 1)
            {
                repeat += 1;
                repeat %= s;
            }
            if (repeat != 0)
            {
                j -= 1;
            }
            cout << "\n";
            j++;
        }
        cout << "\n";
    }
}