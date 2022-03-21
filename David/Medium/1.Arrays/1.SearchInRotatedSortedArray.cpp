#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        /*
        1. listen
            input: integer array nums sorted in asending order
            nums is possibly rotated at an unknown pivot index k(1 <= k < nums.length)
            output: index of target if it is in nums, lese -1
            
        2. example
            cuaderno
        
        3. brute force
            brute force can be lineal traversal and see if the number exists
        
        4. optimize
            Binary search
            
        7. test
            -has pivot, rotated left, with target
            -has pivot, rotated right, with target
            -has pivot, rotated left, without target
            -has pivot, rotated right, without target
            -doesn't has pivot, with target
            -doesn't has pivot, without target
            -size 2
            -size 1
 
            
        */
        
        //Check if there is just 1 element in the array
        if(nums.size() == 1){
            if(nums[0] == target) return 0;
            else return -1;
        }
        
        //check for extremes
        if(nums[nums.size()-1] == target) return nums.size()-1;
        if(nums[0] == target) return 0;
        
        //If there is more than 1 element in the array
        int pivot;
        
        if(hasPivot(nums)){ //If the array has pivot
            
            pivot = findPivot(nums, 0, nums.size()-1);  //We find it
            
            if(target == nums[pivot]){  //If the value on pivot is ther target, we return that index
                return pivot;
            }
            else if(target > nums[0]){  //If target is greater than the fisrt element, target is
                                        //in the first part, previous to the pivot
                pivot = binarySearch(nums, 0, pivot-1, target);     
            }
            else{   //If the target is not greater, the target is on the end part of the arrat
                pivot = binarySearch(nums, pivot, nums.size()-1, target);                
            }
        }
        else{
            //If there is no pivot, we implement a normal binary search
            pivot = binarySearch(nums, 0, nums.size()-1, target);
        }
       
        return pivot;
    }
    

    
    int findPivot(const vector<int> & nums, int i, int j){  //listo
        //Find pivot

        int pivot = (i+j)/2; 
        
        if(i == j) return pivot;    //If i == j, return pivot
        
        //pivot is on left side
        if(nums[i] > nums[pivot] && nums[j] < nums[pivot]){
            // i > pivot > j
            return findPivot(nums, i, pivot-1);
        }
        else if(nums[i] > nums[pivot] && nums[pivot] < nums[j]){
            // i > pivot < j
            return findPivot(nums, i, pivot);
        }
        //pivot is on right side
        else if(nums[j] < nums[pivot]){
            //i < pivot > j
            return findPivot(nums, pivot+1, j);
        }
        else if(nums[i] < nums[pivot] && nums[pivot] < nums[j]){
            // i < pivot < j
            return i;
        }
        else{
            return pivot;
        }
    }
    
    
    bool hasPivot(const vector<int> & nums){
        //Checks if the array has pivot
        if(nums[0] < nums[nums.size()-1]) return false;
        return true;
    }
    
    
    int binarySearch(const vector<int> & nums, int i, int j, int x){    //listo
        //Binary search
        int pivot = (i + j) / 2;
        
        if(j >= i){
            if(nums[pivot] == x){   //If the pivot is the target, we return
                return pivot;
            }

            if(nums[pivot] > x){   //If the target is smaller
                return binarySearch(nums, i, pivot-1, x);
            }

            else{  //If the target is greater
                return binarySearch(nums, pivot+1, j, x);
            }              
        }
        return -1;
    }
};