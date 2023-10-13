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
    this->doubleJsonInf = new Json(INFINITY);
    this->intJson1 = new Json(1);
    this->intJson5 = new Json(5);
    this->boolJson0 = new Json(false);
    this->boolJson1 = new Json(true);
    this->strJson1 = new Json(string("\\\"\b\f\n\r\t"));
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
    CPPUNIT_ASSERT(this->nullJson1->number_value() == 0.0);
    CPPUNIT_ASSERT(this->nullJson1->int_value() == 0.0);
    CPPUNIT_ASSERT(this->nullJson1->bool_value() == false);
    CPPUNIT_ASSERT(this->nullJson1->string_value() == "");
    CPPUNIT_ASSERT(this->nullJson1->array_items().empty());
    CPPUNIT_ASSERT(this->nullJson1->object_items().empty());
    CPPUNIT_ASSERT((*this->nullJson1)[0] == Json());
    CPPUNIT_ASSERT((*this->nullJson1)["key"] == Json());
    CPPUNIT_ASSERT(this->nullJson1->dump() == "null");
}

void JsonTest::testDoubleNumber() {
    CPPUNIT_ASSERT(this->doubleJson05->is_number());
    CPPUNIT_ASSERT(this->doubleJson05->number_value() == (double)0.5);
    CPPUNIT_ASSERT(this->doubleJson05->int_value() == static_cast<int>(0.5));
    CPPUNIT_ASSERT(this->doubleJson05->bool_value() == false);
    CPPUNIT_ASSERT(this->doubleJson05->string_value() == "");
    CPPUNIT_ASSERT(this->doubleJson05->array_items().empty());
    CPPUNIT_ASSERT(this->doubleJson05->object_items().empty());
    CPPUNIT_ASSERT((*this->doubleJson05)[0] == Json());
    CPPUNIT_ASSERT((*this->doubleJson05)["key"] == Json());
    CPPUNIT_ASSERT(this->doubleJson05->dump() == "0.5");

    CPPUNIT_ASSERT(this->doubleJsonInf->dump() == "null");
}

void JsonTest::testIntNumber() {
    CPPUNIT_ASSERT(this->intJson1->is_number());
    CPPUNIT_ASSERT(this->intJson1->number_value() == 1);
    CPPUNIT_ASSERT(this->intJson1->int_value() == 1);
    CPPUNIT_ASSERT(this->intJson1->bool_value() == false);
    CPPUNIT_ASSERT(this->intJson1->string_value() == "");
    CPPUNIT_ASSERT(this->intJson1->array_items().empty());
    CPPUNIT_ASSERT(this->intJson1->object_items().empty());
    CPPUNIT_ASSERT((*this->intJson1)[0] == Json());
    CPPUNIT_ASSERT((*this->intJson1)["key"] == Json());
    CPPUNIT_ASSERT(this->intJson1->dump() == "1");
}

void JsonTest::testBool() {
    CPPUNIT_ASSERT(this->boolJson0->is_bool());
    CPPUNIT_ASSERT(this->boolJson0->number_value() == 0);
    CPPUNIT_ASSERT(this->boolJson0->int_value() == 0);
    CPPUNIT_ASSERT(this->boolJson0->bool_value() == false);
    CPPUNIT_ASSERT(this->boolJson0->string_value() == "");
    CPPUNIT_ASSERT(this->boolJson0->array_items().empty());
    CPPUNIT_ASSERT(this->boolJson0->object_items().empty());
    CPPUNIT_ASSERT((*this->boolJson0)[0] == Json());
    CPPUNIT_ASSERT((*this->boolJson0)["key"] == Json());
    CPPUNIT_ASSERT(this->boolJson0->dump() == "false");
}

void JsonTest::testString() {
    CPPUNIT_ASSERT(this->strJson3->is_string());
    CPPUNIT_ASSERT(this->strJson3->number_value() == 0);
    CPPUNIT_ASSERT(this->strJson3->int_value() == 0);
    CPPUNIT_ASSERT(this->strJson3->bool_value() == false);
    CPPUNIT_ASSERT(this->strJson3->string_value() == "Hello world!");
    CPPUNIT_ASSERT(this->strJson3->array_items().empty());
    CPPUNIT_ASSERT(this->strJson3->object_items().empty());
    CPPUNIT_ASSERT((*this->strJson3)[0] == Json());
    CPPUNIT_ASSERT((*this->strJson3)["key"] == Json());
    CPPUNIT_ASSERT(this->strJson1->dump() == "\"\\\\\\\"\\b\\f\\n\\r\\t\"");
    CPPUNIT_ASSERT(this->strJson3->dump() == "\"Hello world!\"");
}

void JsonTest::testArray() {
    CPPUNIT_ASSERT(this->arrJson2->is_array());
    CPPUNIT_ASSERT(this->arrJson2->number_value() == 0);
    CPPUNIT_ASSERT(this->arrJson2->int_value() == 0);
    CPPUNIT_ASSERT(this->arrJson2->bool_value() == false);
    CPPUNIT_ASSERT(this->arrJson2->string_value() == "");
    CPPUNIT_ASSERT(this->arrJson2->array_items().size() == 4);
    CPPUNIT_ASSERT(this->arrJson2->object_items().empty());
    CPPUNIT_ASSERT((*this->arrJson2)[0].number_value() == 0.5);
    CPPUNIT_ASSERT((*this->arrJson2)["key"] == Json());
    CPPUNIT_ASSERT(this->arrJson2->dump() == "[0.5, 2.5, 1, 5]");
}

void JsonTest::testObject() {
    CPPUNIT_ASSERT(this->objJson2->is_object());
    CPPUNIT_ASSERT(this->objJson2->number_value() == 0);
    CPPUNIT_ASSERT(this->objJson2->int_value() == 0);
    CPPUNIT_ASSERT(this->objJson2->bool_value() == false);
    CPPUNIT_ASSERT(this->objJson2->string_value() == "");
    CPPUNIT_ASSERT(this->objJson2->array_items().empty());
    CPPUNIT_ASSERT(this->objJson2->object_items().size() == 2);
    CPPUNIT_ASSERT((*this->objJson2)[0] == Json());
    CPPUNIT_ASSERT((*this->objJson2)["1"].int_value() == 1);
    CPPUNIT_ASSERT(this->objJson2->dump() == "{\"1\": 1, \"5\": 5}");
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
    delete this->doubleJsonInf;
    delete this->intJson1;
    delete this->intJson5;
    delete this->boolJson0;
    delete this->boolJson1;
    delete this->strJson1;
    delete this->strJson2;
    delete this->strJson3;

    delete[] this->charArr;
}
