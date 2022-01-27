//Alexa Arreola 26/01/2022
//Tiempo: 50 min

//1. Info
//Tomando en cuenta que son los valores de compra-venta de stocks en el mercado, maximizar la ganancia y regresar valor

//You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

//On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.

//Find and return the maximum profit you can achieve.

//Constraints:

//1 <= prices.length <= 3 * 104
//0 <= prices[i] <= 104
////////////////////////////////////////////////
//2. Ejemplo
//Input: prices = [7,1,5,3,6,4]
//Output: 7

//Input: prices = [1,2,3,4,5]
//Output: 4

//Input: prices = [7,6,4,3,1]
//Output: 0
/////////////////////////////////////////////////
//3. Primera solución

//Buscar el más chico, luego el más grande y sacar la diferencia, después seguir al siguiente más chico y más grande y sumar la diferencia

//Memory: O(1)   Runtime: O(n)

//4. Aún no se me ocurre como optimizarlo



class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        //Inicializa conteo y max,min
        int cuenta = 0;
        int min = prices[0];
        int max = prices[0];
        
        //Runtime: O(n)
        //Memoy: O(1)
        
        
        for(int i = 1; i < prices.size(); i++){
            
            //Buscamos el primer valor mas pequeño
            if(min > prices[i] && max==min){
                min = prices[i];
                max = prices[i];
            }
            //Buscamos el primer valor mas grande
            else if(max < prices[i]){
                max = prices[i];
                
                if(i == prices.size()-1){
                    cuenta = cuenta + (max-min);
                }
            }
            
            //Cuando despues de un num. grande siga uno chico, se hace la diferencia para sacar la ganancia
            //Se resetean los valores de max y min
            else{
                cuenta = cuenta + (max-min);
                min = prices[i];
                max = prices[i];
            }
            
        }
        
        //Regresa ganancias
        return cuenta;
    }
};