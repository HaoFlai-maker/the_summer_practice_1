#include <iostream>
#include <vector>

int main() {
    std::string line;
    std::cin >> line;
    bool info = true;
    for (int i = 0; i < line.size(); i++) {
        if(i == 0 || i == 4  || i == 5) {
            if (std::isdigit(static_cast<unsigned char>(line[i]))) {
                info = false;
                break;
            }
        }
        else {
            if (!std::isdigit(static_cast<unsigned char>(line[i]))) {
                info = false;
                break;
            }
        }
    }
    if (info) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }
    return 0;
}