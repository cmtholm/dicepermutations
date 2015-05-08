#include "dice.h"

int main() {

	//replace values with what you will to test
	//print can be set or just use default val of false
  /*  cout << dicePerm(6, 3, 6, true) << endl;
    cout << dicePerm(2, 2, 3) << endl;
    cout << dicePerm(6, 3, 8) << endl;
    cout << dicePerm(4, 2, 5) << endl;
    cout << dicePerm(4, 3, 5) << endl;
*/
    dice_perm_finder one(6,3,6);
    dice_perm_finder two(2,2,3);
    dice_perm_finder thr(6,3,8);
    dice_perm_finder fou(4,2,5);
    dice_perm_finder fiv(4,3,5);

    cout << one << two << thr << fou << fiv << endl;
    cout << one << endl;
    one.set_n(4);
    cout << one << endl;
    cout << "Done!" << endl;

    return 0;
}
