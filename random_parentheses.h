#ifndef RANDOM_PARENTHESES_H
#define RANDOM_PARENTHESES_H

#include <vector>

std::vector<int> generateInitialSequence(int n);
void fisherYatesShuffle(std::vector<int> &sequence);
int findLowestValley(const std::vector<int> &sequence);
std::vector<int> createWellFormedSequence(const std::vector<int> &sequence, int lowest_valley_index);

#endif 
