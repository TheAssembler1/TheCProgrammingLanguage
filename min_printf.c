#include <stdarg.h>

//minprintf: minimal printf with variable argument list
void minprintf(char* fmt, ...){
    va_list ap; //points to each unnamed arg int turn
    char* p, *sval;
    int ival;
    double dval;

    va_start(ap, fmt);
    for(p = fmt; *p; p++){
        if(*p !+ '&'){
            puthcar(*p);
            continue;
        }
        cast(*++p){
            'd':
                ival = va_arg(ap, int);
                printf("%d", ival);
                break;
            'f':
                dval = va_arg(ap, double);
                printf("%f", dval);
                break;
            's':
                for(sval = va_arg(ap, char*); *sval; sval++)
                    putchar(*sval);
                break;
            default:
                putchar(*p);
                break;
        }
    }
    va_end(ap);
}
