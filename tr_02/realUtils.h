//----------------------------------------------------------------------------

#ifndef REALUTILS_H
#define REALUTILS_H

#include <stdbool.h>

void
Real_swap(double *inout_a,
          double *inout_b);

void
Real_normalise(double *inout_a,
               double *inout_b);

void
RealArray_show(const double *content,
               int count);

double
RealArray_mean(const double *content,
               int count);

void
RealArray_reverse(double *content,
                  int count);

void
RealArray_copy(double *destination,
               const double *source,
               int count);

void
RealArray_reverseCopy(double *destination,
                      const double *source,
                      int count);

void
RealArray_min(const double *content,
              int count,
              double *out_value,
              int *out_index);

void
RealArray_max(const double *content,
              int count,
              double *out_value,
              int *out_index);

void
RealArray_ascendingSort(double *content,
                        int count);

void
RealArray_descendingSort(double *content,
                         int count);

#endif // REALUTILS_H

//----------------------------------------------------------------------------