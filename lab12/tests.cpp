#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "funcs.h"

TEST_CASE("makeVector function"){
    std::vector<int> e1 = makeVector(5);
    std::vector<int> a1 {0,1,2,3,4};
    CHECK(e1 == a1);
}

TEST_CASE("goodVibes function"){
    const std::vector<int> v {-2,-1,0,1,-5,2,3};
    std::vector<int> e2 = goodVibes(v);
    std::vector<int> a2 {1,2,3};
    CHECK(e2 == a2);
}

TEST_CASE("gogeta function"){
    std::vector<int> v1{1,2,3};
    std::vector<int> v2{4,5};
    gogeta(v1,v2);
    std::vector<int> a1{1,2,3,4,5};
    std::vector<int> a2{};
    CHECK(v1 == a1);
    CHECK(v2 == a2);
}

TEST_CASE("sumPairWise function"){
    std::vector<int> t1{1,2,3};
    std::vector<int> t2{4,5};
    std::vector<int> result = sumPairWise(t1, t2);
    std::vector<int> a1{5,7,3};
    CHECK(result == a1);
}