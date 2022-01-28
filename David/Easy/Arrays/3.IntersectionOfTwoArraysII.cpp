#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        /*
        1. listen
            input: 2 integer arrays
            output: array with their intersections
            
            Each element in the result must appear as many times as it shows in both arrays
            Result can be in any order
            
            arrays tienen size entre 1 y 1,000
            nums tienen valor entre 0 y 1000
            
        2. example
            cuaderno
            
        3. brute force
            traverse nums1 and add each number to a hashtable with the frequency of appearance
            traverse nums2 and add each number to a hashtable with the frquency of appearence
            runtime: O(m+n) + O(m)
            memory: O(m+n)
            
        4. optimize
            BCR: O(m+n)
            
        5. walkthrough
            creo 2 hashtables
            relleno el primer hashtable
            relleno el segundo hashtable
            Si la key esta en la otra hashtable y el valor es menor, lo agrego a result
            
            recorro la primer lista y si el valor esta en el otro hashtable, checho cual la tiene menos veces
            Esa cantidad de veces, la agrego al array de la respuesta
        
        7.test
            
        
        */
        //runtime: O(n+m)
        //memory: O(n+m)
        
        /*
        //O(n+m) memory
        unordered_map<int, int> nums1HT; 
        unordered_map<int, int> nums2HT;
        
        vector<int> result = {};
        
        //O(n) runtime
        for(int i = 0; i < nums1.size(); i++){
            nums1HT[nums1[i]]++;
        }
        
        //O(m) runtime
        for(int i = 0; i < nums2.size(); i++){
            
            nums2HT[nums2[i]]++;
            
            if(nums1HT.find(nums2[i]) != nums1HT.end()){
                
                if(nums2HT[nums2[i]] <= nums1HT[nums2[i]]){
                    result.push_back(nums2[i]);
                }
                
            }
        }
        
        return result;
        */
        
        //hash table
        unordered_map<int, int> nums;
        
        //result
        vector<int> result;
        
        //O(n) runtime
        for(int i = 0; i < nums1.size(); i++){
            nums[nums1[i]]++;
        }        
        
        //O(m) runtime
        for(int i = 0; i < nums2.size(); i++){
            
            if(nums[nums2[i]] > 0){
                result.push_back(nums2[i]);
                nums[nums2[i]]--;
            }
        }
        
        return result;
    }
};