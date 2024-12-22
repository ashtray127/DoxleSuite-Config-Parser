#include "lib.h"

namespace DX_CFG_PARSER {
    /* Gets a specified option from the projects dx_cfg file */
    static std::string get_key(std::string option)
    {
        std::ifstream cfg_stream("./project.dx_cfg");
        std::string cur_line;
        while (std::getline(cfg_stream, cur_line))
        {

            // Removes comments
            if (cur_line.find("#") != std::string::npos)
                cur_line = cur_line.substr(0, cur_line.find("#"));
        
            // Ignores empty lines
            if (cur_line == "")
                continue;

            // This would be a syntax error
            size_t find_equal = cur_line.find("=");

            if (find_equal == std::string::npos)
                continue;

            std::string key = cur_line.substr(0, find_equal);
            std::string value = cur_line.substr(find_equal+1, cur_line.size());

            // Now we trim the whitespace on the key and value
            size_t keyBegin = key.find_first_not_of(" ");
            size_t keyEnd = key.find_last_not_of(" ");
            key = key.substr(keyBegin, keyEnd+1);

            // We only need to continue if it's the key we are looking for
            if (option != key)
                continue;

            size_t valueBegin = value.find_first_not_of(" ");
            size_t valueEnd = value.find_last_not_of(" ");
            value = value.substr(valueBegin, valueEnd+1);

            return value;

        }

        // If nothing has returned yet, then it's not a key inside of the options
        return "";

    }

    struct Option {
        std::string key;
        std::string value;
    };

    static std::vector<Option> get_all()
    {
        std::vector<Option> output;

        std::ifstream cfg_stream("./project.dx_cfg");
        std::string cur_line;
        while (std::getline(cfg_stream, cur_line))
        {

            // Removes comments
            if (cur_line.find("#") != std::string::npos)
                cur_line = cur_line.substr(0, cur_line.find("#"));
        
            // Ignores empty lines
            if (cur_line == "")
                continue;

            // This would be a syntax error
            size_t find_equal = cur_line.find("=");

            if (find_equal == std::string::npos)
                continue;

            std::string key = cur_line.substr(0, find_equal);
            std::string value = cur_line.substr(find_equal+1, cur_line.size());

            // Now we trim the whitespace on the key and value
            size_t keyBegin = key.find_first_not_of(" ");
            size_t keyEnd = key.find_last_not_of(" ");
            key = key.substr(keyBegin, keyEnd+1);

            size_t valueBegin = value.find_first_not_of(" ");
            size_t valueEnd = value.find_last_not_of(" ");
            value = value.substr(valueBegin, valueEnd+1);

            // Now we construct the struct of this option
            Option next_option = {key, value};

            output.push_back(next_option);
        }

        // If nothing has returned yet, then it's not a key inside of the options
        return output;
    }

}