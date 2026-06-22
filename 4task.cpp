#include <iostream>

int main(){
    int n = 0;
    int k = 0;

    std::cin >> n >> k;

    int* mas = new int[n];
    std::string line;

    for(int i = 0; i < n; i++){
        std::cin >> mas[i];
    }

    std::cin >> line;

    for(int i = 0; i < k; i++) {
        for(int j = 0; j < n; j++) {
            std::swap(line[j],line[(mas[j]-1)]);
        }
        std::cout << line << std::endl;
    }
    std::cout << line;
}