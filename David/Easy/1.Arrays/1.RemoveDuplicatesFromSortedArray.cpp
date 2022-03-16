#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // 1 listen
        /*
            input: integer array nums, sorted in increasing order
            output: k
            k = number of unique elements
            
            remove duplicates in place
            each unique element must appear only once
            relative order of the numbers should be kept the same
       

            Result must be placed in the first k-1 indices of the array

            Return K
            
            Array has between 0 and 30,000 elements
            Nums are sorted in non-decreasing order
        
        */
        
        // 2 example
        /*
            [1,1,2]
            
            [0,0,1,1,1,2,2,3,3,4]
        */
        
        // 3 brute force
        /*
            Usar metodo para borrar elemento del vector, en cualquier index donde se repita algún 
            valor.
            O(n^2), linear despues del elemento borrado. Si todos los elementos son iguales F.
        
        */
        // 4 optimize
        /*
            Pointer que representa k, y se encarga de acomodar los numeros que no se repiten
            Pointer que va recorriendo la lista de numeros, hasta el final
            
            si el pointer que recorre es mayor al que marca k, recorro el que marca k y 
            ahora ese valor será el nvalor que fue diferente a k.
            
            runtime: O(n)
            memory: O(1)
        */
        
        // 5 walkthrough
        /*
            pointer que recorre todo el array
            pointer estaca que comienza desde el inicio
            
            cuando el valor en el pointer que recorre sea mayor a estaca
            recorro estaca uno y le doy el valor en el que está el pointer que se recorre
        */
        // 6 implement
        
        // 7 test
        /*
            
            
            Special Cases:
                Array vacío
                Array donde todos los numeros son el mismo
                
        */
        
        //Erase
        //runtime: O(n^2)
        //memory: O(1)
        /*
        //Si el array no tienen ningún elemento, regreso
        if(nums.size() == 0){
            return 0;
        }
        
        int j = 1;
        
        while(j < nums.size()){
            
            if(nums[j-1] == nums[j]){
                nums.erase(nums.begin() + j);
            }
            else{
                j++;
            }
            
        }
        
        return nums.size();
        
        */
        
        //Double pointer
        //runtime: O(n)
        //memory: O(1)
        
        //Si el array no tienen ningún elemento, regreso 0
        if(nums.size() == 0){
            return 0;
        }
        
        //Si el array tiene elementos
        
        int k = 0;  //Apuntador a indice donde siempre estarán los valores unicos. memory: O(1)
        
        for(int i = 0; i < nums.size(); i++){   //O(n) runtime
            
            //Si el valor en el que estamos, es mayor que nums[k]
            if(nums[k] < nums[i]){
                k++;    //Recorro nums[k]
                nums[k] = nums[i];  //Agrego el valor
            }
        }
        
        return k+1;
        
    }
};
/*

*/