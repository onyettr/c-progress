#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int barlength = 60;
static char bar[10];

void c_progress(char label[], int step, int total)
{
  int width = barlength - strlen(label);
  int pos = (step * width) / total;
  int percent;
  int i;

  percent = (step * 100) / total;

  printf("%s [", label);
  for (i=0; i < pos; i++)
  {
    printf("%c", '#');
  }
  // printf("% *c", width - pos + 1, ']');
  
  printf("] %d%% \r", percent);
  fflush(stdout);  
}

int main ( void )
{
  int i;
  
  memset(bar, '-', barlength);
  bar[barlength-1] = '\0';

  for (i=0; i < 100; i++)
  {
    c_progress("Test", i, 100);
    for(int j=0; j < 100000000; j++);
  }
}
