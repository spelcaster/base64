// Copyright 2016 <https://hitgub.com/spelcaster>

#ifndef __DCW_BASE_64_H__
#define __DCW_BASE_64_H__

#include <string>
#include <vector>

//! Base64
/*!
 * This class can convert a text to base64
 */
class Base64 {
 private:
    /*!
     * The base 64 alphabet
     */
    std::string map_;

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
    //! Base64 constructor
    Base64();

    //! Base64 destructor
    ~Base64();

    /*!
     * @brief Encode a string into base64
     *
     * @param[in] text The text that will be encoded
     *
     * @returns The text encoded into base64
     */
    std::string encode(std::string text);

    /*!
     * @todo Implement the base64 decoder
     */
    std::string decode(std::string text);
};

#endif // __DCW_BASE_64_H__
