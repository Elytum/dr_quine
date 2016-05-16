/* Le commentaire dans l'introduction */

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
    "/* Le commentaire dans l'introduction */\n\n#inclu"
    "de <stdio.h>\n\nvoid quote(const char *s)\n{\n    in"
    "t i;\n\n    printf(\"    \\\"\");\n    for (i=0; s[i]; "
    "++i) {\n        if (s[i] == '\\\\')\n            pri"
    "ntf(\"\\\\\\\\\");\n        else if (s[i] == '\"')\n     "
    "       printf(\"\\\\\\\"\");\n        else if (s[i] == "
    "'\\n')\n            printf(\"\\\\n\");\n        else\n  "
    "          printf(\"%c\", s[i]);\n        if (i % 48"
    " == 47)\n            printf(\"\\\"\\n    \\\"\");\n    }\n"
    "    printf(\"\\\"\");\n}\n\nconst char progdata[] =\n@@;"
    "\n\nint main(void)\n{\n    /* Le commentaire dans le"
    " main */\n    int i;\n\n    for (i=0; progdata[i]; "
    "++i) {\n        if (progdata[i] == '@' && progdat"
    "a[i+1] == '@')\n        {\n            quote(progd"
    "ata);\n            i++;\n        } else\n          "
    "  printf(\"%c\", progdata[i]);\n    }\n    return 0;"
    "\n}\n";

int main(void)
{
    /* Le commentaire dans le main */
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
