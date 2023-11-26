#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <string>
std::string alg(std::string& str);
std::string algReverse(std::string& str);
std::string base64_decode(std::string const& encoded_string);
static inline bool is_base64(unsigned char c);
std::string base64_encode(std::string const& str_to_encode);
int getRandom(int min, int max);

#endif // !FUNCTIONS_HPP

