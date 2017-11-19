#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <libgen.h>

void loud(int i)
{
	char buffer[1024];
	if (i == 0)
		snprintf(buffer, sizeof(buffer), "g++ Sully_%d.cpp -o Sully_%d", i, i);
	else
		snprintf(buffer, sizeof(buffer), "g++ Sully_%d.cpp -o Sully_%d && ./Sully_%d", i, i, i);
	system(buffer);
}

void out(const char *s)
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

const char laughing[] =
	    "#include <iostream>\n#include <cstdio>\n#include <"
    "stdlib.h>\n#include <unistd.h>\n#include <string.h"
    ">\n#include <libgen.h>\n\nvoid loud(int i)\n{\n	char "
    "buffer[1024];\n	if (i == 0)\n		snprintf(buffer, si"
    "zeof(buffer), \"g++ Sully_%d.cpp -o Sully_%d\", i,"
    " i);\n	else\n		snprintf(buffer, sizeof(buffer), \"g"
    "++ Sully_%d.cpp -o Sully_%d && ./Sully_%d\", i, i"
    ", i);\n	system(buffer);\n}\n\nvoid out(const char *s"
    ")\n{\n    int i;\n\n    std::cout << \"    \\\"\";\n    f"
    "or (i=0; s[i]; ++i) {\n        if (s[i] == '\\\\')\n"
    "            std::cout << \"\\\\\\\\\";\n        else if"
    " (s[i] == '\"')\n            std::cout << \"\\\\\\\"\";\n"
    "        else if (s[i] == '\\n')\n            std::"
    "cout << \"\\\\n\";\n        else\n            std::cou"
    "t << s[i];\n        if (i % 48 == 47)\n           "
    " std::cout << \"\\\"\\n    \\\"\";\n    }\n    std::cout "
    "<< \"\\\"\";\n}\n\nconst char laughing[] =\n	@@;\n\nint ma"
    "in(void)\n{\n	int i = $$;\n    if (i<0)\n        ret"
    "urn (-1);\n	if (strcmp(basename((char *)__FILE__)"
    ", \"Sully.cpp\"))\n		--i;\n	int copy = i;\n	char buff"
    "er[42];\n	snprintf(buffer, sizeof(buffer), \"Sully"
    "_%d.cpp\", i);\n	freopen(buffer, \"w\", stdout);\n\n	f"
    "or (i=0; laughing[i]; ++i) {\n		if (laughing[i] ="
    "= '@' && laughing[i+1] == '@')\n		{\n			out(laughi"
    "ng);\n			i++;\n		}\n		else if (laughing[i] == '$' &"
    "& laughing[i+1] == '$')\n		{\n			std::cout << copy"
    ";\n			i++;\n		}\n		else\n			std::cout << laughing[i]"
    ";\n	}\n	fclose(stdout);\n	loud(copy);\n	return 0;\n}\n"
    "";

int main(void)
{
	int i = 5;
    if (i<0)
        return (-1);
	if (strcmp(basename((char *)__FILE__), "Sully.cpp"))
		--i;
	int copy = i;
	char buffer[42];
	snprintf(buffer, sizeof(buffer), "Sully_%d.cpp", i);
	freopen(buffer, "w", stdout);

	for (i=0; laughing[i]; ++i) {
		if (laughing[i] == '@' && laughing[i+1] == '@')
		{
			out(laughing);
			i++;
		}
		else if (laughing[i] == '$' && laughing[i+1] == '$')
		{
			std::cout << copy;
			i++;
		}
		else
			std::cout << laughing[i];
	}
	fclose(stdout);
	loud(copy);
	return 0;
}
