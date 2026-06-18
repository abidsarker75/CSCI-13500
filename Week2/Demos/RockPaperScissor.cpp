#include <iostream>
#include <random>

int main() {

    std::string play_again = "yes";

    // Lets players play again if they want to
    while (play_again == "yes" || play_again == "Yes") {

        // Game welcomes user
        std::cout << "Welcome to Rock Paper Scissor!" << std::endl;
        // Declaring variables
        int player_score = 0;
        int bot_score = 0;
        std::string player_move;
        int bot_move = 0;
        std::string bot_pick;

        // Game loop
        for (int rounds = 0; rounds < 3; rounds++) {

            // Check for early winner
            if (player_score >= 2 || bot_score >= 2) {
                break;
            }

            // Asks for users input
            std::cout << "Choose rock, paper, or scissor: ";
            std::cin >> player_move;

            // Input validation for wrong move
            while (player_move != "rock" && player_move != "paper" && player_move != "scissor") {
                std::cout << "Invalid move. Please choose rock, paper, or scissor: ";
                std::cin >> player_move;
            }

            // Generate bot input
            bot_move = rand() % 3;

            if (bot_move == 0) {
                bot_pick = "rock";
            }
            else if (bot_move == 1) {
                bot_pick = "paper";
            }
            else {
                bot_pick = "scissor";
            }

            std::cout << "Bot chose: " << bot_pick << std::endl;

            // Figure out the score
            if (player_move == bot_pick) {
                std::cout << "This round is a tie!" << std::endl;
            }
            else if (
                (player_move == "rock" && bot_pick == "scissor") ||
                (player_move == "paper" && bot_pick == "rock") ||
                (player_move == "scissor" && bot_pick == "paper")
            ) {
                player_score++;
                std::cout << "You win this round!" << std::endl;
            }
            else {
                bot_score++;
                std::cout << "Bot wins this round!" << std::endl;
            }

            std::cout << "Score: Player " << player_score << " - Bot " << bot_score << std::endl;
        }

        // Declare winner or tie
        if (player_score > bot_score) {
            std::cout << "Player wins!" << std::endl;
        }
        else if (bot_score > player_score) {
            std::cout << "Bot wins!" << std::endl;
        }
        else {
            std::cout << "Tie!" << std::endl;
        }

        // Asks the user if they want to play again
        std::cout << "Do you want to play again? Type yes or no: ";
        std::cin >> play_again;

        // Input validation for play again answer
        while (play_again != "yes" && play_again != "Yes" && play_again != "no" && play_again != "No") {
            std::cout << "Invalid answer. Please type yes or no: ";
            std::cin >> play_again;
        }

        std::cout << std::endl;
    }
    // Tells the user the program is ended
    std::cout << "Program ended. Thank you for playing" << std::endl;

    return 0;
}