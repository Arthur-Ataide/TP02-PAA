#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#if defined(__MINGW32__) || defined(_MSC_VER)
#define limparInput() fflush(stdin)
#define limparTela() system("cls");
#define pausarTela() system("pause");

#else
#define limparInput() __fpurge(stdin)
#define limparTela() clear();
#define pausarTela() printf("\nPress any key to continue..."); limparInput(); getchar();

#endif

#define pausarLimparTela() pausarTela(); limparTela();

