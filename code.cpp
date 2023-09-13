#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    if(n % 2 == 1) cout << -1 << endl;
    else 
    {
        string ans;
        vector<vector<int>> mat(n, vector<int>(n));
        mat[0][0] = 0;
        int count = 1;
        ans = ans + 'R';
        for(int i = 0; i < n; i++)
        {
            int j = 0;
            if(i % 2 == 0) 
            {
                for(int j = 1; j < n; j++)
                {
                    mat[i][j] = count % n;
                    count++;
                    if(j != n-1)
                        ans = ans + 'R';
                }
                ans = ans + 'D';
            }
            else 
            {
                for(int j = n-1; j >= 1; j--)
                {
                    mat[i][j] = count % n;
                    count++;
                    if(j != n-1)
                        ans = ans + 'L';
                }
                if(i != n-1)
                    ans = ans + 'D';
            }
        }
        ans = ans + 'L';
        for(int i = n-1; i >= 0; i--)
        {
            mat[i][0] = count % n;
            count++;
            if(i != 0)
            ans = ans + 'U';
        }
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
        cout << ans << endl;
    }

	return 0;
}
