#include <iostream>
#include <queue>

#define NCARDS 52 /* number of cards */
#define NSUITS 4  /* number of suits */
#define MAXSTEPS 100 /* max steps a war game can take before tieing */

char values[] = "23456789TJQKA";
char suits[] = "cdhs";

using namespace std;

/* set up a mapping system from (value,suit) to an unique integer for easier programming */

int rank_card(char value, char suit) {
    int i,j; /* counters */
    for (i=0; i< (NCARDS/NSUITS); i++){
        if (values[i] == value) {
            for (j=0; j<NSUITS; j++){
                if (suits[j] == suit){
                    //ex: 0 * 13 + 4 -> 6 of clubs
                    return (i * NSUITS + j);
                }
            }
        }
    }
}

char suit(int card) {
    return ( suits[card % NSUITS]);
}

char value(int card) {
    return (values[card / NSUITS]);
}

int real_value(int card) {
    return card / NSUITS;
}

// pass by reference to make parameter mutable
void clear_queue(queue<int>& a, queue<int>& b) {
    while (!a.empty()) {
        b.push(a.front());
        a.pop();
    } 
}

void war (queue<int> a, queue<int> b) {
    // step counter
    int steps = 0;
    // top cards
    int x,y;
    // cards involved in the war
    queue<int> c;
    // are we involved in a war
    bool inwar;

    inwar = false;
    
    while((!a.empty()) && (!b.empty() && (steps < MAXSTEPS))) {
        cout << "size a " << a.size() << " size b " << b.size() << endl;
        steps++;
        x = a.front();
        a.pop();
        y = b.front();
        b.pop();
        c.push(x);
        c.push(y);
        if (inwar) {
            // in we were in war, we just put the cards in the queue and continue, (these are the face down cards)
            inwar = false;
        } else {
            cout << value(x) << " vs. " << value(y) << endl;
            if (real_value(x) > real_value(y))
                clear_queue(c,a);
            else if (real_value(x) < real_value(y))
                clear_queue(c, b);
            else if (real_value(y) == real_value(x))
                inwar = true;
        }
    }

    cout << "size a " << a.size() << " size b " << b.size() << endl;
    if (!a.empty() && b.empty()) {
        cout << "a wins in " << steps << " steps\n";
    } else if (a.empty() && !b.empty()) {
        cout << "b wins in " << steps << " steps\n";
    } else {
         cout << "game tied in " << steps << " steps\n";
    }
}


int main()
{
    queue<int> decks[2]; /* player's decks */
    char value,suit,c;   /* input characters */
    int i;               /* deck counter */

    bool flag = false;
    while (!flag) {
        // iterate decks to avoid duplication
        for (i=0; i<=1; i++) {
            while ((c = getchar()) && c != '\n') {
                if (c == EOF) {
                    
                    flag = true;
                    break;
                }
                if (c != ' ') {
                    value = c;
                    suit = getchar();
                    // debugging input reading
                    cout << i << " " << value << " " << suit << endl;
                    decks[i].push(rank_card(value, suit));
                }
            }
        }
        if (!flag) {
            war(decks[0], decks[1]);
        }

        

    }
}