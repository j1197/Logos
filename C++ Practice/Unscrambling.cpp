

#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include<cstdlib>
#include<ctime>
#include <vector>
#include <cctype>

using namespace std;

int main () {
    srand(time(0));
    int random = rand();
    int min = 0;
    int max = 44000;
    //cout << "Seed = " << time(0) << endl;
    int finalNum = rand()%(max-min+1)+min;
    //cout << "Random number = " << finalNum << endl;
    vector<string> words;
    ifstream file("/Users/jp/Desktop/words.txt");
    string line;
    while (getline(file, line)) words.push_back(line);

    string chosenword = words[rand() % words.size()];
    transform(chosenword.begin(), chosenword.end(), chosenword.begin(), ::tolower);
    //cout << chosenword << endl;

    string shuffled = chosenword;

    //cout << chosenword << endl;
    random_shuffle(shuffled.begin(), shuffled.end());
    cout << "Hello! Welcome to the game 'Unscramble the word'! \n";
    cout << "The game is straightforward. The given word has to be unjumbled and it will, post unscrambling, form an actual English word. \n";
    cout << "Your scrambled word is: " << shuffled << '\n';

    cout << "Enter your answer: " << endl;
    string guessedword;
    getline( cin, guessedword);

    transform(guessedword.begin(), guessedword.end(), guessedword.begin(), ::tolower);
    cout<< guessedword<< endl;
    if (chosenword == guessedword)
        cout << "You are right! " << endl;
    else
        cout << " Wrong answer, the word was: " << chosenword << endl;

    return 0;
}