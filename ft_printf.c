#include "Libft/libft.h"

char	flegs_check(char *str, int *index)
{
	while (str[index])
	{
		if (str[index] == 37)
			return (str[index + 1]);
		else
			index++;
	}
	return (NULL);
}

int ft_printf(const char *str, ...)
{
	int *index = 0;
	while (str[index])
	{}

}

int main(void)
{
	printf("yolo %s", yep);
}
