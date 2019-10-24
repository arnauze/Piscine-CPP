#include "Fixed.class.hpp"
#include "Stack.class.hpp"

void            calculate_until_close(Stack *operators, Stack *operands) {
    int res;
    char c;
    while ((c = operators->pop().front()) != '(') {
        int a = std::stoi(operands->pop());
        int b = std::stoi(operands->pop());
        if (c == '+') res = a + b;
        else if (c == '-') res = b - a;
        else if (c == '*') res = a * b;
        else if (c == '/') res = b / a;
        operands->add(std::to_string(res));
    }
}

std::string            calculate(Stack *operators, Stack *operands) {

    int res = 0;
    char c = operators->pop().front();

    if (c == ')') {
        calculate_until_close(operators, operands);
    } else {
        int a = std::stoi(operands->pop());
        int b = std::stoi(operands->pop());
        if (c == '+') res = a + b;
        else if (c == '-') res = b - a;
        else if (c == '*') res = a * b;
        else if (c == '/') res = b / a;
    }

    std::string str = std::to_string(res);
    return str;
}

int             precedence(char c) {
    if (c == '+' || c == '-') return 1;
    else if (c == '/' || c == '*') return 2;
    else if (c == ')') return 3;
    else return -1;
}

bool            is_operator(char c) {
    if ( c == '+' || c == '-' ||
    c== '*' || c == '/' ||
    c == '(' || c == ')' )
        return true;
    return false;
}

void            react_to_operator(char c, Stack *operators, Stack *operands) {
    if (c == ')') {
        calculate_until_close(operators, operands);
    } else if (operators->size() == 0 || (operators->size() > 0 && (precedence(operators->top().front()) < precedence(c)))) {
        // I just add the operators to the operator stack
        operators->add(std::string(1, c));
    } else {
        // I pop one operator and two operands, calculate, and then push the result back to the operand stack
        operands->add(calculate(operators, operands));
        operators->add(std::string(1, c));
    }
}

int            react_to_non_operator(char *str, int index, Stack *operands) {
    int         i = index;
    int         j = -1;
    char        newstr[100];

    if (isdigit(str[i])) {
        while (isdigit(str[i])) 
            newstr[++j] = str[i++];
        newstr[++j] = '\0';
    } else j += 2;

    operands->add(std::string(newstr));
    return j;
}

int             main( int argc, char **argv ) {
    int         i = -1;
    Stack       operators;
    Stack       operands;

    if (argc == 2) {

        while (argv[1][++i]) {
            if (argv[1][i] == '(') operators.add(std::string(1, argv[1][i]));
            else if (is_operator(argv[1][i])) react_to_operator(argv[1][i], &operators, &operands);
            else if (argv[1][i] == ' ') continue ;
            else i += react_to_non_operator(argv[1], i, &operands) - 1;
        }
        while (!operators.isEmpty()) {
            operands.add(calculate(&operators, &operands));
        }
        std::cout << operands.top() << std::endl;

    } else
        std::cout << "usage: ./eval_expr <expression>" << std::endl;
    return 0;
}