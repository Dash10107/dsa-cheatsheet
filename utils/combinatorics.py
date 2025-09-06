"""
Combinatorics Utilities
======================

This module provides combinatorial functions: factorial, nCr, nPr, modular nCr, binomial coefficients, catalan numbers, etc.
"""

MOD = 10**9 + 7

from math import comb

def factorial(n):
    """Compute n! (factorial of n)."""
    result = 1
    for i in range(2, n + 1):
        result *= i
    return result

def nCr(n, r):
    """Compute n choose r (binomial coefficient)."""
    if r < 0 or r > n:
        return 0
    return factorial(n) // (factorial(r) * factorial(n - r))

def nPr(n, r):
    """Compute n permute r (number of ways to arrange r out of n)."""
    if r < 0 or r > n:
        return 0
    return factorial(n) // factorial(n - r)

def modinv(a, mod=MOD):
    """Modular inverse using Fermat's little theorem (mod must be prime)."""
    return pow(a, mod - 2, mod)

def modfact(n, mod=MOD):
    """Compute n! % mod."""
    result = 1
    for i in range(2, n + 1):
        result = (result * i) % mod
    return result

def mod_nCr(n, r, mod=MOD):
    """Compute nCr % mod efficiently."""
    if r < 0 or r > n:
        return 0
    num = modfact(n, mod)
    denom = (modfact(r, mod) * modfact(n - r, mod)) % mod
    return (num * modinv(denom, mod)) % mod

def catalan_number(n):
    """Compute nth Catalan number."""
    return nCr(2 * n, n) // (n + 1)

def mod_catalan_number(n, mod=MOD):
    """Compute nth Catalan number modulo mod."""
    return (mod_nCr(2 * n, n, mod) * modinv(n + 1, mod)) % mod

# Test cases
if __name__ == "__main__":
    print(f"5! = {factorial(5)}")
    print(f"10 choose 3 = {nCr(10, 3)}")
    print(f"10 permute 3 = {nPr(10, 3)}")
    print(f"10C3 mod 1e9+7 = {mod_nCr(10, 3)}")
    print(f"Catalan(5) = {catalan_number(5)}")
    print(f"Catalan(5) mod 1e9+7 = {mod_catalan_number(5)}")
