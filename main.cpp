#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <cctype>

#include "ArrayStack.h"

using namespace std;

// Token

struct Token{
    string value;   // number, operator, or parenthesis
    ArrayStack<Token> tokens;
};

// Tokenizer

void tokenize(const string& line) {
    Token token;
    for (int x = 1; x < line.length(); x++) {
        token.value = line.substr(x - 1,x);
        if (token.value != " ") {
            token.tokens.push(token);
        }
    }
}

// Helpers

bool isOperator(const string& s) {
    return s == "+" || s == "-" || s == "*" || s == "/";
}

bool isParenthesis(const string& s){
    return s == "(" || s == ")";
}

int precedence(const string& op) {
    // TODO
    return 0;
}

// Detection

bool isValidPostfix(const vector<Token>& tokens) {
    // TODO
    return false;
}

bool isValidInfix(const ArrayStack<Token>& tokens) {
    for(int x = 1; x < tokens.size(); x++){
        if(!isOperator(tokens.top().value)){
            tokens.pop();
            if(!isOperator(tokens.top().value)){
                return false;
            }
        }
    }
    return true;
}

// Conversion

void infixToPostfix(const vector<Token>& tokens) {
    ArrayStack<Token> output;
    ArrayStack<Token> operators;
    Token token;
    for (int x = 0; x < tokens.size(); x++) {
        if (isOperator(token.tokens.top().value)) {
            operators.push(token.tokens.top());
        }
        else {
            output.push(tokens[x]);
        }
    }
    for (int a = 0; a < operators.size(); a++) {
        output.push(operators.top());
    }
}

// Evaluation

double evalPostfix(const vector<Token>& tokens) {
    ArrayStack<double> stack;
    // TODO
    return 0.0;
}

// Main

int main() {
    string line;
    getline(cin, line);

    vector<Token> tokens = tokenize(line);

    if (isValidPostfix(tokens)) {
        cout << "FORMAT: POSTFIX\n";
        cout << "RESULT: " << evalPostfix(tokens) << "\n";
    }
    else if (isValidInfix(tokens)) {
        vector<Token> postfix = infixToPostfix(tokens);
        cout << "FORMAT: INFIX\n";
        cout << "POSTFIX: ";
        for (const auto& t : postfix) {
            cout << t.value << " ";
        }
        cout << "\n";
        cout << "RESULT: " << evalPostfix(postfix) << "\n";
    }
    else {
        cout << "FORMAT: NEITHER\n";
        cout << "ERROR: invalid expression\n";
    }

    return 0;
}