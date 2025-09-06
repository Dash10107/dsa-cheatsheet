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
        // TODO: Implement two sum using hashmap
        return new int[0];
    }
    
    public static List<List<String>> groupAnagrams(String[] strs) {
        // TODO: Implement group anagrams
        return new ArrayList<>();
    }
    
    public static int longestConsecutive(int[] nums) {
        // TODO: Implement longest consecutive sequence
        return 0;
    }
    
    public static boolean containsDuplicate(int[] nums) {
        // TODO: Implement duplicate check
        return false;
    }
    
    public static int[] intersection(int[] nums1, int[] nums2) {
        // TODO: Implement array intersection
        return new int[0];
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
