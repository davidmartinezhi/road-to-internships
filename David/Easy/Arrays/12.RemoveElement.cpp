#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        /*
        1. listen
            input: integer array nums, and integer val
            Remove all ocuurrances of val in nums. in-place
            
            The relative order of the elements may be changed
            
            Put the result elements in the first part of the array nums.
            
            output: k
            
            Memory must be O(1)
            
            nums length is between 0 and 100
            nums[i] value ranges from 0 to 50
            val value ranges from 0 to 100
            (Si val es 51 o mayor, regreso el array)
            
        2. example
            [3, 2, 2, 3] val=3
            [2, 2, 3, 3]
            k=2
            
            [0,1,2,2,3,0,4,2] val = 2
            [0,1,3,0,4,2,2,2]
            k=5
            
        3. brute force
            two pointer technique
                fixed pointer and iterative pointer
            
            runtime: O(n)
            memory: O(1)
        
        4. optimize
            BCR: O(n) traversing the list just once
            
        5. walkthrough
            initialize
            fixed pointer to 0
            traverse the list from 1
            
                if fixed == val and traverse is diff from val
                    advance
                    
        6. implement
        
        7.test
            -Val with 51 or more, returns the list directly
            -nums is empty
            -Val not in nums
            -All nums are val
            -1 val in nums
            -multiple vals in number
        */
        
        //  If nums is an empty list
        if(nums.size() == 0){
            return 0;
        }
        
        //If val is a number not in range of nums[i]
        if(val > 50){
            return nums.size();
        }
        
        
        //Create fixed pointers for values not equal to val
        int k = 0;
        
        //Traverse the vector
        for(int i = 0; i < nums.size(); i++){
            
            if(nums[k] == val && nums[i] != val){ //If nums[k] is val and nums[i] isn't
                swap(nums, i, k);
                k++;
            }     
            else if(nums[k] != val){    //If nums[k] is not val, we move it one space
                k++;
            }
        }
        return k;   //Return k
        
        //También pudo ser y así no utilizo el swap
        /*
        int k = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != val){
                nums[k] = nums[i];
                k++;
            }
        }
        return k;
        */
    }
    
    void swap(vector<int> & nums, int i, int j){
        //Swap characters inside the list
        int aux = nums[i];
        nums[i] = nums[j];
        nums[j] = aux;
    }
};


/*
Nota:
    -Terminado en 28 minutos.
    -No dudar de mi mismo, la logica estaba bien pero aún así me daba miedo probarla. Eso me hizo perder tiempo
    -Solución optima para el problema y sacada rapido.
*/