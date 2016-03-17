// Copyright 2016 <https://github.com/spelcaster>

#include "exception/CharacterNotFoundException.cpp"
#include "exception/OutOfBoundsException.cpp"

#include "include/Base64.hpp"
#include "include/BaseConverter.hpp"

//! Base64 constructor
Base64::Base64() {
    character_set_.append("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    character_set_.append("abcdefghijklmnopqrstuvwxyz");
    character_set_.append("0123456789");
    character_set_.append("+/");
}

//! Base64 destructor
Base64::~Base64() {
}

int Base64::getIndexOf(const char character) {
    try {
        return getIndexOfRecursively(character_set_.begin(), character);
    } catch (CharacterNotFoundException &e) {
        std::cout << e.what() << std::endl;
    }

    return -1;
}

char Base64::getCharacterAt(const int index) {
    if ((index < 0) || (index >= character_set_.size())) {
        std::stringstream sstream;

        sstream << "Index out of bounds exception: ";
        sstream << "index: " << index << " size: " << character_set_.size();

        throw OutOfBoundsException(sstream.str());
    }

    return character_set_[index];
}

int Base64::getIndexOfRecursively(std::string::iterator it, const char character) {
    if (it == character_set_.end()) {
        throw CharacterNotFoundException();
    } else if (character == *it) {
        return it - character_set_.begin();
    }

    return getIndexOfRecursively(++it, character);
}

