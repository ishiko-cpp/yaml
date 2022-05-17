/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/yaml/blob/main/LICENSE.txt
*/

#include "YAMLPushParserTests.hpp"
#include "Ishiko/YAML/linkoptions.hpp"
#include <Ishiko/TestFramework/Core.hpp>

using namespace Ishiko;

int main(int argc, char* argv[])
{
    TestHarness theTestHarness("IshikoYAML");

    theTestHarness.context().setTestDataDirectory("../../data");

    TestSequence& theTests = theTestHarness.tests();
    theTests.append<YAMLPushParserTests>();

    return theTestHarness.run();
}
