#include <iostream>
#include <cmath>
#include <cstdlib>
#include "httplib.h"

using namespace httplib;

int calculateELO(int ratingA, int ratingB, bool win) {
    int k = 32;
    float expected = 1.0 / (1 + pow(10, (ratingB - ratingA) / 400.0));
    return ratingA + k * (win - expected);
}

int main() {
    Server svr;

    svr.Post("/match", [](const Request& req, Response& res) {
        if (!req.has_param("player_id") || !req.has_param("rating")) {
            res.set_content("Missing parameters", "text/plain");
            return;
        }

        int player_id = std::stoi(req.get_param_value("player_id"));
        int rating = std::stoi(req.get_param_value("rating"));

        int opponent_rating = 1000;
        bool win = rand() % 2;

        int new_rating = calculateELO(rating, opponent_rating, win);

        std::string result = "Player " + std::to_string(player_id) +
            (win ? " WON " : " LOST ") +
            " New Rating: " + std::to_string(new_rating);

        res.set_content(result, "text/plain");
    });

    std::cout << "Server running on port 8080\n";
    svr.listen("0.0.0.0", 8080);
}