#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#if defined(__MINGW32__) || defined(_MSC_VER)
#define limparInput() fflush(stdin)
#define limparTela() system("cls");
#define pausarTela() system("pause");

#else
#include <stdio_ext.h>
#define limparInput() __fpurge(stdin)
#define limparTela() system("clear")
#define pausarTela() printf("\nPress any key to continue..."); limparInput(); getchar();

#endif

#define pausarLimparTela() pausarTela(); limparTela();

