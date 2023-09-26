
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Movie {
private:
    string title;
    double review;

public:
    Movie(string t, double r) : title(t), review(r){}
    void printMovie() {
        cout << "Title: " << title << " Review: " << review << endl;
    }
};

int main() {

    vector<Movie> movies;
    movies.push_back(Movie("Titanic", 9.0));
    movies.push_back(Movie("gone with the wind", 9.6));
    movies.push_back(Movie("terminator", 9.7));

    for (auto &a : movies) 
        a.printMovie();
    
    return 0;
}