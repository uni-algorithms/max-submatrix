#include <cassert>
#include "max-submatrix.cpp"

auto main() -> int {
    std::ifstream input("input.txt");
    std::ofstream output("output.txt");
    assert(input);
    assert(output);
    output << sumMaxSubMatrix(input);
    input.close();
    output.close();
    return 0;
}