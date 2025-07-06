def acorn_generator(seeds, m, N):
    k = len(seeds) - 1  # order
    X = [[0] * (k + 1) for _ in range(N + 1)]
    X[0] = seeds[:]
    U = []

    for n in range(1, N + 1):
        X[n][0] = X[n - 1][0]
        for j in range(1, k + 1):
            X[n][j] = (X[n - 1][j] + X[n][j - 1]) % m
        U.append(X[n][k] / m)
    
    return U

# Example usage
seeds = [1, 2, 3]  # k = 2
m = 10007
N = 10
random_numbers = acorn_generator(seeds, m, N)
print("Generated ACORN random numbers:", random_numbers)
