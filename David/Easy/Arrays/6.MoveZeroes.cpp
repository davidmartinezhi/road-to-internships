#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        /*
        1. listen
            input: integer array "nums"
                Move all the zeros to the end
                Mantain relative order of non-zero integers
            output: array with all zero's moved to the right
            
            In-place
            array size is between 1 and 10,000
            Numbers are in range (INT_MIN, INT_MAX)
        
        2. example
        
            Cuaderno
        
        3. brute force
            
            Look for the first element 0
            Pointer estaca se queda en el 0
            El otro pointer sale en busca de otro 0
            
            Si encuentra numero diferente a 0
            Hace switch de los valores
            
            
        4. optimize
            
            Best Conceivable Runtime: O(n)
            El approach cumple con esta condición
            
            Estaca siempre se mueve hasta encontrar un valor 0
            
        5. walkthrough
            Busco el valor 0 con la estaca
            
            Un segundo apuntador sale en busca de nu número no 0
            
            Si lo encuentra hace switch y la estaca se mueve hasta ese valor
            
        6. implement
        
        7. test
            Un solo lemento en el array
        */
        
        /*
        //Array de solo un elemento
        if(nums.size() == 1){
            return;
        }
        
        int i = 0;
        
        //Runtime: O(n)
        //Recorro el array
        while(i < nums.size()){
            int j = i;
            
            //Si encuentro un 0
            if(nums[i] == 0){
                
                //Recorro el resto del array con otro apuntador
                while(j < nums.size()){
                    
                    //Si el valor es diferente a 0
                    if(nums[j] != 0){
                        //Hago swap
                        swap(nums, i, j);
                        break;
                    }
                    
                    j++;
                }
            }
            
            if(j == nums.size()){
                break;
            }
            
            i++;
        }
        */
        
        
        

        //Index
        //Solución Alexa :)
        //Runtime: O(n)
        //Memory: O(1)
        
        int index1 = 0;
        
        //[2, 0, 3, 4, 0, 0, 5]
        //[1,0,1]
        //[1,1,0]
        
        //Recorro toda la lista a partir del segundo index. O(n)
        for(int i = 1; i < nums.size(); i++){
            
            //Si el primer valor es diferente de 0 lo recorremos 1 espacio
            if(nums[index1] != 0){
                index1++;
            }
            
            //Si el valor en index1 es 0 y el valor en nums[i] es diferente de 0
            if(nums[index1] == 0 && nums[i] != 0){

                nums[index1] = nums[i]; //Hacemos switch de valores
                nums[i] = 0;
                index1++;

            }
        }
        
    }
    
    /*
    void swap(vector<int> & nums, int i, int j){
        int aux = nums[i];
        nums[i] = nums[j];
        nums[j] = aux;
    }
    */
};