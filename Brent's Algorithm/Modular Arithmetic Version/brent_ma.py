def brent_modular(f, x0):
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

    # Find mu
    mu = 0
    tortoise = hare = x0
    for _ in range(lam):
        hare = f(hare)

    while tortoise != hare:
        tortoise = f(tortoise)
        hare = f(hare)
        mu += 1

    return mu, lam

# Example: f(x) = (x^2 + 1) % 97
mod = 97
f = lambda x: (x * x + 1) % mod
x0 = 10

mu, lam = brent_modular(f, x0)
print("Cycle starts at index:", mu)
print("Cycle length:", lam)
