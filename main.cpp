#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

int GetNumberOfDigits(int i) {
    int count;
    for (count = 0; i > 0; count++) {
        i = i / 10;
    }
    return count;
}

bool HasRecurringDigits(string str, string& recurringDigits) {
    set<char> seenDigits;
    set<char> recurringSet;

    for (char digit : str) {
        if (seenDigits.count(digit) > 0) {
            recurringSet.insert(digit);
        }
        seenDigits.insert(digit);
    }
    // no recurring digits
    if (recurringSet.empty()) {
        recurringDigits = "None";
        return false;
    } else {
        recurringDigits = "";
        for (char digit : recurringSet) {
            recurringDigits += digit;
            recurringDigits += ",";
        }
        recurringDigits.pop_back(); // Remove the last comma
        return true;
    }
}

int main() {
    int numberSquared, numberCubed;
    string str1, str2, str3;
    string recurringDigits;
    // can't go above 100 because the numbers will be 10+
    for (int n = 0; n <= 100; n++) {
        numberSquared = n * n;
        numberCubed = n * n * n;
        if (GetNumberOfDigits(numberCubed) + GetNumberOfDigits(numberSquared) == 10) {
            str1 = to_string(numberSquared);
            str2 = to_string(numberCubed);
            str3 = str1 + str2;

            // Sort the string
            sort(str3.begin(), str3.end());

            if (HasRecurringDigits(str3, recurringDigits)) {
                cout << "Conflicting digits found [" << n << "]: Recurring digits: " << recurringDigits << " | Digits: " << str3 << " (Squared+Cubed): " << numberSquared << " + " << numberCubed << endl;
            } else {
                cout << "Non-conflicting number [" << n << "]: Recurring digits: "<< recurringDigits << " | Digits: " << str3 << " (Squared+Cubed): " << numberSquared << " + " << numberCubed << endl;;
            }
        } else {
            // cant check if all digits are there if both numbers are less than 10
            cout << "Insufficient numbers" << endl;
        }
    }

    return 0;
}
