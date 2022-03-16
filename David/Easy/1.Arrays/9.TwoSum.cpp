#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Listen
            //I receive an array (nums) with integers and a target integer
            //I must return two indices, the numbers that add up to the target
            //Each input has exactly one solution
            //I can't use the same element twice
            //I can return the answer in any order
            //Array size varies between 2 and 10,000
            
        // Example
            // nums = [1, 2, 3, 7, 10] , target = 17 -> [3, 4]
            // nums = [0, 2, 3], target = 2 -> [0, 1] 
        
            //Solo observo el caso de que si existe una solución
            //Siento que no existe un special case en este problema
        
        // Brute Force
            //Por cada numero, recorrer el resto de la lista para comparar la suma con el target
            //Tendría eficiencia runtime O(N^2) y memory O(1)
            
        // Optimize
            //Si decido iterar ambas listas, deberia almenos poner un break cuando encuentre la pareja
                //O regresar los indices de manera directa
        
            //Podria hacer un sort
                //Luego usar metodo estilo binary search para comparar valores
                //Podría sacar O(N log N) runtime y memoria O(N)
        
            //Puedo usar hashtables
                //Meto los datos y luego al recorrer la lista
                //Saco target - el valor en el que estoy
                    //Lo busco en la hashtable, si existe me da el resultado
                //Puede sacar memoria O(N) y runtime O(N) average, 
                    //si existieran colisiones en todas las celdas del hashtable sería runtime O(N^2)
                    //Considerando que yo fuera a usar unordered_map
            
        
        // Walkthrough
            //Primero haré el approach de O(N^2) de manera secuencial
            //Por cada numero de la lista, recorro los numeros restantes a la derecha
                //Si encuentro la suma que me regresa el target, regreso la respuesta
        
        // Implement
        // Test
            //Asumire que todas las respuestas tienen una solución y no pondre un caso de que no tenga
            
        
        /*
        //Resultado con eficiencia O(N^2) runtime y O(1) Memory
        //Resuelto de manera secuencial
        
        for(int i = 0; i < nums.size() - 1; i++){   //Recorro cada numero
            for(int j = i + 1; j < nums.size(); j++){   //Recorro el resto de numeros a su derecha
                
                //Checo si la suma es igual al target
                if(nums[i] + nums[j] == target){    //Si es así
                    vector<int> aux = {i, j};   //Creo vector auxiliar con respuesta
                    return aux; //Regreso resultado
                }
            }
        }
        
        return vector<int>(0);
        */
        
        /*
        //Solución alterna usando Hashtable, usando unordered_map
        //Recorro la lista de manera normal y para cada num hago la operación
            //Target - num[i]
            //Busco el resultado en la hashtable y si no se encuentra, agrego (num[i], index) al ht
        //Así recorro toda la lista
        
        unordered_map<int, int> matches;
        vector<int> result = {};
        
        for(int i = 0; i < nums.size(); i++){   //Recorro todos los numeros del array
            
            int aux = target - nums[i]; //Saco el numero que me daría el target como resultado
            
            if(matches.find(aux) != matches.end()){ //Si el numero aux esta en mi hashtable
                
                result.push_back(matches[aux]); //Agrego ese numero al vector resultado
                result.push_back(i);    //Agrego el index i a mi vector resultado
                return result;  //Regreso el resultado
            }
            else{
                //Si no esta el valor en la hashtable, se agrega junto con su index
                matches[nums[i]] = i; 
            }
            
        }
        return result;  //Se regresa el result en caso de que no exista resultado
        */
        
        //Resultado O(N log N), de las respuestas con mejor runtime en leetcode.
        vector<int> b;
        
        int n = nums.size();
        
        //O(N) memoria, O(N) runtime
        for (int i=0;i<n;i++)   //Copia lista original
            b.push_back(nums[i]);
        
        //O(N log N) runtime, O(1) memoria
        sort(nums.begin(),nums.end());  //Hace sort de la original
        
        //O(N) runtime, O(1) memoria
        vector<int> ans;//Crea vector para regresar resultado
        int start =0;   //Apuntador a inicio del array
        int end = n-1;  //Apuntador al final del array
        
        while(end>start){    //Mientras no se crucen los apuntadores
        
            if(target==nums[start]+nums[end]){   //Si la suma de ambos apuntadores es el target
                                                //Se regresa el resultado
                   ans.push_back(nums[start]);
                   ans.push_back(nums[end]);
                                 break;
            }
            
            if (target < nums[start]+nums[end]){    //Si el target es menor, decremento el apuntador
                                                    //del final
            
                   end--;
            }
            
            if (target > nums[start]+nums[end]){    //Si el target es mayor, incremento el apuntador
                                                    //del inicio
            start++;
            }
        }
        
        
        //O(N+N) = O(N) runtime, O(1) memory
           for(int i=0;i<n;i++) //Recorre el array copia del original antes del sort
           {
                if(b[i] == ans[0])  //Si el valor es el mismo que el del resultado, index se actualiza
                {
                    ans[0]=i;
                    break;
                }
            }

            for(int i=n-1;i>=0;i--) //Actualiza index al correspondiente
            {
                if(b[i]==ans[1])
                {
                    ans[1]=i;
                    break;
                }
            }

        return ans ;

    }
};
/*
Nota:
    -Terminado en menos de 20 minutos, pero se que podría mejorar la eficiencia al hacer un precompute en el array, antes de analizarlo y hacer la logica.
    -Mi solución de brute force estuvo rapida de sacar e implementar, debo recordar de aplicar hashtable seguido y checar rapido si puede aplicar
    -Me tarde en la optimización. Si pense en hacer un sort desde el inicio pero no aterrice la idea.
    -Resulto ser una buena idea y si valia la pena almenos adentrarme a investigar como podia funcionar
        -Pude haber sacado el resultado más optimo en menos de 40 minutos, si hubiera investigado eso.
        -Pude asumir que estaba ordenada la lista y aplicar el DIY technique, para ver la posibilidad de sacar el problema.
*/