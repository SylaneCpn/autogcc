//----------------------------------------------------------------------------

#include <stdio.h>
#include "realUtils.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "strUtils.h"

void
test_Real_swap(void)
{
  printf("\n~~~~ %s() ~~~~\n", __func__);
  double a=1.1, b=2.2;
  printf("before: a=%g b=%g\n", a, b);
  Real_swap(&a, &b);
  printf("after: a=%g b=%g\n", a, b);
}

void
test_Real_normalise(void)
{
  printf("\n~~~~ %s() ~~~~\n", __func__);
  double a=1.5, b=4.5;
  printf("before: a=%g b=%g\n", a, b);
  Real_normalise(&a, &b);
  printf("after: a=%g b=%g\n", a, b);
}

void
test_RealArray_show(void)
{
  printf("\n~~~~ %s() ~~~~\n", __func__);
  double values[]={0.0, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9};
  int count=(int)(sizeof(values)/sizeof(values[0]));
  printf("values: ");
  RealArray_show(values, count);
  printf("\n");
}

void
test_RealArray_mean(void)
{
  printf("\n~~~~ %s() ~~~~\n", __func__);
  double values[]={0.0, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9};
  int count=(int)(sizeof(values)/sizeof(values[0]));
  printf("values: ");
  RealArray_show(values, count);
  printf("\n");
  printf("mean: %g\n", RealArray_mean(values, count));
}

void
test_RealArray_reverse(void)
{
  printf("\n~~~~ %s() ~~~~\n", __func__);
  double values[]={0.0, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9};
  int count=(int)(sizeof(values)/sizeof(values[0]));
  printf("before: ");
  RealArray_show(values, count);
  printf("\n");
  RealArray_reverse(values, count);
  printf("after: ");
  RealArray_show(values, count);
  printf("\n");
}

void
test_RealArray_copy(void)
{
  printf("\n~~~~ %s() ~~~~\n", __func__);
  double values1[10]={0.0, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9};
  double values2[10];
  int count=(int)(sizeof(values1)/sizeof(values1[0]));
  printf("values1: ");
  RealArray_show(values1, count);
  printf("\n");
  RealArray_copy(values2, values1, count);
  printf("values2: ");
  RealArray_show(values2, count);
  printf("\n");
}

void
test_RealArray_reverseCopy(void)
{
  printf("\n~~~~ %s() ~~~~\n", __func__);
  double values1[10]={0.0, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9};
  double values2[10];
  int count=(int)(sizeof(values1)/sizeof(values1[0]));
  printf("values1: ");
  RealArray_show(values1, count);
  printf("\n");
  RealArray_reverseCopy(values2, values1, count);
  printf("values2: ");
  RealArray_show(values2, count);
  printf("\n");
}

void
test_RealArray_min(void)
{
  printf("\n~~~~ %s() ~~~~\n", __func__);
  double values[]={8.8, 5.5, 0.0, 3.3, 7.7, 4.4, 1.1, 9.9, 2.2, 6.6};
  int count=(int)(sizeof(values)/sizeof(values[0]));
  printf("values: ");
  RealArray_show(values, count);
  printf("\n");
  double minValue;
  int minIndex;
  RealArray_min(values, count, &minValue, &minIndex);
  printf("min: %g at index %d\n", minValue, minIndex);
}

void
test_RealArray_max(void)
{
  printf("\n~~~~ %s() ~~~~\n", __func__);
  double values[]={8.8, 5.5, 0.0, 3.3, 7.7, 4.4, 1.1, 9.9, 2.2, 6.6};
  int count=(int)(sizeof(values)/sizeof(values[0]));
  printf("values: ");
  RealArray_show(values, count);
  printf("\n");
  double maxValue;
  int maxIndex;
  RealArray_max(values, count, &maxValue, &maxIndex);
  printf("max: %g at index %d\n", maxValue, maxIndex);
}

void
test_RealArray_ascendingSort(void)
{
  printf("\n~~~~ %s() ~~~~\n", __func__);
  double values[]={8.8, 5.5, 0.0, 3.3, 7.7, 4.4, 1.1, 9.9, 2.2, 6.6};
  int count=(int)(sizeof(values)/sizeof(values[0]));
  printf("before: ");
  RealArray_show(values, count);
  printf("\n");
  RealArray_ascendingSort(values, count);
  printf("after: ");
  RealArray_show(values, count);
  printf("\n");
}

void
test_RealArray_descendingSort(void)
{
  printf("\n~~~~ %s() ~~~~\n", __func__);
  double values[]={8.8, 5.5, 0.0, 3.3, 7.7, 4.4, 1.1, 9.9, 2.2, 6.6};
  int count=(int)(sizeof(values)/sizeof(values[0]));
  printf("before: ");
  RealArray_show(values, count);
  printf("\n");
  RealArray_descendingSort(values, count);
  printf("after: ");
  RealArray_show(values, count);
  printf("\n");
}

void
test_Str_upper(void)
{
  printf("\n~~~~ %s() ~~~~\n", __func__);
  char msg[]="This message is _REALLY_ useful! Isn't it?";
  printf("before: <%s>\n", msg);
  Str_upper(msg);
  printf("after: <%s>\n", msg);
}

void
test_Str_lower(void)
{
  printf("\n~~~~ %s() ~~~~\n", __func__);
  char msg[]="This message is _REALLY_ useful! Isn't it?";
  printf("before: <%s>\n", msg);
  Str_lower(msg);
  printf("after: <%s>\n", msg);
}

void
test_Str_repeat(void)
{
  printf("\n~~~~ %s() ~~~~\n", __func__);
  char *str=Str_repeat('*', 16);
  printf("result: <%s>\n", str);
  if(strcmp(str, "****************")==0)
  {
    printf("match\n");
  }
  else
  {
    printf("mistmatch!\n");
  }
  free(str);
}

void
test_Str_create(void)
{
  printf("\n~~~~ %s() ~~~~\n", __func__);
  const char *msg="Is it the same?";
  printf("original: <%s>\n", msg);
  char *str=Str_create(msg, -1);
  printf("copy: <%s>\n", str);
  if(strcmp(str, msg)==0)
  {
    printf("match\n");
  }
  else
  {
    printf("mistmatch!\n");
  }
  free(str);
}

void
test_Str_add(void)
{
  printf("\n~~~~ %s() ~~~~\n", __func__);
  const char *msg1="It starts like this... ";
  const char *msg2="Then it ends like that!";
  printf("original: <%s> <%s>\n", msg1, msg2);
  char *msg=Str_add(msg1, msg2);
  printf("copy: <%s>\n", msg);
  if((strncmp(msg, msg1, strlen(msg1))==0)&& // starts with msg1?
     (strcmp(msg+strlen(msg1), msg2)==0))    // ends with msg2?
  {
    printf("match\n");
  }
  else
  {
    printf("mistmatch!\n");
  }
  free(msg);
}

void
test_Str_append(void)
{
  printf("\n~~~~ %s() ~~~~\n", __func__);
  const char *msg1="It starts like this... ";
  const char *msg2="Then it ends like that!";
  printf("original: <%s> <%s>\n", msg1, msg2);
  char *msg=Str_create(msg1, -1);
  Str_append(&msg, msg2);
  printf("copy: <%s>\n", msg);
  if((strncmp(msg, msg1, strlen(msg1))==0)&& // starts with msg1?
     (strcmp(msg+strlen(msg1), msg2)==0))    // ends with msg2?
  {
    printf("match\n");
  }
  else
  {
    printf("mistmatch!\n");
  }
  free(msg);
}

void
test_Str_findWord(void)
{
  printf("\n~~~~ %s() ~~~~\n", __func__);
  const char *longText=
    " I am the passenger and I ride and I ride \n"
    " I ride through the city's backsides      \n"
    " I see the stars come out of the sky      \n"
    " Yeah, the bright and hollow sky          \n"
    " You know it looks so good tonight        \n"
    "                                          \n"
    " I am the passenger                       \n"
    " I stay under glass                       \n"
    " I look through my window so bright       \n"
    " I see the stars come out tonight         \n"
    " I see the bright and hollow sky          \n"
    " Over the city's ripped backsides         \n"
    " And everything looks good tonight        \n"
    " Singing la la la la la.. lala la la,     \n"
    " la la la la.. lala la la etc             \n"
    "                                          \n"
    " Get into the car                         \n"
    " We'll be the passenger                   \n"
    " We'll ride through the city tonight      \n"
    " We'll see the city's ripped backsides    \n"
    " We'll see the bright and hollow sky      \n"
    " We'll see the stars that shine so bright \n"
    " Stars made for us tonight                \n"
    "                                          \n"
    " Oh, the passenger                        \n"
    " How, how he rides                        \n"
    " Oh, the passenger                        \n"
    " He rides and he rides                    \n"
    " He looks through his window              \n"
    " What does he see?                        \n"
    " He sees the sign and hollow sky          \n"
    " He sees the stars come out tonight       \n"
    " He sees the city's ripped backsides      \n"
    " He sees the winding ocean drive          \n"
    " And everything was made for you and me   \n"
    " All of it was made for you and me        \n"
    " 'Cause it just belongs to you and me     \n"
    " So let's take a ride and see what's mine \n"
    " Singing la la la la la.. lala la la,     \n"
    " la la la la.. lala la la etc             \n"
    "                                          \n"
    " Oh the passenger                         \n"
    " He rides and he rides                    \n"
    " He sees things from under glass          \n"
    " He looks through his window side         \n"
    " He sees the things that he knows are his \n"
    " He sees the bright and hollow sky        \n"
    " He sees the city sleep at night          \n"
    " He sees the stars are out tonight        \n"
    " And all of it is yours and mine          \n"
    " And all of it is yours and mine          \n"
    " So let's ride and ride and ride and ride \n"
    " Oh, oh, Singing la la la la lalalala     \n";
  int wordCount=0;
  for(int begin, length;
      Str_findWord(longText, &begin, &length);
      longText+=begin+length)
  {
    char *str=Str_create(longText+begin, length);
    ++wordCount;
    printf("<%s> ", str);
    free(str);
  }
  printf("\n%d words\n", wordCount);
}

int
main(void)
{
  test_Real_swap();
  test_Real_normalise();
  test_RealArray_show();
  test_RealArray_mean();
  test_RealArray_reverse();
  test_RealArray_copy();
  test_RealArray_reverseCopy();
  test_RealArray_min();
  test_RealArray_max();
  test_RealArray_ascendingSort();
  test_RealArray_descendingSort();
  test_Str_upper();
  test_Str_lower();
  test_Str_repeat();
  test_Str_create();
  test_Str_add();
  test_Str_append();
  test_Str_findWord();
  return 0;
}

//----------------------------------------------------------------------------