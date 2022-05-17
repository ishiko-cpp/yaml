/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/yaml/blob/main/LICENSE.txt
*/

#include "YAMLPushParserTestCallbacks.hpp"

void YAMLPushParserTestCallbacks::onKey(boost::string_view data)
{
    m_events.emplace_back(EventType::key, data.to_string());
}

const std::vector<std::pair<YAMLPushParserTestCallbacks::EventType, std::string>>&
YAMLPushParserTestCallbacks::events() const
{
    return m_events;
}
