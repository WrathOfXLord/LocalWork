#include <iostream>
#include <random>
#include <vector>
#include <chrono>

enum winLoss {
    switchedWin,
    switchedLost,
    didntSwitchedWin,
    didntSwitchedLost
};

void playMontyHallAndPrintStats(int doorCount, int howManyTimes, bool randomDoor, bool randomSwitch, bool switchDoors) {
    int winLostCounts[4] {};
    std::random_device seed;     // true random number generator, it may be more expensive than prng ones //overloads () operator.
    // auto seed = std::chrono::steady_clock::now().time_since_epoch().count();
    std::mt19937_64 rng{seed()}; // Mersenne Twister 19937 random number generator
    std::uniform_int_distribution<int> distribute{1, doorCount};
    for (int count{}; count < howManyTimes; ++count)
    {
        int prizeDoor{distribute(rng)};
        int chosenDoor {-1};
        std::cout << "Choose your door (1-" << doorCount << "): ";
        if(randomDoor) {
            chosenDoor = distribute(rng);
        } else {
            std::cin >> chosenDoor;
        }
        std::cout << "Chosen door: " << chosenDoor << "\n";
        
        int doorsToBeOpened {-1};
        do {
            doorsToBeOpened = distribute(rng);
        } while (doorsToBeOpened == chosenDoor || doorsToBeOpened == prizeDoor);
        
        int unchosenDoorToBeSwitched;
        do {
            unchosenDoorToBeSwitched = distribute(rng);
        } while(doorsToBeOpened == unchosenDoorToBeSwitched || unchosenDoorToBeSwitched == chosenDoor);

        std::cout << "Door " << doorsToBeOpened << " has been opened. Do you want to switch your door with "
                  << unchosenDoorToBeSwitched << " (y-n): ";
        
        char response {-1};
        if(randomSwitch) {
            std::uniform_int_distribution<int> distributeSwitch{0, 1};
            response = (distributeSwitch(rng))? 'y': 'n';
        } else {
            if(switchDoors) {
                response = 'y';
            } else {
                response = 'n';
            }
        }

        std::cout << response << "\n";

        bool isSwitched {};
        if(response == 'y') {
            chosenDoor = unchosenDoorToBeSwitched;
            isSwitched = true;
        }

        if(chosenDoor == prizeDoor) {
            if(isSwitched) {
                ++winLostCounts[switchedWin];
            } else {
                ++winLostCounts[didntSwitchedWin];
            }
            std::cout << "You won the car !\n";
        } else {
            if(isSwitched) {
                ++winLostCounts[switchedLost];
            } else {
                ++winLostCounts[didntSwitchedLost];
            }
            std::cout << "You didn't win anything !\n";
        }
    }

    std::cout << "Win Loss Statistics\n";
    std::cout << "Switched win: " << winLostCounts[switchedWin] << "\n";
    std::cout << "Switched lost: " << winLostCounts[switchedLost] << "\n";
    std::cout << "Switching winrate: " << (static_cast<double>(winLostCounts[switchedWin]) / (winLostCounts[switchedWin] + winLostCounts[switchedLost]) * 100)
              << "%\n";
    std::cout << "--------------------------------------------\n";
    std::cout << "Unswitched win: " << winLostCounts[didntSwitchedWin] << "\n";
    std::cout << "Unswitched lost: " << winLostCounts[didntSwitchedLost] << "\n";
}

int main()
{
    playMontyHallAndPrintStats(3, 10000, true, false, true);

    return EXIT_SUCCESS;
}