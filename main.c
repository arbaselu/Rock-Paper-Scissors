#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <ctype.h>

// Function prototypes
int Player();
int isOptionValid(const char* choice);
void Computer();
void determineWinner();
void FinalWinner();
void ClearInputBuffer();
void ResetScores();
 void ClearScreen();
// Global variables for player and computer choices, and scores
char player[10];
char computer[10];
int PlayerScore = 0;
int ComputerScore = 0;

int main() {
    char ExitCommand[10];
    srand(time(NULL)); // Initialize random number generator

    // Main game loop
    do {
        Player(); // Get player's choice
        Computer(); // Get computer's choice
        determineWinner(); // Determine the winner of the round

        // Display current scores
        printf("SCORE:\nPlayer: %d\nComputer: %d\n", PlayerScore, ComputerScore);

        // Ask user if they want to exit, restart, or continue
        printf("\nDo you want to exit, restart, or continue? (Exit: E, Restart: R, Continue: Type anything and press Enter to Continue)\n");
        scanf("%1s", ExitCommand);
        ClearScreen();
        ClearInputBuffer(); // Clear the input buffer

        // Check if the user wants to exit or restart
    if (tolower(ExitCommand[0]) == 'r') {
            ResetScores();
        }
    } while (tolower(ExitCommand[0]) != 'e');

    printf("FINAL SCORE:\nPlayer: %d\nComputer: %d\n", PlayerScore, ComputerScore);
    FinalWinner();
    printf("\n\n\n\nThe console will close in 5 seconds...");
    sleep(5);

    return 0;
}

// Function to get player's choice
int Player() {
    while (1) {
       printf("Rock, Paper or Scissors?\n");
         printf("\nPlayer: ");
        scanf("%9s", player);
        ClearInputBuffer();

        // Convert player choice to lowercase
        for (int i = 0; player[i]; i++) {
            player[i] = tolower(player[i]);
        }

        // Check if the player's choice is valid
        if (isOptionValid(player)) {
            return 0;
        } else {

            printf("\nInvalid choice. Please try again.\n");
           
            sleep(1);
            ClearScreen();
        }
    }
}

// Function to check if the given choice is valid
int isOptionValid(const char* choice) {
    const char* options[] = {"rock", "paper", "scissors"};
    for (int i = 0; i < 3; i++) {
        if (strcmp(choice, options[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

// Function to generate computer's choice
void Computer() {
    const char* options[] = {"rock", "paper", "scissors"};
    int RandomComputer = rand() % 3;
    strcpy(computer, options[RandomComputer]);

    printf("\nComputer: %s\n", computer);
}

// Function to determine the winner of the round
void determineWinner() {
    if (strcmp(player, computer) == 0) {
        printf("\nResult: Is Draw\n");
    } else if ((strcmp(player, "rock") == 0 && strcmp(computer, "scissors") == 0) ||
               (strcmp(player, "paper") == 0 && strcmp(computer, "rock") == 0) ||
               (strcmp(player, "scissors") == 0 && strcmp(computer, "paper") == 0)) {
        printf("\nResult: Player Wins\n");
        PlayerScore++; // Increment player's score
    } else {
        printf("\nResult: Computer Wins\n");
        ComputerScore++; // Increment computer's score
    }
}

// Function to display the final winner
void FinalWinner() {
    if (PlayerScore > ComputerScore) {
        printf("\nWinner: Player wins the Game\n");
    } else if (ComputerScore > PlayerScore) {
        printf("\nWinner: Computer wins the Game\n");
    } else {
        printf("\nThe Score is Equal\n");
    }
}

// Function to clear the input buffer
void ClearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

// Function to reset scores
void ResetScores() {
    PlayerScore = 0;
    ComputerScore = 0;
    printf("\nScores have been reset!\n");
}

 //Clears the console screen by executing the 'cls' command on Windows or 'clear' on Unix/Linux.
void ClearScreen() {
    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif
}
