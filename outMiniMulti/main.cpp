#include <iostream>
#include <fstream>

using namespace std;

ifstream in("lab.txt");
int n,m,L[11][11],ip,jp,nr;
int Dx[] = {0, -1, 0, 1, 0};
int Dy[] = {0, 0, 1, 0, -1};
int mini;

void init()
{
    in >> n >> m >> ip >> jp;
    mini = n * m;

    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= m; j++){
        in >> L[i][j];
        L[i][j] = ((L[i][j] == 0) ? -1 : 0);
    }
}

void write()
{
    nr++;int j;
    for(int i = 1; i <= n; i++){
    for(j = 1; j <= m; j++)
        switch(L[i][j])
        {
            case -1: cout << "* "; break;
            case  0: cout << "# "; break;
            default: cout << L[i][j] << ' '; break;
        }

        cout << endl;
    }
    cout << endl;
}

void bcktr(int i, int j, int k)
{
    int in, jn;
    for(int l = 1; l <= 4; l++){

        in = i+Dx[l];
        jn = j+Dy[l];

        if(in >= 1 && in <= n && jn >= 1 && jn <= m)
        if(L[in][jn] == 0){

            L[in][jn] = k;
            if(in == 1 || in == n || jn == 1 || jn == m)
                if(k < mini)
                    mini = k;
            else
                bcktr(in, jn, ++k);

            L[in][jn] = 0;
        }
    }
}

void bcktrAfter(int i, int j, int k)
{
    int in, jn;
    for(int l = 1; l <= 4; l++){

        in = i+Dx[l];
        jn = j+Dy[l];

        if(in >= 1 && in <= n && jn >= 1 && jn <= m)
        if(L[in][jn] == 0){

            L[in][jn] = k;
            if(in == 1 || in == n || jn == 1 || jn == m)
                if(k == mini)
                    write();
            else
                bcktr(in, jn, ++k);

            L[in][jn] = 0;
        }
    }
}

int main()
{
    init();

    write();
    L[ip][jp] = 1;
    bcktr(ip, jp, 2);
    bcktrAfter(ip, jp, 2);

    return 0;
}
