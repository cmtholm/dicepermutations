#ifndef __dice__
#define __dice__
#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;


class dice_perm_finder {
    friend std::ostream;
    private:
        
    //creating vector table
	//rows are number of dice, columns are sum
	vector<vector<int> > master_table;
        int num_ways = 0;
        int m;
        int n;
        int x;

        void print_table(std::ostream &os) const;
        void print_num_ways(std::ostream &os) const;

//REQUIRES: n>0, x>0
//Modifies: none
//Effects: Finds number of ways to get the sum x, from n dice with m sides
//			if print is true prints the contents of dynamic prog table
        void populate_table();

    public:

        dice_perm_finder(int m_in, int n_in, int x_in) 
            : m(m_in), n(n_in), x(x_in) {
            populate_table();
        }


        void print(std::ostream &os) const;
        void set_x();
        void set_m();
        void set_n();

};


std::ostream& operator<< (std::ostream& os, const dice_perm_finder& c);

#endif
