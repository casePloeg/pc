#include <iostream>

using namespace std;

int cycles(int num)
{
    if (num == 0)
    {
        return 0;
    }
    int res = 1;
    while (num > 1)
    {
        if (num % 2 == 0)
        {
            num = num / 2;
        }
        else
        {
            num = num * 3 + 1;
        }
        res++;
    }
    return res;
}

int main()
{
    int i, j;

    while (cin >> i >> j)
    {
        int max = 0;
        int s;
        int t;
        if (i < j)
        {
            s = i;
            t = j;
        }
        else
        {
            s = j;
            t = i;
        }
        int cur = s;
        while (cur <= t)
        {
            // find cycle number
            int c = cycles(cur);
            if (c > max)
            {
                max = c;
            }
            cur++;
        }
        cout << i << " " << j << " " << max << endl;
    }
}
