/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/yaml/blob/main/LICENSE.txt
*/

#include "YAMLPushParser.hpp"
#include <Ishiko/Text.hpp>

using namespace Ishiko;

void YAMLPushParser::Callbacks::onKey(boost::string_view data)
{
}

void YAMLPushParser::Callbacks::onString(boost::string_view data)
{
}

YAMLPushParser::YAMLPushParser(Callbacks& callbacks)
    : m_callbacks(callbacks)
{
    m_parsingMode = ParsingMode::key;
}

bool YAMLPushParser::onData(boost::string_view data, bool eod)
{
    const char* previous = data.data();
    const char* current = previous;
    const char* end = current + data.length();
    while (current < end)
    {
        switch (m_parsingMode)
        {
        case ParsingMode::key:
            while (current < end)
            {
                if (*current == ':')
                {
                    if (m_fragmentedData.empty() && ((current - previous) > 0))
                    {
                        m_callbacks.onKey(boost::string_view(previous, (current - previous)));
                    }
                    else
                    {
                        m_fragmentedData.append(data.data(), current - data.data());
                        m_callbacks.onKey(boost::string_view(previous, (current - previous)));
                        m_fragmentedData.clear();
                    }
                    break;
                }
                ++current;
            }
            if (current == end)
            {
                m_fragmentedData.append(previous, (current - previous));
            }
            else
            {
                m_parsingMode = ParsingMode::colon;
            }
            break;

        case ParsingMode::colon:
            if (*current == ':')
            {
                m_parsingMode = ParsingMode::whitespace;
            }
            else
            {
                // TODO: error
            }
            ++current;
            break;

        case ParsingMode::whitespace:
            while (current < end)
            {
                if ((*current != ' ') && (*current != '\t'))
                {
                    /*
                    if (m_fragmentedData.empty() && ((current - previous) > 0))
                    {
                        m_callbacks.onKey(boost::string_view(previous, (current - previous)));
                    }
                    else
                    {
                        m_fragmentedData.append(data.data(), current - data.data());
                        m_callbacks.onKey(boost::string_view(previous, (current - previous)));
                        m_fragmentedData.clear();
                    }*/
                    // TODO: this should be set in a separate state
                    previous = current;
                    break;
                }
                ++current;
            }
            if (current == end)
            {
                m_fragmentedData.append(previous, (current - previous));
            }
            else
            {
                m_parsingMode = ParsingMode::stringScalar;
            }
            break;

        case ParsingMode::stringScalar:
            while (current < end)
            {
                if (!ASCII::IsAlpha(*current))
                {
                    if (m_fragmentedData.empty() && ((current - previous) > 0))
                    {
                        m_callbacks.onString(boost::string_view(previous, (current - previous)));
                    }
                    else
                    {
                        m_fragmentedData.append(data.data(), current - data.data());
                        m_callbacks.onString(boost::string_view(previous, (current - previous)));
                        m_fragmentedData.clear();
                    }
                    break;
                }
                ++current;
            }
            if (current == end)
            {
                m_fragmentedData.append(previous, (current - previous));
            }
            else
            {
                // TODO: what is the next state, for now we just only cope with a single mapping in the file
                //m_parsingMode = ParsingMode::stringScalar;
            }
            break;

        default:
            // TODO: error
            break;
        }
    }
    if ((current == end) && eod)
    {
        while (true)
        {
            switch (m_parsingMode)
            {
            case ParsingMode::key:
                // TODO: this is an error
                break;

            case ParsingMode::colon:
                // TODO: this is an error
                break;

            case ParsingMode::whitespace:
                // TODO
                break;

            case ParsingMode::stringScalar:
                m_fragmentedData.append(data.data(), current - data.data());
                m_callbacks.onString(boost::string_view(previous, (current - previous)));
                m_fragmentedData.clear();
                // TODO: only works because we only cope with the single mapping case, need to move to an appropriate
                // state
                return true;
                break;
           
            default:
                // TODO: error
                break;
            }
        }
    }
    return false;
}
