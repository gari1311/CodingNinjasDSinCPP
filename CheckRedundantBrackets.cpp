/*
Given a string mathematical expression, return true if redundant brackets are present in the expression. Brackets are redundant if there is nothing inside the bracket or more than one pair of brackets are present.
Assume the given string expression is balanced and contains only one type of bracket i.e. ().
Note: You will not get partial score for this problem. You will get marks only if all test cases are passed.
Input Format :
String s (Expression)
Output Format :
true or false
Sample Input 1:
((a + b)) 
Sample Output 1:
true
Sample Input 2:
(a+b) 
Sample Output 2:
false
*/

#include <iostream>
using namespace std;
#include "solution.h"

int main() {
    char input[1000000];
    cin.getline(input, 1000000);

    if(checkRedundantBrackets(input)) {
	    cout << "true" << endl;
    }
    else {
	    cout << "false" << endl;
    }

}
#include <stack>
using namespace std;
bool checkRedundantBrackets(char *input) {
	// Write your code here
if(input==nullptr) return false;
    stack<char> s;
    char top;
    while(*input!='\0')
    {
        switch(*input)
        {
            case '(':
                s.push(*input);
                break;
            case ')':
                if(s.empty() || s.top()!='o') return true;
                s.pop(); // pop 'o'
                if(s.empty() || s.top()!='(') return true;
                s.pop(); // pop '('
                break;
            case '+': case '-': case '/': case '*':
                if(s.empty() || s.top()!='o') s.push('o');
                break;
        }
        input++;
    }
    //if(s.empty()) return true;
    return false;
}
