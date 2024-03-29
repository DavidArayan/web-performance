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

#include <algorithm>
#include "defs.h"
#include "decl.h"

#ifdef __cplusplus
	extern "C" {
#endif

  void merge_sort(point *p[], point *p_temp[], uindex l, uindex r)
  {
	uindex i, j, k, m;

	if (r - l > 0)
	{
	  m = (r + l) / 2;
	  merge_sort(p, p_temp, l, m);
	  merge_sort(p, p_temp, m+1, r);

	  for (i = m+1; i > l; i--)
		p_temp[i-1] = p[i-1];
	  for (j = m; j < r; j++)
		p_temp[r+m-j] = p[j+1];
	  for (k = l; k <= r; k++)
		if (p_temp[i]->x < p_temp[j]->x) {
		  p[k] = p_temp[i];
		  i = i + 1;
		} else if (p_temp[i]->x == p_temp[j]->x && p_temp[i]->y < p_temp[j]->y) {
		  p[k] = p_temp[i];
		  i = i + 1;
		} else {
		  p[k] = p_temp[j];
		  j = j - 1;
		}
	}
  }

  bool cmp(const point &p1, const point &p2)
  {
	if (p1.x < p2.x)
	  return true;
	else if (p1.x > p2.x)
	  return false;
	else if (p1.y < p2.y)
	  return true;
	else
	  return false;
  }

  bool cmp_ptr(const point *p1, const point *p2)
  {
	if (p1->x < p2->x)
	  return true;
	else if (p1->x > p2->x)
	  return false;
	else if (p1->y < p2->y)
	  return true;
	else
	  return false;
  }

void std_sort(point p[], uindex l, uindex r)
{
  std::sort(&p[l], &p[r+1], cmp);
}

void std_sort_ptr(point *p[], uindex l, uindex r)
{
  std::sort(&p[l], &p[r+1], cmp_ptr);
}

#ifdef __cplusplus
	}
#endif