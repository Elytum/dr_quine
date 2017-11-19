#include <iostream>
#include <cstdio>
#define GO int main(void) {go();}
#define BIDULE0 int go(void)
#define BIDULE1 void gadgeto(const char *s)
/*
    This program will print its own source when run.
*/

BIDULE1
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
    "#include <iostream>\n#include <cstdio>\n#define GO"
    " int main(void) {go();}\n#define BIDULE0 int go(v"
    "oid)\n#define BIDULE1 void gadgeto(const char *s)"
    "\n/*\n    This program will print its own source w"
    "hen run.\n*/\n\nBIDULE1\n{\n    int i;\n\n    std::cout"
    " << \"    \\\"\";\n    for (i=0; s[i]; ++i) {\n       "
    " if (s[i] == '\\\\')\n            std::cout << \"\\\\\\"
    "\\\";\n        else if (s[i] == '\"')\n            st"
    "d::cout << \"\\\\\\\"\";\n        else if (s[i] == '\\n'"
    ")\n            std::cout << \"\\\\n\";\n        else\n "
    "           std::cout << s[i];\n        if (i % 48"
    " == 47)\n            std::cout << \"\\\"\\n    \\\"\";\n "
    "   }\n    std::cout << \"\\\"\";\n}\n\nconst char progda"
    "ta[] =\n@@;\n\nBIDULE0\n{\n	int i;\n	freopen(\"Grace_ki"
    "d.cpp\", \"w\", stdout);\n\n	for (i=0; progdata[i]; +"
    "+i) {\n		if (progdata[i] == '@' && progdata[i+1] "
    "== '@')\n		{\n			gadgeto(progdata);\n			i++;\n		} el"
    "se\n		std::cout << progdata[i];\n	}\n	return 0;\n}\n\n"
    "GO\n";

BIDULE0
{
	int i;
	freopen("Grace_kid.cpp", "w", stdout);

	for (i=0; progdata[i]; ++i) {
		if (progdata[i] == '@' && progdata[i+1] == '@')
		{
			gadgeto(progdata);
			i++;
		} else
		std::cout << progdata[i];
	}
	return 0;
}

GO
