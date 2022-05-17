/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/yaml/blob/main/LICENSE.txt
*/

#ifndef _ISHIKO_CPP_YAML_YAMLPUSHPARSER_HPP_
#define _ISHIKO_CPP_YAML_YAMLPUSHPARSER_HPP_

namespace Ishiko
{

class YAMLPushParser
{
public:
    class Callbacks
    {
    };

    YAMLPushParser(Callbacks& callbacks);

private:
    Callbacks& m_callbacks;
};

}

#endif
