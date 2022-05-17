/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/yaml/blob/main/LICENSE.txt
*/

#ifndef _ISHIKO_CPP_YAML_YAMLPUSHPARSER_HPP_
#define _ISHIKO_CPP_YAML_YAMLPUSHPARSER_HPP_

#include <boost/utility/string_view.hpp>

namespace Ishiko
{

class YAMLPushParser
{
public:
    class Callbacks
    {
    public:
        virtual ~Callbacks() = default;

        virtual void onKey(boost::string_view data);
        virtual void onString(boost::string_view data);
    };

    YAMLPushParser(Callbacks& callbacks);

    bool onData(boost::string_view data, bool eod);

private:
    enum class ParsingMode
    {
        key,
        colon,
        whitespace,
        stringScalar
    };

    ParsingMode m_parsingMode;
    std::string m_fragmentedData;
    Callbacks& m_callbacks;
};

}

#endif
