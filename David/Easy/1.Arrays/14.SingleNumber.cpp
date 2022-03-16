#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        /*
            1. listen
            
                input: array of integers, nums
                    -every element appears twice, except for one
                    -it's a non-empty array
                
                solution must have a linear runtime coplexity and use only constant extra space
                
                output: The single number
                
                nums length is between 1 and 30,000
                nums[i] is between -30,000 to 30,000
                
            2. example
                [1, 2, 2, 1, 4, 4, 5]
                5
                
                [1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6]
                6
            
            3. brute force
                
                hashtable con cuenta de cada elemento
                elemento con cuenta de 1, lo regreso
                
                runtime: O(n)
                memory: O(n)
                
            4. optimize
                
                BCR: O(n)
                
                Como sacar memoria O(1)?
                
                Puedo ordenar el array y luego recorrer con fixed window de 2
                runtime: O(n log n)
                memory: O(1)
                
            5. walkthrough
            
            6. implement
            
            7.test
                Array of size 1
                Array of size 2
                Array of more than 2 elements
        */
        
        /*
        //Hashtable
        unordered_map<int, int> ht;
        int result;
        
        for(int i = 0; i < nums.size(); i++){
            ht[nums[i]]++;
        }
        
        for(int i = 0; i < nums.size(); i++){
            if(ht[nums[i]] == 1){
                result = nums[i];
                break;
            }
        }
        
        return result;
        */
        
        int result = 0;
        for(int i = 0; i < nums.size(); i++){
            result ^= nums[i];
        }
        
        return result;
    }
};