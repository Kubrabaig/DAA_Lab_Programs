#include <iostream>
#include <string>
using namespace std;

int main() {
    string text, pattern;
    cout << "Enter text: ";
    cin >> text;
    cout << "Enter pattern: ";
    cin >> pattern;

    int n = text.length();
    int m = pattern.length();
    int i = m - 1, j = m - 1;

    while (i < n) {
        if (text[i] == pattern[j]) {
            if (j == 0) {
                cout << "Pattern found at position " << i << endl;
                return 0;
            }
            i--;
            j--;
        } else {
            i = i + m - min(j, 1 + text.find(text[i]));
            j = m - 1;
        }
    }

    cout << "Pattern not found";
    return 0;
}