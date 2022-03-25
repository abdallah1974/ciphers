#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// declare the message and key that user will input
string message, key;
// func to take inputs from user and check validation of it
string getting_inputs(string& message, string& key){

    // asking user to input a message he want to cipher ;
    cout << "Please enter a message:" << endl;
    // check validation of inputs
    while (true){

        cin.clear();
        cin.sync();
        getline(cin , message);
        // convert all chars to upper case
        transform(message.begin(), message.end(), message.begin(), ::toupper);
        // message should be less than 80 char
        if(message.length() > 80){
            cout << "plz enter a message less than 80 char" << endl;
        }else{
            cout << "plz enter a key" << endl;
            // check validation of key
            while (true){
                cin >> key;
                transform(key.begin(), key.end(), key.begin(), ::toupper);
                bool valid = true;
                for(int i = 0; i < key.length(); i++){
                    // key must be from alphabetic characters only
                    if (!isalpha(key[i])){
                        cout << "plz enter a key from alphabetic characters only"<<endl;
                        valid = false;
                        break;
                    }

                }
                if (valid){
                    // key must be less than 8 chars
                    if(key.length() > 8){
                        cout << "plz enter a key less than 8 char" << endl ;
                    }else{
                        break;

                    }

                }

            }

            break;
        }


    }
    return message, key;
}
// func to cipher a message by Vignere Cipher
void cipher(){
    // take inputs from user
    getting_inputs(message , key);
    // looping in every char
    for(int i = 0; i < message.length() ; i++){
        int x = i;
        // if it is an alphabet , we convert it to encrypted char
        if (isalpha(message[i])){
            while  (x >= key.length()){
                x -= key.length();
            }
            message[i] = ((message[i] + key[x])% 26) + 'A';
            cout << message[i];
        // if it isn't an alphabet, we print it without changes
        }else{
            cout << message[i];
        }

    }
    cout << endl;
}
// func to decipher a message by Vignere Cipher.
void decipher(){
    // take inputs from user
    getting_inputs(message , key);
    // looping in every char
    for(int i = 0; i < message.length() ; i++){
        int x = i;
        if (isalpha(message[i])){
            while  (x >= key.length()){
                x -= key.length();
            }

            for(int z = 1; z < 26; z++){
                // get the reverse of mod 26 to know sum of message char and key char
                if( ((message[i] - 'A') + (z*26) ) - key[x] > 65){
                    // print original char buy - key char
                    cout << (char)(((message[i] - 'A') + (z*26) ) - key[x]);
                    break;
                }
            }

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
