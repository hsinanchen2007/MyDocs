#include <iostream>
#include <string>

void getNameAndScore(std::string& name, int& score);

int main()
{
  using namespace std;

  const int totalPlayers = 5;

  string names[totalPlayers];
  int scores[totalPlayers];
  int highScoreIndex = 0;

  for (int i = 0; i != totalPlayers; ++i)
  {
    getNameAndScore(names[i], scores[i]);

    if (scores[i] > scores[highScoreIndex])
      highScoreIndex = i;
  }

  cout << "\nThe high score of " << scores[highScoreIndex] <<
    " belongs to " << names[highScoreIndex] << endl;

  return 0;
}

void getNameAndScore(std::string& name, int& score)
{
  using namespace std;

  cout << "\nEnter player's first name: ";
  cin >> name;

  cout << "Enter player's score: ";
  cin >> score;
}

// For the book "C++ Data Structures from Scratch" (www.cppdatastructures.com)
// Copyright 2015 by Robert MacGregor.  All rights reserved.