#ifndef PLAYERINPUT_H
#define PLAYERINPUT_H
#include <vector>
#include <string>
#include <iostream>

using namespace std;
class PlayerInput
{
    public:
        PlayerInput();
        virtual ~PlayerInput();

        bool checkInput(vector<char> checked, char testChar);
        bool checkMatch(string wordInput, char testChar);
        string updateMaskedWord(string maskedWord, string guessingWord, char testChar);
        bool compareCheck(string maskedWord, string guessingWord);

    protected:

    private:

};

#endif // PLAYERINPUT_H
