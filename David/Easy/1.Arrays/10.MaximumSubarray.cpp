#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        /*
        1. listen
            input: integer array nums
            
            find the coniguous subarray (containing at leat one number).
            Whitch has the largest sum
            
            return it's sum
            
            subarray is a contiguous part of the array.
            
            nums length is between 1 and 100,000
            nums[i] values are in range from -10,000 to 10,000
        
        2. example
        
        [-2,1,-3,4,-1,2,1,-5,4]
        output: 6
        
        [1]
        output: 1
        
        [5, 4, -1, 7, 8]
        output: 23
        
        3. brute force
            para cada elemento recorrer el resto de la lista, siempre checar la suma
            y 
            guardar la suma maxima. De la misma manera que en unity guardamos al
            enemigo más cercano
            
            Runtime: O(n^2)
            memory: O(1)
            
            
        4. optimize
            Slidingi window technique
            
            runtime: O(n)
            memory: O(n^2)
            
            BCR: O(n)
            afuerzas debo recorrer el array una vez almenos.
            
        5. walkthrough
        
            brute force:
                declaro max_sum y lo igualo al primer valor del array
                creo nested for loops
                dentro del primer loop creo la variable de curr_sum
                cada elemento del otro loop lo sumo y si
                    el curr es mayor al max. max = curr
                    
            optimize:
                declaro apuntador i que marca el inicio de la window
                declaro maxsum
                
                recorro toda la lista con un apuntador j
                si la suma de la window actual es mayor a maxsum
                maxsum = currsum
                
                sino
                 mientras la currsum sea menor a maxsum
                desplazo i hasta que la suma sea mayor o i == j
                
                ------
                
                
        6. implement
        
        7, test
                -single element
                
                todo:
                    check in optimized solution if check previous currsum with max sum or previous currsum
            
        */
        
        //brute fore
        /*
        int maxSum = nums[0];
        
        for(int i = 0; i < nums.size(); i++){
            int currSum = 0;
            for(int j = i; j < nums.size(); j++){
                currSum += nums[j];
                
                if(currSum > maxSum){
                    maxSum = currSum;
                }
            }
        }
        
        return maxSum;
        */
        

        //Solución optima, Kadane's algorithm
        int maxSum = nums[0];  
        int sum = 0;
        
        //runtime: O(n)
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i]; //Agrego nuevo valor a la suma
            if(sum > maxSum) maxSum = sum;  //Si sum es mayor, actualizo maxSum
            if(sum < 0) sum = 0;    //Si sum es negativo, lo cambio a 0, para comenzar a contar de nuevo con el siguiente dato
            
            //Si sum es positivo, se queda como está. Sin importar si es mayo a maxSum o no
        }
        
        return maxSum;
        
    }
};
/*
Nota:

    //Antes de solución optima
    -Creo se resuelve con sliding window technique pero tengo duda sobre que condiciones utilizar
     para saber si debo recorrer i o no.

    -Brute force salio en 5 minutos

    -Optimized Solution no pasaba todos los casos de prueba y me consumio todo el tiempo restante

    -Debo volver a checar la logica del optimizedd solution, sino buscarla en youtube y poner atención en la comparación.

    Ya soy bueno para saber el recorrido que se necesita en cada tipo de problema, en este caso la logica fue lo que me confundio, pero voy muy bien.

    //Despues de solución optima
    -Si es complicado conseguir la respuesta con sliding window technique.
    -Después de investigar la respuesta más optima descubrí que es con un algoritmo que se llama Kadane's Algorithm)

*/