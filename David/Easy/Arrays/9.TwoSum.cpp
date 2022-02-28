#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        /*
        1. listen
            input: array of integers nums, and an integer target
            output: indices of the two numbers that add up to target
                
            Each input has exactly one solution and you may not use the same element twice
            
            I can return the answer in any order
            
            nums size is between 2 and 10,000
            nums[i] can be between 1 billion and - 1 billion
                
        2. example
            
        
        3. brute force
            Recorro el vector y agrego todos los numeros a un hashtable<num, index> 
            Recorro otra vez y saco el valor de target - nums[i]
            Si existe el valor, regreso los indexes.
            
            runtime: O(n + n)
            memory: O(n)
            
        4. optimize
            Puedo recorrer solo una vez
            si el valor a buscar ya esta en la hashtable, regreso i y la key
            
            Como conseguía el valor de la key en la hashtable? con metodo find
        
            
            runtime: O(n)
            memory: O(n)
            
        5. walkthrough
            
            Inicializo hashtable<nums, index>
            Recorro nums
                Saco valor a buscar (target-nums[i])
                checo si el valor esta en las keys de la hashtable
                    si esta, regreso vector con i y la key del valor
        
        6. implement
        
        7. test
            
            
            
        */
        
        /*
        unordered_map<int, int> ht;
        vector<int> result(2, 0);
        //[3,3] t=6
        for(int i = 0; i < nums.size(); i++){
            
            int search = (target - nums[i]); //Valor a buscar
            
            //Si el valor se encuentra en la hashtable
            if(ht.find(search) != ht.end()){
                 
                result[0] = ht[search];
                result[1] = i;
                break;  
            }
            
            ht[nums[i]] = i;
        }
        
        return result;
        */
        
        
        //Runtime: O(n) + O(insert and search in hashtable): O(n)
        //Memory: O(n)
        
        unordered_map<int, int> ht;
        
        for(int i = 0; i < nums.size(); i++){
            
            int search = (target - nums[i]);
            
            //Para conseguir apuntador
            auto it = ht.find(search);
            
            //Si el valor se encuentra en la hashtable
            if(it != ht.end()){
                return {it->second, i};
            }
            
            ht[nums[i]] = i;
        }
        
        return {};
        
    }
};