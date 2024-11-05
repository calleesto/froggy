#include <iostream>
#include <chrono>
#include <thread>

using namespace std; // Use the standard namespace

#define SCREEN_HEIGHT 10
#define SCREEN_WIDTH 10

struct GameState {
    char screen[SCREEN_HEIGHT][SCREEN_WIDTH];
    int quit;
};

// Declare start_time as global variable
chrono::steady_clock::time_point start_time;

void displayTimer() {
    // Calculate elapsed time
    auto now = chrono::steady_clock::now();
    auto elapsed = chrono::duration_cast<chrono::seconds>(now - start_time).count();

    // Clear the console (optional, for cleaner output)
    cout << "\033[H\033[J"; // ANSI escape code to clear screen (works on most terminals)

    // Display elapsed time
    cout << "Elapsed Time: " << elapsed << " seconds" << endl;

    // Pause for 1 second
    this_thread::sleep_for(chrono::seconds(1));
}

int main() {
    struct GameState gameState;
    gameState.quit = 0;

    start_time = chrono::steady_clock::now(); // Get the start time

    while (!gameState.quit) {
        // Call displayTimer every loop iteration to show the timer
        displayTimer();

        // For example purposes, let's quit after 10 seconds
        if (chrono::duration_cast<chrono::seconds>(chrono::steady_clock::now() - start_time).count() > 10) {
            gameState.quit = 1;
        }
    }

    return 0;
}
