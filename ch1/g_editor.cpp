#include <iostream>
#include <vector>
#include <array>

using namespace std;

int main()
{
    char img[250][250];
    string cmd;
    int m;
    int n;
    while (cin >> cmd && cmd.compare("X") != 0)
    {
        if (cmd[0] == 'I')
        {
            cin >> m >> n;
            for (int i = 0; i < 250; i++)
            {
                for (int j = 0; j < 250; j++)
                {
                    img[i][j] = 'O';
                }
            }
        }
        else if (cmd[0] == 'C')
        {
            //cout << "C";
            for (int i = 0; i < 250; i++)
            {
                for (int j = 0; j < 250; j++)
                {
                    img[i][j] = 'O';
                }
            }
        }
        else if (cmd[0] == 'L')
        {
            //cout << "L";
            int x, y;
            cin >> x >> y;
            char c;
            cin >> c;
            img[y - 1][x - 1] = c;
        }
        else if (cmd[0] == 'V')
        {
            //cout << "V";
            int x, y1, y2;
            cin >> x >> y1 >> y2;
            char c;
            cin >> c;
            int s = min(y1, y2) - 1;
            int t = max(y1, y2) - 1;
            for (int i = s; i < t + 1; i++)
            {
                img[i][x - 1] = c;
            }
        }
        else if (cmd[0] == 'H')
        {
            //cout << "H";

            int x1, x2, y;
            cin >> x1 >> x2 >> y;
            char c;
            cin >> c;
            int s = min(x1, x2) - 1;
            int t = max(x1, x2) - 1;
            for (int i = s; i < t + 1; i++)
            {
                img[y - 1][i] = c;
            }
        }
        else if (cmd[0] == 'K')
        {
            //cout << "K";
            int x1, x2, y1, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            char c;
            cin >> c;
            int sx = min(x1, x2) - 1;
            int tx = max(x1, x2) - 1;
            int sy = min(y1, y2) - 1;
            int ty = max(y1, y2) - 1;
            for (int i = sx; i < tx + 1; i++)
            {
                for (int j = sy; j < ty + 1; j++)
                {
                    img[j][i] = c;
                }
            }
        }
        else if (cmd[0] == 'F')
        {
            //cout << "F";
            vector<array<int, 2>> pixs;
            // make sure to initialize to 0
            int visited[250][250] = {{0}};

            int x, y;
            cin >> x >> y;
            char c;
            cin >> c;
            pixs.push_back({(y - 1), (x - 1)});
            while (pixs.size() > 0)
            {
                int i, j;
                i = pixs.back()[0];
                j = pixs.back()[1];
                pixs.pop_back();
                // check for flood

                if (i > 0 && img[i][j] == img[i - 1][j] && visited[i - 1][j] != 1)
                {
                    pixs.push_back({i - 1, j});
                    visited[i - 1][j] = 1;
                }
                if (i < (n - 1) && img[i][j] == img[i + 1][j] && visited[i + 1][j] != 1)
                {
                    pixs.push_back({i + 1, j});
                    visited[i + 1][j] = 1;
                }
                if (j > 0 && img[i][j] == img[i][j - 1] && visited[i][j - 1] != 1)
                {
                    pixs.push_back({i, j - 1});
                    visited[i][j - 1] = 1;
                }
                if (j < (m - 1) && img[i][j] == img[i][j + 1] && visited[i][j + 1] != 1)
                {
                    pixs.push_back({i, j + 1});
                    visited[i][j + 1] = 1;
                }

                //set cur pix to new color
                img[i][j] = c;
            }
        }
        else if (cmd[0] == 'S')
        {
            string name;
            cin >> name;
            cout << name << "\n";

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    cout << img[i][j];
                }
                cout << "\n";
            }
        }
        else
        {
            string waste;
            getline(cin, waste);
        }
    }
}