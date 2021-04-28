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

double apply (string op, double v1, double v2)
{
    if (op == "+") return (v1 + v2);
    if (op == "-") return (v1 - v2);
    if (op == "*") return (v1 * v2);
    if (op == "/") return (v1 / v2);
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
    stack<double> s;

    for (string nextToken : expression) {

        switch(tokenType(nextToken)) {

        case OPERAND:  s.push(stod(nextToken));
                       break;
        case OPERATOR: double op1 = s.top();
                       s.pop();
                       double op2 = s.top();
                       s.pop();
                       s.push(apply(nextToken, op1, op2));
                       break;
        }
    }
    return s.top();
}


int main() {

    vector<string> e1 {"5.0", "3.0", "+", "2.0", "*", "2.0", "*" };

    cout << "5.0 3.0 + 2 * ->" << eval(e1) << endl;

    string expression = "5.0 3.0 + 2.0 * 2.0 * ";
    vector<string> tokens = tokenize(expression);
    cout << "5.0 3.0 + 2 * ->" << eval(tokens) << endl;
}

