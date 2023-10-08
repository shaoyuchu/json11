#ifndef JSON_TEST_H
#define JSON_TEST_H

#include <cppunit/extensions/HelperMacros.h>

#include <string>

#include "json11.hpp"

using namespace std;
using namespace json11;

class JsonTest : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(JsonTest);
    CPPUNIT_TEST(testNull1);
    CPPUNIT_TEST(testNull2);
    CPPUNIT_TEST(testDoubleNumber);
    CPPUNIT_TEST(testIntNumber);
    CPPUNIT_TEST(testBool);
    CPPUNIT_TEST(testString);
    CPPUNIT_TEST_SUITE_END();

   public:
    JsonTest();
    void setUp();
    void testNull1();
    void testNull2();
    void testDoubleNumber();
    void testIntNumber();
    void testBool();
    void testString();
    void tearDown();

   private:
    string str;
    char* charArr;
    Json* nullJson1;
    Json* nullJson2;
    Json* doubleJson05;
    Json* doubleJson25;
    Json* intJson1;
    Json* intJson5;
    Json* boolJson0;
    Json* boolJson1;
    Json* strJson1;
    Json* strJson2;
    Json* strJson3;
};

#endif