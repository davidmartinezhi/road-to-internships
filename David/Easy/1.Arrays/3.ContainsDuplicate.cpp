#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        /*
        1. listen
            input: integers array nums
            output: true/false
            
            return true if any value in the list appears at least twice
            else return false
            
            nums length is between 1 and 100,000
            nums value is between -one billion and one billion
          
         2. Example
            
            [1,2,3,4,5,6,2] -> true
            
            [5,3,2,1,4,9] -> false
            [1] -> false
         
         3. Brute Force
            
            Sort the array
            Sliding window with size of two
            
            //runtime: O(n log n)
            //memory: O(1)
            
            Hashtables
            Add number and it's frequency
            If frequency is equal to 2. return true
            else false
            //runtime: O(n)
            //memory: O(n)
            
        4. optimize
        
        5. walkthrough
            hashtables:
                initialize hashtable
                traverse the list and add each element as key, to the hashtable with a value of 1
                if the element is found again it will add 1, making it 2
                if the value is equal to 2, return true
                
            Sort:
                sort the numbers array
                Traverse the array with a window of size two
                if both numbers inside the window are the same
                    return true
                    
        6. implement
            
            
        7.test
            Array of size 1
            Array with repeating numbers
            Array with no repeating numbers
            
        */
        
        /*
        //Hashtables solution
        //memory: O(n)
        unordered_map<int, int> numbersFreq;    //Initializing empty hashtable
        
        //runtime: O(n)
        for(int i = 0; i < nums.size(); i++){   //Traverse the list
            numbersFreq[nums[i]]++; //Add 1 to the frequency of that number
            
            if(numbersFreq[nums[i]] == 2){  //If the frequency is equal to 2, return true
                return true;
            }
        }
        return false;   //return false if it is not found
        */
        
        //Sorting the array
        
        //runtime: O(n log n)
        sort(nums.begin(), nums.end()); //Sort numbers
        
        //runtime: O(n)
        for(int i = 1; i < nums.size(); i++){   //Traverse from the second element, if it exists
            
            if(nums[i-1] == nums[i]){   //Window with size 2 and 2 numbers being compares
                return true;   
            }
        }
        
        return false;
    }
};

