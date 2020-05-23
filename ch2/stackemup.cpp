#include <iostream>
#include <sstream>
#include <array>

using namespace std;

int main() {
    int t;
    string line;
    getline(cin, line);
    t = stoi(line);
    getline(cin,line);

    for (int i=0; i<t; i++) {
        // array of possible shuffles the dealer knows
        int shuffles [100][52] = {{0}};
        
        int n;
        getline(cin, line);
        n = stoi(line); // number of shuffles
        for (int j=0; j<n; j++) {
            // getline(cin, line);
            // string buf;
            // std:stringstream ss(line);
            int pos;
            for (int k=0; k<52; k++) {
                cin >> pos;
                // convert to zero index
                shuffles[j][k] = pos - 1;
            }
        }


        // for (int j=0; j<n; j++) {
        //     for (int k=0; k<52; k++) {
        //         cout << shuffles[j][k] << " ";
        //     }
        //     cout << endl;
        // }

        getline(cin,line);
        array<int, 52> deck = {0};
        for (int j=0; j<52; j++) {
            deck[j] = j;
        }

        // for (int j=0; j<52; j++) {
        //     cout << deck[j] << " ";
        // }
        // cout << endl;

        while(getline(cin, line) && line.compare("") != 0) {
            int sh = stoi(line) - 1;
            array<int, 52> tmp_deck = {0};
            for (int j=0; j<52; j++) {
                tmp_deck[j] = deck[shuffles[sh][j]];
            }
            deck = tmp_deck;
        }
        string values [13] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"};
        string suits [4] = {"Clubs", "Diamonds", "Hearts", "Spades"};
        for (int j=0; j<52; j++) {
            string val, suit;
            val = values[deck[j]%13];
            suit = suits[deck[j]/13];
            cout << val << " of " << suit << endl;
        }
        if (i != t-1){
            cout << endl;
        }
    }
}