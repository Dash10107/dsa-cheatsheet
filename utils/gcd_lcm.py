"""
GCD and LCM Utility Functions
============================

This module contains utility functions for greatest common divisor (GCD),
least common multiple (LCM), and related number theory operations.
"""

def gcd(a, b):
    """
    Find greatest common divisor of two numbers using Euclidean algorithm.
    
    Args:
        a: First integer
        b: Second integer
    
    Returns:
        GCD of a and b
    """
    while b:
        a, b = b, a % b
    return abs(a)


def gcd_recursive(a, b):
    """
    Find greatest common divisor using recursive Euclidean algorithm.
    
    Args:
        a: First integer
        b: Second integer
    
    Returns:
        GCD of a and b
    """
    if b == 0:
        return abs(a)
    return gcd_recursive(b, a % b)


def gcd_multiple(numbers):
    """
    Find GCD of multiple numbers.
    
    Args:
        numbers: List of integers
    
    Returns:
        GCD of all numbers
    """
    if not numbers:
        return 0
    
    result = numbers[0]
    for num in numbers[1:]:
        result = gcd(result, num)
    
    return result


def lcm(a, b):
    """
    Find least common multiple of two numbers.
    
    Args:
        a: First integer
        b: Second integer
    
    Returns:
        LCM of a and b
    """
    return abs(a * b) // gcd(a, b)


def lcm_multiple(numbers):
    """
    Find LCM of multiple numbers.
    
    Args:
        numbers: List of integers
    
    Returns:
        LCM of all numbers
    """
    if not numbers:
        return 0
    
    result = numbers[0]
    for num in numbers[1:]:
        result = lcm(result, num)
    
    return result


def extended_gcd(a, b):
    """
    Extended Euclidean algorithm to find GCD and coefficients.
    
    Args:
        a: First integer
        b: Second integer
    
    Returns:
        Tuple (gcd, x, y) where gcd = ax + by
    """
    if a == 0:
        return b, 0, 1
    
    gcd_val, x1, y1 = extended_gcd(b % a, a)
    x = y1 - (b // a) * x1
    y = x1
    
    return gcd_val, x, y


def modular_inverse(a, m):
    """
    Find modular multiplicative inverse of a modulo m.
    
    Args:
        a: Integer
        m: Modulus
    
    Returns:
        Modular inverse of a mod m, or None if it doesn't exist
    """
    gcd_val, x, y = extended_gcd(a, m)
    
    if gcd_val != 1:
        return None  # Modular inverse doesn't exist
    
    return (x % m + m) % m


def modular_exponentiation(base, exponent, modulus):
    """
    Compute (base^exponent) mod modulus efficiently.
    
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
        if exponent % 2 == 1:
            result = (result * base) % modulus
        
        exponent = exponent >> 1
        base = (base * base) % modulus
    
    return result


def chinese_remainder_theorem(remainders, moduli):
    """
    Solve system of congruences using Chinese Remainder Theorem.
    
    Args:
        remainders: List of remainders
        moduli: List of moduli
    
    Returns:
        Solution x such that x ≡ remainders[i] (mod moduli[i])
    """
    if len(remainders) != len(moduli):
        raise ValueError("Remainders and moduli must have same length")
    
    n = len(remainders)
    
    # Compute product of all moduli
    product = 1
    for m in moduli:
        product *= m
    
    result = 0
    
    for i in range(n):
        # Compute Mi = product / moduli[i]
        Mi = product // moduli[i]
        
        # Find modular inverse of Mi mod moduli[i]
        Mi_inv = modular_inverse(Mi, moduli[i])
        
        if Mi_inv is None:
            raise ValueError("Modular inverse doesn't exist")
        
        result += remainders[i] * Mi * Mi_inv
    
    return result % product


def bezout_coefficients(a, b):
    """
    Find Bezout coefficients for two integers.
    
    Args:
        a: First integer
        b: Second integer
    
    Returns:
        Tuple (x, y) such that ax + by = gcd(a, b)
    """
    gcd_val, x, y = extended_gcd(a, b)
    return x, y


def is_coprime(a, b):
    """
    Check if two numbers are coprime (relatively prime).
    
    Args:
        a: First integer
        b: Second integer
    
    Returns:
        True if a and b are coprime, False otherwise
    """
    return gcd(a, b) == 1


def euler_totient(n):
    """
    Compute Euler's totient function φ(n).
    
    Args:
        n: Positive integer
    
    Returns:
        Number of integers from 1 to n that are coprime with n
    """
    if n <= 0:
        return 0
    
    result = n
    
    # Check for all prime factors
    p = 2
    while p * p <= n:
        if n % p == 0:
            # Remove all multiples of p
            while n % p == 0:
                n //= p
            result -= result // p
        p += 1
    
    # If n is still greater than 1, it's a prime factor
    if n > 1:
        result -= result // n
    
    return result


# Test cases
if __name__ == "__main__":
    # Test GCD
    print(f"GCD(48, 18): {gcd(48, 18)}")
    print(f"GCD(100, 25): {gcd(100, 25)}")
    print(f"GCD of [12, 18, 24]: {gcd_multiple([12, 18, 24])}")
    
    # Test LCM
    print(f"LCM(12, 18): {lcm(12, 18)}")
    print(f"LCM(4, 6, 8): {lcm_multiple([4, 6, 8])}")
    
    # Test Extended GCD
    a, b = 56, 15
    gcd_val, x, y = extended_gcd(a, b)
    print(f"Extended GCD({a}, {b}): gcd={gcd_val}, x={x}, y={y}")
    print(f"Verification: {a}*{x} + {b}*{y} = {a*x + b*y}")
    
    # Test Modular Inverse
    a, m = 3, 11
    inv = modular_inverse(a, m)
    print(f"Modular inverse of {a} mod {m}: {inv}")
    if inv:
        print(f"Verification: {a} * {inv} mod {m} = {(a * inv) % m}")
    
    # Test Modular Exponentiation
    base, exp, mod = 2, 10, 1000
    result = modular_exponentiation(base, exp, mod)
    print(f"{base}^{exp} mod {mod} = {result}")
    
    # Test Chinese Remainder Theorem
    remainders = [2, 3, 2]
    moduli = [3, 5, 7]
    solution = chinese_remainder_theorem(remainders, moduli)
    print(f"CRT solution: {solution}")
    for i in range(len(remainders)):
        print(f"  {solution} ≡ {remainders[i]} (mod {moduli[i]})")
    
    # Test Bezout Coefficients
    a, b = 30, 12
    x, y = bezout_coefficients(a, b)
    print(f"Bezout coefficients for {a}, {b}: x={x}, y={y}")
    print(f"Verification: {a}*{x} + {b}*{y} = {a*x + b*y}")
    
    # Test Coprime
    print(f"Are 17 and 25 coprime? {is_coprime(17, 25)}")
    print(f"Are 12 and 18 coprime? {is_coprime(12, 18)}")
    
    # Test Euler Totient
    n = 12
    print(f"Euler totient φ({n}): {euler_totient(n)}")
