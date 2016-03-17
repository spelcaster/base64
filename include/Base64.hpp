// Copyright 2016 <https://github.com/spelcaster>

#ifndef __DCW_BASE_64_H__
#define __DCW_BASE_64_H__

#include <string>
#include <vector>
#include <sstream>

//! Base64
/*!
 * This class can convert a text to base64
 */
class Base64 {
 private:
    /*!
     * The base 64 alphabet
     */
    std::string character_set_;

    /*!
     * @brief Recursively search for character in the chacter set
     *
     * @param[in] it        The character set iterator
     * @param[in] character The letter that we're looking for
     *
     * @throw CharacterNotFoundException If the character is not present
     *                                   in character set
     *
     * @returns The index of the given letter
     */
    int getIndexOfRecursively(std::string::iterator it, const char character);

 public:
    //! Base64 constructor
    Base64();

    //! Base64 destructor
    ~Base64();

    /*!
     * @brief Get the index of an entry in the character set
     *
     * @param[in] character The letter that we want to know the index
     *
     * @returns The index of the letter
     */
    int getIndexOf(const char character);

    /*!
     * @brief Get the character in a given index
     *
     * @param[in] index The index of the character
     *
     * @throw OutOfBoundsException If index is not a valid key
     *
     * @returns The character in the given index
     */
    char getCharacterAt(const int index);
};

#endif // __DCW_BASE_64_H__
