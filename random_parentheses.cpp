#include "random_parentheses.h"
#include <algorithm> 
#include <random>    
#include <chrono>    

std::vector<int> generateInitialSequence(int n) {
    std::vector<int> sequence(2 * n + 1);
    std::fill(sequence.begin(), sequence.begin() + n, 1);
    std::fill(sequence.begin() + n, sequence.end(), -1);
    return sequence;
}

void fisherYatesShuffle(std::vector<int> &sequence) {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(sequence.begin(), sequence.end(), std::default_random_engine(seed));
}

int findLowestValley(const std::vector<int> &sequence) {
    int min_valley = 0;
    int current_sum = 0;
    int min_index = 0;

    for (size_t i = 0; i < sequence.size(); ++i) {
        current_sum += sequence[i];
        if (current_sum < min_valley) {
            min_valley = current_sum;
            min_index = i;
        }
    }
    return min_index;
}

std::vector<int> createWellFormedSequence(const std::vector<int> &sequence, int lowest_valley_index) {
    std::vector<int> well_formed_sequence(sequence.size() - 1);
    std::vector<int> p1(sequence.begin(), sequence.begin() + lowest_valley_index + 1);
    std::vector<int> p2(sequence.begin() + lowest_valley_index + 1, sequence.end());

    p1.pop_back(); // Remove the last -1 from P1

    well_formed_sequence.insert(well_formed_sequence.end(), p2.begin(), p2.end());
    well_formed_sequence.insert(well_formed_sequence.end(), p1.rbegin(), p1.rend());

    return well_formed_sequence;
}
