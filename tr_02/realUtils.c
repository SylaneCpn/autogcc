//----------------------------------------------------------------------------

#include "realUtils.h"
#include <stdio.h>
#include <float.h>

void
Real_swap(double *inout_a,
          double *inout_b)
{
  //-- load inout-parameters --
  double a=*inout_a;
  double b=*inout_b;
  //-- store out-parameters --
  *inout_a=b;
  *inout_b=a;
}

void
Real_normalise(double *inout_a,
               double *inout_b)
{
  //-- load inout-parameters --
  double a=*inout_a;
  double b=*inout_b;
  //-- perform work --
  double factor=1.0/(a+b);
  a*=factor;
  b*=factor;
  //-- store out-parameters --
  *inout_a=a;
  *inout_b=b;
}

void
RealArray_show(const double *content,
               int count)
{
  printf("[ ");
  for(int i=0; i<count; ++i)
  {
    if(i!=0)
    {
      printf(", ");
    }
    printf("%g", content[i]);
  }
  printf(" ]");
}

double
RealArray_mean(const double *content,
               int count)
{
  double sum=0.0;
  for(int i=0; i<count; ++i)
  {
    sum+=content[i];
  }
  return sum/count;
}

void
RealArray_reverse(double *content,
                  int count)
{
  int mid=count/2;
  for(int i=0; i<mid; ++i)
  {
    Real_swap(content+i, content+count-1-i);
  }
}

void
RealArray_copy(double *destination,
               const double *source,
               int count)
{
  for(int i=0; i<count; ++i)
  {
    destination[i]=source[i];
  }
}

void
RealArray_reverseCopy(double *destination,
                      const double *source,
                      int count)
{
  for(int i=0; i<count; ++i)
  {
    destination[count-1-i]=source[i];
  }
}

void
RealArray_min(const double *content,
              int count,
              double *out_value,
              int *out_index)
{
  double minValue=content[0];
  int minIndex=0;
  for(int i=1; i<count; ++i)
  {
    double value=content[i];
    if(value<minValue)
    {
      minValue=value;
      minIndex=i;
    }
  }
  //-- store out-parameters --
  *out_value=minValue;
  *out_index=minIndex;
}

void
RealArray_max(const double *content,
              int count,
              double *out_value,
              int *out_index)
{
  double maxValue=content[0];
  int maxIndex=0;
  for(int i=1; i<count; ++i)
  {
    double value=content[i];
    if(value>maxValue)
    {
      maxValue=value;
      maxIndex=i;
    }
  }
  //-- store out-parameters --
  *out_value=maxValue;
  *out_index=maxIndex;
}

void
RealArray_ascendingSort(double *content,
                        int count)
{
  for(int i=0; i<count; ++i)
  {
    double value;
    int index;
    RealArray_min(content+i, count-i, &value, &index);
    if(index)
    {
      Real_swap(content+i, content+i+index);
    }
  }
}

void
RealArray_descendingSort(double *content,
                         int count)
{
  for(int i=0; i<count; ++i)
  {
    double value;
    int index;
    RealArray_max(content+i, count-i, &value, &index);
    if(index)
    {
      Real_swap(content+i, content+i+index);
    }
  }
}

//----------------------------------------------------------------------------