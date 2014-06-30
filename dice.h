#ifndef __dice__
#define __dice__
#include <iostream>
#include <vector>
using namespace std;


//Requires: none
//Modifies: standard out
//Effects: print contents of table
void printTable(int col, int row, vector< vector<int> > const &table) {
    for (int i = 0; i <= col; i++) {
      for (int j = 0; j <= row; j++)
        cout << table[i][j] << " ";
      cout << endl;
    } 
}


//REQUIRES: n>0, x>0
//Modifies: none
//Effects: Finds number of ways to get the sum x, from n dice with m sides
//			if print is true prints the contents of dynamic prog table
int dicePerm(int m, int n, int x, bool print=false) {

	//if x higher than all dice could possibly sum to, 1 or 0 solutions
	if(m*n <= x)
		return (m*n == x);
	//if x <= number of dice, only 1 or 0 possible solutions
	else if(n >= x)
		return (n == x);

    //creating vector table
	//rows are number of dice, columns are sum
	vector<vector<int> > table(n+1, vector<int>(x+1, 0));
 
    //For 1 die only 1 way to form all solutions
	//stops at whichever is less, m or x
    for (int i = 1; (i <= m) and (i <= x); i++)
        table[1][i] = 1;
 
    // Each table val is sum of all previous values of previous die
    // i: num dice
	// j: sum
	// k: num sides
	//starts at second die because first taken care of above
    for (int i = 2; i <= n; i++)
        for (int j = 1; j <= x; j++)
            for (int k = 1; k <= m && k < j; k++)
                table[i][j] += table[i-1][j-k];
 
	if(print)
		printTable(n, x, table);

    return table[n][x];
}

#endif
