#include <iostream>
#include <vector>

int main() {
    int h = 0;
    int w = 0;
    std::cin >> h >> w;
    std::vector<std::vector<int>> a(h, std::vector<int>(w));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            std::cin >> a[i][j];
        }
    }

    // Ищем левый верхний угол прямоугольника
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (a[i][j] == 1) {
                // Проверяем, что это левый верхний угол (перед ним сверху и слева должны быть нули или это край)
                bool is_top  = (i == 0 || a[i-1][j] == 0);
                bool is_left = (j == 0 || a[i][j-1] == 0);
                
                if (is_top && is_left) {
                    // Выводим координаты в формате 1-индексации
                    // Ввод в тесте дает координаты верхнего левого угла 5 4
                    std::cout << i - 1 << " " << j - 1 << " ";
                    
                    // Теперь ищем правый нижний угол прямоугольника
                    int bottom_i = i;
                    int right_j = j;
                    
                    // Идем вниз, пока идут единицы
                    while (bottom_i + 1 < h && a[bottom_i + 1][j] == 1) {
                        bottom_i++;
                    }
                    // Идем вправо, пока идут единицы
                    while (right_j + 1 < w && a[i][right_j + 1] == 1) {
                        right_j++;
                    }
                    
                    std::cout << bottom_i + 1 << " " << right_j + 1 << std::endl;
                    return 0;
                }
            }
        }
    }
    return 0;
}