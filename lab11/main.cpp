#include <iostream>
#include "social.h"
#include "network.h"
int main(){
    Profile p1("marco", "Marco");    
    std::cout << p1.getUsername() << std::endl; // marco
    std::cout << p1.getFullName() << std::endl; // Marco (@marco)

    Network nw;
    std::cout << nw.addUser("mario", "Mario") << std::endl;     // true (1)
    std::cout << nw.addUser("mario", "Mario2") << std::endl;    // false (0) /beep

    nw.addUser("mario", "Mario");
    nw.addUser("luigi", "Luigi");
    nw.addUser("yoshi", "Yoshi");

    nw.follow("mario", "luigi");// mario 0 luigi 1
    nw.follow("mario", "yoshi");// mario 0 yoshi 2
    nw.follow("luigi", "mario");
    nw.follow("luigi", "yoshi");
    nw.follow("yoshi", "mario");
    nw.follow("yoshi", "luigi");
    // add a user who does not follow others
    nw.addUser("wario", "Wario");

    nw.printDot();
}