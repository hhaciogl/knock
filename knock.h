/* knock.h -- simplistic Knock generator.  */

#ifndef HEADER_KNOCK_H
#define HEADER_KNOCK_H


#include <stdio.h>
#include <stdlib.h>

static fail = 0;
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
        fail = 1;                                                       \
        if (#__VA_ARGS__[0])                                            \
          printf ("not ok - %s:%d: (%s) %s failed - %s\n",              \
                  __FILE__, __LINE__, __FUNCTION__, # expr, "" __VA_ARGS__); \
        else                                                            \
          printf ("not ok - %s:%d: (%s) %s failed\n",                   \
                  __FILE__, __LINE__, __FUNCTION__, # expr);            \
      }                                                                 \
  } while(0)

#define fail(...)                                                       \
  do {                                                                   \  
    fail = 1;                                                               \
    if (#__VA_ARGS__[0])                                                \
      printf ("not ok - %s:%d (%s) - %s\n",                             \
              __FILE__, __LINE__, __FUNCTION__, "" __VA_ARGS__);        \
    else                                                                \
      printf ("not ok - %s:%d (%s)\n",                                  \
              __FILE__, __LINE__, __FUNCTION__);                        \
  } while(0)

#define pass(...)  do { ok(1, __VA_ARGS__); } while(0)
#define diag(fmt, args...)  do { printf ("# " fmt "\n" , ##args); } while(0)
#define exit_status() do { fail == 0 ? return (0); : return (1); } while(0)
#endif /* !defined HEADER_KNOCK_H */
