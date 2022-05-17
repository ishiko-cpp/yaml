/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/json/blob/main/LICENSE.txt
*/

#include "YAMLPushParserTests.hpp"
#include "helpers/YAMLPushParserTestCallbacks.hpp"
#include "Ishiko/YAML/YAMLPushParser.hpp"
#include <Ishiko/FileSystem.hpp>
#include <Ishiko/Text.hpp>

using namespace Ishiko;

YAMLPushParserTests::YAMLPushParserTests(const TestNumber& number, const TestContext& context)
    : TestSequence(number, "YAMLPushParser tests", context)
{
    append<HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
}

void YAMLPushParserTests::ConstructorTest1(Test& test)
{
    YAMLPushParser::Callbacks callbacks;
    YAMLPushParser parser(callbacks);

    ISHIKO_TEST_PASS();
}
