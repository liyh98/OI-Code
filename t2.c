#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int v[100];
int main()
{
    const size_t maxLineLen = 1024;
    char line[maxLineLen];
    while (fgets(line, maxLineLen, stdin) != NULL)
    {
        memset(v, 0, sizeof v);
        int n = strlen(line);
        for (int i = 0; i < n; i++)
        {
            if (line[i] >= 'a' && line[i] <= 'z')
                v[line[i] - 'a'] = 1;
            if (line[i] >= 'A' && line[i] <= 'Z')
                v[line[i] - 'A'] = 1;
        }
        int flag = 0;
        for (int i = 0; i < 26; i++)
            if (!v[i])
            {
                putchar('a' + i);
                flag = 1;
            }
        puts(flag ? "" : "NULL");
    }
}