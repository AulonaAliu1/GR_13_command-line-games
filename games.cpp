#include <iostream>
#include <algorithm>
#include <string>
#include <ctime>
using namespace std;
#define GTW 1
void guessTheWord(){
    srand(time(0));
    const int n=5;
    string words[n] = {"programim", "elektronike", "sinjale", "matematike", "vegla"};
    
    string wordToGuess = words[rand() % n];// merr nje antare random
    string guessedWord(wordToGuess.length(), '_');//e mbush nje string me _ ne baze te gjatesise se fjales
    string wrongLetters = "";
    int attempts = 6;

    cout << "Loja Guess The Word ka filluar!" << endl;

    
    while (attempts > 0 && guessedWord != wordToGuess) {
        cout << "\nFjala: " << guessedWord << endl;
        cout << "Edhe: " << attempts <<" mundesi te mbetura" << endl;
        cout << "Shkronjat e gabuara: " << wrongLetters<<" " << endl;
        cout << "Zgjedhe nje shkronje: ";
        char guess;
        cin >> guess;

        bool correct = false;
        for (int i = 0; i < wordToGuess.length();i++) {
            if (wordToGuess[i] == guess && guessedWord[i] == '_') {
                guessedWord[i] = guess;
                correct = true;
            }
        }

        if (!correct) {
            wrongLetters += guess;
            attempts--;
        }
    }

    if (guessedWord == wordToGuess) {
        cout << "\nUrime keni gjetur fjalen: " << wordToGuess << endl;
    } else {
        cout << "\nLoja ka mbaruar! Fjala ishte: " << wordToGuess << endl;
    }

}

int main(){
    int pickGame;
    const int numberOfGames=1;
    cout<<"Zgjedhe lojen: 1.Guess the word ";
    cin>>pickGame;
    switch (pickGame)
    {
    case GTW:
       guessTheWord();
        break;
    
    default:
        break;
    }
    return 0;
}