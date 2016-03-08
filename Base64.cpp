// Copyright 2016 <https://github.com/spelcaster>

#include "include/Base64.hpp"
#include "include/BaseConverter.hpp"

//! Base64 constructor
Base64::Base64() {
    map_.append("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    map_.append("abcdefghijklmnopqrstuvwxyz");
    map_.append("0123456789");
    map_.append("+/");
}

//! Base64 destructor
Base64::~Base64() {
    std::vector< std::vector< int > >().swap(chunks_);
}

/*!
 * @brief This method appends a chunk of 24 bits to the chunks matrix
 *
 * @param[in] chunk The chunk of 24 bits being added
 */
void Base64::appendChunk(std::vector< int > chunk) {
    chunks_.insert(chunks_.begin(), chunk);
}

/*!
 * @brief This will recursively iterate through chunks encoding them
 *
 * @param[in]  it          An reverse iterator to walk along the chunks
 *                         array
 * @param[out] encoded_str The resultant string
 *
 * @returns The resultant string
 */
std::string Base64::encodeChunks(
    std::vector< std::vector<int> >::reverse_iterator it,
    std::string encoded_str
) {
    if (it == chunks_.rend()) {
        return encoded_str;
    }

    std::vector< int > chunk = *it;
    std::vector< int >::iterator it_x = chunk.begin();

    encoded_str.append(encodeChunk(chunk, it_x, ""));

    return encodeChunks(++it, encoded_str);
}

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
std::string Base64::encodeChunk(
    const std::vector< int > &chunk,
    std::vector< int >::iterator it,
    std::string str
) {
    if (it == chunk.end()) {
        return str;
    }

    BaseConverter conv;

    std::vector< int > range(it, it+6);

    conv.setBinnary(range);
    conv.convertToDecimal();

    str += map_[conv.getDecimal()];

    return encodeChunk(chunk, it+6, str);
}

/*!
 * @brief Encode a string into base64
 *
 * @param[in] text The text that will be encoded
 *
 * @returns The text encoded into base64
 */
std::string Base64::encode(std::string text) {
    std::vector< int > chunk;
    std::vector< int > temp;

    BaseConverter conv;

    for (std::string::iterator it = text.begin(); it != text.end(); ++it) {
        unsigned int code =  static_cast<unsigned int>(
            static_cast<unsigned char>(*it)
        );

        conv.setDecimal(code);
        conv.convertToBinnary();

        temp = conv.toByte();

        chunk.insert(chunk.end(), temp.begin(), temp.end());

        temp.clear();

        if (chunk.size() == 24) {
            appendChunk(chunk);

            std::vector< int >().swap(chunk);
        }
    }

    if (!chunk.empty()) {
        conv.zeroFillTail(24 - chunk.size(), chunk);

        appendChunk(chunk);
    }

    std::vector< std::vector< int > >::reverse_iterator it = chunks_.rbegin();

    std::string result = encodeChunks(it, "");
    int size = result.size();
    int counter = 1;

    // Check if it need to overwrite 'A' with '='
    while (counter < 3) {
        if (size < 0) {
            break;
        } if (result[size - counter] == 'A') {
            result[size - counter] = '=';
            counter++;
            continue;
        }

        break;
    }

    std::vector< std::vector< int > >().swap(chunks_);

    return result;
}

