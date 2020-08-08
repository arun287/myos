#include <limits.h>
#include <stdbool.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

static bool print(const char* data, size_t length) 
{
	const unsigned char* bytes = (const unsigned char*) data;
	for (size_t i = 0; i < length; i++)
		if (putchar(bytes[i]) == EOF)
			return false;
	return true;
}

int printf(const char* restrict format, ...) 
{
	va_list parameters;
	va_start(parameters, format);

	int written = 0;

	while (*format != '\0') 
    {
		size_t maxrem = INT_MAX - written;

		if (format[0] != '%' || format[1] == '%') 
        {
            size_t amount = 1;

			if (format[0] == '%')
				format++;
		
			while (format[amount] && format[amount] != '%')
				amount++;

			if (maxrem < amount) 
				return -1;
			
			if (!print(format, amount))
				return -1;

			format += amount;
			written += amount;

			continue;
		}

		const char* format_begun_at = format++;

		if (*format == 'c') 
        {
			format++;
			char c = (char) va_arg(parameters, int /* char promotes to int */);

			if (!maxrem) 
				return -1;
			
			if (!print(&c, sizeof(c)))
				return -1;

			written++;
		}
        else if (*format == 's') 
        {
			format++;
			const char* str = va_arg(parameters, const char*);
			size_t len = strlen(str);

			if (maxrem < len) 
				return -1;
			
			if (!print(str, len))
				return -1;

			written += len;
		}
        /*else if (*format == 'd') 
        {
		  format++;
		  int num = va_arg(parameters, int);
		  char buf[32];
		  char* numString = itoa(num, buf, 10);
		  size_t len = strlen(numString);

		  if (maxrem < len)
              return -1;

		  if (!print(numString, len))
		    return -1;
		} 
        else if (*format == 'x') 
        {
		  format++;
		  uint32_t num = va_arg(parameters, uint32_t);
		  char buf[32];
		  char* numString = utoa(num, buf, 16);
		  size_t len = strlen(numString);

		  if (maxrem+2 < len)
		    return -1;

		  if (!print("0x", 2))
		    return -1;

		  if (!print(numString, len))
		    return -1;
		  
		}*/       
        else if(*format == 'd')
        {
            format++;

            int num = (int)va_arg(parameters,int);
            int rev = 0;
            int len = 0;

            while(num>0)
            {
                rev *= 10;
                rev += num%10;
                num /= 10;
                len++;
            }

            int count = 0;
            while(rev > 0)
            {
                count++;
                char c = (char)(rev%10 + 48);
                rev /= 10;
                
                if (!maxrem) 
				    return -1;
			
			    if (!print(&c, sizeof(c)))
				    return -1;

			    written++;
            }

            while(count<len)
            {
                char c = '0';
                
                if(!maxrem)
                    return -1;

                if(!print(&c, sizeof(c)))
                    return -1;

                written++;
                count++;
            }
        }
        else 
        {
			format = format_begun_at;
			size_t len = strlen(format);

			if (maxrem < len) 
				return -1;
			
			if (!print(format, len))
				return -1;

			written += len;
			format += len;
		}
	}

	va_end(parameters);
	return written;
}

