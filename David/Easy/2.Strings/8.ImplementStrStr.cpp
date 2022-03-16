#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        /*
        1. listen
        
            implement strStr()
            input: input haystack and input needle. both are strings
            output: index of the first ocurrance of the needle in haystack. -1 if needle is not found
            
            return 0, when needle is an empty string
            
            hay and needls size are in range 0 and 50,000
            they consist of only lowercase english letters
            
        2. example
        
            "hello", needle = "ll"
            -> 2
            
            "aaaaa", needle = "bba"
            -> -1
            
            haystack = "", needle = ""
            -> 0
        
        3. brute force
            For each char in haystack, we traverse the needle
            If a char is different, we break
            
            runtime: O(m*n)
            memory: O(1)
        
        4. optimize
            traverse haystack, if a char is equal to the first char of the needle
            we traverse that part.
            
            
            runtime: O(n+m)
            memory: O(1)
            
        5. walkthrough
            traverse haystack until a char is the same as the first char in needle
            Create a pointer for the traversal of needle
            if the pointer is equal to needle size-1. return i
            
        6. implement
        
        7. test
            empty needle *
            needle not in haystack *
            needle in haystack*
            needle is haytack*
            empty haystack and non-empty needle *
            needle is longer than haystack
            
            checklist:
                j == needle.size() or j == needle.size() - 1
        */
        
        //Este es el brute force
        /*
        //Check if needle is empty
        if(needle.size() == 0) return 0;
        
        //Check if needle is greater than haystack
        if(needle.size() > haystack.size()) return -1;
        
        //O(n)
        for(int i = 0; i < haystack.size() - needle.size()+1; i++){
            int j = 0;
            
            while(haystack[i+j] == needle[j] && i+j < haystack.size()){
                j++;
            }
            
            if(j == needle.size()) return i;
        }
        
        return -1;  //needle not found
        */
        
        if(needle.size() == 0) return 0;
        
        //Set up LPS table
        int n = needle.size();
        vector<int> LPS(n, 0); //Memory: O(m) 
        int prevLPS = 0, i = 1;
        
        //Runtime: O(m)
        while(i < n){
            if(needle[i] == needle[prevLPS]){
                LPS[i] = prevLPS + 1;
                i++;
                prevLPS++;
            }
            else{
                if(prevLPS == 0){
                    LPS[i] = 0;
                    i++;
                }
                else{
                    prevLPS = LPS[prevLPS-1];
                }
            }
        }
        
        //Traverse the haystack
        //Ponter at the beginning of each word
        i = 0; //haystack
        int j = 0; //pointer for needle
        
        //Runtime: O(n)
        while(i < haystack.size()){
            if(haystack[i] == needle[j]){
                i++;
                j++;
            }
            else{
                if(j == 0){
                    i++;
                } else{
                    j = LPS[j-1];
                }
            }
            
            if(j == needle.size()){
                return i-j;
            }
        }
        
        return -1;

    }
};
/*
Notas:
28 min brute force

Resulta que existe un algoritmo para solucionar esto
KMP string matching algorithm, lo reduce a n el runtime

Es muy bueno aprender algoritmos utiles como el de Kadane y este
*/