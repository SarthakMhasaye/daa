#include <iostream>
#include <vector>
using namespace std;

// Add two square matrices of size n x n.
vector<vector<int>> addMatrix(const vector<vector<int>>& A,const vector<vector<int>>& B){
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            C[i][j] = A[i][j] + B[i][j];
        }
    }
    return C;
}
vector<vector<int>> subtractMatrix(const vector<vector<int>>& A,const vector<vector<int>>& B){
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            C[i][j] = A[i][j] - B[i][j];
        }
    }
    return C;
}
vector<vector<int>> strassen(const vector<vector<int>>& A,const vector<vector<int>>& B){
    int n = A.size();
    if (n == 1){
        return {{A[0][0] * B[0][0]}};
    }
    int half = n / 2;
    vector<vector<int>> A11(half, vector<int>(half));
    vector<vector<int>> A12(half, vector<int>(half));
    vector<vector<int>> A21(half, vector<int>(half));
    vector<vector<int>> A22(half, vector<int>(half));
    vector<vector<int>> B11(half, vector<int>(half));
    vector<vector<int>> B12(half, vector<int>(half));
    vector<vector<int>> B21(half, vector<int>(half));
    vector<vector<int>> B22(half, vector<int>(half));
    // Split A and B into four smaller matrices each.
    for (int i = 0; i < half; i++){
        for (int j = 0; j < half; j++){
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + half];
            A21[i][j] = A[i + half][j];
            A22[i][j] = A[i + half][j + half];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + half];
            B21[i][j] = B[i + half][j];
            B22[i][j] = B[i + half][j + half]; 
        }
    }
    auto P1 = strassen(A11, subtractMatrix(B12, B22));
    auto P2 = strassen(addMatrix(A11, A12), B22);
    auto P3 = strassen(addMatrix(A21, A22), B11);
    auto P4 = strassen(A22, subtractMatrix(B21, B11));
    auto P5 = strassen(addMatrix(A11, A22), addMatrix(B11, B22));
    auto P6 = strassen(subtractMatrix(A12, A22), addMatrix(B21, B22));
    auto P7 = strassen(subtractMatrix(A11, A21), addMatrix(B11, B12));
    auto C11 = addMatrix(subtractMatrix(addMatrix(P5, P4), P2), P6);
    auto C12 = addMatrix(P1, P2);
    auto C21 = addMatrix(P3, P4);
    auto C22 = subtractMatrix(subtractMatrix(addMatrix(P5, P1), P3), P7);
    vector<vector<int>> C(n, vector<int>(n));
    // Combine result submatrices into the full result.
    for (int i = 0; i < half; i++){
        for (int j = 0; j < half; j++){
            C[i][j] = C11[i][j];
            C[i][j + half] = C12[i][j];
            C[i + half][j] = C21[i][j];
            C[i + half][j + half] = C22[i][j]; } }
    return C; 
}
// Print a matrix to the console.
void printMatrix(const vector<vector<int>>& matrix){
    for (const auto& row : matrix){
        for (int value : row){
            cout << value << " ";}
        cout << '\n'; }}
int main(){
    vector<vector<int>> A = {{1, 2}, {3, 4}};
    vector<vector<int>> B = {{5, 6}, {7, 8}};
    cout << "Matrix A:\n";
    printMatrix(A);
    cout << "\nMatrix B:\n";
    printMatrix(B);
    vector<vector<int>> C = strassen(A, B);
    cout << "\nResult Matrix:\n";
    printMatrix(C);
    return 0; 
}
