def is_prime(n):
    if n <= 1: return False
    if n <= 3: return True
    if n % 2 == 0 or n % 3 == 0: return False
    i = 5
    while i * i <= n:
        if n % i == 0 or n % (i + 2) == 0: return False
        i += 6
    return True

def blum_blum_shub(p, q, seed, n_bits):
    assert is_prime(p) and p % 4 == 3, "p must be prime and ≡ 3 mod 4"
    assert is_prime(q) and q % 4 == 3, "q must be prime and ≡ 3 mod 4"
    M = p * q
    assert 1 < seed < M and seed % p != 0 and seed % q != 0, "Invalid seed"

    x = seed
    bits = []

    for _ in range(n_bits):
        x = pow(x, 2, M)
        bits.append(x % 2)

    return bits

# Example usage
p = 499
q = 547
seed = 159201
n = 20

output_bits = blum_blum_shub(p, q, seed, n)
print("Random bits:", ''.join(map(str, output_bits)))
