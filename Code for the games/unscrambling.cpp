//
// Created by JP on 2019-05-29.
//


#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include<cstdlib>
#include<ctime>
#include <vector>
#include <cctype>

using namespace std;

string selectword(){
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
    string word = words[rand() % words.size()];
    return word;
}

string shuffling(string originalword){
    transform(originalword.begin(), originalword.end(), originalword.begin(), ::tolower);
    //cout << chosenword << endl;
    string shuffled = originalword;
    //cout << chosenword << endl;
    random_shuffle(shuffled.begin(), shuffled.end());
    return shuffled;
}

int unscrambling(string question, string answer ){
    //cout<< guessedword<< endl;
    if (question == answer)
        //cout << "You are right! " << endl;
        return true;
    else
        //cout << " Wrong answer, the word was: " << chosenword << endl;
        return false;
}

int main () {
    cout << "What game would you like to play?" << endl;
    cout << "Enter 'U' for playing the game 'Unscrambling'." << endl;
    char gameselection;
    cin >> gameselection;
    if(gameselection == 'U'){
        string chosenword = selectword();
        //cout << chosenword;
        string shuffledword = shuffling(chosenword);
        cout << "Hello! Welcome to the game 'Unscramble the word'! \n";
        cout << "The game is straightforward. The given word has to be unjumbled and it will, post unscrambling, form an actual English word. \n";
        cout << "Your scrambled word is: " << shuffledword << '\n';
        cin.ignore(256, '\n');
        string guessedword;
        cout << "Enter your answer: " << endl;
        getline(cin, guessedword);
        transform(guessedword.begin(), guessedword.end(), guessedword.begin(), ::tolower);
        bool res = unscrambling(chosenword, guessedword);
        if(res == true)
            cout << "You are right! " << endl;
        else
            cout << "Wrong answer, the word was: " << chosenword << endl;}



    return 0;
}