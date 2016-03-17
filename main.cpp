// Copyright 2016 <https://githut.com/spelcaster>

#include <iostream>
#include <vector>
#include <string>

#include "include/Base64Encoder.hpp"
#include "include/Base64Decoder.hpp"

void encode();
void decode();

/*!
 * @brief Program main function
 *
 * @returns The exit code
 */
int main () {
    encode();
    decode();
    return 0;
}

void encode() {
    Base64Encoder encoder;
    std::string text;

    text = "A";
    std::cout << "Encoding: " << text << std::endl;
    std::cout << "Encoded: " << encoder.encode(text) << std::endl;
    std::cout << std::endl;
    text.clear();

    text = "AB";
    std::cout << "Encoding: " << text << std::endl;
    std::cout << "Encoded: " << encoder.encode(text) << std::endl;
    std::cout << std::endl;
    text.clear();

    text = "ABC";
    std::cout << "Encoding: " << text << std::endl;
    std::cout << "Encoded: " << encoder.encode(text) << std::endl;
    std::cout << std::endl;
    text.clear();

    text = "ããã";
    std::cout << "Encoding: " << text << std::endl;
    std::cout << "Encoded: " << encoder.encode(text) << std::endl;
    std::cout << std::endl;
    text.clear();

    text = "correct horse battery staple";
    std::cout << "Encoding: " << text << std::endl;
    std::cout << "Encoded: " << encoder.encode(text) << std::endl;
    std::cout << std::endl;
    text.clear();
}

void decode() {
    Base64Decoder decoder;
    std::string text;

    text = "QQ==";
    std::cout << "Decoding: " << text << std::endl;
    std::cout << "Decoded: " << decoder.decode(text) << std::endl;
    std::cout << std::endl;
    text.clear();

    text = "QUI=";
    std::cout << "Decoding: " << text << std::endl;
    std::cout << "Decoded: " << decoder.decode(text) << std::endl;
    std::cout << std::endl;
    text.clear();

    text = "QUJD";
    std::cout << "Decoding: " << text << std::endl;
    std::cout << "Decoded: " << decoder.decode(text) << std::endl;
    std::cout << std::endl;
    text.clear();

    text = "w6PDo8Oj";
    std::cout << "Decoding: " << text << std::endl;
    std::cout << "Decoded: " << decoder.decode(text) << std::endl;
    std::cout << std::endl;
    text.clear();

    text = "Y29ycmVjdCBob3JzZSBiYXR0ZXJ5IHN0YXBsZQ==";
    std::cout << "Decoding: " << text << std::endl;
    std::cout << "Decoded: " << decoder.decode(text) << std::endl;
    std::cout << std::endl;
    text.clear();
}
