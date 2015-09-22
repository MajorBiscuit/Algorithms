#include <vector>               // vector
#include <iostream>             // cout
typedef std::vector<int>::size_type vsize_t;

void ins_sort(std::vector<int> & series);

void ins_sort(std::vector<int> & series) {
    for (vsize_t i = 1; i < series.size(); i++) {
        int key = series[i];
        for (int j = i - 1; j > -1; j--) {
            if (key < series[j]) {
                series[j + 1] = series[j];
                series[j] = key;
            }
            else break;
        }
    }
}

int main() {
    std::vector<int> v {6, 4, 5, 3};
    ins_sort(v);
    for (int e : v) {
        std::cout << e << " ";
    }
    std::cout << std::endl;
    return 0;
}
