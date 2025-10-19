#include <iostream>
using namespace std;

class Stack {
public:
    int topIndex;
    int maxSize;
    char arr[10];

    Stack() {
        topIndex = -1;
        maxSize = 10;
    }

    void push(char val) {
        if (topIndex >= maxSize - 1) {
            cout << "Stack overflow!" << endl;
            return;
        }
        arr[++topIndex] = val;
    }

    char pop() {
        if (topIndex == -1) {
            cout << "Stack underflow!" << endl;
            return '\0';
        }
        return arr[topIndex--];
    }

    char top() {
        if (topIndex == -1) {
            return '\0';
        }
        return arr[topIndex];
    }

    bool isEmpty() {
        if (topIndex == -1) {
            return false;
        } else {
            return true;
        }
    }

    void display() {
        if (topIndex == -1) {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Stack contents (top to bottom): ";
        for (int i = topIndex; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int priority_check(char a) {
    if (a == '^') {
        return 3;
    } else if (a == '*' || a == '/') {
        return 2;
    } else {
        return 1;
    }
}

void infix_to_postfix(char equation[10]) {
    int i = 0;
    Stack ss;
    char ans[10];
    int j = 0;

    while (i < 10 && equation[i] != '\0') {
        if ((equation[i] >= '0' && equation[i] <= '9') ||
            (equation[i] >= 'A' && equation[i] <= 'Z') ||
            (equation[i] >= 'a' && equation[i] <= 'z')) 
        {
            ans[j++] = equation[i];
        } 
        else if (equation[i] == '(') {
            ss.push(equation[i]);
        } 
        else if (equation[i] == ')') {
            while (ss.isEmpty()&& ss.top()!='(') {
                ans[j++] = ss.top();
                ss.pop();
            }
            ss.pop();
        } 
        else {
            while (ss.isEmpty() || priority_check(equation[i]) <= priority_check(ss.top())) {
                ans[j++] = ss.top();
                ss.pop();
            }
            ss.push(equation[i]);
        }
        i++;
    }

    while (ss.isEmpty()) {
        ans[j++] = ss.top();
        ss.pop();
    }

    ans[j] = '\0';
    cout << "Postfix Expression: " << ans << endl;
}

void reverseString(char str[]) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

void infix_to_prefix(char equation[10]) {
    int len = strlen(equation);

    reverseString(equation);

    for (int i = 0; i < len; i++) {
        if (equation[i] == '(')
            equation[i] = ')';
        else if (equation[i] == ')')
            equation[i] = '(';
    }

    Stack ss;
    char ans[10];
    int j = 0;

    for (int i = 0; i < len; i++) {
        if ((equation[i] >= '0' && equation[i] <= '9') ||
            (equation[i] >= 'A' && equation[i] <= 'Z') ||
            (equation[i] >= 'a' && equation[i] <= 'z')) 
        {
            ans[j++] = equation[i];
        } 
        else if (equation[i] == '(') {
            ss.push(equation[i]);
        } 
        else if (equation[i] == ')') {
            while (ss.isEmpty() && ss.top() != '(') {
                ans[j++] = ss.top();
                ss.pop();
            }
            if (ss.top() == '(') {
                ss.pop();
            }
        } 
        else {
            while (ss.isEmpty() && priority_check(equation[i]) < priority_check(ss.top())) {
                ans[j++] = ss.top();
                ss.pop();
            }
            ss.push(equation[i]);
        }
    }

    while (ss.isEmpty()) {
        ans[j++] = ss.top();
        ss.pop();
    }

    ans[j] = '\0';

    reverseString(ans);

    cout << "Prefix Expression: " << ans << endl;
}


int main() {
    char exp[10];
    cout << "Enter infix expression (max 10 chars): ";
    cin >> exp;
    infix_to_postfix(exp);
    return 0;
}
