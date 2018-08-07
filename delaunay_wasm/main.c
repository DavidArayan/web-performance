/*   Author: Geoff Leach, Department of Computer Science, RMIT.
 *   email: gl@cs.rmit.edu.au
 *
 *   Date: 6/10/93
 *
 *   Version 1.0
 *   
 *   Copyright (c) RMIT 1993. All rights reserved.
 *
 *   License to copy and use this software purposes is granted provided 
 *   that appropriate credit is given to both RMIT and the author.
 *
 *   License is also granted to make and use derivative works provided
 *   that appropriate credit is given to both RMIT and the author.
 *
 *   RMIT makes no representations concerning either the merchantability 
 *   of this software or the suitability of this software for any particular 
 *   purpose.  It is provided "as is" without express or implied warranty 
 *   of any kind.
 *
 *   These notices must be retained in any copies of any part of this software.
 */

#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#endif

#include  <stdio.h>
#include  <stdlib.h>
#define BSD
#define TIME
#ifdef TIME
#ifdef BSD
#include        <sys/time.h>
#include        <sys/resource.h>
#endif
#ifdef SYSV
#include        <sys/types.h>
#include        <sys/times.h>
#include        <sys/param.h>
#endif
#endif


#include  "defs.h"
#include  "decl.h"
#include  "extern.h"
#include  "edge.h"

extern "C" {
  static void triangulate(char exp, int rep, cardinal n, char *params);

  int main(int argc, char** argv)
  {
    printf("Running Program!\n");
    int i, rep_no, n_reps;
    cardinal n;
    char exp;
    char *p;

    for (i = 1; i < argc; i++)
    {
      mystod(&argv[i][0], &n_reps, &p);
      if (n_reps == 0)
        n_reps = 1;
      exp = *p;
      mystod(++p, (int *)&n, &p);

  #ifdef TIME
      printf("Experiment %c, %d points params %s\n", exp, n, p);
  #endif

      for (rep_no = 0; rep_no < n_reps; rep_no++)
        triangulate(exp, rep_no, n, p);
    }

    printf("Finishing Program!\n");
    return 0;
  }


  static void triangulate(char exp, int rep, cardinal n, char *params)
  {
    edge *l_cw, *r_ccw;
    uindex i;
    point **p_sorted, **p_temp;
  #ifdef TIME
  #ifdef BSD
    struct rusage r_s, r_f;
    getrusage(RUSAGE_SELF, &r_s);
  #endif
  #ifdef SYSV
    struct tms t_s, t_f;
    times(&t_s);
  #endif
  #endif

    alloc_memory(n);

    get_points(exp, rep, n, params);

  #ifdef TIME
  #ifdef BSD
    getrusage(RUSAGE_SELF, &r_f);
    printf("utime %ld %ld stime %ld %ld \n", 
           r_f.ru_utime.tv_sec-r_s.ru_utime.tv_sec,
           r_f.ru_utime.tv_usec-r_s.ru_utime.tv_usec,
           r_f.ru_stime.tv_sec-r_s.ru_stime.tv_sec,
           r_f.ru_stime.tv_usec-r_s.ru_stime.tv_usec);
    r_s = r_f;
  #endif
  #ifdef SYSV
    times(&t_f);
    printf("utime %ld stime %ld\n", 
     (t_f.tms_utime-t_s.tms_utime)/CLK_TCK,
     (t_f.tms_stime-t_s.tms_stime)/CLK_TCK);
    t_s = t_f;
  #endif
  #endif
    
    /* Initialise entry edge pointers. */
    for (i = 0; i < n; i++)
      p_array[i].entry_pt = NULL;

    /* Sort. */
    p_sorted = (point **)malloc((unsigned)n*sizeof(point *));
    if (p_sorted == NULL)
      panic("triangulate: not enough memory\n");
  #if 0  
    p_temp = (point **)malloc((unsigned)n*sizeof(point *));
    if (p_temp == NULL)
      panic("triangulate: not enough memory\n");
  #endif

    #if 0
    for (i = 0; i < n; i++)
      p_sorted[i] = p_array + i;
    #endif

    std_sort(p_array, 0, n-1);
    for (i = 0; i < n; i++) 
      p_sorted[i] = p_array + i;

  #if 0
    merge_sort(p_sorted, p_temp, 0, n-1);

    free((char *)p_temp);
  #endif

  #ifdef TIME
  #ifdef BSD
    getrusage(RUSAGE_SELF, &r_f);
    printf("utime %ld %ld stime %ld %ld \n", 
           r_f.ru_utime.tv_sec-r_s.ru_utime.tv_sec,
           r_f.ru_utime.tv_usec-r_s.ru_utime.tv_usec,
           r_f.ru_stime.tv_sec-r_s.ru_stime.tv_sec,
           r_f.ru_stime.tv_usec-r_s.ru_stime.tv_usec);
    r_s = r_f;
  #endif
  #ifdef SYSV
    times(&t_f);
    printf("utime %ld stime %ld\n", 
     (t_f.tms_utime-t_s.tms_utime)/CLK_TCK,
     (t_f.tms_stime-t_s.tms_stime)/CLK_TCK);
    t_s = t_f;
  #endif
  #endif
    

    /* Triangulate. */
    divide(p_sorted, 0, n-1, &l_cw, &r_ccw);

  #ifdef TIME
  #ifdef BSD
    getrusage(RUSAGE_SELF, &r_f);
    printf("utime %ld %ld stime %ld %ld \n", 
           r_f.ru_utime.tv_sec-r_s.ru_utime.tv_sec,
           r_f.ru_utime.tv_usec-r_s.ru_utime.tv_usec,
           r_f.ru_stime.tv_sec-r_s.ru_stime.tv_sec,
           r_f.ru_stime.tv_usec-r_s.ru_stime.tv_usec);
    r_s = r_f;
  #endif
  #ifdef SYSV
    times(&t_f);
    printf("utime %ld stime %ld\n", 
     (t_f.tms_utime-t_s.tms_utime)/CLK_TCK,
     (t_f.tms_stime-t_s.tms_stime)/CLK_TCK);
    t_s = t_f;
  #endif
  #endif
    
  #define OUTPUT
  #undef OUTPUT
  #ifdef OUTPUT
    print_results(n, 'e');
  #endif

  #ifdef TIME
  #ifdef BSD
    getrusage(RUSAGE_SELF, &r_f);
    printf("utime %ld %ld stime %ld %ld \n", 
           r_f.ru_utime.tv_sec-r_s.ru_utime.tv_sec,
           r_f.ru_utime.tv_usec-r_s.ru_utime.tv_usec,
           r_f.ru_stime.tv_sec-r_s.ru_stime.tv_sec,
           r_f.ru_stime.tv_usec-r_s.ru_stime.tv_usec);
    r_s = r_f;
  #endif
  #ifdef SYSV
    times(&t_f);
    printf("utime %ld stime %ld\n", 
     (t_f.tms_utime-t_s.tms_utime)/CLK_TCK,
     (t_f.tms_stime-t_s.tms_stime)/CLK_TCK);
    t_s = t_f;
  #endif
  #endif
    
    free((char *)p_sorted);
    free_memory();

  #ifdef TIME
  #ifdef BSD
    getrusage(RUSAGE_SELF, &r_f);
    printf("utime %ld %ld stime %ld %ld \n", 
           r_f.ru_utime.tv_sec,
           r_f.ru_utime.tv_usec,
           r_f.ru_stime.tv_sec,
           r_f.ru_stime.tv_usec);
    r_s = r_f;
  #endif
  #ifdef SYSV
    times(&t_f);
    printf("utime %ld stime %ld\n", 
           (t_f.tms_utime)/CLK_TCK,
           (t_f.tms_stime)/CLK_TCK);
    t_s = t_f;
  #endif
  #endif

    exit(EXIT_SUCCESS);
  }
}