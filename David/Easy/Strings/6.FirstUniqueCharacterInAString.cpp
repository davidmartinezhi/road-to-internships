#include <iostream>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        /*
        1. listen
            input: string "s"
            output: index of the first non-repeating character
            
            if it doesn't exists, return -1
            
            string length is between 1 and 100,000
            s consists of only lowercase english letters
        
        2. example
            
            "loveleetcode", 2
            "ooa", 2
        
        3. brute force
            Crear hashtable 
            recorro una vez el string y guardo la letra y su contador
            recorro de nuevo y si ese key tiene un valor de 1, regreso el index
            
            runtime: O(n)
            memory: O(1)
        
        4. optimize
        
            BCR: O(n)
            
            Talvez podría usar menos memoria al utilizar el array, pero en teoria es lo mismo
            
        5. walkthrough
            Crear hashtable 
            recorro una vez el string y guardo la letra y su contador
            recorro de nuevo y si ese key tiene un valor de 1, regreso el index
        
        6. implement
        
        7. test
        
        */
        
        /*
        //Creo hashtable
        unordered_map<char, int> ht;
        
        //Recorro una vez, para guardar char y cuenta
        for(int i = 0; i < s.size(); i++){
            ht[s[i]]++;
        }
        
        //Recorro para checar quien tiene valor de 1
        for(int i = 0; i < s.size(); i++){
            if(ht[s[i]] == 1){
                return i;   //Regreso i
            }
        }
        
        return -1;
        
        */
        
        //Solución con array
        int letters[26] = {};
        
        for(int i = 0; i < s.size(); i++){
            letters[s[i]-'a']++;
        }
        
        for(int i = 0; i < s.size(); i++){
            if(letters[s[i]-'a']  == 1) return i;
        }
        
        return -1;
    }
};