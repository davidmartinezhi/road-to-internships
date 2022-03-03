#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        
        /*
        1. listen
            input: string given as an array of characters "s"
            output: void
            
            must be with O(1) memory
            s length between 1 and 100,000
            s[i] is a printable ascii character
            
        2. example
        
            ["h", "e", "l", "l", "o"]
            ["o", "l", "l", "e", "h"]
            
        3. brute force
            pointer at beginning
            pointer at the end
            
            switch values and move beginning++, and end--;
            
            runtime: O(n)
            memory: O(1)
            
        4. Optimeze
            BCR: O(n)
            the brute force method is pretty optime
        
        5. walkthrough
        pointer start and end
        switch the values s[start] and s[end]
        move start++, end--
        
        6. implement
        
        7. test
            one letter in the vector
            multiple letters in the vector
        */
        
        int start = 0;
        int end = s.size() - 1;
        
        while(start < end){
            char aux = s[start];
            s[start] = s[end];
            s[end] = aux;
            
            start++;
            end--;
        }
    }
};
