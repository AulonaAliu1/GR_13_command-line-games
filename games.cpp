#include <iostream>
#include <string>
#include <ctime>
using namespace std;

//define new games 
#define GTW 1
#define GTN 2


void guessTheNumber() {
    srand(time(0));  
    int randomNumber = rand() % 100 + 1; 
    int guess;
    int maxAttempts = 7;

    cout << "Loja Guess the Number filloi! Zgjedhe nje numer prej 1 deri ne 100." << endl;

    while (maxAttempts > 0) {
        cout << "\nKeni dhe " << maxAttempts << " mundesi. Zgjedhe numrin: ";
        cin >> guess;

        if (guess == randomNumber) {
            cout << "Urime numri i sakte eshte: " << randomNumber << endl;
            return;
        } 
        else if (guess > randomNumber) {
            cout << "Me poshte.";
        } 
        else {
            cout << "Me larte.";
        }

        maxAttempts--;
    }

    cout << "\nLoja mbaroi! Numri i sakte ishte : " << randomNumber << endl;
}
void guessTheWord(){
    srand(time(0));
    int x;
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
            wrongLetters += guess;//nese guess eshte wrong e shtojme shkronjen ne wrong letters
            attempts--;//zbresim mundesite per nje
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
    //update this when adding new game
    const int numberOfGames=2;
    cout<<"Zgjedhe lojen: 1.Guess the word, 2.Guess the number ";
    cin>>pickGame;
    while (pickGame>numberOfGames||pickGame<0)
    {
        cout<<"Zgjedhje nje numer nga 1 deri ne "<<numberOfGames;
    }
    switch (pickGame)
    {
    case GTW:
       guessTheWord();
        break;
    
    case GTN:
       guessTheNumber();
        break;
    
    default:
        break;
    }
    return 0;
}