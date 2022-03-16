#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        /*
        1. listen
            input: 1-indexed array of integers "numbers" that is already sorted in non-decreasing ord
            1-indexed, comienza de 1, no de 0
            
            find 2 numbers that add up to a specific target
            These two numbers are inside the list, index1 < index2
            
            output: indices of 2 numbers, index1 and index2. Added by one
            
            There is exactly one solution always, you may not use the same element twice
            
            numbers is in range 2 and 30,000
            nums[i] i sbetween -1000 and 1000
            numbers is sorted in non-decreasing order
            target is between -1000 and 1000
            exactly one solution
            
        2. example
        
            [2, 7, 11, 15], target = 9
            
            [2, 3, 4], target = 6
            
            [-1, 0] target = -1
        
        3. brute force
            
            nested for loops that traverse the rest of the list
            runtime: O(n^2)
            memory: O(1)
            
        4. optimize
            
            Hashtable for constant runtime: O(n)
            memory: O(n)
            
            Array is already sorted
            Use two pointers, one at max value, one at min value
            If it's less than target. Move left
            If it's more than target. Move right
            
            If it adds up to target, return an array with both indexes+1 on them.
            There is only one solution.
            runtime: O(n)
            memory: O(1)
        
        5. walkthrough
            
        */
        
        int start = 0;
        int end = numbers.size() - 1;
        
        //Runtime: O(n)
        while(start < end){
            int sum = numbers[start] + numbers[end];
            
            if(sum > target){
                end--;
            }else if(sum < target){
                start++;
            }else{
                return {start+1, end+1};
            }
        }
        return {};
    }
};
/*
24 minutos
*/