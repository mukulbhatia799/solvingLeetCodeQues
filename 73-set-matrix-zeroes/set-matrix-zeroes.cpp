class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int c0 = 1;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(mat[i][j] == 0) {
                    if(i == 0 || j == 0) {
                        if(i == 0) {
                            mat[0][0] = 0;
                        }
                        if(j == 0) {
                            c0 = 0;
                        }
                    }
                    else {
                        mat[i][0] = 0;
                        mat[0][j] = 0;
                    }
                }
            }
        }
        cout << "c0: " << c0 << endl;

        cout << "print after row and col fill: " << endl;
        for(auto &vec: mat) {
            for(int val: vec) {
                cout << val << " ";
            }
            cout << endl;
        }
        cout << endl;

        for(int i = 1; i < n; i++) {
            if(mat[i][0] == 0) {
                for(int j = 1; j < m; j++) {
                    mat[i][j] = 0;
                }
            }
        }
        cout << "print after col check: " << endl;
        for(auto &vec: mat) {
            for(int val: vec) {
                cout << val << " ";
            }
            cout << endl;
        }
        cout << endl;

        for(int i = 1; i < m; i++) {
            if(mat[0][i] == 0) {
                for(int j = 1; j < n; j++) {
                    mat[j][i] = 0;
                }
            }
        }
        cout << "print after row check: " << endl;
        for(auto &vec: mat) {
            for(int val: vec) {
                cout << val << " ";
            }
            cout << endl;
        }
        cout << endl;

        if(mat[0][0] == 0) {
            for(int i = 0; i < m; i++) {
                mat[0][i] = 0;
            }
        }
        cout << "print after 0,0: " << endl;
        for(auto &vec: mat) {
            for(int val: vec) {
                cout << val << " ";
            }
            cout << endl;
        }
        cout << endl;

        if(c0 == 0) {
            for(int i = 0; i < n; i++) {
                mat[i][0] = 0;
            }
        }  
    }
};