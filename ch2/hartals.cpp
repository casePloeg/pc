#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t; // # of tests
    cin >> t;
    for (int i=0; i<t; i++) {
        int n;
        cin >> n; // number of days in sequence
        int parties;
        cin >> parties; // number of parties
        int intervals [100];
        for (int j=0; j<parties; j++) { 
            int ivn; // read interval for party[i]
            cin >> ivn;
            intervals[j] = ivn;
        }
        int days_missed = 0;
        for (int j=1; j<n+1; j++) {
            if ((j%7) != 0 && (j%7) != 6) {
                for (int k=0; k<parties; k++) {
                    if ((j%intervals[k]) == 0) {
                        days_missed++;
                        break;
                    }
                }
            }
        }
        cout << days_missed << endl;
    }
}