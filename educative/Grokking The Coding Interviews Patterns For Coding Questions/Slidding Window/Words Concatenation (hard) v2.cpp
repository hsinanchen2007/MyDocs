/*

https://www.educative.io/courses/grokking-the-coding-interview/N8nMBvDQJ0m

Solution#
This problem follows the Sliding Window pattern and has a lot of similarities 
with Maximum Sum Subarray of Size K. We will keep track of all the words in a 
HashMap and try to match them in the given string. Here are the set of steps 
for our algorithm:

Keep the frequency of every word in a HashMap.
Starting from every index in the string, try to match all the words. In each 
iteration, keep track of all the words that we have already seen in another 
HashMap. If a word is not found or has a higher frequency than required, we 
can move on to the next character in the string. Store the index if we have 
found all the words.

Time Complexity#
The time complexity of the above algorithm will be O(N * M * Len) where ‘N’ 
is the number of characters in the given string, ‘M’ is the total number of 
words, and ‘Len’ is the length of a word.

Space Complexity#
The space complexity of the algorithm is O(M) since at most, we will be storing 
all the words in the two HashMaps. In the worst case, we also need O(N) space 
for the resulting list. So, the overall space complexity of the algorithm will 
be O(M+N).

*/

using namespace std;

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

class WordConcatenation {
 public:
  static vector<int> findWordConcatenation(const string &str, const vector<string> &words) {
    unordered_map<string, int> wordFrequencyMap;
    for (auto word : words) {
      wordFrequencyMap[word]++;
    }

    vector<int> resultIndices;
    int wordsCount = words.size(), wordLength = words[0].length();

    for (int i = 0; i <= int(str.length()) - wordsCount * wordLength; i++) {
      unordered_map<string, int> wordsSeen;
      for (int j = 0; j < wordsCount; j++) {
        int nextWordIndex = i + j * wordLength;
        // get the next word from the string
        string word = str.substr(nextWordIndex, wordLength);
        if (wordFrequencyMap.find(word) ==
            wordFrequencyMap.end()) {  // break if we don't need this word
          break;
        }

        wordsSeen[word]++;  // add the word to the 'wordsSeen' map

        // no need to process further if the word has higher frequency than required
        if (wordsSeen[word] > wordFrequencyMap[word]) {
          break;
        }

        if (j + 1 == wordsCount) {  // store index if we have found all the words
          resultIndices.push_back(i);
        }
      }
    }

    return resultIndices;
  }
};

int main(int argc, char *argv[]) {
  vector<int> result =
      WordConcatenation::findWordConcatenation("catfoxcat", vector<string>{"cat", "fox"});
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;

  result = WordConcatenation::findWordConcatenation("catcatfoxfox", vector<string>{"cat", "fox"});
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;
}
