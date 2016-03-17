// Copyright 2016 <https://github.com/spelcaster>

#include "include/Base64.hpp"
#include "include/Base64Decoder.hpp"
#include "include/BaseConverter.hpp"

#include "exception/InvalidBlockException.cpp"

#include <iostream>

//! Base64Decoder constructor
Base64Decoder::Base64Decoder() {
}

//! Base64Decoder destructor
Base64Decoder::~Base64Decoder() {
    std::vector< std::vector< char > >().swap(chunks_);
}

/*!
 * @brief This method appends a chunk of 24 bits to the chunks matrix
 *
 * @param[in] chunk The chunk of 24 bits being added
 */
void Base64Decoder::appendChunk(std::vector< char > chunk) {
    chunks_.insert(chunks_.begin(), chunk);
}

/*!
 * @brief This will recursively iterate through chunks encoding them
 *
 * @param[in]  it          An reverse iterator to walk along the chunks
 *                         array
 * @param[out] decoded_str The resultant string
 *
 * @returns The resultant string
 */
std::string Base64Decoder::decodeChunks(
    std::vector< std::vector< char > >::reverse_iterator it,
    std::string decoded_str
) {
    if (it == chunks_.rend()) {
        return decoded_str;
    }

    std::vector< int > temp;
    BaseConverter conv;

    std::vector< char > chunk = *it;
    std::vector< char >::iterator it_x = chunk.begin();

    if ((it + 1) == chunks_.rend()) {
        //  Override '=' with 'A'
        overrideChunk(chunk, (it_x + 2));
    }

    temp = decodeChunk(chunk, it_x, temp);

    for (std::vector< int >::iterator it = temp.begin(); it != temp.end(); it += 8) {
        std::vector< int > bit_array(it, it+8);

        conv.setBinnary(bit_array);
        conv.convertToDecimal();

        decoded_str += static_cast<unsigned char>(conv.getDecimal());
    }

    return decodeChunks(++it, decoded_str);
}

void Base64Decoder::overrideChunk(
    std::vector< char > &chunk,
    std::vector< char >::iterator it
) {
    if (it == chunk.end()) {
        return;
    }

    if (*it == '=') {
        unsigned int index = it - chunk.begin();
        chunk[index] = 'A';
    }

    overrideChunk(chunk, ++it);
}

/*!
 * @brief This will recursively iterate through a chunk and decode the
 *        chunk, each chunk generates 4 elements in base64 encoding
 *
 * @param[in]  &chunk The chunk being decoded
 * @param[in]  it     The chunk iterator
 * @param[out] str    The resultant string
 *
 * @returns The resultant string
 */
std::vector< int > Base64Decoder::decodeChunk(
    const std::vector< char > &chunk,
    std::vector< char >::iterator it,
    std::vector< int > bit_array
) {
    if (it == chunk.end()) {
        return bit_array;
    }

    BaseConverter conv;
    std::vector< int > temp;

    unsigned int index = getIndexOf(*it);

    conv.setDecimal(index);
    conv.convertToBinnary();

    temp = conv.getBinnary();

    conv.zeroFillHead(6 - temp.size(), temp);

    bit_array.insert(bit_array.end(), temp.begin(), temp.end());

    return decodeChunk(chunk, ++it, bit_array);
}

/*!
 * @brief Encode a string into base64
 *
 * @param[in] text The text that will be decoded
 *
 * @returns The text decoded into base64
 */
std::string Base64Decoder::decode(std::string text) {
    std::vector< char > chunk;
    std::vector< char > temp;

    BaseConverter conv;

    for (std::string::iterator it = text.begin(); it != text.end(); ++it) {
        chunk.insert(chunk.end(), *it);

        if (chunk.size() == 4) {
            appendChunk(chunk);

            std::vector< char >().swap(chunk);
        }
    }

    // chunk size can't be different than 4
    if (!chunk.empty()) {
        throw InvalidBlockException();
    }

    std::vector< std::vector< char > >::reverse_iterator it = chunks_.rbegin();

    std::string result = decodeChunks(it, "");

    std::vector< std::vector< char > >().swap(chunks_);

    return result;
}

