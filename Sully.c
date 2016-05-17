#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <libgen.h>

void loud(int i)
{
	if (i == 0)
		return ;

	char buffer[1024];
	snprintf(buffer, sizeof(buffer), "gcc Sully_%d.c -o Sully_%d && ./Sully_%d", i, i, i);
	system(buffer);
}

void out(int fd, const char *s)
{
	int i;

	dprintf(fd, "    \"");
	for (i=0; s[i]; ++i) {
		if (s[i] == '\\')
			dprintf(fd, "\\\\");
		else if (s[i] == '"')
			dprintf(fd, "\\\"");
		else if (s[i] == '\n')
			dprintf(fd, "\\n");
		else
			dprintf(fd, "%c", s[i]);
		if (i % 48 == 47)
			dprintf(fd, "\"\n    \"");
		}
	dprintf(fd, "\"");
}

const char laughing[] =
	    "#include <stdio.h>\n#include <fcntl.h>\n#include <"
    "stdlib.h>\n#include <unistd.h>\n#include <string.h"
    ">\n#include <libgen.h>\n\nvoid loud(int i)\n{\n	if (i"
    " == 0)\n		return ;\n\n	char buffer[1024];\n	snprintf"
    "(buffer, sizeof(buffer), \"gcc Sully_%%d.c -o Sul"
    "ly_%%d && ./Sully_%%d\", i, i, i);\n	system(buffer"
    ");\n}\n\nvoid out(int fd, const char *s)\n{\n	int i;\n"
    "\n	dprintf(fd, \"    \\\"\");\n	for (i=0; s[i]; ++i) {"
    "\n		if (s[i] == '\\\\')\n			dprintf(fd, \"\\\\\\\\\");\n		e"
    "lse if (s[i] == '\"')\n			dprintf(fd, \"\\\\\\\"\");\n		e"
    "lse if (s[i] == '\\n')\n			dprintf(fd, \"\\\\n\");\n		e"
    "lse\n			dprintf(fd, \"%%c\", s[i]);\n		if (i %% 48 ="
    "= 47)\n			dprintf(fd, \"\\\"\\n    \\\"\");\n		}\n	dprintf"
    "(fd, \"\\\"\");\n}\n\nconst char laughing[] =\n	@@;\n\nint"
    " main(void)\n{\n	int i = $$;\n	if (strcmp(basename("
    "__FILE__), \"Sully.c\"))\n		--i;\n	int copy = i;\n	ch"
    "ar buffer[42];\n	snprintf(buffer, sizeof(buffer),"
    " \"Sully_%%d.c\", i);\n	int fd = open(buffer, O_RDW"
    "R | O_CREAT | O_SYNC, 0777);\n\n	for (i=0; laughin"
    "g[i]; ++i) {\n		if (laughing[i] == '@' && laughin"
    "g[i+1] == '@')\n		{\n			out(fd, laughing);\n			i++;"
    "\n		}\n		else if (laughing[i] == '$' && laughing[i"
    "+1] == '$')\n		{\n			dprintf(fd, \"%%d\", copy);\n			"
    "i++;\n		}\n		else if (laughing[i] == '%%')\n		{\n			"
    "dprintf(fd, \"%%%%\");\n			++i;\n		}\n		else\n			dprin"
    "tf(fd, \"%%c\", laughing[i]);\n	}\n	close(fd);\n	loud"
    "(copy);\n	return 0;\n}\n";

int main(void)
{
	int i = 5;
	if (strcmp(basename(__FILE__), "Sully.c"))
		--i;
	int copy = i;
	char buffer[42];
	snprintf(buffer, sizeof(buffer), "Sully_%d.c", i);
	int fd = open(buffer, O_RDWR | O_CREAT | O_SYNC, 0777);

	for (i=0; laughing[i]; ++i) {
		if (laughing[i] == '@' && laughing[i+1] == '@')
		{
			out(fd, laughing);
			i++;
		}
		else if (laughing[i] == '$' && laughing[i+1] == '$')
		{
			dprintf(fd, "%d", copy);
			i++;
		}
		else if (laughing[i] == '%')
		{
			dprintf(fd, "%%");
			++i;
		}
		else
			dprintf(fd, "%c", laughing[i]);
	}
	close(fd);
	loud(copy);
	return 0;
}
