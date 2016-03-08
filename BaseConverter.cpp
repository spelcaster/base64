// Copyright 2016 <https://github.com/spelcaster>

#include "include/BaseConverter.hpp"

#include <cmath>
#include <iostream>

//! BaseConverter constructor
BaseConverter::BaseConverter() {
    decimal_ = 0;
}

//! BaseConverter destructor
BaseConverter::~BaseConverter() {
    std::vector<int>().swap(binnary_);
}

/*!
 * @brief Gets the number in base 2
 *
 * @returns The integer in base 2 as a bit array
 */
std::vector<int> BaseConverter::getBinnary() {
    return binnary_;
}

/**!
 * @brief Sets the number in base 2
 *
 * @param[in] binnary The number in base 2
 */
void BaseConverter::setBinnary(std::vector<int> binnary) {
    binnary_ = binnary;
}

/*!
 * @brief Gets the number in base 10
 *
 * @returns The number in base 10
 */
unsigned int BaseConverter::getDecimal() {
    return decimal_;
}

/**!
 * @brief Sets the number in base10
 *
 * @param[in] number The number in base 10
 */
void BaseConverter::setDecimal(unsigned int decimal) {
    decimal_ = decimal;
}

/**!
 * @brief Wrapper method to run binnaryConverter using member attributes
 */
void BaseConverter::convertToBinnary() {
    std::vector<int> arr;

    // Destroy binnary_
    std::vector<int>().swap(binnary_);

    binnaryConverter(decimal_, arr);

    binnary_ = arr;
}

/*!
 * @brief Convert a base 10 integer to bit array
 *
 * @param[in]  value The number in base 10
 * @param[out] &arr  The number in base 2
 */
void BaseConverter::binnaryConverter(int value, std::vector<int> &arr) {
    if (value == 0) {
        arr.insert(arr.begin(), 0);
        return;
    } else if (value == 1) {
        arr.insert(arr.begin(), 1);
        return;
    }

    arr.insert(arr.begin(), value % 2);

    return binnaryConverter((value / 2), arr);
}

/**!
 * @brief Wrapper method to run decimalConverter using member attributes
 */
void BaseConverter::convertToDecimal() {
    std::vector<int>::iterator it = binnary_.begin();

    decimal_ = decimalConverter(it, binnary_.size() - 1, 0);
}

/*!
 * @brief Convert a base 2 number (bit array) to a base 10 integer
 *
 * @param[in]  it      A vector iterator to walk along the array
 * @param[in]  exp     The expoent that will be used in exponentiation of
 *                     base 2
 * @param[out] decimal The number in base 10 (used for tail recursion)
 *
 * @returns The number in base 10;
 */
unsigned int BaseConverter::decimalConverter(
    std::vector<int>::iterator it, int exp, unsigned int decimal
) {
    decimal += *it * static_cast<unsigned int>(std::pow(2.0, exp));

    if (it != binnary_.end()) {
        return decimalConverter(++it, --exp, decimal);
    }

    return decimal;
}

/**!
 * @brief This method normalize a bit array to a byte array of size
 *        equals to a number multiple of 8, for example:
 *        - 1000 -> 00001000;
 *        - 100000000 -> 0000000100000000
 *
 * @returns The bit array normalized to a byte size
 */
std::vector<int> BaseConverter::toByte() {
    if ((binnary_.size() % 8) == 0) {
        return binnary_;
    }

    int factor = (binnary_.size() / 8) + 1;

    std::vector<int> copy = binnary_;

    zeroFillHead((8 * factor) - binnary_.size(), copy);

    return copy;
}

/**!
 * @brief This method will prepend 0's in vector N times
 *
 * @param[in]  size The number of times the operation will be executed
 * @param[out] &arr The vector that will be modified
 */
void BaseConverter::zeroFillHead(int size, std::vector<int> &arr) {
    if (size == 0) {
        return;
    }

    arr.insert(arr.begin(), 0);

    zeroFillHead(size - 1, arr);
}

/**!
 * @brief This method will append 0's in vector N times
 *
 * @param[in]  size The number of times the operation will be executed
 * @param[out] &arr The vector that will be modified
 */
void BaseConverter::zeroFillTail(int size, std::vector<int> &arr) {
    if (size == 0) {
        return;
    }

    arr.push_back(0);

    zeroFillTail(size - 1, arr);
}


