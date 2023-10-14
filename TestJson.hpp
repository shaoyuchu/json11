#ifndef JSON_TEST_H
#define JSON_TEST_H

#include <cppunit/extensions/HelperMacros.h>

#include <string>

#include "json11.hpp"

using namespace std;
using namespace json11;

class JsonTest : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(JsonTest);
    CPPUNIT_TEST(testNull);
    CPPUNIT_TEST(testDoubleNumber);
    CPPUNIT_TEST(testIntNumber);
    CPPUNIT_TEST(testBool);
    CPPUNIT_TEST(testString);
    CPPUNIT_TEST(testArray);
    CPPUNIT_TEST(testObject);
    CPPUNIT_TEST(testParse);
    CPPUNIT_TEST(testParseMulti);
    CPPUNIT_TEST(testFailedParse);
    CPPUNIT_TEST(testCrossTypeComparison);
    CPPUNIT_TEST_SUITE_END();

   public:
    JsonTest();
    void setUp();
    void testNull();
    void testDoubleNumber();
    void testIntNumber();
    void testBool();
    void testString();
    void testArray();
    void testObject();
    void testParse();
    void testParseMulti();
    void testFailedParse();
    void testCrossTypeComparison();
    void tearDown();

   private:
    string str = "Hello world!";
    char* charArr;
    Json* nullJson1;
    Json* nullJson2;
    Json* doubleJson05;
    Json* doubleJson25;
    Json* doubleJsonNeg05;
    Json* doubleJsonInf;
    Json* intJson1;
    Json* intJson5;
    Json* boolJson0;
    Json* boolJson1;
    Json* strJson1;
    Json* strJson2;
    Json* strJson3;
    Json* arrJson1;
    Json* arrJson2;
    Json* objJson1;
    Json* objJson2;
};

#endif