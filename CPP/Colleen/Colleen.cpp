/*
     This program will print its own source when run._0
*/

#include <iostream>

void quote(const char *s)
{
    int i;

    std::cout << "    \"";
    for (i=0; s[i]; ++i) {
        if (s[i] == '\\')
            std::cout << "\\\\";
        else if (s[i] == '"')
            std::cout << "\\\"";
        else if (s[i] == '\n')
            std::cout << "\\n";
        else
            std::cout << s[i];
        if (i % 48 == 47)
            std::cout << "\"\n    \"";
    }
    std::cout << "\"";
}

const char progdata[] =
    "/*\n     This program will print its own source w"
    "hen run._0\n*/\n\n#include <iostream>\n\nvoid quote(c"
    "onst char *s)\n{\n    int i;\n\n    std::cout << \"  "
    "  \\\"\";\n    for (i=0; s[i]; ++i) {\n        if (s["
    "i] == '\\\\')\n            std::cout << \"\\\\\\\\\";\n   "
    "     else if (s[i] == '\"')\n            std::cout"
    " << \"\\\\\\\"\";\n        else if (s[i] == '\\n')\n     "
    "       std::cout << \"\\\\n\";\n        else\n        "
    "    std::cout << s[i];\n        if (i % 48 == 47)"
    "\n            std::cout << \"\\\"\\n    \\\"\";\n    }\n  "
    "  std::cout << \"\\\"\";\n}\n\nconst char progdata[] =\n"
    "@@;\n\nint main(void)\n{\n/*\n    This program will p"
    "rint its own source when run._1\n*/\n    int i;\n\n "
    "   for (i=0; progdata[i]; ++i) {\n        if (pro"
    "gdata[i] == '@' && progdata[i+1] == '@')\n       "
    " {\n            quote(progdata);\n            i++;"
    "\n        } else\n            std::cout << progdat"
    "a[i];\n    }\n    return 0;\n}\n";

int main(void)
{
/*
    This program will print its own source when run._1
*/
    int i;

    for (i=0; progdata[i]; ++i) {
        if (progdata[i] == '@' && progdata[i+1] == '@')
        {
            quote(progdata);
            i++;
        } else
            std::cout << progdata[i];
    }
    return 0;
}
