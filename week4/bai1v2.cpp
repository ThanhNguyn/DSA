
#include <bits/stdc++.h>
using namespace std;

int n, T;
vector<int> A;
vector<int> selected;

void backtrack(int index, int sum)
{
    if (index == n)
    {
        if (sum == T)
        {
            for (int i = 0; i < selected.size(); i++)
            {
                if (i > 0)
                    cout << " + ";
                cout << selected[i];
            }

            cout << " = " << T << '\n';
        }

        return;
    }

    backtrack(index + 1, sum);

    selected.push_back(A[index]);

    backtrack(index + 1, sum + A[index]);

    selected.pop_back();
}

int main()
{
    cin >> n;

    A.resize(n);

    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    cin >> T;

    backtrack(0, 0);

    return 0;
}
