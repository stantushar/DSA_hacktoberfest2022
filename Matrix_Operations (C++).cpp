#include <iostream>
using namespace std;

int main()
{
    cout << "\t\t\t\t\t\t\t***** SPARSE MATRIX OPERATIONS *****\n\n";
    
    // Accepting Matrix 1
    cout << "Enter Matrix 1 :" << endl;
    
    int Row_1, Column_1;
    cout << "Number of Rows & Columns (Enter Space Seperated) : ";
    cin >> Row_1 >> Column_1;
    
    int Array_1[Row_1][Column_1];
    
    for (int i = 0; i < Row_1; i++){
        for (int j = 0; j < Column_1; j++){
            cin >> Array_1[i][j];
        }
    }
    
    cout << "\n";
    
    // Accepting Matrix 2
    cout << "Enter Matrix 2 :" << endl;
    
    int Row_2, Column_2;
    cout << "Number of Rows & Columns (Enter Space Seperated) : ";
    cin >> Row_2 >> Column_2;
    
    int Array_2[Row_2][Column_2];
    
    for (int i = 0; i < Row_2; i++){
        for (int j = 0; j < Column_2; j++){
            cin >> Array_2[i][j];
        }
    }
    
    // *************************************************************************
    
    // Checking Sparse or Not (If NOT, then TERMINATING Program)
    int Zero_Counter1 = 0;
    int Zero_Counter2 = 0;
    
    for (int i = 0; i < Row_1; i++){
        for (int j = 0; j < Column_1; j++){
            if (Array_1[i][j] == 0){
                Zero_Counter1 ++;
            }
        }
    }
    
    if (Zero_Counter1 > ((Row_1 * Column_1)/2)){
        cout << "\nMatrix 1 is Sparse";
    }
    else{
        cout << "\nMatrix 1 is not Sparse";
        cout << "\nProblem Statement has Requirement of ONLY SPARSE MATRIX";
        exit(0);
    }
    
    
    for (int i = 0; i < Row_2; i++){
        for (int j = 0; j < Column_2; j++){
            if (Array_2[i][j] == 0){
                Zero_Counter2 ++;
            }
        }
    }
    
    if (Zero_Counter2 > ((Row_2 * Column_2)/2)){
        cout << "\nMatrix 2 is Sparse" << endl;
    }
    else{
        cout << "\nMatrix 2 is not Sparse";
        cout << "\nProblem Statement has Requirement of ONLY SPARSE MATRIX";
        exit(0);
    }
    
    // *************************************************************************
    // Sparse Matrix Converter
    int Non_Zero_Counter1 = (Row_1 * Column_1) - Zero_Counter1;
    int Non_Zero_Counter2 = (Row_2 * Column_2) - Zero_Counter2;
    
    int Sparse_Matrix_1[Non_Zero_Counter1][3], Sparse_Matrix_2[Non_Zero_Counter2][3];
    
    // Sparse Matrix 1
    int k1 = 0;
    for (int i = 0; i < Row_1; i++){
        for (int j = 0; j < Column_1; j++){
            if (Array_1[i][j] != 0){
                Sparse_Matrix_1[k1][0] = i;
                Sparse_Matrix_1[k1][1] = j;
                Sparse_Matrix_1[k1][2] = Array_1[i][j];
                k1++;
            }
        }
    }
    
    // Sparse Matrix 2
    int k2 = 0;
    for (int i = 0; i < Row_2; i++){
        for (int j = 0; j < Column_2; j++){
            if (Array_2[i][j] != 0){
                Sparse_Matrix_2[k2][0] = i;
                Sparse_Matrix_2[k2][1] = j;
                Sparse_Matrix_2[k2][2] = Array_2[i][j];
                k2++;
            }
        }
    }
    
    // *************************************************************************
    // Displaying Sparse Matrices
    cout << "\nSparse Matrix 1 (Order --> Row | Column | Value)" << endl;
    for (int x = 0; x < k1; x++){
        for (int y = 0; y < 3; y++){
            cout << Sparse_Matrix_1[x][y] << " ";
        }
        cout << "\n";
    }
    
    cout << "\nSparse Matrix 2 (Order --> Row | Column | Value)" << endl;
    for (int x = 0; x < k2; x++){
        for (int y = 0; y < 3; y++){
            cout << Sparse_Matrix_2[x][y] << " ";
        }
        cout << "\n";
    }
    
    
    // Making Menu-Driven
    char Choice;
    
    while(1){
        cout << "\n\nPress 1 to Display the Simple Transpose of the Sparse Matrices";
        cout << "\nPress 2 to Display the Fast Transpose of the Sparse Matrices";
        cout << "\nPress 3 to Add the Two Sparse Matrices";
        cout << "\nPress 4 to Exit";
        
        cout << "\n\nUser's Choice : ";
        cin >> Choice;
        
        switch(Choice){
            case '1':                                                       // Simple Transpose of Matrix & Displaying Sparse
            {
                int Simple_Transpose_Matrix_1[Row_1][Column_1], Simple_Transpose_Matrix_2[Row_2][Column_2];
                
                for (int i = 0; i < Row_1; i++){
                    for (int j = 0; j < Column_1; j++){
                        Simple_Transpose_Matrix_1[j][i] = Array_1[i][j];
                    }
                }
                for (int i = 0; i < Row_2; i++){
                    for (int j = 0; j < Column_2; j++){
                        Simple_Transpose_Matrix_2[j][i] = Array_2[i][j];
                    }
                }
                
                // Displaying Simple Transpose Of Both Sparse Matrices
                cout << "\nSimple Transpose of Sparse Matrix 1 : " << endl;
                for (int i = 0; i < Row_1; i++){
                    for (int j = 0; j < Column_1; j++){
                        if (Simple_Transpose_Matrix_1[i][j] != 0){
                            cout << i << " " << j << " "<< Simple_Transpose_Matrix_1[i][j] << " " << endl;
                        }
                    }
                }
                
                cout << "\nSimple Transpose of Sparse Matrix 2 : " << endl;
                for (int i = 0; i < Row_2; i++){
                    for (int j = 0; j < Column_2; j++){
                        if (Simple_Transpose_Matrix_2[i][j] != 0){
                            cout << i << " " << j << " "<< Simple_Transpose_Matrix_2[i][j] << " " << endl;
                        }
                    }
                }
                
                break;
            }
            
            case '2':                                                          // Performing Fast Transpose
            {
                // Defining 3 Arrays --> Total, Index & Fast_Transpose Array
                int Location_1, C_Number_1, Total_1[Column_1], Index_1[Column_1 + 1], Fast_Transpose_1[k1][3];
                
                // Declaring All Elements of Total Array to 0 (Initially)
                for (int i = 0; i < Column_1; i++){
                    Total_1[i] = 0;
                }
                
                // Filling Frequencies of each column to Total
                for (int i = 0; i < k1; i++){
                    Total_1[Sparse_Matrix_1[i][1]] += 1;
                }
                
                Index_1[0] = 1;    
                // Filling Index Array
                for (int i = 1; i < (Column_1 + 1); i++){
                    Index_1[i] = Index_1[i - 1] + Total_1[i - 1];
                }
                
                // Main Code for Fast Transpose
                for (int i = 0; i < k1; i++){
                    C_Number_1 = Sparse_Matrix_1[i][1];
                    Location_1 = Index_1[C_Number_1];
                    Fast_Transpose_1[Location_1 - 1][0] = Sparse_Matrix_1[i][1];
                    Fast_Transpose_1[Location_1 - 1][1] = Sparse_Matrix_1[i][0];
                    Fast_Transpose_1[Location_1 - 1][2] = Sparse_Matrix_1[i][2];
                    Index_1[C_Number_1]++;
                }
                
                // Displaying Fast Transpose
                cout << "\nFast Transpose of Sparse Matrix 1 : " << endl;
                for (int i = 0; i < k1; i++){
                    for (int j = 0; j < 3; j++){
                        cout << Fast_Transpose_1[i][j] << " ";
                    }
                    cout << "\n";
                }
                
                // Matrix 2
                // Defining 3 Arrays --> Total, Index & Fast_Transpose Array
                int Location_2, C_Number_2, Total_2[Column_2], Index_2[Column_2 + 1], Fast_Transpose_2[k2][3];
                
                // Declaring All Elements of Total Array to 0 (Initially)
                for (int i = 0; i < Column_2; i++){
                    Total_2[i] = 0;
                }
                
                // Filling Frequencies of each column to Total
                for (int i = 0; i < k2; i++){
                    Total_2[Sparse_Matrix_2[i][1]] += 1;
                }
                
                Index_2[0] = 1;    
                // Filling Index Array
                for (int i = 1; i < (Column_2 + 1); i++){
                    Index_2[i] = Index_2[i - 1] + Total_2[i - 1];
                }
                
                // Main Code for Fast Transpose
                for (int i = 0; i < k2; i++){
                    C_Number_2 = Sparse_Matrix_2[i][1];
                    Location_2 = Index_2[C_Number_2];
                    Fast_Transpose_2[Location_2 - 1][0] = Sparse_Matrix_2[i][1];
                    Fast_Transpose_2[Location_2 - 1][1] = Sparse_Matrix_2[i][0];
                    Fast_Transpose_2[Location_2 - 1][2] = Sparse_Matrix_2[i][2];
                    Index_2[C_Number_2]++;
                }
                
                // Displaying Fast Transpose
                cout << "\nFast Transpose of Sparse Matrix 2 : " << endl;
                for (int i = 0; i < k2; i++){
                    for (int j = 0; j < 3; j++){
                        cout << Fast_Transpose_2[i][j] << " ";
                    }
                    cout << "\n";
                }
                break;
            }
            
            case '3':                                                   // Addition of Matrix & Displaying Sparse
            {
                if ((Row_1 == Row_2) && (Column_1 == Column_2)){
                    int Row = Row_1;
                    int Column = Column_1;
                    int Added_Array[Row][Column];
                    
                    for (int i = 0; i < Row; i++){
                        for (int j = 0; j < Column; j++){
                            Added_Array[i][j] = Array_1[i][j] + Array_2[i][j];
                        }
                    }
                    
                    // Display Added Matrix
                    cout << "\nAdded Sparse Matrix (Order --> Row | Column | Value)" << endl;
                    for (int i = 0; i < Row; i++){
                        for (int j = 0; j < Column; j++){
                            if (Added_Array[i][j] != 0){
                                cout << i << " " << j << " "<< Added_Array[i][j] << endl;
                            }
                        }
                    }
                }
                
                else{
                    cout << "\nCannot Add Matrices, if they are of different Orders";
                }
                break;
            }
            
            case '4':
                cout << "\n\nTHANK YOU :) HAVE A GREAT DAY :D";
                exit(0);
                
            default:
                cout << "\nInvalid Input !!!";
                break;
        }
    }    
    return 0;
}