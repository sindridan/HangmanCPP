#include "MainUI.h"

MainUI::MainUI()
{
    //ctor
}

MainUI::~MainUI()
{
    //dtor
}
void MainUI::startUI(){
    GameUI gameui;
    AdminUI adminui;
    HangmanService hms;
    HangmanRepo hmr;

    bool check = true;
    while(check){
        int input = 0;
        cout << "Welcome to HANGMAN" << endl;
        cout << "1. Play game" << endl;
        cout << "2. Admin mode" << endl;
        cout << "3. High scores" << endl;
        cout << "4. Quit" << endl;
        cout << "Select: ";
        cin >> input;
        if(input == 1){
            cout << endl << endl;
            gameui.startUI();
        }
        else if(input == 2){
            cout << endl << endl;
            adminui.adminUI();
        }
        else if(input == 3){
            cout << endl << endl;
            cout << "Top 5 high scores: " << endl << endl;
            vector<PlayerModel> players = hms.getPlayers();
            for(int i = 0; i < 5; i++){
                if(i == 0){
                    cout << "High score record holder is: " << players[0].name;
                    cout << ", with the score of: " << players[0].score << "!" << endl << endl;
                }
                else{
                    cout << "Player #" << i+1 << ": " << players[i].name << ", score: " << players[i].score << endl;
                }
            }
            cout << endl << endl;
        }
        else if(input == 4){
            cout << "Good bye :)";
            exit(0);
        }
        else{
            cout << "incorrect input";
        }
    }

}
