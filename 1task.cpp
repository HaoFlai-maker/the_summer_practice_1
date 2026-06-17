#include <iostream>
#include <algorithm>

int main(){
    int n = 0;
    std::cin >> n;
    int* ans = new int[n];

    int l = 0;
    int sum = 0;
    int mn = 10000;
    
    for(int i = 0; i < n; i++) {
        l++;
        int* mas = new int[l];
        for(int j = 0; j < l; j++) {
            std::cin >> mas[j];
            if(mas[j] < mn) {
                mn = mas[j];
            }
        }
        sum += mn;
        ans[i] = mn;
        delete[] mas;
    }
    std::cout << sum << std::endl;
    for(int i = 0; i < n; i++) {
        std::cout << ans[i] << " ";
    }
    delete[] ans;
}