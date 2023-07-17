#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "social.h"
#include "network.h"
TEST_CASE("Task A"){
    Profile p1("marco", "Marco");
    CHECK(p1.getUsername() == "marco");
    CHECK(p1.getFullName() == "Marco (@marco)");
}

Network nw;
TEST_CASE("Task B"){
    CHECK(nw.addUser("mario", "Mario") == true);
    CHECK(nw.addUser("mario", "Mario2") == false);
}

TEST_CASE("Task C"){
    nw.follow("luigi", "mario");
    nw.follow("luigi", "yoshi");
    nw.follow("yoshi", "mario");
    nw.follow("yoshi", "luigi");
    CHECK(nw.follow("luigi", "mario") == 1);
    CHECK(nw.follow("luigi", "yoshi") == 1);
    CHECK(nw.follow("yoshi", "mario") == 1);
    CHECK(nw.follow("yoshi", "luigi") == 1);

}