#include <bits/stdc++.h>
using namespace std;

struct Prod
{
    string l;
    vector<string> r;
};
struct Act
{
    string t;
    int st;
    int pr;
};

map<pair<int, string>, Act> ACTION;
map<pair<int, string>, int> GOTO;
vector<Prod> g;

void initG()
{
    g.push_back({"Q'", {"Q"}});
    g.push_back({"Q", {"Q", "A", "B"}});
    g.push_back({"Q", {"A", "b"}});
    g.push_back({"A", {"A", "b"}});
    g.push_back({"A", {"B"}});
    g.push_back({"B", {"a"}});
    g.push_back({"B", {"b"}});
}

void addShift(int s, string x, int to) { ACTION[{s, x}] = {"shift", to, -1}; }
void addReduce(int s, string x, int p) { ACTION[{s, x}] = {"reduce", -1, p}; }
void addAccept(int s) { ACTION[{s, "$"}] = {"accept", -1, -1}; }
void addGoto(int s, string x, int to) { GOTO[{s, x}] = to; }

void initT()
{
    addShift(0, "a", 5);
    addShift(0, "b", 3);
    addGoto(0, "A", 4);
    addGoto(0, "B", 1);
    addGoto(0, "Q", 2);

    addReduce(1, "b", 4);

    addAccept(2);
    addShift(2, "a", 8);
    addShift(2, "b", 9);
    addGoto(2, "A", 6);
    addGoto(2, "B", 7);

    addReduce(3, "b", 6);

    addShift(4, "b", 10);

    addReduce(5, "b", 5);

    addShift(6, "a", 13);
    addShift(6, "b", 12);
    addGoto(6, "B", 11);

    addReduce(7, "a", 4);
    addReduce(7, "b", 4);

    addReduce(8, "a", 5);
    addReduce(8, "b", 5);

    addReduce(9, "a", 6);
    addReduce(9, "b", 6);

    addReduce(10, "$", 2);
    addReduce(10, "a", 2);
    addReduce(10, "b", 3);

    addReduce(11, "$", 1);
    addReduce(11, "a", 1);
    addReduce(11, "b", 1);

    addReduce(12, "$", 6);
    addReduce(12, "a", 3);
    addReduce(12, "b", 6);

    addReduce(13, "$", 5);
    addReduce(13, "a", 5);
    addReduce(13, "b", 5);
}

void parse(const vector<string> &toks)
{
    vector<int> st = {0};
    vector<string> sy;
    int i = 0;
    while (true)
    {
        int cs = st.back();
        string a = toks[i];
        auto key = make_pair(cs, a);
        if (ACTION.find(key) == ACTION.end())
        {
            cout << "Error: no action for state " << cs << " on symbol " << a << "\n";
            return;
        }
        Act act = ACTION[key];
        if (act.t == "shift")
        {
            cout << "Shift " << a << " -> state " << act.st << "\n";
            sy.push_back(a);
            st.push_back(act.st);
            ++i;
        }
        else if (act.t == "reduce")
        {
            Prod p = g[act.pr];
            cout << "Reduce " << p.l << " -> ";
            for (auto &x : p.r)
                cout << x << " ";
            cout << "\n";
            for (size_t k = 0; k < p.r.size(); ++k)
            {
                sy.pop_back();
                st.pop_back();
            }
            sy.push_back(p.l);
            auto gotoKey = make_pair(st.back(), p.l);
            if (GOTO.find(gotoKey) == GOTO.end())
            {
                cout << "Error: no goto for state " << st.back() << " on " << p.l << "\n";
                return;
            }
            int ns = GOTO[gotoKey];
            st.push_back(ns);
            cout << "Goto state " << ns << "\n";
        }
        else if (act.t == "accept")
        {
            cout << "Input accepted\n";
            return;
        }
        else
        {
            cout << "Internal error\n";
            return;
        }
    }
}

int main()
{
    initG();
    initT();

    cout << "\n\n23BCT0266\n\nEnter input string : ";
    string s;
    cin >> s;

    vector<string> toks;
    for (char c : s)
    {
        if (c == 'a' || c == 'b')
            toks.push_back(string(1, c));
        else
        {
            cout << "Invalid char: " << c << "\n";
            return 0;
        }
    }
    toks.push_back("$");

    parse(toks);
    return 0;
}
