"""
Fast Modular Exponentiation and Number Theory Utilities
=====================================================

This module contains utility functions for fast modular exponentiation,
prime number operations, and other number theory utilities.
"""

def fast_modular_exponentiation(base, exponent, modulus):
    """
    Compute (base^exponent) mod modulus efficiently using binary exponentiation.
    
    Args:
        base: Base number
        exponent: Exponent
        modulus: Modulus
    
    Returns:
        (base^exponent) mod modulus
    """
    if modulus == 1:
        return 0
    
    result = 1
    base = base % modulus
    
    while exponent > 0:
        if exponent & 1:  # If exponent is odd
            result = (result * base) % modulus
        
        exponent = exponent >> 1  # Divide exponent by 2
        base = (base * base) % modulus
    
    return result


def is_prime(n):
    """
    Check if a number is prime using trial division.
    
    Args:
        n: Number to check
    
    Returns:
        True if n is prime, False otherwise
    """
    if n < 2:
        return False
    if n == 2:
        return True
    if n % 2 == 0:
        return False
    
    for i in range(3, int(n**0.5) + 1, 2):
        if n % i == 0:
            return False
    
    return True


def is_prime_fermat(n, k=5):
    """
    Check if a number is prime using Fermat's primality test.
    
    Args:
        n: Number to check
        k: Number of iterations
    
    Returns:
        True if n is probably prime, False if definitely composite
    """
    if n < 2:
        return False
    if n == 2:
        return True
    if n % 2 == 0:
        return False
    
    import random
    
    for _ in range(k):
        a = random.randint(2, n - 2)
        if fast_modular_exponentiation(a, n - 1, n) != 1:
            return False
    
    return True


def sieve_of_eratosthenes(n):
    """
    Generate all prime numbers up to n using Sieve of Eratosthenes.
    
    Args:
        n: Upper bound
    
    Returns:
        List of prime numbers up to n
    """
    if n < 2:
        return []
    
    is_prime = [True] * (n + 1)
    is_prime[0] = is_prime[1] = False
    
    for i in range(2, int(n**0.5) + 1):
        if is_prime[i]:
            for j in range(i * i, n + 1, i):
                is_prime[j] = False
    
    return [i for i in range(2, n + 1) if is_prime[i]]


def prime_factors(n):
    """
    Find all prime factors of a number.
    
    Args:
        n: Number to factorize
    
    Returns:
        List of prime factors
    """
    factors = []
    
    # Check for 2
    while n % 2 == 0:
        factors.append(2)
        n //= 2
    
    # Check for odd numbers
    i = 3
    while i * i <= n:
        while n % i == 0:
            factors.append(i)
            n //= i
        i += 2
    
    # If n is still greater than 1, it's a prime factor
    if n > 1:
        factors.append(n)
    
    return factors


def prime_factors_count(n):
    """
    Count the number of each prime factor.
    
    Args:
        n: Number to factorize
    
    Returns:
        Dictionary mapping prime factors to their counts
    """
    factors = prime_factors(n)
    factor_count = {}
    
    for factor in factors:
        factor_count[factor] = factor_count.get(factor, 0) + 1
    
    return factor_count


def modular_inverse_fermat(a, p):
    """
    Find modular inverse using Fermat's little theorem.
    Only works when p is prime.
    
    Args:
        a: Number
        p: Prime modulus
    
    Returns:
        Modular inverse of a mod p
    """
    if not is_prime(p):
        raise ValueError("Modulus must be prime for Fermat's method")
    
    return fast_modular_exponentiation(a, p - 2, p)


def miller_rabin(n, k=5):
    """
    Check if a number is prime using Miller-Rabin primality test.
    
    Args:
        n: Number to check
        k: Number of iterations
    
    Returns:
        True if n is probably prime, False if definitely composite
    """
    if n < 2:
        return False
    if n == 2 or n == 3:
        return True
    if n % 2 == 0:
        return False
    
    # Write n-1 as d * 2^r
    r = 0
    d = n - 1
    while d % 2 == 0:
        r += 1
        d //= 2
    
    import random
    
    for _ in range(k):
        a = random.randint(2, n - 2)
        x = fast_modular_exponentiation(a, d, n)
        
        if x == 1 or x == n - 1:
            continue
        
        for _ in range(r - 1):
            x = (x * x) % n
            if x == n - 1:
                break
        else:
            return False
    
    return True


def pollard_rho(n):
    """
    Find a non-trivial factor of n using Pollard's rho algorithm.
    
    Args:
        n: Number to factorize
    
    Returns:
        A non-trivial factor of n, or n if n is prime
    """
    if n % 2 == 0:
        return 2
    
    import random
    
    x = random.randint(2, n - 1)
    y = x
    c = random.randint(1, n - 1)
    d = 1
    
    while d == 1:
        x = (x * x + c) % n
        y = (y * y + c) % n
        y = (y * y + c) % n
        d = gcd(abs(x - y), n)
    
    return d


def gcd(a, b):
    """
    Helper function for GCD calculation.
    """
    while b:
        a, b = b, a % b
    return abs(a)


def lucas_lehmer(p):
    """
    Check if 2^p - 1 is prime using Lucas-Lehmer test.
    
    Args:
        p: Prime number
    
    Returns:
        True if 2^p - 1 is prime, False otherwise
    """
    if not is_prime(p):
        return False
    
    if p == 2:
        return True
    
    s = 4
    m = (1 << p) - 1  # 2^p - 1
    
    for _ in range(p - 2):
        s = (s * s - 2) % m
    
    return s == 0


def next_prime(n):
    """
    Find the next prime number after n.
    
    Args:
        n: Starting number
    
    Returns:
        Next prime number after n
    """
    n += 1
    while not is_prime(n):
        n += 1
    return n


def prev_prime(n):
    """
    Find the previous prime number before n.
    
    Args:
        n: Starting number
    
    Returns:
        Previous prime number before n, or None if none exists
    """
    if n <= 2:
        return None
    
    n -= 1
    while n > 2 and not is_prime(n):
        n -= 1
    
    return n if n > 1 else None


# Test cases
if __name__ == "__main__":
    # Test fast modular exponentiation
    base, exp, mod = 2, 100, 1000
    result = fast_modular_exponentiation(base, exp, mod)
    print(f"{base}^{exp} mod {mod} = {result}")
    
    # Test prime checking
    numbers = [17, 25, 29, 97, 100]
    for num in numbers:
        print(f"{num} is prime: {is_prime(num)}")
    
    # Test Fermat primality test
    for num in numbers:
        print(f"{num} is probably prime (Fermat): {is_prime_fermat(num)}")
    
    # Test Sieve of Eratosthenes
    n = 30
    primes = sieve_of_eratosthenes(n)
    print(f"Primes up to {n}: {primes}")
    
    # Test prime factorization
    numbers = [12, 60, 100, 97]
    for num in numbers:
        factors = prime_factors(num)
        print(f"Prime factors of {num}: {factors}")
    
    # Test prime factors count
    for num in numbers:
        factor_count = prime_factors_count(num)
        print(f"Prime factors count of {num}: {factor_count}")
    
    # Test modular inverse with Fermat
    a, p = 3, 11
    if is_prime(p):
        inv = modular_inverse_fermat(a, p)
        print(f"Modular inverse of {a} mod {p} (Fermat): {inv}")
    
    # Test Miller-Rabin
    for num in numbers:
        print(f"{num} is probably prime (Miller-Rabin): {miller_rabin(num)}")
    
    # Test Pollard's rho
    composite = 8051
    factor = pollard_rho(composite)
    print(f"A factor of {composite}: {factor}")
    
    # Test Lucas-Lehmer
    mersenne_exponents = [2, 3, 5, 7, 13]
    for p in mersenne_exponents:
        if is_prime(p):
            is_mersenne_prime = lucas_lehmer(p)
            print(f"2^{p} - 1 is prime: {is_mersenne_prime}")
    
    # Test next/previous prime
    n = 20
    print(f"Next prime after {n}: {next_prime(n)}")
    print(f"Previous prime before {n}: {prev_prime(n)}")
