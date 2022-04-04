#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

int printchar(char c)
{
	int ret = 0;
	ret += write(1, &c, 1);
	return(ret);
}


int printnbr(int nb, int base)
{
	
	int ret = 0;

	if(nb == 0)
		ret += printchar('0');
	if (nb < 0)
	{
		ret += printchar('-');
		nb *= -1;
	}
	if(nb > base)
	{
		ret += printnbr(nb / base, base);
		ret += printnbr(nb % base, base);
	}
	else
	{
		if(nb < 10)
			nb += 48;
		else
			nb += 87;
		ret += printchar(nb);
	}
	return(ret);
}

int printstr(char *str)
{
	int i = 0;
	int ret = 0;
	while(str[i] != 0)
	{
		ret += write(1, &str[i], 1);
		i++;
	}
	return(ret);
}

int printargs(char toprint, va_list args)
{
	int ret= 0;
	if (toprint == 's')
		ret += printstr(va_arg(args, char *));
	if(toprint == 'd')
		ret += printnbr(va_arg(args, int), 10);
	if (toprint == 'x')
		ret += printnbr(va_arg(args, long), 16);
	return(ret);
}


int ft_printf(const char *toprint, ...)

{
	int i = 0;
	va_list args;
	int ret = 0; 
	va_start(args, toprint);

	while(toprint[i] != 0)
	{
		if(toprint[i] == '%' && (toprint[i+1] == 's' | toprint[i+1] == 'x' | toprint[i+1] == 'd'))
		{
			i++;
			ret += printargs(toprint[i], args);
		}
		else
			ret += printchar(toprint[i]);
		i++;
	}
	va_end(args);
	return(ret);
}
