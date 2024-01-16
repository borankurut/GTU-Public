#if !defined SELECT_SORT_HEAD
#define SELECT_SORT_HEAD

/*
*   select_sort_lib.h
*   this library includes function for select sorting an integer array.
*/

/*  select sorts given array                                        */
extern void select_sort(int arr[], int n);


/*  return the minimum number inside the low_ix, high_ix range.     */
extern int select_sort_lib_min_ix_range(int arr[], int low_ix, int high_ix);

#endif