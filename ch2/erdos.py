import collections


def bfs(n_to_collab, n_to_erdos, name):
    erdos = 0
    q = []
    q.append((erdos, name))
    visited = set()
    while len(q) != 0:
        erdos, name = q.pop(0)
        # print(erdos, name)
        if (name not in n_to_erdos):
            n_to_erdos[name] = erdos
        visited.add(name)
        # print(n_to_collab[name])
        for n in n_to_collab[name]:
            if n not in visited:
                q.append((erdos + 1, n))


t = int(input())
for t_i in range(t):
    p, n = map(int, input().split())
    n_to_collab = collections.defaultdict(set)
    for i in range(p):
        names = []
        names_data, paper = input().split(':')
        # print(names_data, paper)
        names_data = names_data.split(',')
        # print(names_data)
        # print(names_data)
        # print(names_data)
        name = ""
        for s in names_data:
            s = s.strip()
            if len(s) > 0:
                name += s.strip() + ", "
                if s[-1] == '.':
                    names.append(name[:-2])
                    name = ""
        # print(names)
        for name1 in names:
            for name2 in names:
                # print (name1, name2, name2 not in n_to_collab[name1])
                if (name1 != name2):
                    n_to_collab[name1].add(name2)
                    n_to_collab[name2].add(name1)

    print("Scenario " + str(t_i+1))
    n_to_erdos = dict()
    bfs(n_to_collab, n_to_erdos, "Erdos, P.")  


    for i in range(n):
        name = input()
        if (name.strip() in n_to_erdos):
            print(name + " " + str(n_to_erdos[name.strip()]))
        else:
            print(name + " infinity")
        
