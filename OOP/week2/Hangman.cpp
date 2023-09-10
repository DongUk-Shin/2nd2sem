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

    if (response == 'y' || response == 'Y') 
        return true;
    else 
        return false;
}

int main() { 
    
    string solution;
    //string list[] = { "the", "apple", " programming ", " language "}; //단어 list

    string filename = "C:\\Users\\PC\\Desktop\\git\\2nd2sem\\OOP\\week2\\letters.txt";
    ifstream file(filename);

    
    string list[50]; 
    int wordCount = 0;

    string word;
    while (file >> word && wordCount < 50) {
        list[wordCount] = word; // 각 단어를 배열에 저장
        wordCount++;
    }

    do {
        srand(static_cast<unsigned int>(time(nullptr)));
        int n = rand() % 50;
        solution = list[n]; //사전에서 랜덤 단어 선택해 solution에 저장

        string guess(solution.length(), '_');
        int tryCount = 7;  
        string triedletters;
        char userInput; 

        do {
            cout << "The word now looks like this:" << guess << endl; // guess 현재 상태 보여주기
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
                cout << "Succes!" << endl;
                break;
            }

            cout << "you have " << tryCount << " guesses left";
            cout << " (tried letters: " << triedletters << ")\n" << endl;
            
        } while (tryCount > 0 );

        cout << "You win or You failed: " << solution;
        cout << " (tried letters: " << triedletters << ")" << endl;
        

    } while (play_again());
    
    cout << "Game Over!" << endl;
    file.close();
    return 0;
}