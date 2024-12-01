#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    // Initialize random seed
    std::srand(std::time(0));

    // Generate a random number between 1 and 100
    int randomNumber = std::rand() % 100 + 1;

    int userGuess;
    bool guessedCorrectly = false;

    std::cout << "Welcome to the Guessing Game!" << std::endl;
    std::cout << "I have generated a random number between 1 and 100." << std::endl;
    std::cout << "Try to guess it!" << std::endl;

    // Keep asking the user for guesses until they guess correctly
    while (!guessedCorrectly) {
        std::cout << "Enter your guess: ";
        std::cin >> userGuess;

        if (userGuess < randomNumber) {
            std::cout << "Your guess is too low. Try again!" << std::endl;
        } else if (userGuess > randomNumber) {
            std::cout << "Your guess is too high. Try again!" << std::endl;
        } else {
            std::cout << "Congratulations! You guessed the correct number!" << std::endl;
            guessedCorrectly = true;
        }
    }

    return 0;
}

