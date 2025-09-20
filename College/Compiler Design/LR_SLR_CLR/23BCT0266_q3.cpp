#include <bits/stdc++.h>
using namespace std;

struct Act
{
    char t;  // s = shift, r = reduce, a = accept, e = error
    int num; // state or production
};

struct Prod
{
    char l;
    string r;
};

vector<Prod> prods = {
    {'S', "E"},   // 0
    {'E', "E+T"}, // 1
    {'E', "T"},   // 2
    {'T', "T*F"}, // 3
    {'T', "F"},   // 4
    {'F', "(E)"}, // 5
    {'F', "id"}   // 6
};

map<pair<int, string>, Act> ACTION;
map<pair<int, char>, int> GOTO;

void initTable()
{
    ACTION[{0, "id"}] = {'s', 5};
    ACTION[{0, "("}] = {'s', 4};
    GOTO[{0, 'E'}] = 1;
    GOTO[{0, 'T'}] = 2;
    GOTO[{0, 'F'}] = 3;

    ACTION[{1, "$"}] = {'a', 0};
    ACTION[{1, "+"}] = {'s', 6};

    ACTION[{2, "+"}] = {'r', 2};
    ACTION[{2, "*"}] = {'s', 7};
    ACTION[{2, ")"}] = {'r', 2};
    ACTION[{2, "$"}] = {'r', 2};

    ACTION[{3, "+"}] = {'r', 4};
    ACTION[{3, "*"}] = {'r', 4};
    ACTION[{3, ")"}] = {'r', 4};
    ACTION[{3, "$"}] = {'r', 4};

    ACTION[{4, "id"}] = {'s', 5};
    ACTION[{4, "("}] = {'s', 4};
    GOTO[{4, 'E'}] = 8;
    GOTO[{4, 'T'}] = 2;
    GOTO[{4, 'F'}] = 3;

    ACTION[{5, "+"}] = {'r', 6};
    ACTION[{5, "*"}] = {'r', 6};
    ACTION[{5, ")"}] = {'r', 6};
    ACTION[{5, "$"}] = {'r', 6};

    ACTION[{6, "id"}] = {'s', 5};
    ACTION[{6, "("}] = {'s', 4};
    GOTO[{6, 'T'}] = 9;
    GOTO[{6, 'F'}] = 3;

    ACTION[{7, "id"}] = {'s', 5};
    ACTION[{7, "("}] = {'s', 4};
    GOTO[{7, 'F'}] = 10;

    ACTION[{8, "+"}] = {'s', 6};
    ACTION[{8, ")"}] = {'s', 11};

    ACTION[{9, "+"}] = {'r', 1};
    ACTION[{9, "*"}] = {'s', 7};
    ACTION[{9, ")"}] = {'r', 1};
    ACTION[{9, "$"}] = {'r', 1};

    ACTION[{10, "+"}] = {'r', 3};
    ACTION[{10, "*"}] = {'r', 3};
    ACTION[{10, ")"}] = {'r', 3};
    ACTION[{10, "$"}] = {'r', 3};

    ACTION[{11, "+"}] = {'r', 5};
    ACTION[{11, "*"}] = {'r', 5};
    ACTION[{11, ")"}] = {'r', 5};
    ACTION[{11, "$"}] = {'r', 5};
}

int main()
{
    cout << "\n23BCT0266\n\n";
    initTable();

    cout << "Enter expression: ";
    string s;
    getline(cin, s);

    vector<string> in;
    for (size_t i = 0; i < s.size();)
    {
        if (isspace(s[i]))
        {
            i++;
            continue;
        }
        if (s[i] == 'i' && i + 1 < s.size() && s[i + 1] == 'd')
        {
            in.push_back("id");
            i += 2;
        }
        else
        {
            in.push_back(string(1, s[i]));
            i++;
        }
    }
    in.push_back("$");

    stack<int> st;
    stack<string> sy;
    st.push(0);

    int ip = 0;
    cout << left << setw(20) << "States" << setw(30) << "Input" << "Action\n";
    cout << "-------------------------------------------------------------\n";

    while (true)
    {
        int cs = st.top();
        string tok = in[ip];
        Act act = ACTION.count({cs, tok}) ? ACTION[{cs, tok}] : Act{'e', -1};

        stack<int> tmp = st;
        string sc;
        while (!tmp.empty())
        {
            sc = to_string(tmp.top()) + " " + sc;
            tmp.pop();
        }
        string rem;
        for (int j = ip; j < in.size(); j++)
            rem += in[j] + " ";
        cout << setw(20) << sc << setw(30) << rem;

        if (act.t == 's')
        {
            cout << "Shift -> state " << act.num << "\n";
            sy.push(tok);
            st.push(act.num);
            ip++;
        }
        else if (act.t == 'r')
        {
            Prod p = prods[act.num];
            cout << "Reduce by " << p.l << " -> " << p.r << "\n";
            if (p.r != "#")
            {
                for (int k = 0; k < p.r.size(); k++)
                {
                    sy.pop();
                    st.pop();
                }
            }
            sy.push(string(1, p.l));
            int ns = GOTO[{st.top(), p.l}];
            st.push(ns);
        }
        else if (act.t == 'a')
        {
            cout << "ACCEPTED\n";
            break;
        }
        else
        {
            cout << "ERROR at token " << tok << "\n";
            break;
        }
    }
}
