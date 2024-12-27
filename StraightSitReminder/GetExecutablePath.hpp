#pragma once


#include <iostream>
#include <string>
#include <locale>
#include <codecvt>
#include <filesystem>

#ifdef _WIN32
#include <windows.h>

std::string getExecutablePath() {
    wchar_t path[MAX_PATH];
    if (GetModuleFileNameW(NULL, path, MAX_PATH) != 0) {
        // Wide karakter dizisini dar karakter dizisine dönüştür
        std::wstring wpath(path);
        std::string pathStr(wpath.begin(), wpath.end()); // Dönüştürme işlemi
        return pathStr;
    } else {
        std::cerr << "Hata: Dosya yolu alınamadı!" << std::endl;
        return "";
    }
}

std::string sep() {
    return "\\";
}

#else
#include <unistd.h>
#include <limits.h>

std::string getExecutablePath() {
    char path[PATH_MAX];
    ssize_t len = readlink("/proc/self/exe", path, sizeof(path) - 1);
    if (len != -1) {
        path[len] = '\0';
        return std::string(path);
    } else {
        std::cerr << "Hata: Dosya yolu alınamadı!" << std::endl;
        return "";
    }
}

std::string sep() {
    return "/";
}

#endif

std::string getDirectory(const std::string &fullPath) {
    std::filesystem::path path(fullPath);
    return path.parent_path().string();
}