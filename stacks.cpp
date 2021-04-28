#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <stack>

using namespace std;

enum TokenType {
    OPERATOR,
    OPERAND,
};

set<string> VALID_OPS { "+", "-", "*", "/" };

TokenType tokenType(string s) {
    if ((VALID_OPS.count(s.substr(0,1)) != 0)) {
        return OPERATOR;
    } else {
        return OPERAND;
    }
}

double apply (string operand, double v1, double v2)
{
    if (operand == "+") return (v1 + v2);
    if (operand == "-") return (v1 - v2);
    if (operand == "*") return (v1 * v2);
    if (operand == "/") return (v1 / v2);
    return 0.0;  // Just to avoid no-return warning
}


vector<string> tokenize(string expression)
{
    vector<string> result;
    int tokenStart = 0;
    int i=0;
    while (i<expression.size()) {
        if (expression.substr(i,1) == " ") {
            result.push_back(expression.substr(tokenStart,i-tokenStart));
            tokenStart = i+1;
        }
        i++;
    }
    return result;
}

double eval(vector<string> expression)
{

    

}


int main() {

    vector<string> e1 {"5.0", "3.0", "+", "2.0", "*", "2.0", "*" };

    cout << "5.0 3.0 + 2 * ->" << eval(e1) << endl;

    string expression = "5.0 3.0 + 2.0 * 2.0 * ";
    vector<string> tokens = tokenize(expression);
    cout << "5.0 3.0 + 2 * ->" << eval(tokens) << endl;
}

