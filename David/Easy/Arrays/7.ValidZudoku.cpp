#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        /*
        1. listen
            
            Determine if a 9x9 sudoku board is valid
            
            valid sudoku board:
                -each row contains 1-9 digits without repetition
                -each column contains 1-9 digits without repetition
                -each sub matrix 3x3 contains 1-9 digits without repetition
            
            Only the filled cells need to be validated
            
        2. example
        
            Cuaderno
        
        3. brute force
            
            Hashtable auxiliar para guardar digitos
            Hacer 3 recorridos de la matriz (despues de cada recorrido, vacío la matriz)
                -recorro renglones
                -recorro columnas
                -recorro submatrices 3x3
                
            runtime: O(9x9 + 9x9 + 9x9 + (vacíar hashtable 2 veces = 9+9))
            runtime: O(1) constante, siempte se recorrera esa misma cantidad de veces en el pero caso
            memory: O(1) La hashtable tendra un tamaño maximo de 9. y siempre guardará 9 datos
            
        4. Optimize
        
            Podría hacer 2 hashtables para checar columnas y renglones en un solo recorrido?
            
            Iré por la brute force primero
        
        5. walkthrough
            
            Creo hashtable auxiliar
            
            recorro renglones
            
            recorro columnas
            
            recorro 3 x 3
            
            Si en algún momento la hashtable tiene numeros repetidos, regreso false
            
            Si recorre todo sin problemas, regreso true
            
        6. implement
        
        7. test
                -numeros repetidos en renglones
                -numeros repetidos en columnas
                -numeros repetidos en sub-matrix
                -no se repiten numeros
            
        */
        
        //Checamos columnas y renglones
        
        for(int i = 0; i < 9; i++){
            
            unordered_map<char,int> col;
            unordered_map<char,int> row;
            
            for(int j = 0; j < 9; j++){
                
                //Checamos rows
                if(board[i][j] != '.'){
                    
                    row[board[i][j]]++;
                    
                    if(row[board[i][j]] > 1){
                        return false;
                    }
                }
                
                //Checamos columns
                if(board[j][i] != '.'){
                    
                    col[board[j][i]]++;
                    
                    if(col[board[j][i]] > 1){
                        return false;
                    }
                }
            }
        }
        
        //Checamos sub matrices
        for(int i = 0; i < 9; i+= 3){
            
            for(int j = 0; j < 9; j+=3){
                unordered_map<char, int> ht;
                
                for(int k = 0; k < 3; k++){
                    
                    for(int h = 0; h < 3; h++){
                                            
                        if(board[i+h][j+k] != '.'){
                            
                            ht[board[i+h][j+k]]++;
                            
                            if(ht[board[i+h][j+k]] > 1){
                                return false;
                            }
                            
                        }
                        
                    }

                }
                
            }
                
        }
        
        return true;
    }
};