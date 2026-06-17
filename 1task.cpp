#include <iostream>
#include <algorithm>
#include <vector>

int main(){
    int n = 0;
    std::cin >> n;
    int** matrix = new int*[n];
    int** dp = new int*[n];

    int l = 0;
    int sum = 0;

    for(int i = 0; i < n; i++) {
        l++;
        matrix[i] = new int[l]; 
        dp[i] = new int[l];
        for(int j = 0; j < l; j++) {
            std::cin >> matrix[i][j];
        }
    }

    for(int j = 0; j < n; j++) {
        dp[n-1][j] = matrix[n-1][j];
    }

    for(int i = n - 2; i >= 0; i--) {
        for(int j = 0; j <= i; j++) {
            dp[i][j] = matrix[i][j] + std::min(dp[i+1][j], dp[i+1][j+1]);
        }
    }
    std::cout << dp[0][0] << std::endl;
}