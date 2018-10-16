#ifndef MAX_SUB_CPP
#define MAX_SUB_CPP

#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

auto sumMaxSubSequence(std::vector<int> vector) -> int {
    int sol = 0;
    int sum = 0;

    for (int el: vector) {
        sum += el;
        if (sum < 0) sum = 0;
        sol = std::max(sol, sum);
    }

    return sol;
}

auto sumMaxSubMatrix(std::istream &input) -> int {
    unsigned long r = 0;
    unsigned long c = 0;
    std::vector<std::vector<int>> matrix;
    std::vector<int> vector;

    input >> r;
    input >> c;

    vector.resize(r);
    matrix.resize(r);

    for (int i = 0; i < r; ++i) {
        matrix[i].resize(c);
        for (int j = 0; j < c; ++j) {
            input >> matrix[i][j];
        }
    }

    int sol = 0;


    for (int lt = 0; lt < c; ++lt) {

        for (int i = 0; i < r; ++i) {
            vector[i] = matrix[i][lt];
        }
        sol = std::max(sol, sumMaxSubSequence(vector));

        for (int rt = lt + 1; rt < c; ++rt) {

            for (int i = 0; i < r; ++i) {
                vector[i] += matrix[i][rt];
            }
            sol = std::max(sol, sumMaxSubSequence(vector));

        }
    }

    return sol;
}

#endif //MAX_SUB_CPP
