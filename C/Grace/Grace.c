#include <stdio.h>
#include <fcntl.h>
#define GO int main(void) {go();}
#define BIDULE0 int go(void)
#define BIDULE1 void gadgeto(int fd, const char *s)
/*
    This program will print its own source when run.
*/

BIDULE1
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

const char progdata[] =
    "#include <stdio.h>\n#include <fcntl.h>\n#define GO"
    " int main(void) {go();}\n#define BIDULE0 int go(v"
    "oid)\n#define BIDULE1 void gadgeto(int fd, const "
    "char *s)\n/*\n    This program will print its own "
    "source when run.\n*/\n\nBIDULE1\n{\n	int i;\n\n	dprintf"
    "(fd, \"    \\\"\");\n	for (i=0; s[i]; ++i) {\n		if (s["
    "i] == '\\\\')\n			dprintf(fd, \"\\\\\\\\\");\n		else if (s"
    "[i] == '\"')\n			dprintf(fd, \"\\\\\\\"\");\n		else if (s"
    "[i] == '\\n')\n			dprintf(fd, \"\\\\n\");\n		else\n			dp"
    "rintf(fd, \"%c\", s[i]);\n		if (i % 48 == 47)\n			dp"
    "rintf(fd, \"\\\"\\n    \\\"\");\n		}\n	dprintf(fd, \"\\\"\");"
    "\n}\n\nconst char progdata[] =\n@@;\n\nBIDULE0\n{\n	int "
    "i;\n	int fd = open(\"Grace_kid.c\", O_RDWR | O_CREA"
    "T | O_SYNC);\n\n	for (i=0; progdata[i]; ++i) {\n		i"
    "f (progdata[i] == '@' && progdata[i+1] == '@')\n	"
    "	{\n			gadgeto(fd, progdata);\n			i++;\n		} else\n		"
    "dprintf(fd, \"%c\", progdata[i]);\n	}\n	return 0;\n}\n"
    "\nGO\n";

BIDULE0
{
	int i;
	int fd = open("Grace_kid.c", O_RDWR | O_CREAT | O_SYNC);

	for (i=0; progdata[i]; ++i) {
		if (progdata[i] == '@' && progdata[i+1] == '@')
		{
			gadgeto(fd, progdata);
			i++;
		} else
		dprintf(fd, "%c", progdata[i]);
	}
	return 0;
}

GO
