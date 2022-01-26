//1. Escuchar info
//Remover duplicados, regresar cantidad de numeros k sin duplicar, modificar el mismo array para que los primeros numeros sean los útiles, no importa los valores que se encuentren después de k
//Retricciones: memory O(1)

//2. Ejemplo
//Input: nums = [1,1,2,4,8,10,10]
//Output: 5, nums = [1,2,4,8,10,-,-]
//3. Fuerza Bruta
//Inicializar cont = length de array
//Checar con dos apuntadores si el siguiente es mayor, si no lo es le resta 1 al cont, 

//Se pasa de tiempo:
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k= nums.size();
         if(k==0){
            return 0;
        }
        int base = nums[0];
        int error = base - 1;
        
       
        
        //O(n)
        for(int i = 1; i<nums.size(); i++){
            
            if(base == nums[i]){
                nums[i] = error;
                k = k-1;
            }
            
            if(base < nums[i]){
                base = nums[i];
            }

        }
        
        //O(n^2)
        for(int i = 0; i<nums.size(); i++){
            if(nums[i]==error){
                for(int j = i+1; j<nums.size();j++){
                    if(nums[j] != error){
                        nums[i] = nums[j];
                        nums[j] = error;
                        break;
                    }
                }
            }
        }
        return k;
    }
};

//Optimizar: dos apuntadores con uno fijo