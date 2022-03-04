#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        /*
        1. listen
            input: string "s"
            output: true if it is a palindrome, false if it isn't
            
            for the phrase to be a palindrome remove non-alphanumeric characters and convert
            upper case letters to lower case letters.
            
            Palindrome is a phrase/word that is read the same way foward and backwards
            
            string length is in range 1 and 200,000
        
        2. example
            "A man, a plan, a canal: Panama" true
            "race a car" false
            " " true
        
        3. brute force
            
            add each letter to an array, not taking non-alphabetic characters and converting
            add each letter to another array, this time backwards
            compare both arrays
            
            runtime: O(n)
            memory: O(n)
            
        4. Optimize
            two pointer technique
                one pointer at start, the other at end
            
            O(n) runtime
            O(1) memory
            
        5. walkthrough
            Pointer at beggining, ponter at end
            move pointer until it is in an alphanumeric value
            compare
            if they are the same, move pointers to continue their traversal
            else return false   
            
        6. implement
        
        7. test
            phrase is palindrome
            phrase is not palindrome
            phrase has one character
            empty string
        
        */

        //Pointers
        int start = 0;
        int end = s.size() - 1;
        
        //Traverse: runtime O(n)
        while(start < end){
            
            //Move left pointer to a valid character
            while( !isalnum(s[start]) && start < end){
                start++;
            }
            
            //Move right pointer to a valid character
            while( !isalnum(s[end]) && start < end){
                end--;
            }
            
            if(tolower(s[start]) != tolower(s[end])) return false;
            
            start++;
            end--;
            
        }
        
        return true;
    }
};

//Terminado en 18 minutos