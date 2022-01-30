/*
Alexa Arreola 
Primer intento: 28/01/2022
Segundo intento ya bien: 30/01/2022

50 min sin nada JAJAJ, David me ayudó a sacar el primer intento aunque se pase de tiempo
Despues de ver la resp de david pos la puse parecida jajaj el 30 de enero

1. Cada dígito de un numero se guardó en orden en un array
Se debe sumarle uno al numero real y regresar un array con sus dígitos divididos
Nunca va a empezar con un 0

1 <= digits.length <= 100
0 <= digits[i] <= 9
digits does not contain any leading 0's.

2. 
Input: digits = [1,2,3]
Output: [1,2,4]

Input: digits = [4,3,2,1]
Output: [4,3,2,2]

Input: digits = [9]
Output: [1,0]

3. Fuerza bruta: 

sacar el numero como un solo int, sumarle uno, guardar la respuesta en otro vector

De atras para adelante buscar el primer 9, sumarle 1 a antes y poner en 0 el resto
Si el 9 es el primer elemento de la lista, se le tiene que agregar un elemento extraaaa



#include <math.h>
#include <algorithm> 

*/

class Solution {
public:
    
    vector<int> plusOne(vector<int>& digits) {
        
        
        
        vector<int> respuesta;
        int tam = digits.size();
        
        for(int i = 0; i<tam; i++){
            respuesta.push_back(digits[i]);
        }
        
        for(int i = 0; i < tam; i++){
            
            if(respuesta[tam-i-1] == 9){
                respuesta[tam-i-1] = 0;
            }
            else{
                respuesta[tam-i-1] = respuesta[tam-i-1]+1;
                break;
            }
        }
        
        if(respuesta[0] == 0){
            respuesta.push_back(0);
            respuesta[0] = 1;
        }
        
        return respuesta;
        
        
        /*
        //////////////// SI FUNCIONA PERO COMO QUE SE TARDA MUCHO, NO ES LA MEJOR OPCION  ///////////////////
        vector<int> respuesta;
        int num =0;
            
        for(int i = 0; i < digits.size(); i++){
        
   //   con esto pasas un vector a numero segun david     num = (num * 10 ) + digits[i];
            
            num = num + digits[i]*pow(10,digits.size()-1-i );
        }
        
        cout << num;
        num++;
        int aux;
        
        while(num>0){
            aux = num%10;
            respuesta.push_back(aux);
            num = num/10;
            
        }
        
        int start = 0;
        int end = respuesta.size()-1;
        
        //se rota
        while(start<end){
            
            int aux = respuesta[start];
            respuesta[start] = respuesta[end];
            respuesta[end] = aux;
            
            start++;
            end--;
        }
        

        return respuesta;
        
        
            
            
        ///////////////Este es otro intento, no funciona, pero es una idea///////////////////
        
        if(digits[digits.size()-1] != 9){
            
            for(int i = 0; i< digits.size()-1;i++){
                
                respuesta.push_back(digits[i]);
            }
            
            return respuesta.push_back(digits[digits.size()-1]+1);
        }
        
        int aux = 
        
        for(int i = digits.size()-1; i>0; i++){
            
            if(digits[i-1] != 9){
                
                if(digits[i-1] !=
                   
                respuesta[]
                digits[i-1]++;
                break;
                
            }
            
        }
            
        }
        
         */
    }
};