#include <bits/stdc++.h>
using namespace std;
unordered_map<char, string> charToMorseMap = {
    {'A', ".-"}, {'B', "-..."}, {'C', "-.-."}, {'D', "-.."}, {'E', "."}, {'F', "..-."}, 
    {'G', "--."}, {'H', "...."}, {'I', ".."}, {'J', ".---"}, {'K', "-.-"}, {'L', ".-.."}, 
    {'M', "--"}, {'N', "-."}, {'O', "---"}, {'P', ".--."}, {'Q', "--.-"}, {'R', ".-."}, 
    {'S', "..."}, {'T', "-"}, {'U', "..-"}, {'V', "...-"}, {'W', ".--"}, {'X', "-..-"}, 
    {'Y', "-.--"}, {'Z', "--.."}, {'0', "-----"}, {'1', ".----"}, {'2', "..---"}, 
    {'3', "...--"}, {'4', "....-"}, {'5', "....."}, {'6', "-...."}, {'7', "--..."}, 
    {'8', "---.."}, {'9', "----."},{' ',"/"}
};

unordered_map<string, char> morseToCharMap;

void initializeMorseToCharMap() {//creating reverse mapping 
    for (auto& pair : charToMorseMap) {
        morseToCharMap[pair.second] = pair.first;//swapping keys and values of charToMorseMap and storing it in new map morseToCharMap
    }
}

string textToMorse(string& text) {
    stringstream ss;
    for (char c : text) { //It iterates over each character in the input string. 
        if (isalpha(c) || isdigit(c)|| c==' ') { //If the character is an alphabet letter or a digit, it converts the character to uppercase
            ss << charToMorseMap[toupper(c)] << " "; //looks up its Morse code from charToMorseMap, and appends it to the stringstream ss
        } else{
            ss << " ";//If other symbols or operator found which are out of map list, then append space
        }
    }
    return ss.str();
}

string morseToText(string& morseCode) {
    stringstream ss(morseCode);
    string token;//To store individual Morse code sequences from the input string using the stringstream.
    string result = "";
    while (ss >> token) { // loop that runs as long as there are Morse code sequences left from the ss stringstream //In each iteration, it extracts a Morse code sequence and stores it in the token variable.
        auto it = morseToCharMap.find(token);//For each Morse code token, it looks up the corresponding character from the morseToCharMap
        if (it != morseToCharMap.end()) {//If a valid Morse code is encountered
            result += it->second;
        } else {
            result += '?';  // If invalid Morse code is encountered
        }
    }
    return result;
}

int main() {
    initializeMorseToCharMap();//Used for reverse mapping

    string morseCode, text, result = "";
    int choice;
    
    while (true) {
        cout << "Enter choice:\n 1: Convert Text to MorseCode \n 2: Convert MorseCode to Text \n 3: Exit" << endl;
        cout<<"Choice:";
        cin >> choice;
        
        if (choice == 1) {
            cout << "Enter Text: ";
            cin.ignore();
            getline(cin, text);
            result = textToMorse(text);
            cout << text << " in Morse code is: " << result << endl;
        } else if (choice == 2) {
            cout << "Enter Morse code: ";
            cin.ignore();
            getline(cin, morseCode);
            result = morseToText(morseCode);
            cout << morseCode << " in Text is: " << result << endl;
        } else if (choice == 3) {
            break;
        } else {
            cout << "Invalid Input" <<endl;
            break;
        }
    }
    return 0;
}

