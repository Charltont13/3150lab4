#include "random_parentheses.h"
#include <iostream>

int main() {
    int n;
    std::cout << "Enter n for the sequence of parentheses: ";
    std::cin >> n;

    std::vector<int> sequence = generateInitialSequence(n);
    fisherYatesShuffle(sequence);
    int lowest_valley_index = findLowestValley(sequence);
    std::vector<int> well_formed_sequence = createWellFormedSequence(sequence, lowest_valley_index);

    for (int val : well_formed_sequence) {
        std::cout << (val == 1 ? "(" : ")");
    }
    std::cout << std::endl;

    return 0;
}
