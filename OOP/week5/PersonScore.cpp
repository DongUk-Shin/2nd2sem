#include <vector>
#include <iostream>
using namespace std;

int main() {

    vector<int> sc;

    int i, score, sum = 0;
    do {
        cout << "Input Score: ";
        cin >> score;
        if (score != -1)
            sc.push_back(score);
        

    } while (score != -1);

    for (auto& a : sc) {
        sum += a;
    }
    double avg = sum / sc.size();
    cout << "Sum: " << sum << endl;
    cout << "Avg: " << avg << endl;

    return 0;
}