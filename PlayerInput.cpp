#include "PlayerInput.h"

PlayerInput::PlayerInput()
{
    //ctor
}

PlayerInput::~PlayerInput()
{
    //dtor
}

bool PlayerInput::checkInput(vector<char> checked, char testChar){

    for(int i = 0; i < checked.size(); i++){
        if(checked[i] == testChar){
            return true;
        }
    }
    return false;
}

bool PlayerInput::checkMatch(string wordInput, char testChar){

    for(int i = 0; i < wordInput.size(); i++){
        if(wordInput[i] == testChar){
            return true;
        }
    }
    return false;
}

string PlayerInput::updateMaskedWord(string maskedWord, string guessingWord, char testChar){

    string newMaskedWord = maskedWord;
    for(int i = 0; i < guessingWord.size(); i++){
        if(guessingWord[i] == testChar){
            newMaskedWord[i] = testChar;
        }
    }
    return newMaskedWord;
}

bool PlayerInput::compareCheck(string maskedWord, string guessingWord){

    if(maskedWord == guessingWord){
        return true;
    }
    return false;
}
