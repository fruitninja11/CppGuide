
#include <iostream>
#include <omp.h>

int main() {
    int n = 100;
    int sum = 0;

    #pragma omp parallel for reduction(+:sum)
    for (int i = 1; i <= n; ++i) {
        sum += i;
    }

    std::cout << "Sum: " << sum << std::endl;

    return 0;
}
