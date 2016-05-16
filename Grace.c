#include <stdio.h>
#include <fcntl.h>
#define GO int main(void) {go();}
/* Le commentaire dans l'introduction */

void gadgeto(int fd, const char *s)
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
    " int main(void) {go();}\n/* Le commentaire dans l"
    "'introduction */\n\nvoid gadgeto(int fd, const cha"
    "r *s)\n{\n	int i;\n\n	dprintf(fd, \"    \\\"\");\n	for (i"
    "=0; s[i]; ++i) {\n		if (s[i] == '\\\\')\n			dprintf("
    "fd, \"\\\\\\\\\");\n		else if (s[i] == '\"')\n			dprintf("
    "fd, \"\\\\\\\"\");\n		else if (s[i] == '\\n')\n			dprintf"
    "(fd, \"\\\\n\");\n		else\n			dprintf(fd, \"%c\", s[i]);\n"
    "		if (i % 48 == 47)\n			dprintf(fd, \"\\\"\\n    \\\"\")"
    ";\n		}\n	dprintf(fd, \"\\\"\");\n}\n\nconst char progdata"
    "[] =\n@@;\n\nint go(void)\n{\n	int i;\n	int fd = open("
    "\"Grace_kid.c\", O_RDWR | O_CREAT | O_SYNC);\n\n	for"
    " (i=0; progdata[i]; ++i) {\n		if (progdata[i] == "
    "'@' && progdata[i+1] == '@')\n		{\n			gadgeto(fd, "
    "progdata);\n			i++;\n		} else\n		dprintf(fd, \"%c\", "
    "progdata[i]);\n	}\n	return 0;\n}\n\nGO\n";

int go(void)
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
