#include <SFML/Audio.hpp>
#include <iostream>
#include <chrono>
#include <thread>
#include <string>
#include <cstdlib>
#include <filesystem>

#include "Sound.hpp"
#include "TimeCounter.hpp"


int main(int argc, char *argv[]) {
    if(argc != 3) {
        std::cerr << "Missing or too many parameters were provided!\n";
        return 1;
    }
    
    std::string interval {argv[1]};
    size_t reminderIntervalInSeconds {std::stoull(interval)};

    std::string soundFilePath {argv[2]};
    Sound mySound {soundFilePath};

    TimeCounter t {};
    std::cout << "Reminder has started.\n";
    std::cout << "You will be reminded every " << reminderIntervalInSeconds << " seconds.\n";
    t.timedelta();
    while (true) {
        for(auto i {0}; i < 3; ++i) {
            mySound.play();
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
        }
        std::this_thread::sleep_for(std::chrono::seconds(reminderIntervalInSeconds));
        t.timedelta();
    }

    // const auto &timeZoneDB {std::chrono::get_tzdb()};
    // const auto &currentZone {timeZoneDB.current_zone()};
    // std::chrono::local_time<std::chrono::system_clock::duration> lt {currentZone->to_local(std::chrono::system_clock::now())};
    // std::cout << lt << "\n";
    return 0;
}