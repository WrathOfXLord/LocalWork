#pragma once

#include <SFML/Audio.hpp>
#include <iostream>
#include <chrono>
#include <thread>

class Sound {
 private:
    sf::SoundBuffer buffer;
    sf::Sound sound;
 public:
    Sound(const std::string &source)
    : buffer {}, sound {} 
    {
        if (!buffer.loadFromFile(source)) {
            std::runtime_error {"The source file could not be loaded!"};        
        }
        sound.setBuffer(buffer);
    }

    void play() {
        while (sound.getStatus() == sf::Sound::Playing) {
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
        sound.play(); 
    }
};