/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/yaml/blob/main/LICENSE.txt
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
    append<HeapAllocationErrorsTest>("onData mapping test 1", OnDataMappingTest1);
}

void YAMLPushParserTests::ConstructorTest1(Test& test)
{
    YAMLPushParser::Callbacks callbacks;
    YAMLPushParser parser(callbacks);

    ISHIKO_TEST_PASS();
}

void YAMLPushParserTests::OnDataMappingTest1(Test& test)
{
    boost::filesystem::path inputPath = test.context().getTestDataPath("mapping1.yaml");
    std::string jsonData = FileSystem::ReadFile(inputPath);

    YAMLPushParserTestCallbacks callbacks;
    YAMLPushParser parser(callbacks);

    bool complete = parser.onData(jsonData, true);

    ISHIKO_TEST_FAIL_IF_NOT(complete);
    ISHIKO_TEST_ABORT_IF_NEQ(callbacks.events().size(), 2);
    ISHIKO_TEST_FAIL_IF_NEQ(callbacks.events()[0].first, YAMLPushParserTestCallbacks::EventType::key);
    ISHIKO_TEST_FAIL_IF_NEQ(callbacks.events()[0].second, "key");
    ISHIKO_TEST_FAIL_IF_NEQ(callbacks.events()[1].first, YAMLPushParserTestCallbacks::EventType::stringScalar);
    ISHIKO_TEST_FAIL_IF_NEQ(callbacks.events()[1].second, "value");
    ISHIKO_TEST_PASS();
}
