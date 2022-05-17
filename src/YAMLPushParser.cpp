/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/yaml/blob/main/LICENSE.txt
*/

#include "YAMLPushParser.hpp"

using namespace Ishiko;

YAMLPushParser::YAMLPushParser(Callbacks& callbacks)
    : m_callbacks(callbacks)
{
}
