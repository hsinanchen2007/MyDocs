/*

https://www.educative.io/courses/grokking-the-coding-interview/NEOZDEg5PlN

Solution
This problem follows the Subsets pattern and can be mapped to Balanced Parentheses. 
We can follow a similar BFS approach.

Let’s take Example-1 mentioned above to generate all unique generalized abbreviations. 
Following a BFS approach, we will abbreviate one character at a time. At each step, 
we have two options:

Abbreviate the current character, or
Add the current character to the output and skip the abbreviation.
Following these two rules, let’s abbreviate BAT:

Start with an empty word: “”

At every step, we will take all the combinations from the previous step and apply the 
two abbreviation rules to the next character.

Take the empty word from the previous step and add the first character to it. We can 
either abbreviate the character or add it (by skipping abbreviation). This gives us two 
new words: _, B.

In the next iteration, let’s add the second character. Applying the two rules on _ will 
give us _ _ and 1A. Applying the above rules to the other combination B gives us B_ and 
BA.

The next iteration will give us: _ _ _, 2T, 1A_, 1AT, B _ _, B1T, BA_, BAT

The final iteration will give us:3, 2T, 1A1, 1AT, B2, B1T, BA1, BAT
Here is the visual representation of this algorithm:

 Given word: BAT  
 Add 3rd character: T  
 Add 2nd character: A  
 Add 1st character: B  
       
    _   
    B   
    _ _   
    1A   
    B_   
    BA   
    _ _ _   
    2T   
    1A_   
    1AT   
    B_ _   
    B1T   
    BA_   
    BAT   
    3   
    2T   
    1A1   
    1AT   
    B2   
    B1T   
    BA1   
    BAT   

Time complexity
Since we had two options for each character, we will have a maximum of 2^N combinations. 
If you see the visual representation of Example-1 closely, you will realize that it is 
equivalent to a binary tree, where each node has two children. This means that we will 
have 2^N leaf nodes and 2^N-1 intermediate nodes, so the total number of elements pushed 
to the queue will be 2^N + 2^N-1, which is asymptotically equivalent to O(2^N). While 
processing each element, we do need to concatenate the current string with a character. 
This operation will take O(N), so the overall time complexity of our algorithm will be 
O(N*2^N)

Space complexity
All the additional space used by our algorithm is for the output list. Since we can’t have 
more than O(2^N) combinations, the space complexity of our algorithm is O(N*2^N)

*/

using namespace std;

#include <iostream>
#include <queue>
#include <string>
#include <vector>

class AbbreviatedWord {
 public:
  string str;
  int start = 0;
  int count = 0;

  AbbreviatedWord(string str, int start, int count) {
    this->str = str;
    this->start = start;
    this->count = count;
  }
};

class GeneralizedAbbreviation {
 public:
  static vector<string> generateGeneralizedAbbreviation(const string &word) {
    int wordLen = word.length();
    vector<string> result;
    queue<AbbreviatedWord> queue;
    queue.push({"", 0, 0});
    while (!queue.empty()) {
      AbbreviatedWord abWord = queue.front();
      queue.pop();
      if (abWord.start == wordLen) {
        if (abWord.count != 0) {
          abWord.str += to_string(abWord.count);
        }
        result.push_back(abWord.str);
      } else {
        // continue abbreviating by incrementing the current abbreviation count
        queue.push({abWord.str, abWord.start + 1, abWord.count + 1});

        // restart abbreviating, append the count and the current character to the string
        if (abWord.count != 0) {
          abWord.str += to_string(abWord.count);
        }
        abWord.str += word[abWord.start];
        queue.push({abWord.str, abWord.start + 1, 0});
      }
    }

    return result;
  }
};

int main(int argc, char *argv[]) {
  vector<string> result = GeneralizedAbbreviation::generateGeneralizedAbbreviation("BAT");
  cout << "Generalized abbreviation are: ";
  for (auto str : result) {
    cout << str << " ";
  }
  cout << endl;

  result = GeneralizedAbbreviation::generateGeneralizedAbbreviation("code");
  cout << "Generalized abbreviation are: ";
  for (auto str : result) {
    cout << str << " ";
  }
  cout << endl;
}

