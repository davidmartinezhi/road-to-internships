#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
      /*
      1. listen
        input: array with digits, representing a large integer
        output: add one to the large integer
        
        Digit are ordered from less significant to more significant
        There are no leading 0s
        Increment the large integer by one and return the resulting array of digits
        
        array tiene entre 1 y 100 digitos
        digitos tienen valores entre 0 y 9
        el numero no tiene 0s al inicio
        
        
      2. example
        
        [9,9,9,9] -> [1,0,0,0,0]
        [1,9,9,9] -> [2,0,0,0]
        [9,9,9,8] -> [9,9,9,9]
        
    3. brute force 
    
    4. optimize
        recorro la lista de final a principio
        mientras encuentro 9, los convierto a 0
        el primer dato no 9, le sumo 1
        
        Al final del loop, checo si el primer dato es un 0
        Si el primer dato es un 0, lo convierto a 1 y agrego un 0 al final
    
    7. test
        lista con puros 9
        lista con el primer digito diferente a 9
        lista sin 9
        lista con un 9 en medio
        
      */
        
        //runtime: O(n)
        //memory: O(1)
        //[1,9,9]
        //[9,9,1]
        //[9,9,9]
        
        int n = digits.size();
        
        for(int i = n - 1; i >= 0; i--){
            
            if(digits[i] == 9){
                digits[i] = 0;
            }
            else{
                digits[i]++;
                break;
            }
        }
        
        if(digits[0] == 0){
            digits[0] = 1;
            digits.push_back(0);
        }
        
        return digits;
    }
};