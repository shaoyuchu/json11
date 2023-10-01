#include "TestJson.hpp"

#include <cppunit/extensions/HelperMacros.h>

CPPUNIT_TEST_SUITE_REGISTRATION(JsonTest);

void JsonTest::setUp() {
    this->nullJson1 = new Json();
    this->nullJson2 = new Json(nullptr);
}

void JsonTest::nullConstructorTest() {
    CPPUNIT_ASSERT(*(this->nullJson1) == *(this->nullJson2));
}

void JsonTest::tearDown() {
    delete this->nullJson1;
    delete this->nullJson2;
}
