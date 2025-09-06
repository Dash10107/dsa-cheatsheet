import java.util.*;

public class Template {
    static class HashMap {
        private Map<String, Integer> map;
        
        public HashMap() {
            map = new java.util.HashMap<>();
        }
        
        public void put(String key, int value) {
            map.put(key, value);
        }
        
        public int get(String key) {
            return map.getOrDefault(key, -1);
        }
        
        public void remove(String key) {
            map.remove(key);
        }
        
        public boolean containsKey(String key) {
            return map.containsKey(key);
        }
        
        public int size() {
            return map.size();
        }
        
        public boolean empty() {
            return map.isEmpty();
        }
        
        public void clear() {
            map.clear();
        }
        
        public Set<String> keys() {
            return map.keySet();
        }
        
        public Collection<Integer> values() {
            return map.values();
        }
    }
    
    // Common hashmap operations
    public static int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            int complement = target - nums[i];
            if (map.containsKey(complement)) {
                return new int[]{map.get(complement), i};
            }
            map.put(nums[i], i);
        }
        return new int[0];
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
    
    public static int longestConsecutive(int[] nums) {
        Set<Integer> set = new HashSet<>();
        for (int num : nums) set.add(num);
        int longest = 0;
        for (int num : set) {
            if (!set.contains(num - 1)) {
                int current = num;
                int streak = 1;
                while (set.contains(current + 1)) {
                    current++;
                    streak++;
                }
                longest = Math.max(longest, streak);
            }
        }
        return longest;
    }
    
    public static boolean containsDuplicate(int[] nums) {
        Set<Integer> set = new HashSet<>();
        for (int num : nums) {
            if (!set.add(num)) return true;
        }
        return false;
    }
    
    public static int[] intersection(int[] nums1, int[] nums2) {
    Set<Integer> set1 = new HashSet<>();
    for (int n : nums1) set1.add(n);
    Set<Integer> result = new HashSet<>();
    for (int n : nums2) if (set1.contains(n)) result.add(n);
    int[] arr = new int[result.size()];
    int i = 0;
    for (int n : result) arr[i++] = n;
    return arr;
    }
    
    public static void main(String[] args) {
        HashMap hm = new HashMap();
        hm.put("apple", 5);
        hm.put("banana", 3);
        hm.put("cherry", 8);
        
        System.out.println("Size: " + hm.size());
        System.out.println("Value for 'apple': " + hm.get("apple"));
        System.out.println("Contains 'banana': " + hm.containsKey("banana"));
        
        System.out.println("Keys: " + hm.keys());
    }
}
