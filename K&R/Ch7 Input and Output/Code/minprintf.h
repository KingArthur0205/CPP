#include <stdarg.h>
#include <stdio.h>

/**
 * va_start(): The va_start() macro initializes ap, argument pointer, for subsequent use by va_arg() and va_end()
 *
 * va_arg(): The va_arg() macro expands to an expression that has the type and value of the next argument in the call.
 *
 * va_end(): Each invocation of va_start() must be matched by a corresponding invocation of va_end() in the same function.
 */
void minprintf(char *fmt, ...) {
	// argument pointer
	va_list ap;
	char *p, *sval;
	int ival;
	double dval;

	// Initialize ap to point to the first unnamed argument.
	va_start(ap, fmt);
	for(p = fmt; *p; ++p) {
		if(*p != '%') {
			putchar(*p);
			continue;
		}

		// The switch case is executed only when *p == '%'
		switch(*++p) {
			case 'd':
				ival = va_arg(ap, int);
				printf("%d", ival);
				break;
			case 's':
				for(sval = va_arg(ap, char *); *sval; ++sval)
					putchar(*sval);
				break;
			case 'f':
				dval = va_arg(ap, double);
				printf("%f", dval);
				break;
			default:
				putchar(*p);
				break;
		}
	}
	va_end(ap);
}

