// importing libraries
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// declaring message and key that user will input and regular alphabet
string message, key , alphabet = "abcdefghijklmnopqrstuvwxyz";

// func to take inputs from user and check validation of it
string getting_inputs(string& message, string& key){

    // asking user to input a message he want to cipher ;
    cout << "Please enter a message:" << endl;
    cin.clear();
    cin.sync();
    getline(cin , message);
    // transfer all char to lower case
    transform(message.begin(), message.end(), message.begin(), ::tolower);
    // take the key from user
    cout << "plz enter a key" << endl;
    // check validation of inputs
    while (true){
        cin >> key;
        transform(key.begin(), key.end(), key.begin(), ::tolower);
        bool valid = true;
        // looping in every char
        for(int i = 0; i < key.length(); i++){
            // if char is not alphabet , refuse it
            if (!isalpha(key[i])){
                cout << "plz enter a key from alphabetic characters only"<<endl;
                valid = false;
                break;
            }

        }
        if (valid){
            // key must be from 5 chars
            if(key.length() != 5){
                cout << "plz enter a key with 5 chars only" << endl ;
                valid = false;
            }else{
                for(int i = 0; i < key.length(); i++ ){
                    // key must be from unique chars
                    if(count(key.begin(),key.end(),key[i])>1){
                        cout << "plz enter a key with 5 unique chars: "<<endl;
                        valid = false;
                        break;
                    }

                }


            }


        }
        if (valid){
            break;
        }


    }

    // convert the regular alphabet to encrypted one
    for(int i = 0; i < key.length() ; i++){
        for(int x = 0; x < alphabet.length(); x++ ){
            if(key[i] == alphabet[x]){
                alphabet.erase(remove(alphabet.begin(),alphabet.end(),key[i]), alphabet.end());
            }

        }
    }
    key += alphabet;


    return message, key;
}
// func to cipher a message by Simple Substitution Cipher
void cipher(){
    // take inputs
    getting_inputs(message , key);
    // looping in every char
    for(int i = 0; i < message.length() ; i++){
        // if it is an alphabet , we convert it to encrypted char from encrypted alphabet array
        if (isalpha(message[i])){

            message[i] = key[message[i]-97];
            cout << message[i];
        // if it isn't an alphabet, we print it without changes
        }else{
            cout << message[i];
        }
    }
    cout << endl;
}
// func to decipher a message by Simple Substitution Cipher.
void decipher(){
    // take inputs
    getting_inputs(message , key);
    // looping in every char
    for(int i = 0; i < message.length() ; i++){
        // if it is a encrypted alphabet , we revert it to original char from regular alphabet
        if (isalpha(message[i])){

            message[i] = key.find(message[i])+97;
            cout << message[i];
        // if it isn't an alphabet , we print it without changes
        }else{
            cout << message[i];
        }
    }
        cout << endl;
}
// main function
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
