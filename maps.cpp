#include <iostream>
#include <string>
#include <map>

using namespace std;

// https://www.hackerrank.com/challenges/linkedin-practice-dictionaries-and-maps/problem


int main() {

    string paragraph = "A planet is an astronomical body orbiting a star or stellar remnant that is massive enough to be rounded by its own gravity";

    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ ";

    map<char, int> letterFrequency;

    for (char c : alphabet) {
        letterFrequency[c] = 0;
    }

    for (char c : paragraph) {
        letterFrequency[toupper(c)]  ++;
    }

    for (char c : alphabet) {
        cout << "Letter " << c << " appears " << letterFrequency[c] << " times " << endl;
    }

}
