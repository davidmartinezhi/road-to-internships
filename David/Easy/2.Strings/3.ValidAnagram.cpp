#include <iostream>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        /*
        1. listen
            input: two strings "s" adn "t"
            output: true if "t" is an anagram of "s"
            
            Anagrams are words composed of the same letters
            s and t, have a size between 1 and 50,000
            Thery consist of lower case letters only
            
        2. example
            "anagram", "nagaram" -> true
            "rat", "car" -> false
        
        3. brute force
            traverse the first word and add each letter to a hashtable
            traverse the second word and add each letter to a hashtable
            if they are not equal, return false. Else true
            
            runtime: O(n)
            memory: O(n)
        
        4. optimize
            Create an array with 26 cells initialized to 0
            traversal of s adds 1
            traversal of t substracts 1
            
            traverse the 26 cells, if any cell is diff from 0 return false
            
        5. Walkthrough
        
        6. Implement
        
        7. Test
        
        */
        
        /*
        //hashtables
        unordered_map<char, int> htS;
        unordered_map<char, int> htT;
        
        for(int i = 0; i < s.size(); i++){
            htS[s[i]]++;
        }

        for(int i = 0; i < t.size(); i++){
            htT[t[i]]++;
        }
        
        return htS == htT;
        */
        
        //Array
        int letters[26] = {};
        
        for(int i = 0; i < s.size(); i++){
            letters[s[i]-'a']++;
        }

        for(int i = 0; i < t.size(); i++){
            letters[t[i]-'a']--;
        }
        
        for(int i = 0; i < 26; i++){
            if(letters[i] != 0){
                return false;
            }
        }
        
        return true;
    }
};

/*
Terminado en 10 minutos.
Con Hashtables

16 minutos. Ambas soluciones terminadas
*/