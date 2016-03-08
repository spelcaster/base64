// Copyright 2016 <https://githut.com/spelcaster>

#include <iostream>
#include <vector>
#include <string>

#include "include/Base64.hpp"

/*!
 * @brief Program main function
 *
 * @returns The exit code
 */
int main () {
    Base64 base64;
    std::string text;

    text = "A";
    std::cout << "Encoding: " << text << std::endl;
    std::cout << "Encoded: " << base64.encode(text) << std::endl;
    std::cout << std::endl;
    text.clear();

    text = "AB";
    std::cout << "Encoding: " << text << std::endl;
    std::cout << "Encoded: " << base64.encode(text) << std::endl;
    std::cout << std::endl;
    text.clear();

    text = "ABC";
    std::cout << "Encoding: " << text << std::endl;
    std::cout << "Encoded: " << base64.encode(text) << std::endl;
    std::cout << std::endl;
    text.clear();

    text = "ããã";
    std::cout << "Encoding: " << text << std::endl;
    std::cout << "Encoded: " << base64.encode(text) << std::endl;
    std::cout << std::endl;
    text.clear();

    text = "correct horse battery staple";
    std::cout << "Encoding: " << text << std::endl;
    std::cout << "Encoded: " << base64.encode(text) << std::endl;
    std::cout << std::endl;
    text.clear();

    return 0;
}
