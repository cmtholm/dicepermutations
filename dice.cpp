#include "dice.h"


void dice_perm_finder::print( ostream &os) const{

  for(int i = 0; i < 60; ++i) {
    os << "=";
  }
  os << endl;
  print_num_ways(os);
  print_table(os);
  for(int i = 0; i < 60; ++i) {
    os << "=";
  }
  os << endl << endl;
}

void dice_perm_finder::print_table(ostream &os) const {

  os << "\tTable of:\n\t (num_dice, sum) = number_of_ways\n\tfor dice with " << m << " sides." << endl; 

  os << '\t';
  for(int i = 1; i <= x; ++i) {
    os << "----";
  }

  os << endl;

  for(int i = n; i > 0 ; --i) {
    os << '\t' << "| ";
    for(int j = x; j > 0; --j) {
      os << master_table[i][j] << " | ";
    }
    os << endl << '\t';
    for(int k = 1; k <=x; ++k) {
      os << "----";
    }
    os << endl;
  }
}

void dice_perm_finder::print_num_ways(ostream &os) const {

  os << "There are "<< master_table[n][x] << " ways to get the value " << x
    << " with " << n << ", " << m << "-sided dice." << endl << endl;

}

void dice_perm_finder::populate_table() {


  vector<vector<int> > table(n+1, vector<int>(x+1, 0));

  //if x higher than all dice could possibly sum to, 1 or 0 solutions
  if(m*n <= x)
    table[n][x] = (m*n == x) ;
  //if x <= number of dice, only 1 or 0 possible solutions
  else if(n >= x)
    table[n][x] = (n == x);

 
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
 
  master_table = table;
}

void dice_perm_finder::set_x(int x_in) {
    
    //if the sum is differnt must always repopulate the table
    if(x != x_in) {
        x = x_in;
        populate_table();
    }

}

void dice_perm_finder::set_m(int m_in) {
    
    //if the number of sides is different must repopulate table
    if(m != m_in) {
        m = m_in;
        populate_table();
    }
}

void dice_perm_finder::set_n(int n_in) {
    //if we're using less dice we already calculated for more dice
    if(n > n_in) {
        n = n_in;
    }
    //if using more dice can extend from previous last spot
    else if(n < n_in) {
        
        vector<vector<int> > table(n_in+1, vector<int>(x+1, 0));
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <=x; ++j) {
                table[i][j] = master_table[i][j];
            }
        }
        for(int i = n+1; i <= n_in; i++) 
            for (int j = 1; j <= x; j++)
                for (int k = 1; k <= m && k < j; k++)
                    table[i][j] += table[i-1][j-k];

        n = n_in;
        master_table = table;
    }

}

std::ostream& operator<< (std::ostream& os, const dice_perm_finder& c) {

  c.print(os);
  return os;
}
