#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        /*
        1. listen
            input: roman numeral
            output: integer
        
            string length is between 1 and 15
            s consists conly of ('I', 'V', 'X', 'L', 'C', 'D', 'M')
            It's guaranteed that "s" is a valid roman numeral in range [1, 3999]
            
        2. example
            cuaderno
        
        3. brute force
            Creo array con valores enteros
            creo variable entera resultado
            Meto a un array los valores numericos de cada simbolo
            
            Agrego el ultimo valor de la lista al resultado
            Recorro la lista de derecha a izquierda con fixed window 2
            si el num izquierdo es mayor o igual al derecho, sumo el numero al resultado final
            si el num izquierdo es menor, resto el numero del resultado final
            
            runtime: O(n)
            memory: O(n)
            
        4. optimize
            BCR: O(n)
            podría hacer memory O(1), solo recorriendo el string y haciendo IFs
            
        5. walkthrough
            Comenzaré con el brute force
            
        6. implement
        
        7. test
            numero IV y XC
            numero CIV
            numero XIII
            
            SPECIAL CASE:
                valor unico
        
        */
        
        //Runtime: O(n), memory:O(n)
        /*
        vector<int> nums;
        
        for(int i = 0; i < s.size(); i++){
            if(s[i] == 'I') nums.push_back(1);
            if(s[i] == 'V') nums.push_back(5);
            if(s[i] == 'X') nums.push_back(10);
            if(s[i] == 'L') nums.push_back(50);
            if(s[i] == 'C') nums.push_back(100);
            if(s[i] == 'D') nums.push_back(500);
            if(s[i] == 'M') nums.push_back(1000);
        }
        
        int result = nums[nums.size()-1];
        
        for(int i = nums.size() - 1; i > 0; i--){
            if(nums[i-1] >= nums[i]){
                result += nums[i-1];
            }else{
                result -= nums[i-1];
            }
        }
        
        return result;
    }
};
    */
    /*
    
    [10, 100] 90
    [1000, 10, 100, 10] 1100
    [1, 1] = 2
    */
        
    
        //Optimized
        int result = romanToInt(s[s.size()-1]);
    
        for(int i = s.size()-1; i > 0; i--){
            
            int aux = romanToInt(s[i-1]);
        
            if( aux >= romanToInt(s[i])){
                result += aux;
            }else{
                result -= aux;
            }
        }
        
        return result;
        
    
    /*
        //optimization version 2
        unordered_map<char, int> nums;
    
        nums['I'] = 1;
        nums['V'] = 5;
        nums['X'] = 10;
        nums['L'] = 50;
        nums['C'] = 100;
        nums['D'] = 500;
        nums['M'] = 1000;
        
        int result = nums[s[s.size()-1]];
        
        for(int i = s.size()-1; i > 0; i--){
        
            if( nums[s[i-1]] >= nums[s[i]]){
                result += nums[s[i-1]];
                
            }else{
                result -= nums[s[i-1]];
                
            }
        }
        
        return result;
    */
    }
    
    int romanToInt(char & c){
        if(c == 'I') return 1;
        if(c == 'V') return 5;
        if(c == 'X') return 10;
        if(c == 'L') return 50;
        if(c == 'C') return 100;
        if(c == 'D') return 500;
        if(c == 'M') return 1000; 
        
        return 0;
    }
};

/*

//31 minutos brute force
//38 minutos con optimized solution tmbn

*/