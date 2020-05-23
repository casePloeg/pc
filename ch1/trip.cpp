#include <iostream>
#include <iomanip>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    while (cin >> n && n != 0)
    {
        double expenses[1000];
        double total = 0.00;
        double exchanged = 0.00;
        for (int i = 0; i < n; i++)
        {
            double i_exp;
            cin >> i_exp;
            total += i_exp;
            expenses[i] = i_exp;
        }

        double split = total / n;
        double more = 0.00;
        double less = 0.00;

        for (int i = 0; i < n; i++)
        {
            if (split - expenses[i] > 0.01)
            {
                less += floor(split * 100) / 100 - expenses[i];
            }
            else if (expenses[i] - split > 0.01)
            {
                more += expenses[i] - ceil(split * 100) / 100;
            }
        }

        // set so that output has to be in the set precision (min==max)
        std::cout.setf(std::ios::fixed, std::ios::floatfield);
        cout << setprecision(2) << "$" << max(less, more) << "\n";
    }
}