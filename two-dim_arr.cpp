#include <iostream>
#include <array>
#include <random>
#include <algorithm>

using namespace std;

void printMatrix(const array<array<int, 5>, 5>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << "\n";
    }
}

int main() {
    array<array<int, 5>, 5> matrix;

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(10, 99);

    for (auto& row : matrix) {
        for (int& elem : row) {
            elem = dist(gen);
        }
    }

    cout << "Original array:\n";
    printMatrix(matrix);

    for (auto& row : matrix) {
        auto max_el = max_element(row.begin(), row.end());
        swap(row[0], *max_el);
        /*int* max_el = &row[0];
        auto elem = row.begin();
        for (; elem!=row.end(); elem++) {
            if (*elem > *max_el) {
                max_el = &(*elem);
            }
        }
        int tmp = row[0];
        row[0] = *max_el;
        *max_el = tmp;
        */
    }

    cout << "\nArray after swap\n";
    printMatrix(matrix);

    return 0;
}