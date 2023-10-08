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

    vector<Json> arr = {*(this->nullJson1), *(this->nullJson2)};
    this->arrJson1 = new Json(arr);
    this->arrJson2 = new Json(vector<Json>({*(this->doubleJson05), *(this->doubleJson25),
                                            *(this->intJson1), *(this->intJson5)}));

    map<string, Json> obj = {{"0.5", *(this->doubleJson05)},
                             {"2.5", *(this->doubleJson25)}};
    this->objJson1 = new Json(obj);
    this->objJson2 =
        new Json(map<string, Json>({{"1", *(this->intJson1)}, {"5", *(this->intJson5)}}));
}

void JsonTest::testNull() {
    CPPUNIT_ASSERT(this->nullJson1->is_null());
    CPPUNIT_ASSERT(this->nullJson2->is_null());
}

void JsonTest::testDoubleNumber() {
    CPPUNIT_ASSERT(this->doubleJson05->is_number());
    CPPUNIT_ASSERT(this->doubleJson25->is_number());
}

void JsonTest::testIntNumber() {
    CPPUNIT_ASSERT(this->intJson1->is_number());
    CPPUNIT_ASSERT(this->intJson5->is_number());
}

void JsonTest::testBool() {
    CPPUNIT_ASSERT(this->boolJson0->is_bool());
    CPPUNIT_ASSERT(this->boolJson1->is_bool());
}

void JsonTest::testString() {
    CPPUNIT_ASSERT(this->strJson1->is_string());
    CPPUNIT_ASSERT(this->strJson2->is_string());
    CPPUNIT_ASSERT(this->strJson3->is_string());
}

void JsonTest::testArray() {
    CPPUNIT_ASSERT(this->arrJson1->is_array());
    CPPUNIT_ASSERT(this->arrJson2->is_array());
}

void JsonTest::testObject() {
    CPPUNIT_ASSERT(this->objJson1->is_object());
    CPPUNIT_ASSERT(this->objJson2->is_object());
}

void JsonTest::tearDown() {
    delete this->arrJson1;
    delete this->arrJson2;
    delete this->objJson1;
    delete this->objJson2;

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
