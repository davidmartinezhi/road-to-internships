#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        /*
        
        1. listen
            input: array of strings
            output: string with longest common prefix
            
            if there is no common prefix, return an empty string
            
            strings array has at least one word and max 200
            each string size ranges from 0 to 200
            strs[i] consists of only english words
        
        2. example
        
        ["flower","flow","flight"] -> "fl"
        ["dog","racecar","car"] -> ""
        
        
        3. brute force
            Pordría sacar el size de la palabra más pequeña al recorrer la lista una vez
            Luego recorrer todas las palabras de 0 a minsize con fixed window de 2
            si llegan a ser diferente en una parte, lo corto y ese valor es del nuevo common prefix
            Si llega a 0, regreso un empty string
            
            runtime: O(n*m), m siendo el size del longest common prefix
                    Si todas las palabras son la misma palabra, sería O(n^2)
            memory: O(1)
        
        4. optimize
            
            Podría sacar la palabra más pequeña
            Luego recorrer cada letra con cada palabra, y hacer string aux
            Cuando no sean iguales los strings, checo cual size es menor
            El de menor size es el common prefix
            
            runtime: O(n*m)
                Si todas las palabras son la misma palabra, sería O(n^2)
            memory: O(1)
            
            BCR: O(n^2)
            Afuerdzas debo checar los characteres en cada palabra
        
        5. walkthrough
            Recorro para sacar la palabra más pequeña y la defino como longest common prefix
            Recorro toda la lista
                Recorro cada palabra y comparo los characters
                Si no son iguales los characters, checo cual string tiene menor size
                Ese es el longest common prefix
        
        
        6. implement
        
        
        7. test
            -Todas las palabras son iguales
            -Todas las palabra son diferentes
            -Tengo 1 palabra
            -Tengo un empty string en el array
            -Existe un longest common prefix
        
        */
        
        /*
        //Longest common prefix
        string prefix = strs[0];
        
        //Recorro la lista y saco el string más pequeño
        for(int i = 0; i < strs.size(); i++){
            if(strs[i].size() < prefix.size()){
                prefix = strs[i];
            }
        }
        
        //Ahora recorro todo el array de nuevo
        for(int i = 0; i < strs.size(); i++){
            
            string auxString = "";  //Inicializo string auxiliar
            
            for(int j = 0; j < prefix.size(); j++){ //Recorro prefix
                
                if(strs[i][j] != prefix[j]){   //Si no son iguales los characters
                    break;  //Salgo
                }
                
                auxString += prefix[j]; //Le agrego el character a auxString
            }
                    
            if(auxString.size() < prefix.size()){  //Comparo para saber cual es mayor
                prefix = auxString; //Si auxString es menor, ahora ese es el prefix
            }
        }
        
        return prefix;
        */
        
        //Ordeno la lista
        sort(strs.begin(), strs.end());
        string result = ""; //String auxiliar
        
        //Recorro toda la primer palabra
        for(int i = 0; i < strs[0].size(); i++){
            
            
            if(strs[0][i] != strs[strs.size()-1][i]){
                //Si chars son diferentes, me salgo del loop
                break;
            }
            //Agrego el char a result
            result += strs[0][i];
        }
        
        return result;
    }
};