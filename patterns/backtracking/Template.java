import java.util.*;

public class Template {
    // Generate all permutations
    public static List<List<Integer>> generatePermutations(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();
        List<Integer> path = new ArrayList<>();
        boolean[] used = new boolean[nums.length];
        
        backtrack(nums, path, used, result);
        return result;
    }
    
    private static void backtrack(int[] nums, List<Integer> path, boolean[] used, List<List<Integer>> result) {
        if (path.size() == nums.length) {
            result.add(new ArrayList<>(path));
            return;
        }
        
        for (int i = 0; i < nums.length; i++) {
            if (used[i]) continue;
            used[i] = true;
            path.add(nums[i]);
            backtrack(nums, path, used, result);
            path.remove(path.size() - 1);
            used[i] = false;
        }
    }
    
    // Generate all combinations
    public static List<List<Integer>> generateCombinations(int n, int k) {
        List<List<Integer>> result = new ArrayList<>();
        List<Integer> path = new ArrayList<>();
        
        backtrack(1, n, k, path, result);
        return result;
    }
    
    private static void backtrack(int start, int n, int k, List<Integer> path, List<List<Integer>> result) {
        if (path.size() == k) {
            result.add(new ArrayList<>(path));
            return;
        }
        
        for (int i = start; i <= n; i++) {
            path.add(i);
            backtrack(i + 1, n, k, path, result);
            path.remove(path.size() - 1);
        }
    }
    
    // Combination sum
    public static List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> result = new ArrayList<>();
        List<Integer> path = new ArrayList<>();
        Arrays.sort(candidates);
        
        backtrack(0, candidates, target, path, result);
        return result;
    }
    
    private static void backtrack(int start, int[] candidates, int remaining, List<Integer> path, List<List<Integer>> result) {
        if (remaining == 0) {
            result.add(new ArrayList<>(path));
            return;
        }
        
        for (int i = start; i < candidates.length; i++) {
            if (candidates[i] > remaining) break;
            
            path.add(candidates[i]);
            backtrack(i, candidates, remaining - candidates[i], path, result);
            path.remove(path.size() - 1);
        }
    }
    
    // N-Queens problem
    public static List<List<String>> solveNQueens(int n) {
        List<List<String>> result = new ArrayList<>();
        char[][] board = new char[n][n];
        for (char[] row : board) {
            Arrays.fill(row, '.');
        }
        
        backtrack(0, board, result);
        return result;
    }
    
    private static void backtrack(int row, char[][] board, List<List<String>> result) {
        if (row == board.length) {
            List<String> solution = new ArrayList<>();
            for (char[] rowArr : board) {
                solution.add(new String(rowArr));
            }
            result.add(solution);
            return;
        }
        
        for (int col = 0; col < board.length; col++) {
            if (isSafe(board, row, col)) {
                board[row][col] = 'Q';
                backtrack(row + 1, board, result);
                board[row][col] = '.';
            }
        }
    }
    
    private static boolean isSafe(char[][] board, int row, int col) {
        // Check column
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q') return false;
        }
        
        // Check diagonal (top-left to bottom-right)
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') return false;
        }
        
        // Check diagonal (top-right to bottom-left)
        for (int i = row - 1, j = col + 1; i >= 0 && j < board.length; i--, j++) {
            if (board[i][j] == 'Q') return false;
        }
        
        return true;
    }
    
    // Generate valid parentheses
    public static List<String> generateParentheses(int n) {
        List<String> result = new ArrayList<>();
        backtrack("", 0, 0, n, result);
        return result;
    }
    
    private static void backtrack(String path, int open, int close, int n, List<String> result) {
        if (path.length() == 2 * n) {
            result.add(path);
            return;
        }
        
        if (open < n) {
            backtrack(path + "(", open + 1, close, n, result);
        }
        
        if (close < open) {
            backtrack(path + ")", open, close + 1, n, result);
        }
    }
    
    // Palindrome partitioning
    public static List<List<String>> palindromePartitioning(String s) {
        List<List<String>> result = new ArrayList<>();
        List<String> path = new ArrayList<>();
        
        backtrack(0, s, path, result);
        return result;
    }
    
    private static void backtrack(int start, String s, List<String> path, List<List<String>> result) {
        if (start == s.length()) {
            result.add(new ArrayList<>(path));
            return;
        }
        
        for (int end = start + 1; end <= s.length(); end++) {
            String substring = s.substring(start, end);
            if (isPalindrome(substring)) {
                path.add(substring);
                backtrack(end, s, path, result);
                path.remove(path.size() - 1);
            }
        }
    }
    
    private static boolean isPalindrome(String s) {
        int left = 0, right = s.length() - 1;
        while (left < right) {
            if (s.charAt(left) != s.charAt(right)) return false;
            left++;
            right--;
        }
        return true;
    }
    
    // Subset sum
    public static List<List<Integer>> subsetSum(int[] nums, int target) {
        List<List<Integer>> result = new ArrayList<>();
        List<Integer> path = new ArrayList<>();
        Arrays.sort(nums);
        
        backtrack(0, nums, target, path, result);
        return result;
    }
    
    private static void backtrack(int start, int[] nums, int remaining, List<Integer> path, List<List<Integer>> result) {
        if (remaining == 0) {
            result.add(new ArrayList<>(path));
            return;
        }
        
        for (int i = start; i < nums.length; i++) {
            if (nums[i] > remaining) break;
            
            path.add(nums[i]);
            backtrack(i + 1, nums, remaining - nums[i], path, result);
            path.remove(path.size() - 1);
        }
    }
    
    // Common backtracking problems
    public static boolean solveSudoku(char[][] board) {
        // TODO: Implement Sudoku solver
        return false;
    }
    
    public static List<String> wordSearchII(char[][] board, String[] words) {
        // TODO: Implement word search II
        return new ArrayList<>();
    }
    
    public static void main(String[] args) {
        // Test permutations
        int[] nums = {1, 2, 3};
        List<List<Integer>> permutations = generatePermutations(nums);
        System.out.println("Permutations of [1,2,3]: " + permutations);
        
        // Test combinations
        List<List<Integer>> combinations = generateCombinations(4, 2);
        System.out.println("Combinations of 2 from 1-4: " + combinations);
        
        // Test combination sum
        int[] candidates = {2, 3, 6, 7};
        int target = 7;
        List<List<Integer>> combSum = combinationSum(candidates, target);
        System.out.println("Combinations that sum to " + target + ": " + combSum);
        
        // Test parentheses
        List<String> parentheses = generateParentheses(3);
        System.out.println("Valid parentheses for n=3: " + parentheses);
        
        // Test palindrome partitioning
        String s = "aab";
        List<List<String>> partitions = palindromePartitioning(s);
        System.out.println("Palindrome partitions of '" + s + "': " + partitions);
    }
}
