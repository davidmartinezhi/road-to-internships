#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        /*
        1. listen
            input: n*n matrix, representing an image, rotate the image by 90 degrees
            The rotation must be in-place
            matrix "n" is between 1 and 20
            
        2. example
            [[1,2,3],
            [4,5,6],
            [7,8,9]]
            
        3. brute force
        
            Para reacomodar los elementos de row a col y col a row
            Recorro i de 0 a n
                recorro j de i a n
                con swap
            
            Luego reverseo cada lista dentro de la matrix
            
            Runtime: O(n^2) talvez n log n
            memory:O(n)
            
            
        4. optimize
        5.  walktrough
        6. implement
        7. test
        */
        
        int n = matrix[0].size();
        
        //Si la matriz tiene un solo elemento regreso directo
        if(n == 1){
            return;
        }
        
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                int aux = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = aux;
            }
        }
        
        
        //Recorro cada renglon
        for(int i = 0; i < n; i++){
            
            int start = 0;
            int end = n - 1;
            
            while(start < end){
                int aux = matrix[i][start];
                matrix[i][start] = matrix[i][end];
                matrix[i][end] = aux;
                
                start++;
                end--;
            }
            
        }        
    }
};

/*
41 minutos
*/