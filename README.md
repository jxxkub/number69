# The beauty of number 69

inital idea was inspired by [MindYourDecisions](https://www.youtube.com/watch?v=H4YjOD65Ur0)


## Explanation

The overall idea of the video states that
- That the only number between 0 and 100 that uses all the digits from 0 to 9 is 69.

I wanted to check if thats true, so i wrote a program in c++ that checks
- all numbers(n) from 0 to 100.
- Checks if squared number(n) plus the cubed number(n) has 10 digits.
- Checks whether or not the 10 digit number has any recurring digits.
- Outputs numbers from 0 to 100, labelling numbers that have less than or more than 10 digits 'insufficient numbers'
- numbers that have 10 digits, but have recurring digits are formatted:
    - Conflicting digits found [N]: Recurring digits: digit1,digit2 | Digits: 1234667889 (Squared+Cubed): n^2 + n^3
- numbers (in this case number) that has 10 digits, and no recurring digits is formatted:
    - Non-conflicting number [N]: Recurring digits: None | Digits: 0123456789 (Squared+Cubed): n^2 + n^3

![Image of some of the results from the code](/image/Untitled.png)
