#include <iostream>

using namespace std;

int main()
{
    string dummy;
    int n;
    cin >> n;
    getline(cin, dummy);
    getline(cin, dummy);
    for (int i = 0; i < n; i++)
    {
        int regs[10] = {0};
        int ram[1000] = {0};
        string adr;
        int j = 0;
        while (getline(cin, adr) && !adr.empty())
        {
            ram[j] = stoi(adr);
            //std::cout << adr << "\n";
            j++;
        }
        int cur = 0;
        int flag = 0;
        int num_is = 0;
        // keep going until reached halt
        while (flag != 1)
        {
            int val = ram[cur];
            //cout << "val" << val;
            if (val == 100)
            {
                flag = 1;
            }
            if (val < 100)
            {
                int s = val % 10;
                int d = (val / 10) % 10;
                if (regs[s] != 0)
                {
                    // -1 because cur will be incremented per iteration
                    cur = regs[d] - 1;
                }
            }
            else if (val > 199 && val < 300)
            {
                int n = val % 10;
                int d = (val / 10) % 10;
                regs[d] = n;
                regs[d] %= 1000;
            }
            else if (val < 400)
            {
                int n = val % 10;
                int d = (val / 10) % 10;
                regs[d] += n;
                regs[d] %= 1000;
            }
            else if (val < 500)
            {
                int n = val % 10;
                int d = (val / 10) % 10;
                regs[d] *= n;
                regs[d] %= 1000;
            }
            else if (val < 600)
            {
                int s = val % 10;
                int d = (val / 10) % 10;
                regs[d] = regs[s];
            }
            else if (val < 700)
            {
                int s = val % 10;
                int d = (val / 10) % 10;
                regs[d] += regs[s];
                regs[d] %= 1000;
            }
            else if (val < 800)
            {
                int s = val % 10;
                int d = (val / 10) % 10;
                regs[d] *= regs[s];
                regs[d] %= 1000;
            }
            else if (val < 900)
            {
                int a = val % 10;
                int d = (val / 10) % 10;
                regs[d] = ram[regs[a]];
                regs[d] %= 1000;
            }
            else if (val < 1000)
            {
                int a = val % 10;
                int s = (val / 10) % 10;
                ram[regs[a]] = regs[s];
            }

            num_is++;
            cur++;
            //std::cout << "cur: " << cur;
            // for (int i = 0; i < 10; i++)
            // {
            //     std::cout << regs[i] << " ";
            // }

            //std::cout << "\n";
        }
        std::cout << num_is << "\n";
        if (i != n - 1)
        {
            cout << "\n";
        }
    }
}