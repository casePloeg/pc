import sys

NCARDS = 52
NSUITS = 4
NPERSUIT = 13
MAXVAL = 12

def rank_card(value, suit):
    values = "23456789TJQKA"
    suits = "CDHS"
    for i in range(NCARDS//NSUITS):
        if (values[i] == value):
            for j in range(NSUITS):
                if (suits[j] == suit):
                    return j * NSUITS + i
    return -1

def get_suit(card):
    suits = "CDHS"
    return suits[card % NSUITS]

def value(card):
    values = "23456789TJQKA"
    return values[card // NSUITS]

def real_value(card):
    # print(card, NSUITS)
    return card // NSUITS


def check_flush(flush, score):
    high_card = 0
    for i in range(NPERSUIT):
        if (score[i+8] != 0):
            high_card = max((MAXVAL - i) + 1, high_card)
    if flush:
        return high_card
    return 0

def check_straight(score):
    # check for 5 consecutive non zero values
    consec = 0
    high_card = 0
    for i in range(NPERSUIT):
        if (score[i+8] != 0):
            high_card = max((MAXVAL - i) + 1, high_card)
            consec += 1
        else:
            consec = 0
        # if we ever get to 5 consecutive valued cards while checking, return immediately
        if (consec == 5):
            return high_card
    return 0


def check_straight_flush(flush, score):
    return min(check_straight(score), check_flush(flush, score))


def check_4_of_kind(score):
    for i in range(NPERSUIT):
        if (score[i+8] == 4):
            return (MAXVAL - i) + 1
    return 0


def check_full_house(score):
    high_card = 0
    triple = False
    pair = False
    for i in range(NPERSUIT):  
        if (score[i+8] != 0):
            high_card = max((MAXVAL - i) + 1, high_card)
        
        
        if (score[i+8] == 3):
            triple = True
        elif (score[i+8] == 2):
            pair = True
    if (triple and pair): 
        return high_card
    return 0


def check_3_of_kind(score):
    for i in range(NPERSUIT):
        if (score[i+8] == 3):
            return (MAXVAL - i) + 1
    return 0


def check_high_pair(score):
    high_pair = 0
    num_pairs = 0
    for i in range(NPERSUIT):
        if (score[i+8] == 2):
            high_pair = max(high_pair, (MAXVAL - i) + 1)
            num_pairs += 1
    if (num_pairs == 2):
        return high_pair
    return 0


def check_low_pair(score):
    low_pair = 0
    for i in range(NPERSUIT):
        if (score[i+8] == 2):
            low_pair = (MAXVAL - i) + 1
    return low_pair

def eval_hands(hands):
    # if all cards in a hand are the same type flushes are possible
    flush = [True, True]

    # 8 extra bits to store state on special hand types
    # extra bits have rank val of the value of the relevant card + 1, so that val(2) = 1, not 0
    # bit 0 : straight flush, ranked by highest card in hand
    # bit 1 : 4 of a kind, ranked by value of four cards
    # bit 2 : full house, ranked by value of triple (two hands can't have the same triple)
    # bit 3 : flush, ranked by high card
    # bit 4 : straight, ranked by high card
    # bit 5 : three of a kind, ranked by value of (two hands can't have the same triple)
    # bit 6 : two pairs, ranked by high pair -- but be 2 pairs
    # bit 7 : pair, ranked by (low) pair

    scores = [[0 for i in range(21)] for j in range(2)]
    # bits 10 - 22 : represent how many of each card there are, from A to 2
    # A is highest bit
    for j in range(2):
        for i in range(5):
            #print(get_suit(hands[j][i]))
            if (get_suit(hands[j][i]) != get_suit(hands[j][0])):
                flush[j] = False
            # print(MAXVAL + 8 - real_value(hands[j][i]))
            scores[j][MAXVAL + 8 - real_value(hands[j][i])] += 1
    
    
    for j in range(2):
        # print(scores[j])
        scores[j][0] = check_straight_flush(flush[j], scores[j])
        scores[j][1] = check_4_of_kind(scores[j])
        scores[j][2] = check_full_house(scores[j])
        scores[j][3] = check_flush(flush[j], scores[j])
        scores[j][4] = check_straight(scores[j])
        scores[j][5] = check_3_of_kind(scores[j])
        scores[j][6] = check_high_pair(scores[j])
        scores[j][7] = check_low_pair(scores[j])


    # print("black", end= " ")
    # for i in range(21):
    #     print(scores[0][i], end=" ")
    # print()
    # print("white ",end= " ")
    # for i in range(21):
    #     print(scores[1][i], end=" ")
    # print()
    # compare numbers
    winner = -1
    for i in range(21):
        if (scores[0][i] > scores[1][i]):
            winner = 0
            break
        elif (scores[0][i] < scores[1][i]):
            winner = 1
            break

    if (winner == -1):
        print("Tie.")
    elif (winner == 0):
        print("Black wins.")
    elif (winner == 1):
        print("White wins.")
    
if __name__ == "__main__":
    for line in sys.stdin:
        cards = line.split()
        hands = [[],[]]
        for i in range(10):
            value = cards[i][0]
            suit = cards[i][1]
            # print(rank_card(value,suit))
            hands[i//5].append(rank_card(value, suit))
        eval_hands(hands)
