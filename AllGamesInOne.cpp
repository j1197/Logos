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
#include <iostream>
#include<stdlib.h>
#include <iterator>
#include <map>


using namespace std;

string selectwordforanagram(){
    srand(time(0));
    int random = rand();
    int min = 0;
    int max = 44000;
    //cout << "Seed = " << time(0) << endl;
    int finalNum = rand()%(max-min+1)+min;
    //cout << "Random number = " << finalNum << endl;
    vector<string> words;
    ifstream file("./listofanagrams.txt");
    string line;
    while (getline(file, line)) words.push_back(line);
    string word = words[rand() % words.size()];
    return word;
}


string removespaces(string str){
    str.erase(remove(str.begin(), str.end(), ' '), str.end());
    return str;
}


int letterspresentforhangman ( string a, char b){
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

int hangman(string question, string untilnow) {

    int checking;

    int a = 0;
    for (char letter: question) {
        int is_vowel = (letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u');
        if (is_vowel);
        else
            a = a + 1;
    }

    int no_guesses = (2 * a) - 1;
    cout << "The number of guesses are: " << no_guesses << endl;

    int num_of_wrong_guesses = 0;

    string used = "";

    while (num_of_wrong_guesses < no_guesses && (untilnow != question)) {


        cout << "\n\nYou have " << (no_guesses - num_of_wrong_guesses) << " guesses left.\n";
        cout << "\nYou've used the following letters:\n" << used << endl;
        cout << "\nSo far, the word is:\n" << untilnow << endl;

        cout << "Enter your guess: " << endl;
        char guessedletters;
        cin >> guessedletters;
        used.push_back(guessedletters);
        checking = letterspresentforhangman(question, guessedletters);

        if (checking == 0) {
            cout << "That letter is not present." << endl;
            num_of_wrong_guesses++;
        } else {
            cout << "Yay! Good guess!" << endl;
            for (int i = 0; i < question.length(); ++i) {
                if (question[i] == guessedletters)
                    untilnow[i] = guessedletters;
            }
        }


        if (num_of_wrong_guesses == no_guesses) {
            cout << "\nYou have lost!";

            cout << "\nThe word was " << question << endl;
        }

        if (untilnow == question && num_of_wrong_guesses <= no_guesses)
            cout << "You have won! The word is: " << question << endl;

    }

    return 0;
}


int countxx(string s, char x){
    int count = 0;
    for (int i=0;i<s.length();i++){
        if (s[i] == x)
            count++;}
    return count;
}


int actualword(string g){
    vector <string> words;
    ifstream file("/./words.txt");
    string line;
    while (getline(file, line)) words.push_back(line);
    list<string> word_list(words.begin(),words.end());

    if (std::find(word_list.begin(), word_list.end(), g) != word_list.end()){
        cout<<"You are correct, congratulations!"<<endl;
        exit(0);}
    else{
        cout<<"Sorry, this is incorrect as it is not an actual English word."<<endl;
        exit(0);}
    return 0;
}

int norepeats(string e,string f){
    string myKey;
    map<string,int> countsques;
    for (char letterx: e){
        myKey = letterx;
        int myVal = countxx(e,letterx);
        countsques.insert(pair<string,int>(myKey, myVal));
    }
    //cout << countsques << endl;
    string myKey1;
    map<string,int> countsana;
    for (char letter1: f){
        myKey1 = letter1;
        int myVal1 = countxx(f,letter1);
        countsana.insert(pair<string,int>(myKey1, myVal1));
    }

    if (countsques == countsana)
        actualword(f);
    else
        cout<<"Sorry, this is the wrong answer as it repeats the letters."<<endl;
    exit(0);


    return 0;
}


int noextra(string c, string d){
    for(char letter: d){
        if (std::find(c.begin(), c.end(), letter) == c.end()){
            cout<<"Sorry, this is the wrong answer as it uses extra letters."<<endl;
            exit(0);}
        else
            norepeats(c,d);
    }
    return 0;

}

int letterspresent ( string a, string b){
    removespaces(a);
    removespaces(b);
    list<char> a_list(a.begin(), a.end());
    list<char> b_list(b.begin(), b.end());
    int x = 0;
    for(char letter:a_list){
        if (std::find(b_list.begin(), b_list.end(), letter) != b_list.end())
            x = x + 1;
        else{
            cout << "Sorry, this is the wrong answer as it does not use all the letters in the question."<<endl;
            exit(0);}
    }
    if (x==a.size())
        noextra(a,b);
    else{
        cout <<"Noo";
        exit(0);}
    return 0;
}

list<string> knowpossiblewords(string wordlist){
    vector<string> words;
    ifstream file("./words.txt");
    string line;
    while (getline(file, line)) words.push_back(line);
    list<string> possiblewords;
    for(string word: words) {
        list<char> word_list_temp(word.begin(), word.end());
        bool flag = true;
        for (char letter: word_list_temp) {
            bool found = (std::find(wordlist.begin(), wordlist.end(), letter) != wordlist.end());
            if (found && flag)
                flag = true;
            else
                flag = false;
        }
        if (flag)
            possiblewords.push_back(word);
    }

    return possiblewords;
}

void guessing(list<string> allwords, int trials){
    list<string> listwordsguessed;
    while(true){
        //cin.ignore(256, '\n');
        cout<<"Guess possible words: "<<endl;
        string guessed;
        getline( cin, guessed);
        transform(guessed.begin(), guessed.end(), guessed.begin(), ::tolower);

        if (std::find(allwords.begin(), allwords.end(), guessed) != allwords.end())
        {
            cout<<"Yes, this is a possible word!"<<endl;
            allwords.remove(guessed);
            listwordsguessed.push_back(guessed);
        }
        else if (std::find(listwordsguessed.begin(), listwordsguessed.end(), guessed) != listwordsguessed.end())
        {
            cout << "You have already guessed this word!" << endl;
        }
        else if (allwords.size()==0)
        {
            cout<<"Victory, you have guessed all the words!"<<endl;
            exit(0);
        }
        else if(guessed == "q")
        {
            cout <<"Thank you for playing, rest of the words are: " << endl;
            for ( string c: allwords)
                cout<<c<<endl;
            exit(0);
        }
        else if (std::find(allwords.begin(), allwords.end(), guessed) == allwords.end())
        {
            cout<<"Sorry, this is not a possible word" << endl;
            trials = trials - 1;
        }
        else if(trials == 0){
            cout<<"Game over."<< endl;
            exit(0);
        }




    }
}


string selectword(){
    srand(time(0));
    int random = rand();
    int min = 0;
    int max = 44000;
    //cout << "Seed = " << time(0) << endl;
    int finalNum = rand()%(max-min+1)+min;
    //cout << "Random number = " << finalNum << endl;
    vector<string> words;
    ifstream file("./words.txt");
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
    cout << "Enter 'G' for playing the game 'Guess all words from a given word'." << endl;
    cout << "Enter 'A' for playing the game 'Anagrams'." << endl;
    cout << "Enter 'H' for playing the game 'Hangman'." << endl;
    cout << "Enter 'Q' to exit." << endl;
    char gameselection;
    cin >> gameselection;
    gameselection = tolower(gameselection);

    if(gameselection == 'u'){
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
        if(res){
            cout << "You are right! " << endl;
            exit(0);}
        else{
            cout << "Wrong answer, the word was: " << chosenword << endl;
            exit(0);}}


    else if(gameselection == 'g'){
        string chosenword = selectword();
        transform(chosenword.begin(), chosenword.end(), chosenword.begin(), ::tolower);
        list<char> chosenwordlist(chosenword.begin(), chosenword.end());
        cout << "Welcome to the game! You will be given a word and you have to guess other possible words from it.\n " << endl;
        cout << "Your word is: " << chosenword << endl;
        list<string> probableanswers = knowpossiblewords(chosenword);
        cout<<"Number of possible words are: "<< probableanswers.size() << endl;
        int no_trials = (probableanswers.size())/2;
        cout<<"Number of guesses are: "<< no_trials << endl;
        guessing(probableanswers,no_trials);}


    else if(gameselection == 'a') {
        string question = selectwordforanagram();
        transform(question.begin(), question.end(), question.begin(), ::tolower);
        cout << "Welcome to the game! Find anagrams for the word:  " << question<< endl;
        cout << "All the letters given in the word must be present the exact number of times as they appear in the word and no extra letters must be used." << endl;
        cin.ignore(256, '\n');
        string anagram;
        cout<<"Enter your anagram: "<<endl;
        getline(cin,anagram);
        transform(anagram.begin(), anagram.end(), anagram.begin(), ::tolower);
        if (anagram == question)
            cout << "Invalid answer." << endl;

        else if (anagram == "q"){
            cout << "Thank you for playing!" << endl;
            exit(0);}

        else
            letterspresent(question,anagram);


    }



    else if(gameselection == 'h') {
        string chosenword = selectword();
        cout << "Chosen word is " << chosenword << endl;
        transform(chosenword.begin(), chosenword.end(), chosenword.begin(), ::tolower);
        list<char> chosenwordlist(chosenword.begin(), chosenword.end());
        cout << "Welcome to the game 'Hangman'!" << endl;
        cout << "The word is: ";
        string printedword;
        for (char letter: chosenword){
            int is_vowel = (letter== 'a' || letter== 'e' || letter== 'i' || letter== 'o' || letter== 'u');
            if (is_vowel){
//            letters_guessed_till_now.push_back(letter);
                cout << letter<< " ";
                printedword.push_back(letter);
            }
            else {
                cout << '_' << " ";
                printedword.push_back('_');
            }
        }
        cout << endl;

        string soFar = printedword;
        hangman(chosenword,soFar);
    }

    else if(gameselection == 'q'){
        cout << "Thank you for playing!" << endl;
        exit(0);}

    else
        cout << "Invalid character. Please enter a relevant character." << endl;




    return 0;

}






