#ifndef HANGMANSERVICE_H
#define HANGMANSERVICE_H
#include <ctime>
#include <algorithm>
#include "HangmanRepo.h"


class HangmanService
{
    public:
        HangmanService() {}
        virtual ~HangmanService() {}

        ///returns the vector in a randomized order
        vector<string> getRandomWords(){

            vector<string> getWords = hmr.retrieveWords();

            srand(time(NULL));
            random_shuffle(getWords.begin(), getWords.end());
            return getWords;
        }

        void documentName(string name){
            string playerName = name;
            hmr.documentPlayer(playerName);
        }

        void documentScore(int score){
            int playerScore = score;
            hmr.documentScore(playerScore);
        }

        vector<PlayerModel> getPlayers(){
            vector<PlayerModel> highScores = hmr.getPlayers();
            sort(highScores.begin(), highScores.end(), compareInts);
            return highScores;
            //return hmr.getPlayers();
        }

        ///compare functions don't belong in the class, so it is static
        static bool compareInts(const PlayerModel &a, const PlayerModel &b){

            return (a.score > b.score);
        }

    protected:

    private:
        HangmanRepo hmr;
};

#endif // HANGMANSERVICE_H
