#include <iostream>
#include <string>
#include <ctime>
#include <vector>
#include <cstdlib>

using namespace std;

//define new games 
#define GTW 1
#define GTN 2
#define MBG 3
#define DCG 4
int Sillezarin() {
    return rand() % 6 + 1;
}

void Zaret() {
    srand(time(0)); 
    char Zgjidhja;
    cout << "Miresevini ne lojen e zareve!" << endl;

    do {
        int Zari1 = Sillezarin();
        int Zari2 = Sillezarin();

        cout << "Ke hedhur: " << Zari1 << " dhe " << Zari2 << "." << endl;
        cout << "Totali: " << Zari1 + Zari2 << endl;

        cout << "A deshiron te hedhesh serish? (s per po, cdo gje tjeter per jo): ";
        cin >> Zgjidhja;

    } while (Zgjidhja == 's' || Zgjidhja == 'S');

    cout << "Faleminderit qe luajte! Mire u pafshim." << endl;
}
void guessTheNumber() {
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

void magic8Ball() {
    // kjo loje i thote userit me jep nje pyetje me pergjigje "po, jo" dhe ia kthen pergjigjen

    vector<string> pergjigjet = {
        "Po, sigurishte!",
        "Padyshim.",
        "Me shume gjase.",
        "Po!",
        "Pyet perseri me vone.",
        "Me mire te mos e dish tani.",
        "Nuk mund ta di tani.",
        "Mos mbaj shume shprese.",
        "Burimet e mia te informacionit thone jo.",
        "Shume e dyshimte."
    };

    string pyetje;

    cout << "Mire se vini ne Magic 8-Ball! Beni nje pyetje po/jo: ";
    cin.ignore(); 
    getline(cin, pyetje);

    int index = rand() % pergjigjet.size();

    cout << "Pergjigja eshte: " << pergjigjet[index] << endl;
}

int main(){
    srand(time(0));  
    int pickGame;
    //update this when adding new game
    const int numberOfGames=4;
    cout<<"Zgjedhe lojen: 1.Guess the word, 2.Guess the number, 3. Magic 8 Ball , 4. Dice";
    cin>>pickGame;
    while (pickGame>numberOfGames||pickGame<0)
    {
        cout<<"Zgjedhje nje numer nga 1 deri ne 4"<<numberOfGames;
    }
    switch (pickGame)
    {
    case GTW:
       guessTheWord();
        break;
    
    case GTN:
       guessTheNumber();
        break;
    case MBG:
       magic8Ball();
        break;
    case DCG: Zaret();
    break;
    default: cout<<"Kjo loje nuk egziston";
        break;
    }
    return 0;
}