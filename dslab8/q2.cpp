#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

struct Transaction {
    int id;
    double amount;
    string description;
    int flag;
    Transaction* next;
};

class TransactionStack {
    Transaction* top;
    int currentID;
public:
    TransactionStack() {
        top = nullptr;
        currentID = 0;
    }

    string truncateDesc(string desc) {
        if (desc.length() > 20)
            return desc.substr(0, 17) + "...";
        return desc;
    }

    double applyDiscount(double amount) {
        if (amount >= 1500) return amount * 0.7;
        else if (amount >= 1000) return amount * 0.85;
        else if (amount >= 500) return amount * 0.95;
        else return amount;
    }

    void push(double amt, string desc) {
        Transaction* t = new Transaction();
        t->id = ++currentID;
        t->description = truncateDesc(desc);
        if (amt >= 0) {
            t->flag = 1;
            t->amount = applyDiscount(amt);
        } else {
            t->flag = 0;
            t->amount = amt;
        }
        t->next = top;
        top = t;

        cout << t->id << ". " << t->description << " (" << amt << ")";
        if (t->flag == 1) {
            double discount = amt - t->amount;
            if (discount > 0)
                cout << " → Discount " << (discount / amt) * 100 << "% → Final: " << t->amount;
        }
        cout << endl;
    }

    Transaction* pop() {
        if (top == nullptr) {
            cout << "Stack Underflow! No transactions to pop.\n";
            return nullptr;
        }
        Transaction* temp = top;
        top = top->next;

        temp->amount *= -1;
        temp->description += " [REVERSED]";
        temp->flag = 2;

        return temp;
    }

    void display() {
        if (top == nullptr) {
            cout << "No transactions in stack.\n";
            return;
        }

        cout << "\nFinal Stack Output:\n";
        cout << "Top →\n";
        Transaction* temp = top;
        while (temp != nullptr) {
            cout << "[id=" << temp->id
                 << ", amt=" << temp->amount
                 << ", desc=\"" << temp->description
                 << "\", flag=" << temp->flag << "]\n";
            temp = temp->next;
        }
        cout << "Bottom → NULL\n";
    }
};

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

double applyOp(double a, double b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
    }
    return 0;
}

string infixToPostfix(string exp) {
    string output = "";
    char stack[100];
    int top = -1;

    for (int i = 0; i < exp.length(); i++) {
        char c = exp[i];
        if (c == ' ') continue;
        if (isdigit(c) || c == '.') {
            output += c;
        } else if (c == '(') {
            stack[++top] = c;
        } else if (c == ')') {
            output += ' ';
            while (top >= 0 && stack[top] != '(') {
                output += stack[top--];
                output += ' ';
            }
            top--;
        } else {
            output += ' ';
            while (top >= 0 && precedence(stack[top]) >= precedence(c)) {
                output += stack[top--];
                output += ' ';
            }
            stack[++top] = c;
        }
    }

    output += ' ';
    while (top >= 0) {
        output += stack[top--];
        output += ' ';
    }

    return output;
}

double evaluatePostfix(string postfix) {
    double stack[100];
    int top = -1;
    string num = "";

    for (int i = 0; i < postfix.length(); i++) {
        char c = postfix[i];
        if (isdigit(c) || c == '.') {
            num += c;
        } else if (c == ' ' && !num.empty()) {
            stack[++top] = stod(num);
            num = "";
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            double b = stack[top--];
            double a = stack[top--];
            stack[++top] = applyOp(a, b, c);
        }
    }
    return stack[top];
}

int main() {
    srand(time(0));
    TransactionStack store;

    Transaction transactions[7] = {
        {0, 1200, "Sale: Blue Jacket", 1},
        {0, 450, "Sale: Cotton Socks", 1},
        {0, -300, "Refund: Defective Shirt", 0},
        {0, 1700, "Sale: Leather Jacket", 1},
        {0, 600, "Sale: Woolen Scarf", 1},
        {0, -150, "Refund: Size Issue", 0},
        {0, 2000, "Sale: Formal Suit", 1}
    };

    cout << "Pushed Transactions:\n";
    for (int i = 0; i < 4; i++) {
        int idx = rand() % 7;
        store.push(transactions[idx].amount, transactions[idx].description);
    }

    cout << "\nIntermediate Expression Calculation:\n";
    string infix = "(100 + 20) * 0.9 - 5";
    cout << "Infix: " << infix << endl;
    string postfix = infixToPostfix(infix);
    cout << "Postfix: " << postfix << endl;
    double result = evaluatePostfix(postfix);
    cout << "Evaluated Result: " << result << endl;

    cout << "\nPop (remove) one transaction:\n";
    Transaction* reversed = store.pop();
    if (reversed != nullptr) {
        cout << "Popped Transaction: " << reversed->description << endl;
        cout << "Amount changed to " << reversed->amount << endl;
        cout << "Flag updated to " << reversed->flag << endl;
    }

    store.display();

}
