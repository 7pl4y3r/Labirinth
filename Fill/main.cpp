#include <iostream>
#include <fstream>

using namespace std;

ifstream in("lab.txt");
int n,m,ip,jp;
int L[11][11];
int Dx[] = {0, -1, 0, 1, 0};
int Dy[] = {0, 0, 1, 0, -1};

void init()
{
    in >> n >> m >> ip >> jp;
    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= m; j++){
        in >> L[i][j];
        L[i][j] = ((L[i][j] == 0) ? -1 : 0);
    }
}

void write()
{
    for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++)
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

void bcktr(int i, int j)
{
    int in, jn;
    for(int l = 1; l <= 4; l++){

        if(L[i+Dx[l]][j+Dy[l]] != 1){
            in = i+Dx[l];
            jn = j+Dy[l];

            if(L[in][jn] == 0){
            L[in][jn] = 5;
            bcktr(in, jn);
            }
        }
    }
}

int main()
{
    init();

    L[ip][jp] = 5;
    bcktr(ip, jp);

    write();
    return 0;
}
