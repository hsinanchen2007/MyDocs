#ifndef DS2_BITWISEOPERATIONS_PRINTBINARYREP
#define DS2_BITWISEOPERATIONS_PRINTBINARYREP

#include <climits>
#include <iostream>
#include <string>

namespace ds2
{
template <class T>
void printBinaryRep(const T& value);

void printByteSequence(const unsigned char* first, std::size_t length);
void printByte(unsigned char byte);

template <class T>
void printBinaryRep(const T& value)
{
  using namespace std;

  cout << typeid(T).name() << ' ' << value << endl;

  printByteSequence(reinterpret_cast<const unsigned char*>(&value), sizeof(T));

  cout << endl << endl;
}

template <>
void printBinaryRep(const std::string& s)
{
  using namespace std;

  cout << "std::string " << s << endl;

  printByteSequence(
    reinterpret_cast<const unsigned char*>(s.c_str()),
    s.size());

  cout << endl << endl;
}

void printByteSequence(const unsigned char* first, std::size_t length)
{
  using namespace std;

  const unsigned char* currentByte = first;

  cout << "Bytes (forward):\n";
  while (currentByte != first + length)
  {
    printByte(*currentByte++);
    cout << ' ';
  }

  --currentByte;

  cout << "\nBytes (reverse):\n";
  while (currentByte >= first)
  {
    printByte(*currentByte--);
    cout << ' ';
  }
}

void printByte(unsigned char byte)
{
  for (int shiftLength = CHAR_BIT - 1; shiftLength >= 0; --shiftLength)
  {
    int currentBit = (byte >> shiftLength) & 1;
    std::cout << currentBit;
  }
}
};

#endif // DS2_BITWISEOPERATIONS_PRINTBINARYREP

// For the book "C++ Data Structures from Scratch, Vol. 2"
// www.cppdatastructures.com
// Copyright 2018 by Robert MacGregor.  All rights reserved.