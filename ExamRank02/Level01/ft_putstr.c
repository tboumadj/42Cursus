#include <unistd.h>
#include <stdio.h>

void	ft_putstr(char *str)
{
    int i = 0;
    while ( str[i] != '\0')
    {
        write (1, &str[i], 1);
        i++;
    }
}

/* while (str[i])
    ++i;
write(1, str, i);
*/

int main()
{
char a[] = "Hellooo";
ft_putstr(a);
}