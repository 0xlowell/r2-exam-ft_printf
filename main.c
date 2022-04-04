#include <unistd.h>
#include <stdio.h>

int ft_printf(const char *toprint, ...);

int main ()
{
	int ret;
	int nb = -12;
	
	printf("\n");	

	printf("ft_printf wanted: abc \n");
	ret = ft_printf("abc");
	printf("\n");
	printf("return value wanted: 3 _ result: %d \n", ret);
	printf("\n");	
	printf("#################################\n\n");
	printf("ft_printf wanted: lol \n");
	ret = ft_printf("%s", "lol");
	printf("\n");
	printf("return value wanted: 3 _ result: %d \n", ret);
	printf("\n");
	printf("#################################\n\n");
	printf("ft_printf wanted: %% \n");
	ret = ft_printf("%");
	printf("\n");
	printf("return value wanted: 1 _ result: %d \n", ret);
	printf("\n");	
	printf("#################################\n\n");
	printf("ft_printf wanted: -12 \n");
	ret = ft_printf("%d", nb);
	printf("\n");
	printf("return value wanted:  3 _ result: %d \n", ret);
	printf("\n");	
	printf("#################################\n\n");
	printf("ft_printf wanted: -c \n");
	ret = ft_printf("%x", nb);
	printf("\n");
	printf("return value wanted: 2 _ result: %d \n", ret);
	printf("\n");		
}
