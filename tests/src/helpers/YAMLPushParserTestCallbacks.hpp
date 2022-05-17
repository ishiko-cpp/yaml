/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/yaml/blob/main/LICENSE.txt
*/

#ifndef _ISHIKO_CPP_YAML_TESTS_HELPERS_YAMLPUSHPARSERTESTCALLBACKS_HPP_
#define _ISHIKO_CPP_YAML_TESTS_HELPERS_YAMLPUSHPARSERTESTCALLBACKS_HPP_

#include "Ishiko/YAML/YAMLPushParser.hpp"
#include <string>
#include <utility>
#include <vector>

class YAMLPushParserTestCallbacks : public Ishiko::YAMLPushParser::Callbacks
{
public:
    enum EventType
    {
        key,
        stringScalar
    };

    void onKey(boost::string_view data) override;

    const std::vector<std::pair<EventType, std::string>>& events() const;

private:
    std::vector<std::pair<EventType, std::string>> m_events;
};

#endif
