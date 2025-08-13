#include <iostream>
#include <windows.h>
#include <thread>
#include <atomic>
#include <chrono>

std::atomic<bool> key_pressed(false);
std::atomic<bool> exit_requested(false);

// Tuşlara basma ve bırakma işlevi
void press_key(WORD hexKeyCode) {
    INPUT input = {0};
    input.type = INPUT_KEYBOARD;
    input.u.ki.wVk = hexKeyCode;
    SendInput(1, &input, sizeof(INPUT));
}

void release_key(WORD hexKeyCode) {
    INPUT input = {0};
    input.type = INPUT_KEYBOARD;
    input.u.ki.wVk = hexKeyCode;
    input.u.ki.dwFlags = KEYEVENTF_KEYUP;
    SendInput(1, &input, sizeof(INPUT));
}

void pressCtrlG() {
    press_key(VK_CONTROL);
    press_key(0x47);  // G tuşu
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    release_key(0x47);
    release_key(VK_CONTROL);
    std::this_thread::sleep_for(std::chrono::milliseconds(5));
}

// ESC tuşuna basarak programı kapatma işlevi
void onKeyEsc() {
    exit_requested.store(true);
    std::cout << "Exit requested by user. Exiting..." << std::endl;
}

// F7 tuşuna basarak tuş tekrarını başlat/durdur
void onKeyF7() {
    key_pressed.store(!key_pressed.load());
    std::cout << "Key repeat: " << (key_pressed.load() ? "ON" : "OFF") << std::endl;
}

// Tuşları sürekli kontrol eden işlev
void pickUp() {
    while (!exit_requested.load()) {
        if (key_pressed.load()) {
            press_key(0x5A);  // Z tuşuna bas
            std::this_thread::sleep_for(std::chrono::milliseconds(5));
            release_key(0x5A);
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(25));
    }
}

int main() {
    std::thread pickupThread(pickUp);

    std::cout << "Press F7 to toggle key repeat, ESC to exit." << std::endl;

    while (!exit_requested.load()) {
        if (GetAsyncKeyState(VK_F7)) {
            onKeyF7();
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
        }

        if (GetAsyncKeyState(VK_ESCAPE)) {
            onKeyEsc();
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    if (pickupThread.joinable()) {
        pickupThread.join();
    }

    return 0;
}
