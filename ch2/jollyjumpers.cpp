#include <iostream>
#include <set>

using namespace std;

int main() {
    int n; // number of integers
    
    while (cin>>n) {
        set<int> difs;
        //cout << "n: " << n << endl;
        int prev;
        int cur;
        cin>>prev;
        // add the differences to a set
        // minus one here bc already read in one int to set prev
        // might be a problem if n is 0
        for (int i=0; i<n-1; i++){
            cin>>cur;
            int dif = abs(cur-prev);
            difs.insert(dif);
            prev = cur;
        }
        //cout << "cur: " << cur << endl;
        bool jolly = true;
        // check if each value from 1 to n-1 is in the set
        // (could have just used an array here, n is fixed size)
        for (int i=1; i<n; i++) {
            auto search = difs.find(i);
            if (search == difs.end()) {
                jolly = false;
                break;
            }
        }
        if (jolly) {
            cout << "Jolly\n";
        } else {
            cout << "Not jolly\n";
        }
    }
}