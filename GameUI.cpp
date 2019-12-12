#include "GameUI.h"

GameUI::GameUI()
{
    //ctor
}

GameUI::~GameUI()
{
    //dtor
}
void GameUI::startUI(){

    bool noGame = false;
    char play = '\0';

    while(noGame == false){
        cout << "Start new game(Y/N)? ";
        cin >> play;
        if(play == 'Y' || play == 'y'){
            cout << endl;
            cout << "Lets play HANGMAN!" << endl << endl;
            string name;
            cout << "But first, what is your name(no spaces)? ";
            cin >> name;
            mainGameUI(name);
        }
        else if(play == 'N' || play == 'n'){
            cout << "Ok, have a nice day!" << endl << endl << endl;
            MainUI mui;
            mui.startUI();
        }
        else{
            cout << "Invalid input: " << play << ", try again." << endl;
        }
    }
}

void GameUI::endOfGame(string playerName, int playerPoints){
    MainUI mui;
    cout << endl << endl << endl;
    int input = 0;
    cout << "Ok " << playerName << ", your score is " << playerPoints << endl;
    cout << "Reset and play again (1), save score and play again (2), exit and save score (3) or just exit (4)? ";
    cin >> input;
    if(input == 1){
        startUI();
    }
    else if(input == 2){
        ///Saves score and add to scores.txt
        hms.documentName(playerName);
        hms.documentScore(playerPoints);
        startUI();
    }
    else if(input == 3){
        cout << endl << endl;
        hms.documentName(playerName);
        hms.documentScore(playerPoints);
        mui.startUI();
    }
    else{
        cout << endl << endl;
        mui.startUI();
    }
}

int GameUI::getTries(){
    int tries = 0;
    cout << "How many tries (max 15)? ";
    cin >> tries;
    while(tries < 1 || tries >= 16){
        cout << "Incorrect input: " << tries << " try again ";
        cin >> tries;
    }
    return tries;
}

void GameUI::mainGameUI(string name){

    HangmanPlay hmp;

    string playerName = name;

    cout << endl << "Welcome " << playerName << "!" << endl;
    cout << "The current word bank is " << hmp.getWords().size() << " words.." << endl;

    ///user decides how many tries he has
    ///vector to copy the shuffled words
    vector<string> wordList = hmp.getWords();
    int wordListSize = wordList.size();
    ///vector to copy the dashed words
    vector<string> maskedWords = hmp.returnMaskedWord();
    ///vector to check input from user
    vector<char> testVector;

    int turns = wordList.size();
    int playerPoints = 0;
    int tries = getTries(); ///gets player tries
    ///actual game play here
    while(turns != 0){ ///after each successive guess of word, clear the element from both vectors
        PlayerInput pi;
        for(int i = 0; i < wordListSize; i++){
            string guessingWord = wordList[i];
            string maskedWord = maskedWords[i];
            testVector.clear();
            bool turnFinish = false;
            while(!turnFinish){
                if(tries == 0){
                    cout << "All out of tries, game over!" << endl << endl;
                    turns = 0;
                }
                cout << endl << "Word: ";
                cout << maskedWord << endl;
                cout << "You have " << tries << " tries left and " << playerPoints << " points" << endl;
                cout << "Your guess? ";
                char test = '\0';
                cin >> test;
                test = toupper(test); ///make all test inputs to uppercase for simplification

                ///checking conditions of user input and updating the word/game
                if(pi.checkInput(testVector, test)){
                    cout << "You have already tried the character " << test << ", try again" << endl;
                }
                else if(!(pi.checkInput(testVector, test))){
                    testVector.insert(test);
                    if(pi.checkMatch(guessingWord, test)){
                        cout << test << " is a match. Very good!" << endl;
                        ///function to update the masked word with input
                        maskedWord = pi.updateMaskedWord(maskedWord, guessingWord, test);
                        ///function to compare maskedWord with guessingWord,
                        ///if they match, exit loop and enter next index of words
                        if(pi.compareCheck(maskedWord, guessingWord)){
                            cout << "Well done, the word was: " << guessingWord << endl;
                            playerPoints++;
                            cout << endl << endl;
                            ///now to decrement the size of the vectors to fulfill the while loop
                            wordList[i].erase();
                            maskedWords[i].erase();
                            turns--;
                            if(turns == 0){
                                cout << "Congrats, you've finished all the words!" << endl;
                                endOfGame(playerName, playerPoints);
                            }
                            cout << "Do you want to continue (Y/N)? ";
                            char confirmation;
                            cin >> confirmation;
                            if(confirmation == 'N' || confirmation == 'n'){
                                cout << endl;
                                cout << playerName << " has ended game.";
                                endOfGame(playerName, playerPoints);
                            }
                            else{
                                tries = getTries();
                                turnFinish = true;
                            }
                        }
                    }
                    else{
                        cout << test << " is not a match!" << endl;
                        tries--;
                        if(tries == 0){
                            cout << "Oh no, " << playerName << " you're all out of tries! Game over :(" << endl;
                            if(playerPoints == 0){
                                cout << "You had 0 points, you don't lose any points" << endl;
                            }
                            else{
                                cout << "You lose one point :/" << endl;
                                playerPoints--;
                            }
                            endOfGame(playerName, playerPoints);
                        }
                    }
                }
            }
        }
    }
}


