// Copyright 2016 <https://github.com/spelcaster>
//
#ifndef __DCW_OUT_OF_BOUNDS_EXCEPTION_H__
#define __DCW_OUT_OF_BOUNDS_EXCEPTION_H__

#include <iostream>
#include <exception>

//! OutOfBoundsException
/*!
 * This exception should be thrown when an invalid index is used
 */
class OutOfBoundsException: public std::exception {
 private:
    /*!
     * The exception message
     */
    std::string message_;

 public:
    //! OutOfBoundsException constructor
    explicit OutOfBoundsException(
        const std::string& message = "The character index was not found"
    );

    //! OutOfBoundsException destructor
    virtual ~OutOfBoundsException() throw();

    /*!
     * @see std::exception::what
     */
    virtual const char* what() const throw() {
        return message_.c_str();
    }
};

//! OutOfBoundsException constructor
OutOfBoundsException::OutOfBoundsException(const std::string& message) :
    message_(message)
{
}

//! OutOfBoundsException destructor
OutOfBoundsException::~OutOfBoundsException() throw()
{
}

#endif // __DCW_OUT_OF_BOUNDS_EXCEPTION_H__
