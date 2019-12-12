#include "AdminUI.h"

AdminUI::AdminUI()
{
    //ctor
}

AdminUI::~AdminUI()
{
    //dtor
}
void AdminUI::adminUI(){
    MainUI mui;
    HangmanRepo hr;
    char input = '\0';
    cout << "This is admin menu" << endl << endl;
    cout << "Do you want to add a new word to the word bank (Y/N)? ";
    cin >> input;
    if(input == 'Y' || input == 'y'){
        cout << "Word: ";
        string word;
        cin >> word;
        hr.newWord(word);
    }
    else{
        mui.startUI();
    }


}
