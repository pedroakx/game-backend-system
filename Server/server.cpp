#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>

struct Player {
    int id;
    int rating;
};

int calculateELO(int ratingA, int ratingB, bool win) {
    int k = 32;
    float expected = 1.0 / (1 + pow(10, (ratingB - ratingA) / 400.0));
    return ratingA + k * (win - expected);
}

int main(int argc, char* argv[]) {

    if (argc < 3) {
        std::cout << "Invalid input";
        return 1;
    }

    Player playerA = {std::stoi(argv[1]), std::stoi(argv[2])};

    // Simula oponente fake
    Player playerB = {999, 1000};

    bool playerAWins = rand() % 2;

    int newRating = calculateELO(playerA.rating, playerB.rating, playerAWins);

    std::cout << "Match Result\n";
    std::cout << "Player " << playerA.id 
              << (playerAWins ? " WON " : " LOST ")
              << "New Rating: " << newRating;

    return 0;
}