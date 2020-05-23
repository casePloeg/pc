#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

const vector<string> explode(const string &s, const char &c)
{
    string buff{""};
    vector<string> v;

    for (auto n : s)
    {
        if (n != c)
            buff += n;
        else if (n == c && buff != "")
        {
            v.push_back(buff);
            buff = "";
        }
    }
    if (buff != "")
        v.push_back(buff);

    return v;
}

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        string dummy;
        getline(cin, dummy);
        int votes[20] = {0};
        vector<string> pref_list;
        string candidates[20];
        int evicted[20] = {0};
        int num_left = n;
        int total = 0;

        for (int j = 0; j < n; j++)
        {
            string cand;
            getline(cin, cand);
            candidates[j] = cand;
            //std::cout << cand;
        }

        string v;
        while (getline(cin, v) && !v.empty())
        {
            //cout << v << endl;
            // calculate votes
            pref_list.push_back(v);
            vector<string> prefs = explode(v, ' ');
            int voted = 0;
            for (int j = 0; j < n; j++)
            {
                string c = prefs[j];
                //cout << c << " ";
                int idx = stoi(c) - 1;
                //cout << idx << endl;
                if (voted != 1 && evicted[idx] == 0)
                {
                    votes[idx] += 1;
                    total += 1;
                    voted = 1;
                }
            }
        }
        //cout << "total: " << total << endl;
        int winner = 0;
        vector<int> maxs;
        vector<int> mins;
        while (winner != 1)
        {
            maxs.clear();
            int max_ = 0;
            // get indicies of max values in votes
            for (int j = 0; j < n; j++)
            {
                if (evicted[j] != 1 && votes[j] > max_)
                {
                    max_ = votes[j];
                    maxs.clear();
                    maxs.push_back(j);
                }
                else if (votes[j] == max_)
                {
                    maxs.push_back(j);
                }
            }
            // get indicies of min values in votes and set to evicted
            mins.clear();
            int min_ = 1001;
            //cout << max_ << endl;
            for (int j = 0; j < n; j++)
            {
                //cout << votes[j] << " " << min_;
                if (evicted[j] != 1 && votes[j] < min_)
                {

                    min_ = votes[j];
                    mins.clear();
                    mins.push_back(j);
                }
                else if (votes[j] == min_)
                {
                    mins.push_back(j);
                }
            }
            // check if over 50% or everyone tied
            if ((double)max_ > ((double)total / 2) || maxs.size() == num_left)
            {
                winner = 1;
            }
            else
            {
                for (int j : mins)
                {
                    num_left -= 1;
                    evicted[j] = 1;
                }

                // calculate votes again
                for (int j = 0; j < 20; j++)
                {
                    votes[j] = 0;
                }
                for (string v : pref_list)
                {
                    vector<string> prefs = explode(v, ' ');
                    int voted = 0;
                    for (int j = 0; j < n; j++)
                    {
                        string c = prefs[j];
                        int idx = stoi(c) - 1;
                        if (voted != 1 && evicted[idx] == 0)
                        {
                            votes[idx] += 1;
                            voted = 1;
                        }
                    }
                }
            }
            //std::cout << max_ << " " << min_ << endl;
        }

        for (int j : maxs)
        {
            //std::cout << j;
            std::cout << candidates[j] << "\n";
        }

        if (i != t - 1)
        {
            std::cout << "\n";
        }
    }
}