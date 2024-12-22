This is a small project for my upcoming project, the DoxleSuite, which is just going to be a bunch of lower-level software which I plan on writing. This comes with a custom project template and builder manager/whatnot, and so I made a custom (definitely original) config syntax, with the ".dx_cfg" file.

<b>The config syntax:</b>

    - "key = value" (as i said, very original)

Whitespace doesn't matter, you can have it or not have it.
Comments are made with the '#' character. They can be a whole line or at the end of a line.

<b>How to use the parser: (if you're using the suite's folder structure)</b>

    - In a .cpp file--or a header file--inside the /src file add `#include "../utils/cfg_parser`
    - Then, you can use the namespace DX_CFG_PARSER to access some functions

    - `get_key(std::string key)` - This will get a specific key from the config folder, returns a std::string.
    - `get_all()` - Returns a vector containing structs, where you can access each options key and value.

