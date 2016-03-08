// Copyright 2016 <https://github.com/spelcaster>

#ifndef __DCW_BASE_CONVERTER_H__
#define __DCW_BASE_CONVERTER_H__

#include <vector>

//! BaseConverter
/*!
 * This is a base converter class used to do these type of conversions:
 *   - base 2 -> base 10;
 *   - base 10 -> base 2;
 */
class BaseConverter {
 private:
    /*!
     * The number in base 10
     */
    unsigned int decimal_;

    /*!
     * The number in base 2 represented as an array of bits
     */
    std::vector<int> binnary_;

    /*!
     * @brief Convert a base 10 integer to bit array
     *
     * @param[in]  value The number in base 10
     * @param[out] &arr  The number in base 2
     */
    void binnaryConverter(int value, std::vector<int> &arr);

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
    unsigned int decimalConverter(
        std::vector<int>::iterator it,
        int exp,
        unsigned int decimal
    );

 public:
    //! BaseConverter constructor
    BaseConverter();

    //! BaseConverter destructor
    ~BaseConverter();

    /*!
     * @brief Gets the number in base 2
     *
     * @returns The integer in base 2 as a bit array
     */
    std::vector<int> getBinnary();

    /**!
     * @brief Sets the number in base 2
     *
     * @param[in] binnary The number in base 2
     */
    void setBinnary(std::vector<int> binnary);

    /*!
     * @brief Gets the number in base 10
     *
     * @returns The number in base 10
     */
    unsigned int getDecimal();

    /**!
     * @brief Sets the number in base10
     *
     * @param[in] number The number in base 10
     */
    void setDecimal(unsigned int number);

    /**!
     * @brief Wrapper method to run binnaryConverter using member attributes
     */
    void convertToBinnary();

    /**!
     * @brief Wrapper method to run decimalConverter using member attributes
     */
    void convertToDecimal();

    /**!
     * @brief This method normalize a bit array to a byte array of size
     *        equals to a number multiple of 8, for example:
     *        - 1000 -> 00001000;
     *        - 100000000 -> 0000000100000000
     *
     * @returns The bit array normalized to a byte size
     */
    std::vector<int> toByte();

    /**!
     * @brief This method will prepend 0's in vector N times
     *
     * @param[in]  size The number of times the operation will be executed
     * @param[out] &arr The vector that will be modified
     */
    void zeroFillHead(int size, std::vector<int> &arr);

    /**!
     * @brief This method will append 0's in vector N times
     *
     * @param[in]  size The number of times the operation will be executed
     * @param[out] &arr The vector that will be modified
     */
    void zeroFillTail(int size, std::vector<int> &arr);
};

#endif // __DCW_BASE_CONVERTER_H__
