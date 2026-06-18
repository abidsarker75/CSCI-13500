# Program Design Document

## Program Name

RockPaperScissor

## Purpose

This program is a rock, paper, scissor game. It will allow the user to play up to 3 rounds if the first
and second round is a tie or else it will be which ever player gets the score of 2 first. The user will
be playing against the computer and will also allow the user to play again if they want to. This game was
already made but code redundancy, input validation, ui improvement, game logic improvement, and bonus
feature was added.

---

## Inputs

- Game input : rock, paper, or scissor
- Play again : Yes or No

---

## Outputs

- Bot chose:
- Score:
- Either bot or player wins round or ties
- Final winner
- Program ended. Thank you for playing

---

## Variables

| Variable     | Type        | Purpose                                     |
| ------------ | ----------- | ------------------------------------------- |
| player_score | int         | Stores the player's score                   |
| bot_score    | int         | Stores the bot's score                      |
| player_move  | std::string | Stores the move chosen by the player        |
| bot_move     | int         | Stores the random number for the bot's move |
| bot_pick     | std::string | Stores the move chosen by the bot           |
| rounds       | int         | Counts how many rounds have been played     |
| play_again   | std::string | Stores whether the user wants to play again |

---

## Key Design Choices

- For the figuring out scores I improved code redundancy by combining all the if else statements
  for checking when the user wins into one else if statement by adding all the conditions.
- For the ui change I added a while loop in the beginning so that if the user chooses to play again
  they can play again or they can end the program by saying no.
- Another change was displaying the both the player's score and the bot's score and choice rather
  than just seeing what you chose.
- Make sure the user enters the right input for both the game choices and if they want to play again.

---

## Program Steps (Algorithm)

1. Welcome the user to Rock Paper Scissors.
2. Declare the variables and set the player score and bot score to 0.
3. Ask the user to choose rock, paper, or scissor.
4. Validate the users input to make sure they only enter rock, paper, or scissor.
5. Generate a random move for the bot.
6. Compare the player’s move and the bot’s move.
7. Change the score depending on who wins the round.
8. Display what the bot chose and the bots score.
9. Repeat the game for up to 3 rounds or stop early if someone reaches 2 points.
10. Determine and display the final winner or if the game is a tie.
11. Ask the user if they want to play the game again or not.
12. Validate the play again input to make sure they enter yes or no.
13. If the user enters yes, restart the game. If the user does not want to play again
    it will end the program and let the user know the game has ended.

---

## Sample Input/Output

Input:
Choose rock, paper, scissor: scissor
Choose rock, paper, scissor: rock
Choose rock, paper, scissor: paper
Do you want to play again? Type yes or no: no

Output:
Bot chose: rock
Score: Player 0 - Bot 1
Bot chose: scissor
Score: Player 1 - Bot 1
Bot chose: rock
Score: Player 2 - Bot 1
Player Wins!
Program ended. Thank you for playing

---

## Ai relfection

1. I did use ai and I used chatgbt.
2. I used ai for displaying the bots score correctly. I had an issue where the score was changing at the
   time so it would actually display the wrong score when printed. The issue was because I did not update the
   score before I was printing the score and I could not find the error without gbt showing me where the error
   was occuring.
3. Something I learned is code redundancy in this program. I found it really hard to find where code could be
   redundant. It took a lot of reading over the code over and over again to find where I can decrease or change the code to make it less redundant. It took a lot of tries and to also find what inputs might cause validaty issues.
