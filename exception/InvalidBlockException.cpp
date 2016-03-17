// Copyright 2016 <https://github.com/spelcaster>

#ifndef __DCW_INVALID_BLOCK_EXCEPTION_H__
#define __DCW_INVALID_BLOCK_EXCEPTION_H__

#include <iostream>
#include <exception>

//! InvalidBlockException
/*!
 * This exception should be thrown when the block size is different than 4
 */
class InvalidBlockException: public std::exception {
 private:
    /*!
     * The exception message
     */
    std::string message_;

 public:
    //! InvalidBlockException constructor
    explicit InvalidBlockException(
        const std::string& message = "Invalid Base64 block found"
    );

    //! InvalidBlockException destructor
    virtual ~InvalidBlockException() throw();

    /*!
     * @see std::exception::what
     */
    virtual const char* what() const throw() {
        return message_.c_str();
    }
};

//! InvalidBlockException constructor
InvalidBlockException::InvalidBlockException(const std::string& message) :
    message_(message)
{
}

//! InvalidBlockException destructor
InvalidBlockException::~InvalidBlockException() throw()
{
}

#endif // __DCW_INVALID_BLOCK_EXCEPTION_H__
