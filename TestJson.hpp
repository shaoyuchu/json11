#ifndef JSON_TEST_H
#define JSON_TEST_H

#include <cppunit/extensions/HelperMacros.h>

#include "json11.hpp"
using namespace json11;

class JsonTest : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(JsonTest);
    CPPUNIT_TEST(nullConstructorTest);
    CPPUNIT_TEST_SUITE_END();

   public:
    void setUp();
    void nullConstructorTest();
    void tearDown();

   private:
    Json* nullJson1;
    Json* nullJson2;
};

#endif