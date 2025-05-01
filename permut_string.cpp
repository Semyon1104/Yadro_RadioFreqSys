#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void permuteRecursive(string& str, int left, int right) {
    if (left == right) {
        cout << str << endl;
    }
    else {
        for (int i = left; i <= right; i++) {
            swap(str[left], str[i]);
            permuteRecursive(str, left + 1, right);
            swap(str[left], str[i]);
        }
    }
}

void printAllPermutationsRecursive(const string& s) {
    string str = s;
    permuteRecursive(str, 0, str.size() - 1);
}

void printAllPermutationsIterative(string s) {
    sort(s.begin(), s.end());
    cout << s << endl;

    while (true) {
        int i = s.size() - 2;
        while (i >= 0 && s[i] >= s[i + 1])
            i--;

        if (i < 0) break;

        int j = s.size() - 1;
        while (s[j] <= s[i])
            j--;

        swap(s[i], s[j]);

        reverse(s.begin() + i + 1, s.end());

        cout << s << endl;
    }
}

int main() {
    string input;
    cout << "Enter a string: ";
    cin >> input;

    cout << "Recursive permutations:\n";
    printAllPermutationsRecursive(input);

    cout << "\nIterative permutations:\n";
    printAllPermutationsIterative(input);

    return 0;
}