"""
Bit Manipulation Utilities
=========================

This module provides common bit manipulation functions for DSA and competitive programming.
"""

def count_set_bits(n):
    """Count the number of set bits (1s) in integer n."""
    count = 0
    while n:
        n &= n - 1
        count += 1
    return count

def is_power_of_two(n):
    """Check if n is a power of two (n > 0 and only one bit set)."""
    return n > 0 and (n & (n - 1)) == 0

def get_bit(n, i):
    """Get the ith bit (0-indexed from right) of n."""
    return (n >> i) & 1

def set_bit(n, i):
    """Set the ith bit of n to 1."""
    return n | (1 << i)

def unset_bit(n, i):
    """Set the ith bit of n to 0."""
    return n & ~(1 << i)

def toggle_bit(n, i):
    """Toggle the ith bit of n."""
    return n ^ (1 << i)

def lowest_set_bit(n):
    """Return the value of the lowest set bit in n (e.g., 12 -> 4)."""
    return n & -n if n else 0

def highest_set_bit(n):
    """Return the value of the highest set bit in n (e.g., 12 -> 8)."""
    if n == 0:
        return 0
    msb = 0
    while n:
        msb = n
        n &= n - 1
    return msb

def bit_length(n):
    """Return the number of bits needed to represent n in binary."""
    return n.bit_length()

# Test cases
if __name__ == "__main__":
    n = 29
    print(f"Set bits in {n}: {count_set_bits(n)}")
    print(f"Is {n} power of two? {is_power_of_two(n)}")
    print(f"Get 3rd bit of {n}: {get_bit(n, 3)}")
    print(f"Set 1st bit of {n}: {set_bit(n, 1)}")
    print(f"Unset 2nd bit of {n}: {unset_bit(n, 2)}")
    print(f"Toggle 0th bit of {n}: {toggle_bit(n, 0)}")
    print(f"Lowest set bit in {n}: {lowest_set_bit(n)}")
    print(f"Highest set bit in {n}: {highest_set_bit(n)}")
    print(f"Bit length of {n}: {bit_length(n)}")
