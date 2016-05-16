#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

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

const char laughing[] =     "#include <stdio.h>\n#include <fcntl.h>\n#include <"
    "stdlib.h>\n#include <unistd.h>\n#include <string.h"
    ">\n\nvoid loud(int i)\n{\n	if (i == 0)\n		return ;\n\n	"
    "char buffer[1024];\n	snprintf(buffer, sizeof(buff"
    "er), \"gcc Sully_%%d.c -o Sully_%%d &