class StringProcessor:
    def __init__(self, text=""):
        self.text = text
    
    def is_palindrome(self):
        s = self.text
        l, r = 0, len(s) - 1
        while l < r:
            if s[l] != s[r]:
                return False
            l += 1
            r -= 1
        return True
    
    def first_unique_char(self):
        from collections import Counter
        count = Counter(self.text)
        for idx, c in enumerate(self.text):
            if count[c] == 1:
                return idx
        return -1
    
    def longest_substring_no_repeat(self):
        s = self.text
        char_map = {}
        left = max_len = 0
        for right, c in enumerate(s):
            if c in char_map and char_map[c] >= left:
                left = char_map[c] + 1
            char_map[c] = right
            max_len = max(max_len, right - left + 1)
        return max_len
    
    def group_anagrams(self, strs):
        from collections import defaultdict
        anagrams = defaultdict(list)
        for word in strs:
            key = ''.join(sorted(word))
            anagrams[key].append(word)
        return list(anagrams.values())
    
    def valid_anagram(self, s, t):
        from collections import Counter
        return Counter(s) == Counter(t)

# Common string operations
def valid_palindrome(s):
    l, r = 0, len(s) - 1
    while l < r:
        if s[l] != s[r]:
            return False
        l += 1
        r -= 1
    return True

def first_unique_character(s):
    from collections import Counter
    count = Counter(s)
    for idx, c in enumerate(s):
        if count[c] == 1:
            return idx
    return -1

def longest_substring_without_repeating_characters(s):
    char_map = {}
    left = max_len = 0
    for right, c in enumerate(s):
        if c in char_map and char_map[c] >= left:
            left = char_map[c] + 1
        char_map[c] = right
        max_len = max(max_len, right - left + 1)
    return max_len

def group_anagrams(strs):
    from collections import defaultdict
    anagrams = defaultdict(list)
    for word in strs:
        key = ''.join(sorted(word))
        anagrams[key].append(word)
    return list(anagrams.values())

def valid_anagram(s, t):
    from collections import Counter
    return Counter(s) == Counter(t)
