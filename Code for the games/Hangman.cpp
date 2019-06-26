#include <iostream>
#include <fstream>
#include <string.h>
#include <list>
#include<cstdlib>
#include<ctime>
#include <vector>
#include <cctype>
#include<stdio.h>
#include<algorithm>

using namespace std;


string removespaces(string str){
    str.erase(remove(str.begin(), str.end(), ' '), str.end());
    return str;
}


int letterspresent ( string a, char b){
    removespaces(a);
    //list<char> a_list(a.begin(), a.end());
    int i = 0;
    int x = 0;
    for (int i = 0; i < a.length(); i++)
    {
        if(a[i] == b){
            x = 1;
            break;}
        else
            x = 0;}
    return x;

}



int main(){
    srand(time(0));
    int random = rand();
    int min = 0;
    int max = 44000;
    int finalNum = rand() % (max - min + 1) + min;
    vector <string> words;
    ifstream file("/Users/jp/Desktop/words.txt");
    string line;
    while (getline(file, line)) words.push_back(line);

    string chosenword = words[rand() % words.size()];
    cout << "Chosen word is " << chosenword << endl;
    transform(chosenword.begin(), chosenword.end(), chosenword.begin(), ::tolower);
    list<char> chosenwordlist(chosenword.begin(), chosenword.end());



    string soFar;
    string used;
    string printedword;

    //list<char> printedwordlist(printedword.begin(), printedword.end());

    cout << "Welcome to the game 'Hangman'!" << endl;

    cout << "The word is: ";


    int a = 0;
    for (char letter: chosenword){
        int is_vowel = (letter== 'a' || letter== 'e' || letter== 'i' || letter== 'o' || letter== 'u');
        if (is_vowel){
            cout << letter<< " ";
            printedword.push_back(letter);
        }
        else {
            cout << '_' << " ";
            a = a + 1;
            printedword.push_back('_');
        }
    }
    cout << endl;

    soFar = printedword;          //word guessed so far
    used = "";                    // letters already guessed

    int checking;
    int no_guesses = (2 * a) - 1;
    cout << "The number of guesses are: " << no_guesses << endl;
    int num_of_wrong_guesses = 0;

    while (num_of_wrong_guesses < no_guesses&& (soFar != chosenword)) {


        cout << "\n\nYou have " << (no_guesses - num_of_wrong_guesses) << " guesses left.\n";
        cout << "\nYou've used the following letters:\n" << used << endl;
        cout << "\nSo far, the word is:\n" << soFar << endl;

        cout << "Enter your guess: " << endl;
        char guessedletters;
        cin >> guessedletters;
        used.push_back(guessedletters);
        checking = letterspresent(chosenword, guessedletters);

        if(checking == 0){
            cout << "That letter is not present." << endl;
            num_of_wrong_guesses++;
        }
        else{
            cout << "Yay! Good guess!" << endl;
            for (int i = 0; i < chosenword.length(); ++i){
                if (chosenword[i] == guessedletters)
                    soFar[i] = guessedletters;}}


        if (num_of_wrong_guesses == no_guesses)
        {
            cout << "\nYou have lost!";

            cout << "\nThe word was " << chosenword << endl;}

        if(soFar == chosenword && num_of_wrong_guesses <= no_guesses)
            cout << "You have won! The word is: " << chosenword << endl;

    }

    return 0;
}
