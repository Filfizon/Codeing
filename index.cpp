#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

const int DECK_SIZE = 20;
const int TYPES = 8;
const int OCCURRENCES[TYPES] = {3, 3, 3, 3, 2, 2, 2, 2};

vector<int> deck;
int top = DECK_SIZE - 1;

//std::vector<int> myVector = {1, 2, 3, 4, 5};
//std::random_shuffle(myVector.begin(), myVector.end());


void shuffleDeck() {
  deck.clear();  // clear the deck
  for (int i = 0; i < TYPES; i++) {
    for (int j = 0; j < OCCURRENCES[i]; j++) {
      deck.push_back(i);
    }
  }
  random_shuffle(deck.begin(), deck.end());  // shuffle the deck
  top = DECK_SIZE - 1;  // reset the top card
}

int main() {
  srand(time(NULL));  // seed the random number generator
  shuffleDeck();  // shuffle the deck for the first time
  while (true) {
    if (top < 0) {  // if all cards have been drawn, shuffle the deck again
      shuffleDeck();
    }
    int card = deck[top];  // get the top card
    cout << "Card: " << card << endl;
    top--;  // discard the top card
  }
  return 0;
}
