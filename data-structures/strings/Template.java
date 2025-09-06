import java.util.*;

public class Template {
    static class StringOperations {
        // Basic string operations
        public int length(String s) {
            return s.length();
        }
        
        public String reverse(String s) {
            StringBuilder sb = new StringBuilder(s);
            return sb.reverse().toString();
        }
        
        public boolean isPalindrome(String s) {
            int left = 0, right = s.length() - 1;
            while (left < right) {
                if (s.charAt(left) != s.charAt(right)) return false;
                left++;
                right--;
            }
            return true;
        }
        
        public String toLowerCase(String s) {
            return s.toLowerCase();
        }
        
        public String toUpperCase(String s) {
            return s.toUpperCase();
        }
        
        // String searching
        public int findFirstOccurrence(String text, String pattern) {
            int n = text.length();
            int m = pattern.length();
            
            for (int i = 0; i <= n - m; i++) {
                int j;
                for (j = 0; j < m; j++) {
                    if (text.charAt(i + j) != pattern.charAt(j)) break;
                }
                if (j == m) return i;
            }
            return -1;
        }
        
        public List<Integer> findAllOccurrences(String text, String pattern) {
            List<Integer> result = new ArrayList<>();
            int n = text.length();
            int m = pattern.length();
            
            for (int i = 0; i <= n - m; i++) {
                int j;
                for (j = 0; j < m; j++) {
                    if (text.charAt(i + j) != pattern.charAt(j)) break;
                }
                if (j == m) result.add(i);
            }
            return result;
        }
        
        // String manipulation
        public String removeSpaces(String s) {
            return s.replaceAll(" ", "");
        }
        
        public String removeDuplicates(String s) {
            Set<Character> seen = new HashSet<>();
            StringBuilder result = new StringBuilder();
            for (char c : s.toCharArray()) {
                if (!seen.contains(c)) {
                    seen.add(c);
                    result.append(c);
                }
            }
            return result.toString();
        }
        
        public String sortString(String s) {
            char[] chars = s.toCharArray();
            Arrays.sort(chars);
            return new String(chars);
        }
        
        // Advanced string operations
        public boolean isAnagram(String s, String t) {
            if (s.length() != t.length()) return false;
            
            Map<Character, Integer> count = new HashMap<>();
            for (char c : s.toCharArray()) {
                count.put(c, count.getOrDefault(c, 0) + 1);
            }
            for (char c : t.toCharArray()) {
                count.put(c, count.getOrDefault(c, 0) - 1);
                if (count.get(c) < 0) return false;
            }
            return true;
        }
        
        public String longestCommonPrefix(String[] strs) {
            if (strs.length == 0) return "";
            
            String prefix = strs[0];
            for (int i = 1; i < strs.length; i++) {
                while (strs[i].indexOf(prefix) != 0) {
                    prefix = prefix.substring(0, prefix.length() - 1);
                    if (prefix.isEmpty()) return "";
                }
            }
            return prefix;
        }
        
        public int longestSubstringWithoutRepeating(String s) {
            Map<Character, Integer> charMap = new HashMap<>();
            int left = 0, maxLen = 0;
            
            for (int right = 0; right < s.length(); right++) {
                if (charMap.containsKey(s.charAt(right))) {
                    left = Math.max(left, charMap.get(s.charAt(right)) + 1);
                }
                charMap.put(s.charAt(right), right);
                maxLen = Math.max(maxLen, right - left + 1);
            }
            return maxLen;
        }
        
        public boolean isSubsequence(String s, String t) {
            int i = 0, j = 0;
            while (i < s.length() && j < t.length()) {
                if (s.charAt(i) == t.charAt(j)) i++;
                j++;
            }
            return i == s.length();
        }
    }
    
    // Common string problems
    public static String longestPalindrome(String s) {
        if (s == null || s.length() < 1) return "";
        int start = 0, end = 0;
        for (int i = 0; i < s.length(); i++) {
            int len1 = expandAroundCenter(s, i, i);
            int len2 = expandAroundCenter(s, i, i + 1);
            int len = Math.max(len1, len2);
            if (len > end - start) {
                start = i - (len - 1) / 2;
                end = i + len / 2;
            }
        }
        return s.substring(start, end + 1);
    }

    private static int expandAroundCenter(String s, int left, int right) {
        while (left >= 0 && right < s.length() && s.charAt(left) == s.charAt(right)) {
            left--;
            right++;
        }
        return right - left - 1;
    }

    public static String minWindow(String s, String t) {
        if (s.length() == 0 || t.length() == 0) return "";
        Map<Character, Integer> dictT = new HashMap<>();
        for (char c : t.toCharArray()) dictT.put(c, dictT.getOrDefault(c, 0) + 1);
        int required = dictT.size();
        int l = 0, r = 0, formed = 0;
        Map<Character, Integer> windowCounts = new HashMap<>();
        int[] ans = {-1, 0, 0};
        while (r < s.length()) {
            char c = s.charAt(r);
            windowCounts.put(c, windowCounts.getOrDefault(c, 0) + 1);
            if (dictT.containsKey(c) && windowCounts.get(c).intValue() == dictT.get(c).intValue()) {
                formed++;
            }
            while (l <= r && formed == required) {
                c = s.charAt(l);
                if (ans[0] == -1 || r - l + 1 < ans[0]) {
                    ans[0] = r - l + 1;
                    ans[1] = l;
                    ans[2] = r;
                }
                windowCounts.put(c, windowCounts.get(c) - 1);
                if (dictT.containsKey(c) && windowCounts.get(c).intValue() < dictT.get(c).intValue()) {
                    formed--;
                }
                l++;
            }
            r++;
        }
        return ans[0] == -1 ? "" : s.substring(ans[1], ans[2] + 1);
    }

    public static List<List<String>> groupAnagrams(String[] strs) {
        Map<String, List<String>> map = new HashMap<>();
        for (String s : strs) {
            char[] arr = s.toCharArray();
            Arrays.sort(arr);
            String key = new String(arr);
            map.computeIfAbsent(key, k -> new ArrayList<>()).add(s);
        }
        return new ArrayList<>(map.values());
    }

    public static String decodeString(String s) {
        Stack<Integer> counts = new Stack<>();
        Stack<String> result = new Stack<>();
        String res = "";
        int idx = 0;
        while (idx < s.length()) {
            if (Character.isDigit(s.charAt(idx))) {
                int count = 0;
                while (Character.isDigit(s.charAt(idx))) {
                    count = 10 * count + (s.charAt(idx++) - '0');
                }
                counts.push(count);
            } else if (s.charAt(idx) == '[') {
                result.push(res);
                res = "";
                idx++;
            } else if (s.charAt(idx) == ']') {
                String temp = result.pop();
                int repeatTimes = counts.pop();
                StringBuilder sb = new StringBuilder(temp);
                for (int i = 0; i < repeatTimes; i++) sb.append(res);
                res = sb.toString();
                idx++;
            } else {
                res += s.charAt(idx++);
            }
        }
        return res;
    }
    
    public static void main(String[] args) {
        StringOperations ops = new StringOperations();
        
        String test = "Hello World";
        System.out.println("Original: " + test);
        System.out.println("Reversed: " + ops.reverse(test));
        System.out.println("Length: " + ops.length(test));
        System.out.println("Is palindrome: " + ops.isPalindrome("racecar"));
        
        String text = "ababcababc";
        String pattern = "abc";
        System.out.println("First occurrence of '" + pattern + "': " + 
                         ops.findFirstOccurrence(text, pattern));
        
        String[] strs = {"flower", "flow", "flight"};
        System.out.println("Longest common prefix: " + ops.longestCommonPrefix(strs));
    }
}
