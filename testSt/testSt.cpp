#include <iostream>
#include <locale>
#include <string>
#include <algorithm>

int main()
{
    // UTF-8 kodlamasını kullanacak şekilde yerel ayarları ayarlayın
    std::locale utf8_locale(std::locale(), new std::codecvt_utf8<char32_t>);

    // UTF-8 kodlamalı bir string tanımlayın
    std::u8string utf8_string = u8"Merhaba, dünya!";

    // UTF-8 kodlamalı string'i büyük harflere dönüştürün
    std::u32string uppercase_string;
    std::transform(utf8_string.begin(), utf8_string.end(), std::back_inserter(uppercase_string),
        [&](char8_t character) { return std::toupper(character, utf8_locale); });

    // UTF-8 kodlamalı string'i küçük harflere dönüştürün
    std::u32string lowercase_string;
    std::transform(utf8_string.begin(), utf8_string.end(), std::back_inserter(lowercase_string),
        [&](char8_t character) { return std::tolower(character, utf8_locale); });

    // Wstring'leri UTF-8 kodlamalı string'lere dönüştürün
    std::string uppercase_utf8_string = std::wstring_convert<std::codecvt_utf8<char32_t>, char32_t>().to_bytes(uppercase_string);
    std::string lowercase_utf8_string = std::wstring_convert<std::codecvt_utf8<char32_t>, char32_t>().to_bytes(lowercase_string);

    // Sonuçları yazdırın
    std::cout << "Orjinal string: " << utf8_string << std::endl;
    std::cout << "Büyük harflerle: " << uppercase_utf8_string << std::endl;
    std::cout << "Küçük harflerle: " << lowercase_utf8_string << std::endl;

    return 0;
}
