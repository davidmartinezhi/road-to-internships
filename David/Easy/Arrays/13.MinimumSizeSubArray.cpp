#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        /*
        
        1. listen
            input: array of positive integers nums, and a positive integer "target"
            output: return the minimal length of a contiguous subarray o which the sum
                    is greater than or equal to target
            If there is no such subarray, return 0
            
            target is between 1 and a billion
            length is between 1 and 100,000
            nums[i] is between 1 and 100,000
            
            
        2. example
            target: 7, nums: [2, 3, 1, 2, 4, 3]
            target: 4, nums: [1, 4, 4]
            
            
        3. brute force
            nested for loops
            
            
        4. optimize
            kadane's algorithm
            runtime: O(n)
            memory: O(1)
            
            Podría utilizar dynamic window technique
            runtime: O(n)
            memory: O(1)
            
            
        5. walkthrough
        
        kadane's algorithm
            comienzo con variable de minLength
            sum = 0
            Counter
            
            Si sum es mayor o igual al target, comparo counter con minLength
            recorro y agrego el dato a sum
            counter++
            
            Counter = 0
            Sum = nums[i]
        
        Dynamic window technique
        
            Creo variables
                -minWindow
                -currWindow
                -sum
                
                2 pointers
                avanzo el primero hasta que la suma sea mayor o igual a target
                una vez que se cumpla
                    Comparo currentWindow con minWindow, si es menor actualizo minWindow
                    
                Recorro el pointer de atras hasta que la sum sea menor a target o i == j
        
        6. implement
        
        7. test
            -nunca se encuentra el dato
            -dato se encuentra
            -dato está en una sola variable
            -target se cumple con varios elementos
            
            check:
                j < i o j <= i
        */
        
        /*
        int minLength = INT_MAX;
        int sum = 0;
        int counter = 0;
        
        //Recorro la lista
        for(int i = 0; i < nums.size(); i++){
            
            if(nums[i] >= target){
                return 1;
            }
            
            sum += nums[i]; //Agrego el número a sum
            counter++;  //Counter + 1 
            
            if(sum >= target){  //Si sum es mayor o igual al target
                
                if(counter < minLength){ //Si el counter es menor
                    minLength = counter;    //Lo actualizamos
                }
                
                counter = 0;    //Counter lo dejamos en 1
                sum = 0;
            }
              
        }
        
        if(sum >= target){  //Si sum es mayor o igual al target
                
            if(counter < minLength){ //Si el counter es menor
                minLength = counter;    //Lo actualizamos
            }
        }
        
        if(minLength == INT_MAX) return 0;
        
        return minLength;
        
        */
        
        //Si es con sliding window technique
        //Como se cuando debo usar sliding window technique o kadane's
        
        //Sliding window technique
        int minWindow = INT_MAX;
        int currWindow = 0;
        int sum = 0;
        int j = 0;
        
        //Recorro la lista
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i]; //Agrego numero a la suma
            currWindow++;   //Incremento la ventana
            
            if(sum >= target){  //Si se cumple la condición
                if(currWindow < minWindow){ //Comparo ventanas
                    minWindow = currWindow;
                }
            }
            
            while(sum >= target && j < i){  //Mientras sea valida la condición
                
                sum -= nums[j]; //Le resto el ultimo valor a la suma
                currWindow--;   //Actualizo la ventana
                j++;
                
                if(sum >= target){  //Si se cumple la condición
                    if(currWindow < minWindow){ //Comparamos ventanas
                        minWindow = currWindow;
                    }
                }                
            }
        }
        
        if(minWindow == INT_MAX) return 0;
        
    return minWindow;
    }
};

/*
Nota:
    Terminado en 31 minutos
*/