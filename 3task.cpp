#include <iostream>
#include <algorithm>
#include <vector>

void add(std::vector<long long>& street, int index, int value, int n){
    while(index <= n) {
        street[index] += value;
        index += index & - index;
    }
}

void get_sum(std::vector<long long>& street, int index, int value, int n) {
    long long sum = 0;
    while(index > 0) {
        sum += street[index];
        index -= index & - index;
    }
    std::cout << sum << std::endl;
}

int main(){
    int n = 0;
    int k = 0;
    std::cin >> n >> k;
    
    std::vector<long long> street(n+1);

    int oper = 0;
    int u = 0;
    int r = 0;
    for(int i = 0; i < k; i++) {
        std::cin >> oper >> u >> r;
        if (oper == 1) {
            add(street, u, r, n);
        }
        else {
            get_sum(street, r, 0, n);
        }
    }
}