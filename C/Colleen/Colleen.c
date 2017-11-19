/*
     This program will print its own source when run._0
*/

#include <stdio.h>

void quote(const char *s)
{
    int i;

    printf("    \"");
    for (i=0; s[i]; ++i) {
        if (s[i] == '\\')
            printf("\\\\");
        else if (s[i] == '"')
            printf("\\\"");
        else if (s[i] == '\n')
            printf("\\n");
        else
            printf("%c", s[i]);
        if (i % 48 == 47)
            printf("\"\n    \"");
    }
    printf("\"");
}

const char progdata[] =
    "/*\n     This program will print its own source w"
    "hen run._0\n*/\n\n#include <stdio.h>\n\nvoid quote(co"
    "nst char *s)\n{\n    int i;\n\n    printf(\"    \\\"\");"
    "\n    for (i=0; s[i]; ++i) {\n        if (s[i] == "
    "'\\\\')\n            printf(\"\\\\\\\\\");\n        else i"
    "f (s[i] == '\"')\n            printf(\"\\\\\\\"\");\n    "
    "    else if (s[i] == '\\n')\n            printf(\"\\"
    "\\n\");\n        else\n            printf(\"%c\", s[i]"
    ");\n        if (i % 48 == 47)\n            printf("
    "\"\\\"\\n    \\\"\");\n    }\n    printf(\"\\\"\");\n}\n\nconst "
    "char progdata[] =\n@@;\n\nint main(void)\n{\n/*\n    T"
    "his program will print its own source when run._"
    "1\n*/\n    int i;\n\n    for (i=0; progdata[i]; ++i)"
    " {\n        if (progdata[i] == '@' && progdata[i+"
    "1] == '@')\n        {\n            quote(progdata)"
    ";\n            i++;\n        } else\n            pr"
    "intf(\"%c\", progdata[i]);\n    }\n    return 0;\n}\n";

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
            printf("%c", progdata[i]);
    }
    return 0;
}
