/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/yaml/blob/main/LICENSE.txt
*/

#ifndef _ISHIKO_CPP_YAML_TESTS_YAMLPUSHPARSERTESTS_HPP_
#define _ISHIKO_CPP_YAML_TESTS_YAMLPUSHPARSERTESTS_HPP_

#include <Ishiko/TestFramework/Core.hpp>

class YAMLPushParserTests : public Ishiko::TestSequence
{
public:
    YAMLPushParserTests(const Ishiko::TestNumber& number, const Ishiko::TestContext& context);

private:
    static void ConstructorTest1(Ishiko::Test& test);
};

#endif
