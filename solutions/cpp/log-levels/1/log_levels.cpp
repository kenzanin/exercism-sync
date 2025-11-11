#include <string>

namespace log_line
{
    std::string message(const char *msg)
    {
        std::string data{msg};
        if (const auto index = data.find(":"); index != data.npos)
        {
            data = data.substr(index + 2);
        }

        return data;
    }

    std::string log_level(const char *msg)
    {
        std::string data{msg};
        if (const auto index = data.find(":"); index != data.npos)
        {
            data = data.substr(1, index - 2);
        }
        return data;
    }

    std::string reformat(const char *msg)
    {
        auto data1 = message(msg);
        auto data2 = log_level(msg);
        return data1 + " (" + data2 + ")";
    }

} // namespace log_line
