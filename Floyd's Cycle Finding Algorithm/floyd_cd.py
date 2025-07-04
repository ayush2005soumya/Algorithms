def floyd(f, x0):
    # Phase 1: Finding a repetition x_mu = x_2mu
    tortoise = f(x0)
    hare = f(f(x0))
    while tortoise != hare:
        tortoise = f(tortoise)
        hare = f(f(hare))

    # Phase 2: Finding the start of the cycle (mu)
    mu = 0
    tortoise = x0
    while tortoise != hare:
        tortoise = f(tortoise)
        hare = f(hare)
        mu += 1

    # Phase 3: Finding the cycle length (lambda)
    lam = 1
    hare = f(tortoise)
    while tortoise != hare:
        hare = f(hare)
        lam += 1

    return mu, lam

# Example usage
f = lambda x: (x * x + 1) % 255
x0 = 2
mu, lam = floyd(f, x0)
print("Cycle starts at index:", mu)
print("Cycle length:", lam)
