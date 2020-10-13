/*
	Name: Rotate 90 deg Matrix
	Copyright: Product Based CheckList
	Author: Sounish Nath
	Date: 13-10-20 12:12
	Description: Arrays Based Problem
*/
#include<bits/stdc++.h>

using namespace std ;


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
	cout << "90 deg rotation\n";
	for(auto &&row : matrix){
		for(auto &&x : row){
			cout << x << " " ;
		}
		cout << endl;
	}
	
}

