#ifndef HANGMANPLAY_H
#define HANGMANPLAY_H
#include "HangmanService.h"


class HangmanPlay
{
    public:
        HangmanPlay() {}
        virtual ~HangmanPlay() {}

        vector<string> getWords(){
            HangmanService hms;
            vector<string> shuffledWords = hms.getRandomWords();

            return shuffledWords;
        }

        ///retrieve shuffled vector from service, create new vector, push masked words into shuffle
        vector<string> returnMaskedWord(){
            HangmanService hms;
            vector<string> words = hms.getRandomWords();
            vector<string> maskedWords;
            string singleWord = "";
            for(unsigned int i = 0; i < words.size(); i++){ ///main sequence when getting word from txt file, masking it and displaying them.
                string word = words[i];
                word = maskWord(word);
                maskedWords.insert(word);
            }
        return maskedWords;
        }

        ///this function keeps the word from the vector and also produces the '_' char counterpart
        string maskWord(string word){

            string underscoredWord = word;
            for(unsigned int i = 0; i < underscoredWord.size(); i++){
                underscoredWord[i] = '-';
            }
            return underscoredWord;
        }

    protected:

    private:
        //vector<string> words;
};

#endif // HANGMANPLAY_H
