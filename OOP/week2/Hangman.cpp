/*
객지 2주차 Hangman Game
*/
#include <iostream>
#include <String>
#include <ctime>
#include <fstream>
using namespace std;

bool containsCharacter(string s, char c) {
    for (char ch : s) {
        if (ch == c) {
            return true; 
        }
    }
    return false;
}

bool play_again() {
    char response;
    cout << "To be continued? (y/n): ";
    cin >> response;
    cout << "\n";
    if (response == 'y' || response == 'Y') 
        return true;
    else 
        return false;
}

int main() { 
    
    string filename = "C:\\git\\2nd2sem\\OOP\\week2\\letters.txt";
    ifstream file(filename);

    string wordlist[50]; 
    string word;
    string solution;
    int wordIndex = 0;
    
    while (file >> word && wordIndex < 50) {
        wordlist[wordIndex] = word; // 각 단어를 배열에 저장
        wordIndex++;
    }

    do {
        srand(static_cast<unsigned int>(time(nullptr)));
        int n = rand() % 50;
        solution = wordlist[n]; //사전에서 랜덤 단어 선택해 solution에 저장

        string guess(solution.length(), '_');
        string triedletters;
        int tryCount = 7;  
        char userInput; 

        do {
            cout << "The word now looks like this:" << guess << endl; 
            cout << "input: "; // 사용자가 글자 추측
            cin >> userInput;

            for (int i = 0; i < solution.length(); i++) { // 추측 글자를 guess에 반영  
                if (userInput == solution[i]) {
                    guess[i] = userInput;
                }
            }

            //입력한 글자가 중복된 입력인지 확인한다
            if (!containsCharacter(triedletters, userInput)) { //중복된 입력이 아니라면
                triedletters += userInput;
                triedletters += " ";
                tryCount--;
            } else { //중복된 입력이라면 시도 횟수를 차감하지 않는다
                cout << "Already entered character" << endl;
            }
            
            if (solution == guess) {
                cout << "Success!" << endl;
                break;
            }
            
            cout << "you have " << tryCount << " guesses left";
            cout << " (tried letters: " << triedletters << ")\n" << endl;
            
        } while (tryCount > 0 );
        
        if (tryCount > 0) 
            cout << "You win: " << solution;
        else 
            cout << "You failed: " << solution;
        
        cout << " (tried letters: " << triedletters << ")" << endl;
        
    } while (play_again());
    
    cout << "Game Over!" << endl;
    file.close();
    return 0;
}