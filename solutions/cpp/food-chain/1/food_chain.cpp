#include "food_chain.h"
namespace food_chain {
const std::string first_lines[] = {
    "I know an old lady who swallowed a fly.\n",
    "I know an old lady who swallowed a spider.\n"
    "It wriggled and jiggled and tickled inside her.\n",
    "I know an old lady who swallowed a bird.\n"
    "How absurd to swallow a bird!\n",
    "I know an old lady who swallowed a cat.\n"
    "Imagine that, to swallow a cat!\n",
    "I know an old lady who swallowed a dog.\n"
    "What a hog, to swallow a dog!\n",
    "I know an old lady who swallowed a goat.\n"
    "Just opened her throat and swallowed a goat!\n",
    "I know an old lady who swallowed a cow.\n"
    "I don't know how she swallowed a cow!\n",
    "I know an old lady who swallowed a horse.\n"
    "She's dead, of course!\n"};

const std::string line_chain[] = {
    "I don't know why she swallowed the fly. "
    "Perhaps she'll die.\n",
    "She swallowed the spider to catch the fly.\n",
    "She swallowed the bird to catch the spider "
    "that wriggled and jiggled and tickled inside her.\n",
    "She swallowed the cat to catch the bird.\n",
    "She swallowed the dog to catch the cat.\n",
    "She swallowed the goat to catch the dog.\n",
    "She swallowed the cow to catch the goat.\n"};

std::string verse(int num_verses) {
  std::string result = first_lines[num_verses - 1];

  for (int i = num_verses; i > 0 && i < 8; i--) {
    result += line_chain[i - 1];
  }

  return result;
}

std::string verses(int verses_start, int verses_end) {
  std::string song;

  for (int i = verses_start; i <= verses_end; i++) {
    song += verse(i) + "\n";
  }

  return song;
}

std::string sing() { return verses(1, 8); }
} // namespace food_chain
