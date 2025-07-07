def lagged_fibonacci(seed, j, k, m, N, op='+'):
    assert j < k <= len(seed), "Invalid lags or seed size"
    X = seed[:]
    results = []

    for n in range(N):
        if op == '+':
            val = (X[-j] + X[-k]) % m
        elif op == '-':
            val = (X[-j] - X[-k]) % m
        elif op == '*':
            val = (X[-j] * X[-k]) % m
        elif op == 'XOR':
            val = (X[-j] ^ X[-k]) % m
        else:
            raise ValueError("Invalid operation")

        X.append(val)
        results.append(val)

    return results

# Example usage
seed = [1, 1, 2, 3, 5, 8, 13]  # k = 7
j, k, m, N = 5, 7, 1000, 10
print("Generated values:", lagged_fibonacci(seed, j, k, m, N, '+'))
