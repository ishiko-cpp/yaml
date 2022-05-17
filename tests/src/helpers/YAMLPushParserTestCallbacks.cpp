/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/yaml/blob/main/LICENSE.txt
*/

#include "YAMLPushParserTestCallbacks.hpp"

const std::vector<std::pair<YAMLPushParserTestCallbacks::EventType, std::string>>&
YAMLPushParserTestCallbacks::events() const
{
    return m_events;
}
