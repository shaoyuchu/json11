#include "TestJson.hpp"

#include <cppunit/extensions/HelperMacros.h>

CPPUNIT_TEST_SUITE_REGISTRATION(JsonTest);

JsonTest::JsonTest() {
    string str = string("Hello world!");
    this->str = str;
    this->charArr = new char[str.length() + 1];
    strcpy(this->charArr, str.c_str());
}

void JsonTest::setUp() {
    this->nullJson1 = new Json();
    this->nullJson2 = new Json(nullptr);
    this->doubleJson05 = new Json(0.5);
    this->doubleJson25 = new Json(2.5);
    this->intJson1 = new Json(1);
    this->intJson5 = new Json(5);
    this->boolJson0 = new Json(false);
    this->boolJson1 = new Json(true);
    this->strJson1 = new Json(string(""));
    this->strJson2 = new Json(this->str);
    this->strJson3 = new Json(this->charArr);
}

void JsonTest::testNull1() { CPPUNIT_ASSERT(this->nullJson1->is_null()); }

void JsonTest::testNull2() { CPPUNIT_ASSERT(this->nullJson2->is_null()); }

void JsonTest::testDoubleNumber() { CPPUNIT_ASSERT(this->doubleJson05->is_number()); }

void JsonTest::testIntNumber() { CPPUNIT_ASSERT(this->intJson1->is_number()); }

void JsonTest::testBool() { CPPUNIT_ASSERT(this->boolJson0->is_bool()); }

void JsonTest::testString() {
    CPPUNIT_ASSERT(this->strJson1->is_string());
    CPPUNIT_ASSERT(this->strJson2->is_string());
    CPPUNIT_ASSERT(this->strJson3->is_string());
}

void JsonTest::tearDown() {
    delete this->nullJson1;
    delete this->nullJson2;
    delete this->doubleJson05;
    delete this->doubleJson25;
    delete this->intJson1;
    delete this->intJson5;
    delete this->boolJson0;
    delete this->boolJson1;
    delete this->strJson1;
    delete this->strJson2;
    delete this->strJson3;

    delete[] this->charArr;
}
