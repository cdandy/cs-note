#include <stdio.h>
#include <ctype.h>

#define MAXLINE 100

int getline(char line[], int max);
double atof(char s[]);


/*简单计算器程序*/
main()
{
    double sum;
    char line[MAXLINE];

    sum = 0;
    while (getline(line, MAXLINE) > 0)
    { 
        printf("\t%g\n", sum += atof(line));
    }
    
    return 0;
}

/*getline函数:将行保存到s中，并返回该行的长度*/
int getline(char s[], int lim)
{
    int c, i;

    i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        s[i++] = c;

    if (c == '\n')
        s[i++] = c;

    s[i] = '\0';

    return i;
}

/*atof函数:把字符串s转换为相应的双精度浮点数*/
double atof(char s[])
{
    double val, power;
    int i, sign;

    for (i = 0; isspace(s[i]); i++)
    {
        ;
    }

    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;

    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');

    if (s[i] == '.')
        i++;

    for (power = 1.0; isdigit(s[i]); i++)
    {
        val = 10.0 * val + (s[i] - '0');
        power += 10.0;
    }

    return sign * val / power;
}
