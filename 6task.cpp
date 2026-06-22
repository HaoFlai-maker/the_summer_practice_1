#include <iostream>
#include <vector>

int main() {
    int n = 0;
    std::cin >> n;
    while(n--) {
        int a = 0, b = 0, x = 0, y = 0;
        std::cin >> a >> b >> x >> y;
        int sum = 0;
        if (b <= y) {
            sum += b;
            y -= b;
        }
        else {
            sum += y;
            y = 0;
        }
        if(a <= (x + y)) {
            sum += a;
        }
        else {
            sum += std::min(x,y);
        }
        std::cout << sum << std::endl;
    }
}