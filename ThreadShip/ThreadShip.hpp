#pragma once

#include <iostream>
#include <vector>
#include <thread>
#include <chrono>

using std::literals::chrono_literals::operator""ms;

class Ship {
private:
    std::vector<std::thread> mCrew;
    bool launchRequested;

    enum {
        CLEANUP = 1,
        FULLSPEED = 2,
        STOP = 3,
        EXIT = 100
    };

    bool launchThread(int command) {
        switch(command) {
            case CLEANUP:
                mCrew.emplace_back(ThreadFunc::cleanUp);
                mCrew.back().detach();
                break;
            case FULLSPEED:
                mCrew.emplace_back(ThreadFunc::fullSpeed);
                mCrew.back().join();
                break;
            case STOP:
                mCrew.emplace_back(ThreadFunc::stop);
                mCrew.back().join();
                break;
            case EXIT:
                std::cout << "Exiting...\n";
                return false;
            default:
                std::cout << "Invalid command!\n";
        }
        return true;
    }

    class ThreadFunc {
    public:
        static void cleanUp() {
            std::cout << "Cleaning up...\n";
            std::this_thread::sleep_for(3000ms);
            std::cout << "Cleanup completed.\n";
        }

        static void fullSpeed() {
            std::cout << "Gaining momentum to fullspeed ahead...\n";
            std::this_thread::sleep_for(1000ms);
            std::cout << "Moving at fullspeed.\n";
        }

        static void stop() {
            std::cout << "Slowing down...\n";
            std::this_thread::sleep_for(1200ms);
            std::cout << "The ship has stopped.\n";
        }
    };
public:
    Ship() : mCrew {}, launchRequested {} {}
    void run() {
        int command {-1};
        do {
            std::cout << "What does the captain desire to be performed (Cleanup: 1, Fullspeed: 2, Stop: 3, Exit: 100) ?\n" << std::flush;
            std::cin >> command;
            launchRequested = launchThread(command);
        } while(launchRequested);
    }
};