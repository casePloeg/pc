#include <iostream>
#include <array>
using namespace std;

#define NCARDS 52   /* number of cards */
#define NSUITS 4    /* number of suits */
#define NPERSUIT 13 /* number of cards per suit */
#define MAXVAL 12   /* max val a card can have */

/* set up a mapping system from (value,suit) to an unique integer for easier programming */

// objective: reduce the value of poker hand to a single numerical value to make comparisons easier
int rank_card(char value, char suit)
{
    string values = "23456789TJQKA";
    string suits = "CDHS";
    int i, j; /* counters */
    for (i = 0; i < (NCARDS / NSUITS); i++)
    {
        if (values[i] == value)
        {
            for (j = 0; j < NSUITS; j++)
            {
                if (suits[j] == suit)
                {
                    //ex: 0 * 4 + 4 -> 6 of clubs
                    return (i * NSUITS + j);
                }
            }
        }
    }
    return -1;
}

char suit(int card)
{
    string suits = "CDHS";
    return (suits[card % NSUITS]);
}

char value(int card)
{
    string values = "23456789TJQKA";
    return (values[card / NSUITS]);
}

int real_value(int card)
{
    return card / NSUITS;
}

int check_flush(bool flush, std::array<int, 21> score)
{
    int high_card = 0;
    for (int i = 0; i < NPERSUIT; i++)
    {
        if (score[i + 8] != 0)
        {
            high_card = max((MAXVAL - i) + 1, high_card);
        }
    }

    if (flush)
    {
        return high_card;
    }
    return 0;
}

int check_straight(std::array<int, 21> score)
{
    // check for 5 consecutive non zero values
    int consec = 0;
    int high_card = 0;
    for (int i = 0; i < NPERSUIT; i++)
    {
        if (score[i + 8] > 0)
        {
            high_card = max((MAXVAL - i) + 1, high_card);
            consec++;
        }
        else
        {
            consec = 0;
        }
        // if we ever get to 5 consecutive valued cards while checking, return immediately
        if (consec == 5)
        {
            return high_card;
        }
    }
    return 0;
}

int check_straight_flush(bool flush, std::array<int, 21> score)
{
    return min(check_straight(score), check_flush(flush, score));
}

int check_4_of_kind(std::array<int, 21> score)
{
    for (int i = 0; i < NPERSUIT; i++)
    {
        if (score[i + 8] == 4)
        {
            return (MAXVAL - i) + 1;
        }
    }
    return 0;
}

int check_full_house(std::array<int, 21> score)
{
    int triple_card = 0;
    bool triple = false;
    bool pair = false;
    for (int i = 0; i < NPERSUIT; i++)
    {

        if (score[i + 8] == 3)
        {
            triple_card = (MAXVAL - i) + 1;
            triple = true;
        }
        else if (score[i + 8] == 2)
        {
            pair = true;
        }
    }
    if (triple && pair)
    {
        return triple_card;
    }
    return 0;
}

int check_3_of_kind(std::array<int, 21> score)
{
    for (int i = 0; i < NPERSUIT; i++)
    {
        if (score[i + 8] == 3)
        {
            return (MAXVAL - i) + 1;
        }
    }
    return 0;
}

int check_high_pair(std::array<int, 21> score)
{
    int high_pair = 0;
    int num_pairs = 0;
    for (int i = 0; i < NPERSUIT; i++)
    {
        if (score[i + 8] == 2)
        {
            high_pair = max(high_pair, (MAXVAL - i) + 1);
            num_pairs++;
        }
    }
    if (num_pairs == 2)
    {
        return high_pair;
    }
    return 0;
}

int check_low_pair(std::array<int, 21> score)
{
    int low_pair = 0;
    for (int i = 0; i < NPERSUIT; i++)
    {
        if (score[i + 8] == 2)
        {
            low_pair = (MAXVAL - i) + 1;
        }
    }
    return low_pair;
}

void eval_hands(int hands[2][5])
{

    // if all cards in a hand are the same type flushes are possible
    bool flush[2] = {true, true};

    // 8 extra bits to store state on special hand types
    // extra bits have rank val of the value of the relevant card + 1, so that val(2) = 1, not 0
    // bit 0 : straight flush, ranked by highest card in hand
    // bit 1 : 4 of a kind, ranked by value of four cards
    // bit 2 : full house, ranked by value of triple (two hands can't have the same triple)
    // bit 3 : flush, ranked by high card
    // bit 4 : straight, ranked by high card
    // bit 5 : three of a kind, ranked by value of (two hands can't have the same triple)
    // bit 6 : two pairs, ranked by high pair -- but be 2 pairs
    // bit 7 : pair, ranked by (low) pair
    std::array<std::array<int, 21>, 2> scores = {{0}};

    // bits 10 - 22 : represent how many of each card there are, from A to 2
    // A is highest bit
    for (int j = 0; j < 2; j++)
    {
        for (int i = 0; i < 5; i++)
        {

            if (suit(hands[j][i]) != suit(hands[j][0]))
            {
                flush[j] = false;
            }

            scores[j][MAXVAL + 8 - real_value(hands[j][i])] += 1;
        }
    }

    for (int j = 0; j < 2; j++)
    {
        scores[j][0] = check_straight_flush(flush[j], scores[j]);
        scores[j][1] = check_4_of_kind(scores[j]);
        scores[j][2] = check_full_house(scores[j]);
        scores[j][3] = check_flush(flush[j], scores[j]);
        scores[j][4] = check_straight(scores[j]);
        scores[j][5] = check_3_of_kind(scores[j]);
        scores[j][6] = check_high_pair(scores[j]);
        scores[j][7] = check_low_pair(scores[j]);
    }

    // cout << "black: ";
    // for (int i=0; i<21; i++) {
    //     cout << scores[0][i] << " ";
    // }
    // cout << endl;
    // cout << "white: ";
    // for (int i=0; i<21; i++) {
    //     cout << scores[1][i] << " ";
    // }
    // cout << endl;
    // cout << "flush b: " << flush[0];
    // cout << " flush w: " << flush[1] << endl;

    // compare numbers
    int winner = -1;
    for (int i = 0; i < 21; i++)
    {
        if (scores[0][i] > scores[1][i])
        {
            winner = 0;
            break;
        }
        else if (scores[0][i] < scores[1][i])
        {
            winner = 1;
            break;
        }
    }
    if (winner == -1)
    {
        std::cout << "Tie." << endl;
    }
    else if (winner == 0)
    {
        std::cout << "Black wins." << endl;
    }
    else if (winner == 1)
    {
        std::cout << "White wins." << endl;
    }
}

int main()
{
    // holds integer representations of player hands
    int hands[2][5];
    string line;
    // potentially more reliable input
    while (getline(cin, line) && !line.empty())
    {
        char value, suit;
        int card = 0;
        for (int i = 0; i < 30; i += 3)
        {
            value = line[i];
            suit = line[i + 1];
            int player = card / 5;
            int card_num = card % 5;
            hands[player][card_num] = rank_card(value, suit);
            card++;
        }
        eval_hands(hands);
    }
}