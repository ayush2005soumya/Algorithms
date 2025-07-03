def brent_graph(adj_list, start):
    f = lambda x: adj_list[x]
    return brent(f, start)

def brent(f, x0):
    power = lam = 1
    tortoise = x0
    hare = f(x0)

    while tortoise != hare:
        if power == lam:
            tortoise = hare
            power *= 2
            lam = 0
        hare = f(hare)
        lam += 1

    mu = 0
    tortoise = hare = x0
    for _ in range(lam):
        hare = f(hare)

    while tortoise != hare:
        tortoise = f(tortoise)
        hare = f(hare)
        mu += 1

    return mu, lam

# Example graph: 0 → 1 → 2 → 3 → 4 → 2 (cycle: 2 → 3 → 4)
graph = [1, 2, 3, 4, 2]
start_node = 0
mu, lam = brent_graph(graph, start_node)
print("Cycle starts at index:", mu)
print("Cycle length:", lam)
