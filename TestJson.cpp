#include "TestJson.hpp"

#include <cppunit/extensions/HelperMacros.h>

CPPUNIT_TEST_SUITE_REGISTRATION(JsonTest);

JsonTest::JsonTest() {
    this->charArr = new char[this->str.length() + 1];
    strcpy(this->charArr, str.c_str());
}

void JsonTest::setUp() {
    this->nullJson1 = new Json();
    this->nullJson2 = new Json(nullptr);
    this->doubleJson05 = new Json(0.5);
    this->doubleJson25 = new Json(2.5);
    this->doubleJsonNeg025 = new Json(-0.25);
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

    map<string, Json> obj = {
        {"null", *(this->nullJson1)}, {"double", *(this->doubleJsonNeg025)},
        {"int", *(this->intJson1)},   {"string", *(this->strJson1)},
        {"array", *(this->arrJson1)},
    };
    this->objJson1 = new Json(obj);
    this->objJson2 =
        new Json(map<string, Json>({{"1", *(this->intJson1)}, {"5", *(this->intJson5)}}));
}

void JsonTest::testNull() {
    const Json::shape expectedShape = {};
    string err;
    CPPUNIT_ASSERT(!(this->nullJson1->has_shape(expectedShape, err)));
    CPPUNIT_ASSERT(err == "expected JSON object, got null");
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
    CPPUNIT_ASSERT((*this->nullJson1) == (*this->nullJson2));
    CPPUNIT_ASSERT((*this->nullJson1) <= (*this->nullJson2));
    CPPUNIT_ASSERT((*this->nullJson1) >= (*this->nullJson2));
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
    CPPUNIT_ASSERT((*this->doubleJsonNeg025) < (*this->doubleJsonInf));

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
    CPPUNIT_ASSERT((*this->intJson1) <= (*this->intJson5));
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
    CPPUNIT_ASSERT((*this->boolJson0) < (*this->boolJson1));
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
    const Json::shape expectedShape = {{"1", Json::NUMBER}, {"5", Json::NUMBER}};
    string err;
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
    CPPUNIT_ASSERT(this->objJson2->has_shape(expectedShape, err));
    CPPUNIT_ASSERT(err == "");
}

void JsonTest::testParse() {
    string inStr =
        "{\n"
        "// comments\n"
        "/*\n"
        "multi-line comment\n"
        "*/\n"
        "\"null\": null, \"double\": -2.5e-1, \"int\": 1, \"string\": "
        "\"\\\\\\\"\\b\\f\\n\\r\\t\", \"array\": [null, null]\n"
        "}";
    string err = "";
    const char* in = inStr.c_str();
    CPPUNIT_ASSERT(Json::parse(in, err, json11::COMMENTS) == *(this->objJson1));
    // TODO: NaN?
}

void JsonTest::testParseMulti() {
    string in =
        "{\"null\": null, \"double\": -2.5e-1, \"int\": 1, \"string\": "
        "\"\\\\\\\"\\b\\f\\n\\r\\t\", \"array\": [null, null]} "
        "{\"1\": 1, \"5\": 5} "
        "{\"true\": true, \"false\": false} "
        "{}";
    string::size_type pos = 0;
    string err;
    vector<Json> parsedMultiJson = Json::parse_multi(in, err, json11::STANDARD);
    CPPUNIT_ASSERT(parsedMultiJson.size() == 4);
    CPPUNIT_ASSERT(parsedMultiJson[0] == (*this->objJson1));
    CPPUNIT_ASSERT(parsedMultiJson[1] == (*this->objJson2));
}

void JsonTest::testFailedParse() {
    string err = "";
    const char* nullIn = nullptr;
    CPPUNIT_ASSERT(Json::parse(nullIn, err) == nullptr);
    CPPUNIT_ASSERT(err == "null input");
}

void JsonTest::testCrossTypeComparison() {
    CPPUNIT_ASSERT(!((*this->intJson1) == (*this->objJson1)));
    CPPUNIT_ASSERT((*this->boolJson0) < (*this->intJson1));
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
    delete this->doubleJsonNeg025;
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
