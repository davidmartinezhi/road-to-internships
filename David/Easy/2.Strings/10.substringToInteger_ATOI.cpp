#include <iostream>
#include <string>
#include <limits.h>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        /*
        1. listen
        convert a string to a 32-bit signed integer
        
            algorithm
                -read and ignore any whitespace
                -check if the integer is positive or negative
                -read until the next non-character or the end of the input is reached
                -if no digits are read, return 0
                -if the integer is out of the 32-bit signed integer range, return INT_MAX or INT_MIN
                -return the integer as the final result
                
            do not ignore any character other thatn the leading whitespace or the rest of 
            the string after digits
            
            string length is between 0 and 200
            s consists of enlish letters digits(0-9), '-','+','.'
            
        2. example
        
            "42" -> 42
            "    -42" -> -42
            "4193 with words" -> 4193
            "opop34" -> 0
            "     +-32" -> 0
            
            No importa si hay un numero con punto decimal, solo tomamos el entero
        
        3.  brute force
            recorro hasta que no haya whitespace
            checo por signo
            recorro mientras hayan digitos
            
            runtime: O(n)
            memory: O(1)
        
        4. optimize
            
            BCR: O(n)
            
            hay manera de convertir directamente de char a numero
            Ó podría hacer una función que los convierte
            
        5. walkthrough
            traverse the string
                recorro todo el whitespace
                si encuentro char
                    veo si es - o + y salgo
                    si es cualquier otra cosa regreso -
                    
                recorro por los digits
                    si no son digits o llego al final, me salgo
                    saco el digit a agregar
                    checo Minimos y maximos
        6. implement
        
        7. test
            leading whitespace
            leading character
            
            with negative simbol
            with positive simbol
            without simbol
            
            special cases:
                empty string
                MAX_LIMIT
                MIN_LIMIT
            
        */

       //runtime: O(n)
       //memory: O(1)
        
        int result = 0; //result variable
        bool simbol = true; //Simbol flag
        
        //traversal pointer
        int i = 0;
        
        //Traverse white space at the beginning
        while(s[i] == ' ' && i < s.size()) i++;
        
        //Check for simbol
        if(i < s.size()){
            if(s[i] == '-'){
                simbol = false;
                i++;
            } 
            else if(s[i] == '+'){
                i++;
            }  
        }
        
        //Traverse any leading 0
        while(i < s.size() && s[i] == '0') i++;
        
        //Read digits
        //If i is in range and the character is a digit
        while(i < s.size() && isdigit(s[i])){
            
            //Get the integer
            //int aux = charToInt(s[i]);
            int aux = s[i] - '0';   //Conversión de char digito a int
            
            //If the simbol is for a negative number
            if(!simbol){
                if(result > 0){ //If result is positive, change is to negative
                    result *= -1;
                }
                aux *= -1;//Convert aux to a negative number
            }
            

            //Check max and min limits
            if(( result < INT_MIN/ 10) ||  result == INT_MIN/10 && aux < -8){
                return INT_MIN;
            }                
            
            if((result > INT_MAX / 10) ||  result == INT_MAX/10 && aux > 7){
                return INT_MAX;
            }                

            
            //Add char to result
            result = (result * 10) + aux;
            i++;    
        }

        return result;

    }
    
    int charToInt(char & c){
        //Return the integer value of the digit
        if(c == '1') return 1;
        if(c == '2') return 2;
        if(c == '3') return 3;
        if(c == '4') return 4;
        if(c == '5') return 5;
        if(c == '6') return 6;
        if(c == '7') return 7;
        if(c == '8') return 8;
        if(c == '9') return 9;
        
        return 0;
    }
};

/*
//Conversión de char digito a int es con:
                                            char - '0'
//50 minutos
//Hubo confusión en el trabajo con limits, me hubiera detenido a pensar en como hacer congruencia
//Hice muchos movimientos, cuando pude frenarme y resolverlo enseguida
*/
