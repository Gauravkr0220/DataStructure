#include <bits/stdc++.h>

using namespace std;



#define F first

#define S second



vector<int> ranksz;

vector<pair<int, int>> par;

int n, q, setsz;



pair<int, int> finda(int x) {

    if (par[x].F == x) {

        return par[x];

    }

    int parent = par[x].F;

    pair<int, int> temp = finda(parent);

    return par[x] = {temp.F, temp.S + par[x].S};

}



void merge(int x, int y, int z) {

    auto rootX = finda(x);

    auto rootY = finda(y);



    if (rootX.F == rootY.F) {

        return;

    }



    if (ranksz[rootX.F] <= ranksz[rootY.F]) {

        ranksz[rootY.F] += ranksz[rootX.F];

        par[rootX.F] = {rootY.F,par[y].S - par[x].S-z};

    }

    else {

        ranksz[rootX.F] += ranksz[rootY.F];

        par[rootY.F] = {rootX.F, par[x].S + z - par[y].S};

    }



    setsz--;

}



void solve() {

    cin >> n >> q;

    setsz = n;



    par.resize(n);

    ranksz.assign(n, 1);



    for (int i = 0; i < n; i++) {

        par[i] = {i, 0};

    }



    while (q--) {

        int ch;

        cin >> ch;



        if (ch == 0) {

            int x, y, z;

            cin >> x >> y >> z;

            merge(x, y, z);

        }

        else {

            int x, y;

            cin >> x >> y;



            auto rootX = finda(x);

            auto rootY = finda(y);



            if (rootX.F != rootY.F) {

                cout << "?" << endl;

            }

            else {

                cout << par[y].S - par[x].S << endl;

            }

        }

    }

}



int main() {

    ios::sync_with_stdio(false);

    cin.tie(nullptr);

   

    solve();

   

    return 0;

}0