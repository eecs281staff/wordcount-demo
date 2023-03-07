// Example of using an unordered map to count the words in a file.

#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;


// Number of most common words to display
constexpr size_t DISPLAY_COUNT = 10;


// A word/count pair
using WordCountPair = pair<string, size_t>;


// Functor to sort word/count pairs in descending order by count
struct CountSort {
  bool operator()(const WordCountPair &left, const WordCountPair &right) const {
    return left.second > right.second;
  }
};  // CountSort


// Clean up a "word" by converting it to lowercase,
// and removing all punctuation.
void cleanup(string &word) {
  size_t i = 0;
  bool done = (i >= word.length());

  while (!done) {
    if (ispunct(word[i])) {
      // Punctuation: remove the character from the word, and
      // remain at the same letter within the word
      word.erase(i, 1);
    }  // if
    else {
      // Alphabetic or numeric: convert to lower case; move to next letter
      word[i] = tolower(word[i]);
      ++i;
    }  // else

    done = (i >= word.length());
  }  // while
}  // cleanup()


int main() {
  unordered_map<string, size_t> counts;
  string filename, word;
  ifstream infile;
  vector<WordCountPair> sortable;

  do {
    cout << "Enter filename: ";
    getline(cin, filename);
    infile.open(filename.c_str());
  } while (!infile);

  // Read every word from the file
  while (infile >> word) {
    // Clean up the word and count it
    cleanup(word);
    if (word.length() > 0)
      ++counts[word];
  }  // while

  // If you iterate over the unordered map, each word is an apparently
  // random order along with its count. If you switch to a map, they
  // will be in order lexicographically (alphabetically).

  // Put all of the word/count pairs into a vector (simple way)
  /*
  for (auto &x : counts) {
    sortable.push_back(x);
  }  // for
  */

  // Put all of the word/count pairs into a vector (efficient way)
  sortable.resize(counts.size());
  copy(begin(counts), end(counts), begin(sortable));

  // Sort in descending order by count
  sort(begin(sortable), end(sortable), CountSort());

  // Display the most common pairs
  size_t num = min(DISPLAY_COUNT, sortable.size());

  for (size_t i = 0; i < num; ++i) {
    cout << left << setw(20) << sortable[i].first;
    cout << right << setw(5) << sortable[i].second;
    cout << endl;
  }  // for

  return 0;
}  // main()
