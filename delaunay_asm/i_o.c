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

#include  <stdio.h>
#include  <stdlib.h>

#include  "defs.h"
#include  "decl.h"
#include  "extern.h"
#include  "edge.h"

#define  MAX_RANDOM  RAND_MAX
#define PI  3.14159265358979323846


static void print_edges(cardinal n);
static void print_triangles(cardinal n);

static void get_unit_square_points(cardinal np);
static void read_points(cardinal np);

int seeds[10] = {
  17,  
  190813,
  21,
  23491,
  901712,
  6712827,
  8776190,
  910129,
  232875,
  1109117,
};

void get_points(char exp, int rep, cardinal np, char *params)
{
  srandom(seeds[rep]);

  switch (exp) {
  case 'a' :
    get_unit_square_points(np);
    break;
  case 'r' :
    read_points(np);
    break;
  default :
    printf("Unknown experiment\n");
    exit(1);
  }
}

static void get_unit_square_points(cardinal np)
{
  index i;
  point p;

  for (i = 0; i < np; i++)
  {
    p.x = (ordinate)random() / MAX_RANDOM;
    p.y = (ordinate)random() / MAX_RANDOM;

    p_array[i].x = p.x;
    p_array[i].y = p.y;
  }
}

void read_points(cardinal np)
{
  index i;

  for (i = 0; i < np; i++)
    if (scanf("%f %f", &p_array[i].x, &p_array[i].y) != 2)
	panic("Error reading points\n");
}

/*
 * Driver function.
 */
void print_results(cardinal n, char o)
{
  /* Output edges or triangles. */
  if (o == 't')
    print_triangles(n);
  else
    print_edges(n);
}

/* 
 *  Print the ring of edges about each vertex.
 */
static void print_edges(cardinal n)
{
  edge *e_start, *e;
  point *u, *v;
  index i;

  for (i = 0; i < n; i++) {
    u = &p_array[i];
    e_start = e = u->entry_pt;
    do
    {
      v = Other_point(e, u);
      if (u < v)
	if (printf("%ld %ld\n", u - p_array, v - p_array) == EOF)
	  panic("Error printing results\n");
      e = Next(e, u);
    } while (!Identical_refs(e, e_start));
  }
}

/* 
 *  Print the ring of triangles about each vertex.
 */
static void print_triangles(cardinal n)
{
  edge *e_start, *e, *next;
  point *u, *v, *w;
  index i;
  point *t;

  for (i = 0; i < n; i++) {
    u = &p_array[i];
    e_start = e = u->entry_pt;
    do
    {
      v = Other_point(e, u);
      if (u < v) {
	next = Next(e, u);
	w = Other_point(next, u);
	if (u < w)
	  if (Identical_refs(Next(next, w), Prev(e, v))) {  
	    /* Triangle. */
	    if (v > w) { t = v; v = w; w = t; }
	    if (printf("%ld %ld %ld\n", u - p_array, v - p_array, w - p_array) == EOF)
	      panic("Error printing results\n");
	  }
      }

      /* Next edge around u. */
      e = Next(e, u);
    } while (!Identical_refs(e, e_start));
  }
}

void mystod(char *s, int *v, char **p)
{
        int i, n;

        n = 0;
        for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
                n = 10 * n + s[i] - '0';

        *p = s + i;
        *v = n;
}

void mystrtof(char *s, real *v, char **p)
{
        int i;
  real n;

        n = 0;
        for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
                n = 10 * n + s[i] - '0';

        *p = s + i;
        *v = n;
}
