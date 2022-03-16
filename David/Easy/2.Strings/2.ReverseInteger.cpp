#include <iostream>
#include <limits.h>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        /*
        1. listen
            input: 32-bit integer x, with digits reversed
            if reversing the integer causes the value to go outside the 32-bit int range, return 0
            
            no signed or unsigned values are available
            
            constraints:
                -2^31 <= x <= (2^31)-1
                
        2. example
        
        integer reverse
            x = 123
            return 321
            
            x = -123
            return -321
            
            x = 120
            return 21
            
            123 % 10 = 3
            123 / 10 = 12
            
            int result = 0;
            
            result = (result * 10) + 3;
            3
            
            12 % 10 = 2
            12 / 10 = 1
            
            result = (result * 10) + 2
            32
            
        check for constraints
            INT_MAX CHECK (result == INT_MAX/10 && to add < 7) or result > INT_MAX/10)
            INT_MIN CHECK (result == INT_MIN/10 && to add < -8) or result < INT_MAX/10)
            at the end I'll update the sign
            
        3. brute force
            
            initialize int variable for result
            remove each las element from x and add it to (result * 10) + element
            
            runtime: O(n)
            memory: O(1)
            
        4. optimize
            BCR: O(n)
            
        5. walkthrough
        
            
            initialize variable for result
            while x is not 0
                get last element
                update x
                
                check for constraints
                
                add element to result
                
        6. implement
        
        7. test
            
            -positive value
            -negative calue
            
            -pass positive constraint
            -pass negative contraint
            
            -exact positive constraing
            -exact negative constraint
            
            todo:
                -Create functional method that reverse integer
                -Check for constraints
            
        */
        
        
        //result variable
        int result = 0;
        
        //O(n)
        while( x != 0){
            int last = x % 10;  //Last number of x
            x /= 10;    //Update x
            
            //Check for constraints
            //INT_MAX
            if((result == INT_MAX/10 && last > 7) || (result > INT_MAX/10)){
                return 0;
            }
            
            //INT_MIN
            if((result == INT_MIN/10 && last < -8) || (result < INT_MIN/10)){
                return 0;
            }
            
            //Add element to result
            result = (result * 10) + last;   
        }
        return result;
    }
};
/*

Terminado en 34 minutos

*/