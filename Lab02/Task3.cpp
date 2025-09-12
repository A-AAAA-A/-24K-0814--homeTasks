#include <iostream>
#include <stdio.h>
#include <string.h>

int main() {
    int teams;
    std::cout << "Enter number of teams: ";
    std::cin >> teams;

    int** scores = new int*[teams];
    int* teamSizes = new int[teams];

    for (int i = 0; i < teams; i++) {
        std::cout << "Enter number of players in team " << i + 1 << ": ";
        std::cin >> teamSizes[i];
        scores[i] = new int[teamSizes[i]];
        std::cout << "Enter scores for team " << i + 1 << ": ";
        for (int j = 0; j < teamSizes[i]; j++) {
            std::cin >> scores[i][j];
        }
    }

    for (int i = 0; i < teams; i++) {
        int sum = 0;
        for (int j = 0; j < teamSizes[i]; j++) {
            sum += scores[i][j];
        }
        std::cout << "Sum of scores for team " << i + 1 << ": " << sum << '\n';
    }

    for (int i = 0; i < teams; i++) {
        delete[] scores[i];
    }
    delete[] scores;
    delete[] teamSizes;

    return 0;
}
