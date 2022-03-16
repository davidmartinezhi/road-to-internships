#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        /*
        1. listen
        
            input: string "s", containing just the characters '(' ')' '{' '}' '[' ']'
            output: true/false
            
            input string is valid if:
                1. Open brackets must be closed by the same type of character
                2. Open brackerts must be closed in the correct order
                
            s size is between 1 and 10,000
            s consists of parentheses '()[]{}'
        
        
        2. example
            
            "()", true
            "()[]{}", true
            "(]", false
            
            "([])"
        
        3. brute force
            
            si es '(', '{', '['
            los meto al stack
            
            si es ')', '}', ']'
            comparo con el primero del stack
            
            Si no es match regreso false
            si si es, solo elimino ese dato del top
            
            runtime: O(n)
            memory: O(n)
            
            talvez podría hacer un stack para open simbols y queue para closing
        
        4. optimize
            BCR: O(n)
            Se puede mejorar el memory?
        
        5. walkthrough
        
        6.implement
        
        7. test
            parentesís dentro de llaves dentro de corchetes [{()}]
            parentesís llaves y corchetes de lado ()[]{}
            mezcla no valida [(])
            
            special case:
                stack no esta vacío al final, más opening brackets
                string tiene un solo char
                Existen más closing brackets que opening brackets
        */
        
        //Checo si string es de 1 elemento
        if(s.size() == 1){
            return false;
        }
        
        
        stack<char> stack;  //memory: O(n)

        
        //Traverse the string. runtime: O(n)
        for(int i = 0; i < s.size(); i++){
            
            //If the char is an open simbol
            if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
                stack.push(s[i]);   //We push it into the stack
            }
            
            //If the character is a closing simbol
            if(s[i] == ')' || s[i] == ']' || s[i] == '}'){
                
                //Check if stack is empty. checa que no existan más closing que opening
                if(stack.empty()) return false;
                
                char aux = stack.top(); //We grab the top
                stack.pop();    //We remove it from the stack
                
                if(aux == '('){ 
                    if(s[i] != ')') return false;
                }
                
                if(aux == '['){
                    if(s[i] != ']') return false;
                }

                if(aux == '{'){
                    if(s[i] != '}') return false;
                }
            }
        }
        
        //Check if the stack is not empty. Checa que no existan más opening que closing
        if(!stack.empty()) return false;
        
        return true;
        
    }
};

/*
Terminado en 28 minutos

        //Talvez podría hacer 2 arrays uno de opening y otro de closing. Le agrego contadores según el signo
        //Ahora solo comparo en base a index. De esa manera
*/