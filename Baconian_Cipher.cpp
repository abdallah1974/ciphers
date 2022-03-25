/*

*******************************************************************************/
// import some libaraies
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// ******************************************************* //

// func to cipher a message by Baconian Cipher
void cipher(){
    // declare the word that user will input
    string word;
    // asking user to input a message he want to cipher ;
    cout << "Please enter the message to cipher:  " << endl;
    cin.clear();
    cin.sync();
    getline(cin , word);


    // looping in every char in message
    for(int i = 0 ; i < word.size(); i++){
        // if it's space print it without change
        if (isspace(word[i])){
            cout << word[i] << endl;
        // if it's not space:
        }else{
        // converting the char to binary 5 digits
        // * '-65' to make "a-z" = "0-26" to fit Baconian Cipher
            bitset<5> binary(word[i]-65);
        // print the result of cipher by changing every(0,1) to ('a','b')
            cout << binary.to_string('a', 'b') << " ";
        }
    }
    cout << endl;
}
// ********************************************************* //

// func to decipher message by Baconian Cipher
void decipher(){
    // declaring variables
    string message , collector = "";
    vector<string> splited;

    // asking user to input a message he want to decipher ;
    cout << "Please enter the message to decipher:  " << endl;
    bool valid = false;
    // check validation of input and asking to enter correct one
    while (!valid){

        cin.clear();
        cin.sync();
        getline(cin , message);

        // looping in every char
        for (int y = 0; y < message.length();y++){
                // refuse any char except ("a","b"," ")
            if ((message[y] == 'a') || (message[y] == 'b') || (message[y] == ' ')){

                valid = true;

            }else{
                cout << "plz enter a ciphered message to decipher it like 'aaaab aabba abbaa':"<<endl;
                valid = false;
                break;
            }
        }
        // check if every char is represented by 5 encrypted chars or not
        if (valid){
            for (int z = 0; z < message.length();z++){
                if(isspace(message[z])){
                    if ((z+splited.size())%5 == 0){
                        valid = true;
                        break;
                    }else{
                        cout << "plz enter a ciphered message that has space after every 5 chars:"<<endl;
                        valid = false;
                        break;
                    }
                }
            }

        }


        break;
    }

    // when inputs be vaild , we start to decipher it
    // spliting the message and storing the result in "splited" vector
    for(int i = 0; i < message.size(); i = i+6){
        for(int x = 0; x < 5; x++){
            collector += message[x+i];

        }
        splited.push_back(collector);
        collector = "";
    }
    // converting (a,b) to (0,1) then converting them from binary to thier values(ascii code)
    for(int y = 0; y < splited.size();y++){

        bitset<5> binary(splited[y], 0 , splited[y].size(), 'a' , 'b');
        cout <<  char(binary.to_ulong()+65);

    }
    cout <<endl;
}
// ******************************************************************** //

// main func
int main()
{
    int action;

    cout << "Ahlan ya user ya habibi." << endl;
    // ask user about what he want to do
    while(true){

        cout << "What do you like to do today?" << endl;
        cout << "1- Cipher a message" << endl;
        cout << "2- Decipher a message" << endl;
        cout << "3- End" << endl;
        cin >> action;
        if(action == 1){
            cipher();

        }else if(action == 2){
            decipher();

        }else if(action == 3){
            _Exit(0);

        }else{
            cout << "Please enter correct input" << endl;

        }
    }

    return 0;
}
