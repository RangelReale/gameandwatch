#ifndef H__GWDBG__H
#define H__GWDBG__H

#ifdef GW_DEBUG

#define GWDBG_OUTPUT(x)		printf("%s\n", x);
#define GWDBG_FOUTPUT(x, y)		printf(x, y);

#else

#define GWDBG_OUTPUT(x)
#define GWDBG_FOUTPUT(x, y)

#endif

#endif // H__GWDBG__H
