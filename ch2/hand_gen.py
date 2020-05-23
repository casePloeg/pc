import random

def hello(a):
    return a

if __name__ == "__main__":
    suits = "CDHS"
    values = "23456789TJQKA"
    cards = set()
    hello(3)
    for i in range(10000):
        while(len(cards) < 7):
            s = random.randint(0,3)
            v = random.randint(0,12)
            cards.add(values[v]+suits[s])
        cards = list(cards)
        cards = cards[:2] + cards[4:] + cards[2:]
        print(' '.join(cards))
        cards = set()


