import sys
from collections import defaultdict


def match(e, w, a_to_e):
    for i in range(len(e)):
        c_e = e[i]
        c_w = w[i]
        for map_c_e, map_c_w in a_to_e.items():
            # ensure 1-1
            if (map_c_e == c_e and map_c_w != c_w) or (map_c_w == c_w and map_c_e != c_e):
                return False
        a_to_e[c_e] = c_w
    return True


def check_consistent(a_to_e, e_to_w, cur, goal):
    if cur == goal:
        return [True, a_to_e]
    else:
        e, ws = sorted(e_to_w.items(), key=lambda x: len(x[0]), reverse=True)[0]
        for w in ws:
            b = a_to_e.copy()
            if match(e, w, b):
                copy_e_to_w = e_to_w.copy()
                copy_e_to_w.pop(e)
                res = check_consistent(b, copy_e_to_w, cur + 1, goal)
                if res[0]:
                    return res
        return [False, a_to_e]


n = int(input())
words = []

s_t_w = defaultdict(list)
for i in range(n):
    w = input()
    words.append(w)
    s_t_w[len(w)].append(w)

for line in sys.stdin:
    e_msg = line.split()
    e_words = set()
    sizes = set()
    s_t_e = defaultdict(list)
    for e in e_msg:
        e_words.add(e)
        sizes.add(len(e))

    e_words = list(e_words)
    e_words.sort(key = lambda x: len(x), reverse=True)
    # print(e_words)

    e_to_w = defaultdict(list)
    for w in words:
        for e in e_words:
            if len(e) == len(w):
                e_to_w[e].append(w)

    [valid, alpha_t_e] = check_consistent(dict(), e_to_w, 0, len(e_words))

    if valid:
        res = ""
        for e in e_msg:
            for e_c in e:
                if (e_c != " "):
                    res += alpha_t_e[e_c]

            res += " "
        print(res.strip())
    else:
        res = ""
        for e in e_msg:
            for e_c in e:
                if (e_c != " "):
                    res += "*"

            res += " "
        print(res.strip())
