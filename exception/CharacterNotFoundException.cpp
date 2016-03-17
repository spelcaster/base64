// Copyright 2016 <https://github.com/spelcaster>

#ifndef __DCW_CHARACTER_NOT_FOUND_EXCEPTION_H__
#define __DCW_CHARACTER_NOT_FOUND_EXCEPTION_H__

#include <iostream>
#include <exception>

//! CharacterNotFoundException
/*!
 * This exception should be thrown when the character does not exist in the
 * alphabet
 */
class CharacterNotFoundException: public std::exception {
 private:
    /*!
     * The exception message
     */
    std::string message_;

 public:
    //! CharacterNotFoundException constructor
    explicit CharacterNotFoundException(
        const std::string& message = "Character does not exist in the character set"
    );

    //! CharacterNotFoundException destructor
    virtual ~CharacterNotFoundException() throw();

    /*!
     * @see std::exception::what
     */
    virtual const char* what() const throw() {
        return message_.c_str();
    }
};

//! CharacterNotFoundException constructor
CharacterNotFoundException::CharacterNotFoundException(const std::string& message) :
    message_(message)
{
}

//! CharacterNotFoundException destructor
CharacterNotFoundException::~CharacterNotFoundException() throw()
{
}

#endif // __DCW_CHARACTER_NOT_FOUND_EXCEPTION_H__
