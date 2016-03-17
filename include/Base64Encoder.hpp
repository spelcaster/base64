// Copyright 2016 <https://github.com/spelcaster>

#ifndef __DCW_BASE_64_ENCODER_H__
#define __DCW_BASE_64_ENCODER_H__

#include <string>
#include <vector>

#include "Base64.hpp"

//! Base64Encoder
/*!
 * This class can convert a text to base64
 */
class Base64Encoder : private Base64 {
 private:
    /*!
     * This matrix is the number of chunks of 24 bits the text have, those
     * chunks will be converted using the base64 alphabet
     */
    std::vector< std::vector<int> > chunks_;

    /*!
     * @brief This method appends a chunk of 24 bits to the chunks matrix
     *
     * @param[in] chunk The chunk of 24 bits being added
     */
    void appendChunk(std::vector<int> chunk);

    /*!
     * @brief This will recursively iterate through chunks encoding them
     *
     * @param[in]  it          An reverse iterator to walk along the chunks
     *                         array
     * @param[out] encoded_str The resultant string
     *
     * @returns The resultant string
     */
    std::string encodeChunks(
        std::vector< std::vector< int > >::reverse_iterator it,
        std::string encoded_str
    );

    /*!
     * @brief This will recursively iterate through a chunk and encode the
     *        chunk, each chunk generates 4 elements in base64 encoding
     *
     * @param[in]  &chunk The chunk being encoded
     * @param[in]  it     The chunk iterator
     * @param[out] str    The resultant string
     *
     * @returns The resultant string
     */
    std::string encodeChunk(
       const std::vector< int > &chunk,
       std::vector< int >::iterator it,
       std::string str
    );

 public:
    //! Base64Encoder constructor
    Base64Encoder();

    //! Base64Encoder destructor
    ~Base64Encoder();

    /*!
     * @brief Encode a string into base64
     *
     * @param[in] text The text that will be encoded
     *
     * @returns The text encoded into base64
     */
    std::string encode(std::string text);
};

#endif // __DCW_BASE_64_H__
