#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
    /*
        1. listen
            
            input: m * n integer matrix
            
            if an element is 0, set its entire row and column to 0`s
            
            output: the resulting matrix
            
            m and n, size are between 1 and 200
            int values are between INT_MIN and INT_MAX
            
        2. example
            [[1,1,1],[1,0,1],[1,1,1]]
            [[1,0,1],[0,0,0],[1,0,1]]
            
            [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
            [[0,0,0,0],[0,4,5,0],[0,3,1,0]] 
        
        3. brute force
            Traverse the matrix once and mark the col and row ehre a 0 is found
            then modify those colummns and rows
            runtime: O(m+n)
            space: O(m+n)
            
            Use a vector for cols and rows
            
        4. optimize
            BCR: O(m+n)
            space must be: O(1)
            
        
        5. walkthrough
            Space: O(m+n)
                Initialize rows and cols vector, then traverse to mark them
                Finally traverse to set those marks in the matrix to zero
                
            Space: O(1)
                Use the first row and column to mark the cols and row that will be set to 0
                Use the matrix[0][0] to know if the fisrt row and col should be set all to 
                    zeroes at the end 
            
        6. implement
        
        7. test
            - 1*1 matrix
            -matrix without 0
            -matrix with 0
            -matrix with a 0 in the first col
            -matrix with a zero in the firt row
    */
    
        
        //size of m and n
        int rows = matrix.size();
        int columns = matrix[0].size();
        
        //Check if first column or row, must be set to 0
        bool firstRow = false;
        bool firstCol = false;
        
        for(int i = 0; i < rows; i++){
            //firstColumn Check
            if(matrix[i][0] == 0){
                firstCol = true;
            }
        }
        
        for(int i = 0; i < columns; i++){
            //firstRow Check
            if(matrix[0][i] == 0){
                firstRow = true;
            }
        }

        //Modify first row and column to know if the body must be set to 0
        for(int row = 1; row < rows; row++){
            for(int col = 1; col < columns; col++){
                //Traverse the matrix to set 0s
                
                if(matrix[row][col] == 0){
                    //Check cero inside the matrix
                    matrix[0][col] = 0;
                    matrix[row][0] = 0;
                }  
            }
        }
        
        //Convert rows and columns to 0
        for(int row = 1; row < rows; row++){
            for(int col = 1; col < columns; col++){
                
                //Check if the row or column is a 0
                if(matrix[row][0] == 0 || matrix[0][col] == 0){
                    matrix[row][col] = 0;
                }
                
            }
        }
        
        //Convert First Col to 0
        if(firstCol){
            for(int i = 0; i < rows; i++){
                matrix[i][0] = 0;
            }
        }
        
        //Convert First Row to 0
        if(firstRow){
            for(int i = 0; i < columns; i++){
                matrix[0][i] = 0;
            }             
        }
    }
};
/*
Notas:
    Terminado en los 45 minutos
    Runtime: O(m*n)
    Space: O(1)

    -La idea sobre como hacerlo, lo saque rapido
    -Ya sabía como solucionarlo y tenía un error al actualizar la primer fila y columna
        Solo que por querer resolverla de golpe, perdí tiempo.

    -Lo saque rapido una vez que me frene a pensar sobre donde encajar la solución

    -Debería de dejar de programar y pensar sobre como aplicar una sección, antes de moverle al codigo sin saber.
*/