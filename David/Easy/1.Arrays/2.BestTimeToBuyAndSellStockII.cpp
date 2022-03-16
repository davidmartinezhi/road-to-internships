#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        /*
        1. listen
            
            int array "prices" where each index represents a day
            
            Can only hold one stock at the time, but I can buy and sell whenever I want to
            
            return max profit
            
            array containt between 1 and 30,000 elements
            
            prices can vary from 0 to 10,000
        
        2. example
            
            Cuaderno
        
        3. brute force
        
            Sliding Window Technique
            
            Se que es más eficiente con la fixed window, pero mi primer pensamiento sería hacerla
                dinamica. Antes del DIY
                
            runtime: O(n)
            memory: O(1)
        
        4. optimize
        
            Debo sacar la logica con el DIY, sino, no haré el fixed sliding window technique
            Okay, comprobado que fixed sliding window technique también jalaría para el problema
        
        5. walkthrough
            Fixed window
                Window of size 2
                if right is bigger than left
                sum that to max profit
                
            Dynamic window
                Traverse the array until the second to last element
                if the next element is bigger, increase the window
                    when the next element is not bigger
                    add windowSum to maxProfit
                    
                move traversing pointer to the next element from where it ended last sum
                
        
        6. implement
        
        7. test
        special cases for test:
            array with one element
            
        array in decreasing order
        array in increasing order

        */
        
        
        
       
        /*
        //fixed window
        //runtime: O(n)
        //memory: O(1)
        int maxProfit = 0;
        
        for(int i = 0; i < prices.size() - 1; i++){
            
            if(prices[i] < prices[i+1]){
                maxProfit += (prices[i+1] - prices[i]);
            }
            
        }

        return maxProfit;
        */
        
        
        //Dynamic window  
        //runtime: O(n)
        //memory: O(1)
        int maxProfit = 0;
        
        //O(n)
        for(int i = 0; i < prices.size() - 1; i++){
            //Saco el siguiente valor de j
            int j = i+1;
        
            //Checo si valor en j es mayor a valor en i
            if(prices[i] < prices[j]){
                
                //Mientras j no llegue al penultimo elemento
                while(j < prices.size() - 1){
                    
                    //Saco el siguiente dato de j
                    int k = j+1;
                    
                    if(prices[j] < prices[k]){
                        j++;
                    }
                    else{     
                        break;
                    }
                }
                
                maxProfit += (prices[j]-prices[i]);
                i = j;
            }
        }
        return maxProfit;
        
        
    }
};

/*
Repasar sliding window technique y tratar de simplificar el codigo para que sea má entendible
    No solo para el entrevistador, sino también para mí al programarlo.
*/