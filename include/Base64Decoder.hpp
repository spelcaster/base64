// Copyright 2016 <https://github.com/spelcaster>

#ifndef __DCW_BASE_64_DECODER_H__
#define __DCW_BASE_64_DECODER_H__

#include <string>
#include <vector>

#include "Base64.hpp"

//! Base64Decoder
/*!
 * This class can convert a text to base64
 */
class Base64Decoder : private Base64 {
 private:
    /*!
     * This matrix is the number of chunks of 4 chars the encoded text have,
     * those chunks will be converted using the base64 character set
     */
    std::vector< std::vector<char> > chunks_;

    /*!
     * @brief This method appends a chunk of 4 chars to the chunks matrix
     *
     * @param[in] chunk The chunk of 4 chars being added
     */
    void appendChunk(std::vector<char> chunk);

    /*!
     * @brief This will recursively iterate through chunks decoding them
     *
     * @param[in]  it          An reverse iterator to walk along the chunks
     *                         array
     * @param[out] encoded_str The resultant string
     *
     * @returns The resultant string
     */
    std::string decodeChunks(
        std::vector< std::vector< char > >::reverse_iterator it,
        std::string encoded_str
    );

    std::vector< int > decodeChunk(
       const std::vector< char > &chunk,
       std::vector< char >::iterator it,
       std::vector< int > bit_array
    );

    void overrideChunk(
        std::vector< char > &chunk,
        std::vector< char >::iterator it
    );

 public:
    //! Base64Decoder constructor
    Base64Decoder();

    //! Base64Decoder destructor
    ~Base64Decoder();

    std::string decode(std::string text);
};

#endif // __DCW_BASE_64_H__
