#ifndef HANGMANREPO_H
#define HANGMANREPO_H
#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include "playermodel.h"
using namespace std;
class HangmanRepo
{
    public:
        HangmanRepo() {}
        virtual ~HangmanRepo() {}

        ///Gather the words from txt file and input them into the vector words
        vector<string> retrieveWords(){
            vector<string> words;
            string line;
            ifstream fin;
            fin.open("repo.txt");
            do{
                getline(fin, line);
                for(unsigned int i = 0; i < line.size(); i++){
                    line[i] = toupper(line[i]);
                }
                words.insert(line);

            }while(!fin.eof());
            fin.close();
            return words;
        }

        void newWord(string word){
            ofstream fout("repo.txt", ios::app);
            if(fout.is_open()){
                fout << endl << word;
                ///find exception where if the file is empty..
            }
            fout.close();
        }

        void documentPlayer(string name){
            ofstream fout("players.txt", ios::app);
            if(fout.is_open()){
                fout << endl << name;
            }
            fout.close();
        }
        void documentScore(int score){
            ofstream fout("scores.txt", ios::app);
            if(fout.is_open()){
                fout << endl << score;
            }
            fout.close();
        }
        vector<PlayerModel> getPlayers(){
            vector<PlayerModel> players;
            string line;
            ifstream fin;
            fin.open("players.txt");
            do{
                PlayerModel player;
                getline(fin, line);
                for(unsigned int i = 0; i < line.size(); i++){
                    line[i] = toupper(line[i]);
                }

                player.name = line;
                player.score = 0;
                players.insert(player);
            }while(!fin.eof());
            fin.close();
            string line2;
            ifstream fin2;
            fin2.open("scores.txt");
            for(unsigned int i = 0; i < players.size(); i++){
                getline(fin2, line2);
                players[i].score = atoi(line2.c_str());
            }
            fin2.close();
            return players;
        }

        vector<string> getPoints(){
            vector<string> points;
            string line;
            ifstream fin;
            fin.open("points.txt");
            do{
                getline(fin, line);
                points.insert(line);
            }while(!fin.eof());
            fin.close();
            return points;
        }

    protected:

    private:
};

#endif // HANGMANREPO_H
