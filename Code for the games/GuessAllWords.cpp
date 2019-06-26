
#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include<cstdlib>
#include<ctime>
#include <vector>
#include <cctype>
#include <algorithm>
#include<stdlib.h>

using namespace std;


int main () {
    srand(time(0));
    int random = rand();
    int min = 0;
    int max = 370349;
    //cout << "Seed = " << time(0) << endl;
    int finalNum = rand() % (max - min + 1) + min;
    //cout << "Random number = " << finalNum << endl;
    vector <string> words;
    ifstream file("/Users/jp/Desktop/words.txt");
    string line;
    while (getline(file, line)) words.push_back(line);


    string chosenword = words[rand() % words.size()];
    transform(chosenword.begin(), chosenword.end(), chosenword.begin(), ::tolower);
    cout << "Welcome to the game! You will be given a word and you have to guess other possible words from it.\n " << endl;
    cout << "Your word is: " << chosenword << endl;


    list<char> chosenwordlist(chosenword.begin(), chosenword.end());
    //for (char c:chosenwordlist)
    //cout << c << "\n";

    list<string> possiblewords;

    for(string word: words) {
        list<char> word_list_temp(word.begin(), word.end());
        bool flag = true;
        for (char letter: word_list_temp) {
            bool found = (std::find(chosenwordlist.begin(), chosenwordlist.end(), letter) != chosenwordlist.end());
            if (found && flag)
                flag = true;
            else
                flag = false;
        }
        if (flag)
            possiblewords.push_back(word);
    }


    cout<<"Number of possible words are: "<< possiblewords.size() << endl;
    int no_trials = (possiblewords.size())/2;
    cout<<"Number of guesses are: "<< no_trials << endl;

    list<string> listwordsguessed;

    while(true){
        cout<<"Guess possible words: "<<endl;
        string guessed;
        getline( cin, guessed);
        transform(guessed.begin(), guessed.end(), guessed.begin(), ::tolower);

        if (std::find(possiblewords.begin(), possiblewords.end(), guessed) != possiblewords.end())
        {
            cout<<"Yes, this is a possible word!"<<endl;
            possiblewords.remove(guessed);
            listwordsguessed.push_back(guessed);
        }
        else if (std::find(listwordsguessed.begin(), listwordsguessed.end(), guessed) != listwordsguessed.end())
        {
            cout << "You have already guessed this word!" << endl;
        }
        else if (possiblewords.size()==0)
        {
            cout<<"Victory, you have guessed all the words!"<<endl;
            exit(0);
        }
        else if(guessed == "q")
        {
            cout <<"Thank you for playing, rest of the words are: " << endl;
            for ( string c: possiblewords)
                cout<<c<<endl;
            exit(0);
        }
        else if (std::find(possiblewords.begin(), possiblewords.end(), guessed) == possiblewords.end())
        {
            cout<<"Sorry, this is not a possible word" << endl;
            no_trials = no_trials - 1;
        }
        else if(no_trials == 0){
            cout<<"Game over."<< endl;
            exit(0);
        }




    }








    return 0;
}


