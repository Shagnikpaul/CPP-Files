#include <bits/stdc++.h>
using namespace std;

struct Prod
{
    string left;
    vector<string> right;
};

struct Action
{
    string type; // "shift", "reduce", "accept"
    int state;   // next state (for shift)
    int prod;    // production number (for reduce)
};

map<pair<int, string>, Action> ACTION;
map<pair<int, string>, int> GOTO;
vector<Prod> grammar;

void initGrammar()
{
    grammar.push_back({"S'", {"E"}});          // 0
    grammar.push_back({"E", {"E", "*", "T"}}); // 1
    grammar.push_back({"E", {"T"}});           // 2
    grammar.push_back({"T", {"T", "+", "F"}}); // 3
    grammar.push_back({"T", {"F"}});           // 4
    grammar.push_back({"F", {"(", "E", ")"}}); // 5
    grammar.push_back({"F", {"id"}});          // 6
}

void addShift(int s, string sym, int to) { ACTION[{s, sym}] = {"shift", to, -1}; }
void addReduce(int s, string sym, int p) { ACTION[{s, sym}] = {"reduce", -1, p}; }
void addAccept(int s) { ACTION[{s, "$"}] = {"accept", -1, -1}; }
void addGoto(int s, string sym, int to) { GOTO[{s, sym}] = to; }

void initTable()
{
    // --- ACTION table (SLR) ---
    addShift(0, "id", 5);
    addShift(0, "(", 4);

    addShift(1, "*", 6);
    addAccept(1);

    // E → T (prod 2), FOLLOW(E) = { ), $ }
    addReduce(2, ")", 2);
    addReduce(2, "$", 2);
    addShift(2, "+", 7); // shift on '+'
    addShift(2, "*", 6); // ✅ shift on '*', no reduce here

    // T → F (prod 4), FOLLOW(T) = { *, ), $ }
    addReduce(3, "+", 4);
    addReduce(3, "*", 4);
    addReduce(3, ")", 4);
    addReduce(3, "$", 4);

    addShift(4, "id", 5);
    addShift(4, "(", 4);

    // F → id (prod 6), FOLLOW(F) = { +, *, ), $ }
    addReduce(5, "+", 6);
    addReduce(5, "*", 6);
    addReduce(5, ")", 6);
    addReduce(5, "$", 6);

    addShift(6, "id", 5);
    addShift(6, "(", 4);

    addShift(7, "id", 5);
    addShift(7, "(", 4);

    addShift(8, "*", 6);
    addShift(8, ")", 11);

    // E → E * T (prod 1), FOLLOW(E) = { ), $ }
    addReduce(9, ")", 1);
    addReduce(9, "$", 1);

    // T → T + F (prod 3), FOLLOW(T) = { *, ), $ }
    addReduce(10, "*", 3);
    addReduce(10, ")", 3);
    addReduce(10, "$", 3);

    // F → (E) (prod 5), FOLLOW(F) = { +, *, ), $ }
    addReduce(11, "+", 5);
    addReduce(11, "*", 5);
    addReduce(11, ")", 5);
    addReduce(11, "$", 5);

    // --- GOTO table ---
    addGoto(0, "E", 1);
    addGoto(0, "T", 2);
    addGoto(0, "F", 3);

    addGoto(4, "E", 8);
    addGoto(4, "T", 2);
    addGoto(4, "F", 3);

    addGoto(6, "T", 9);
    addGoto(6, "F", 3);

    addGoto(7, "F", 10);
}

void parse(vector<string> tokens)
{
    vector<int> states = {0};
    vector<string> symbols;
    int i = 0;

    while (true)
    {
        int st = states.back();
        string a = tokens[i];
        auto key = make_pair(st, a);

        if (ACTION.find(key) == ACTION.end())
        {
            cout << "Error at state " << st << " on symbol " << a << "\n";
            return;
        }

        Action act = ACTION[key];
        if (act.type == "shift")
        {
            cout << "Shift " << a << " -> state " << act.state << "\n";
            symbols.push_back(a);
            states.push_back(act.state);
            i++;
        }
        else if (act.type == "reduce")
        {
            Prod p = grammar[act.prod];
            cout << "Reduce by " << p.left << " -> ";
            for (auto &x : p.right)
                cout << x << " ";
            cout << "\n";

            for (int k = 0; k < (int)p.right.size(); k++)
            {
                symbols.pop_back();
                states.pop_back();
            }

            symbols.push_back(p.left);
            int newSt = GOTO[{states.back(), p.left}];
            states.push_back(newSt);
        }
        else if (act.type == "accept")
        {
            cout << "String is Accepted\n";
            return;
        }
    }
}

int main()
{
    initGrammar();
    initTable();

    vector<string> tokens = {"(", "id", "*", "id", ")", "+", "id", "*", "(", "id", "+", "id", ")", "$"};
    parse(tokens);
}
