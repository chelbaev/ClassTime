#include <gtest/gtest.h>
#include "TimeLib/time.hpp"

using namespace TimeNameSpace;
using namespace std;

int comp (const Time& a, std::string str){return to_string(a).compare(str);}
int comp (const Time& a, const Time& b){return to_string(a).compare(to_string(b));}

TEST(ConstructorTest, MinValue){
    Time a(0, 0, 0, false);
    Time b(false);
    EXPECT_EQ(comp(a, string("0:0:0")), 0 );
    EXPECT_EQ(comp(a, b), 0);
}

TEST(ConstructorTest, MaxValue){
    Time a (23, 59, 59, false);
    EXPECT_EQ(comp(a, string("23:59:59")), 0);
}

TEST(ConstructorTest, NotNormalizedValue){
    Time aS (0, 0, -1, false);
    Time aM (0, -1, 0, false);
    Time aH (-1, 0, 0, false);
    Time aHMS (-1, -1, -1, false);
    Time bS (0, 0, 60, false);
    Time bM (0, 60, 0, false);
    Time bH (24, 0, 0, false);
    Time bHMS (24, 60, 60, false);
    EXPECT_EQ(comp(aS, string("23:59:59")), 0);
    EXPECT_EQ(comp(aM, string("23:59:0")), 0);
    EXPECT_EQ(comp(aH, string("23:0:0")), 0);
    EXPECT_EQ(comp(aHMS, string("22:58:59")), 0);
    EXPECT_EQ(comp(bS, string("0:1:0")), 0);
    EXPECT_EQ(comp(bM, string("1:0:0")), 0);
    EXPECT_EQ(comp(bH, string("0:0:0")), 0);
    EXPECT_EQ(comp(bHMS, string("1:1:0")), 0);
}

// ToSeconds(), Normalize() и геттеры были проверены в ходе этих тестов 

TEST(SetterTest, testingSet){
    Time a (false);
    a.SetHours(1); 
    a.SetMinutes(1);    
    a.SetSeconds(1);    
    EXPECT_EQ(comp(a, string("1:1:1")), 0);
    a.SetHours(-1);    
    a.SetMinutes(-1);    
    a.SetSeconds(-1);    
    EXPECT_EQ(comp(a, string("22:58:59")), 0);
    a.SetHours(24);    
    a.SetMinutes(60);    
    a.SetSeconds(60);   
    EXPECT_EQ(comp(a, string("1:1:0")), 0);

}

TEST(OperationTest, allOperationTest){
    Time a(1, 1, 1, false);
    Time b(2, 2, 2, false);
    a -= b;
    EXPECT_EQ(comp(a, string("22:58:59")), 0);
    Time c(false);
    c = c + 3661;
    EXPECT_EQ(comp(c, string("1:1:1")), 0);
    c = c - 3661;
    EXPECT_EQ(comp(c, string("0:0:0")), 0);
    Time q(12, 35, 72, false);
    Time p(12, 35, 72, false);
    EXPECT_EQ(p == q, true);
}
