/* TAP inspired macros  */

#ifndef H_H
#define H_H
#ifndef LOG
# define LOG 1
#endif
#include <stdio.h>
#include <stdlib.h>

static int fail = 0;
#define ok(expr, ...)                                                   \
  do {                                                                  \
    if (expr)                                                           \
      {                                                                 \
        if (#__VA_ARGS__[0])                                            \
          printf ("ok - %s\n", "" __VA_ARGS__);                         \
        else                                                            \
          printf ("ok\n");                                              \
      }                                                                 \
    else                                                                \
      {                                                                 \
        fail++;                                                         \
        if (#__VA_ARGS__[0])                                            \
          printf ("not ok - %s:%d: (%s) %s failed - %s\n",              \
                  __FILE__, __LINE__, __FUNCTION__, # expr, "" __VA_ARGS__); \
        else                                                            \
          printf ("not ok - %s:%d: (%s) %s failed\n",                   \
                  __FILE__, __LINE__, __FUNCTION__, # expr);            \
      }                                                                 \
  } while(0)

#define fail(...)                                                       \
  do {                                                                  \
    fail++;                                                           \
    if (#__VA_ARGS__[0])                                                \
      printf ("not ok - %s:%d (%s) - %s\n",                             \
              __FILE__, __LINE__, __FUNCTION__, "" __VA_ARGS__);        \
    else                                                                \
      printf ("not ok - %s:%d (%s)\n",                                  \
              __FILE__, __LINE__, __FUNCTION__);                        \
  } while(0)

#define pass(...)  do { ok(1, __VA_ARGS__); } while(0)
#define exit_status() do {                                              \
  if (fail == 0)                                                        \
  {                                                                     \
    return (0);                                                         \
  }                                                                     \
  return (fail);                                                        \
  } while(0)
# define diag(fmt, ...) do {                                            \
  if (LOG == 1)                                                         \
    printf("# " fmt "\n", __VA_ARGS__);                                 \
  else                                                                  \
    (void)0;                                                            \
  } while(0)
#endif
