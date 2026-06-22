#include <iostream>
#include <vector>

int main() {
    int n = 0;
    std::cin >> n;
    while(n--) {
        int a = 0, b = 0, x = 0, y = 0;
        std::cin >> a >> b >> x >> y;
        std::cout << (b-(y-b)) + (a-(b-y)) + (a-(x-a)) << std::endl;
    }
}