#if !defined(ISBN_VERIFIER_H)
#define ISBN_VERIFIER_H
#include <ctype.h>
#include <string>
namespace isbn_verifier {
bool is_valid(std::string const &);
} // namespace isbn_verifier

#endif // ISBN_VERIFIER_H