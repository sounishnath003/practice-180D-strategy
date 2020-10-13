/*
	Name: Rotate 90 deg Matrix
	Copyright: Product Based CheckList
	Author: Sounish Nath
	Date: 13-10-20 12:12
	Description: Arrays Based Problem
*/
#include<bits/stdc++.h>

using namespace std ;

/* efficient solution in O(1) ex */
void f(vector<vector<int>> &matrix){
	int m = matrix.size(), n = matrix[0].size();
	int row = 0, col = 0, prev = 0, next = 0;
	while(row < m && col < n){
		if(row + 1 == m or col + 1 == n){
			break;
		}
		prev = matrix[row + 1][col];
		for(int i = col; i < n; i++){
			next = matrix[row][i];
			matrix[row][i] = prev;
			prev = next;
		}
		row++;
		for(int i = row; i< m; i++){
			next = matrix[i][n-1];
			matrix[i][n - 1] = prev;
			prev = next;
		}
		n--;
		if(row < m){
			for(int i = n - 1; i >= col; i--){
				next = matrix[m-1][i];
				matrix[m-1][i] = prev;
				prev = next;
			}
		}
		m--;
		if(col < n){
			for(int i = m - 1; i >= row ; i--){
				next = matrix[i][col];
				matrix[i][col] = prev;
				prev = next;
			}
		}
		col++;
	}
}


int main() {
	srand(time(NULL)); cin.tie(0);
	ios::sync_with_stdio(false);
	
	int m, n ;
	cin >> m >> n;
	vector<vector<int>> matrix(m, vector<int>(n));
	for(int r = 0; r < m; r++){
		for(int c = 0; c < n; c++){
			cin >> matrix[r][c];
		}
	}
	/* ineffiecient solution for O(M*N) extra space */
	vector<vector<int>> ans(m, vector<int>(n));
	for(int row = 0; row < m; row++){
		for(int col = 0; col < n; col++){
			ans[row][col] = matrix[m - col - 1][row];
		}
	}
	cout << "90 deg rotation\n";
	for(auto &&row : ans){
		for(auto &&x : row){
			cout << x << " " ;
		}
		cout << endl;
	}
	
}

