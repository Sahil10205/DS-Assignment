#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>
#include <limits>

bool isVowel(char c) {
    c = std::tolower(c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int main() {
    using namespace std;

    int choice;

    while (true) {
        cout << "\n--- String Programs Menu ---\n";
        cout << "1. Concatenate one string to another\n";
        cout << "2. Reverse a string\n";
        cout << "3. Delete all vowels from a string\n";
        cout << "4. Sort strings in alphabetical order\n";
        cout << "5. Convert string to lowercase\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            cout << "Invalid input. Please enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
            case 1: {
                string str1, str2;
                cout << "Enter first string: ";
                getline(cin, str1);
                cout << "Enter second string: ";
                getline(cin, str2);
                
                str1 += str2;
                cout << "Concatenated string: " << str1 << endl;
                break;
            }
            case 2: {
                string str;
                cout << "Enter a string: ";
                getline(cin, str);
                
                reverse(str.begin(), str.end());
                cout << "Reversed string: " << str << endl;
                break;
            }
            case 3: {
                string str;
                cout << "Enter a string: ";
                getline(cin, str);

                str.erase(std::remove_if(str.begin(), str.end(), isVowel), str.end());
                
                cout << "String without vowels: " << str << endl;
                break;
            }
            case 4: {
                int n;
                cout << "Enter number of strings: ";
                
                if (!(cin >> n) || n <= 0) {
                    cout << "Invalid number of strings.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                }
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                vector<string> arr(n);
                cout << "Enter " << n << " strings:\n";
                for (int i = 0; i < n; i++) {
                    cout << "String " << i + 1 << ": ";
                    getline(cin, arr[i]);
                }
                
                sort(arr.begin(), arr.end());
                
                cout << "Strings in alphabetical order:\n";
                for (const string &s : arr) {
                    cout << s << endl;
                }
                break;
            }
            case 5: {
                string str;
                cout << "Enter the string: ";
                getline(cin, str);

                transform(str.begin(), str.end(), str.begin(), 
                          [](unsigned char c){ return std::tolower(c); });
                
                cout << "Lowercase string: " << str << endl;
                break;
            }
            case 6: {
                cout << "Exiting program. Goodbye!\n";
                return 0;
            }
            default: {
                cout << "Invalid choice. Please enter a number between 1 and 6.\n";
            }
        }
    }
    return 0;
}