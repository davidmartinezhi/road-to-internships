/*
Alexa Arreola 27/01/2022
Tiempo: 23 minutos

1. Regresar intersection de numeros entre 2 arrays dados en un nuevo array, si se repiten dos veces los numeros tmb tiene que estar en la respuesta

No importa el orden del array de regreso

Constraints:

1 <= nums1.length, nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 1000

2. Ejemplos

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2,2]

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [4,9]
Explanation: [9,4] is also accepted.

3. Fuerza bruta

Hash table donde key = numero y valor sea un vector de 2 valores: primero el conteo de uno y despues del otro
checar valor por valor el numero del vector en el hash mas chico y guardarlo en un array

Hash table donde se guarde la info de 1 vector, se va buscando los valores del segundo y si coinciden, se le resta 1 al valor y se guarda en un array


*/


//Runtime = O(n+m) 
//Memory = O(n)

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        
        //mapa para nums1
        unordered_map<int, int> mapa1;
        
        //respuesta
        vector<int> respuesta;
        
        //Guarda nums1 en mapa1 considerando key = valor y value = contador
        //O(n)
        for(int i = 0; i < nums1.size(); i++){
            mapa1[nums1[i]]++;
        }
        
        //Recorremos nums2
        //O(m)
        for(int j = 0; j < nums2.size(); j++){
           // Error: if(nums2[j] == mapa1[j] && mapa1[j]!=0){
            
            //Si encuentra key con contador mayor a 0
            if(mapa1[nums2[j]]> 0 ){
                //se añade valor a respuesta
                respuesta.push_back(nums2[j]);
                //Se le resta del contador:
                mapa1[nums2[j]]--;
            }
        }
        
        return respuesta;
        
        
    }
};