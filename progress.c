#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BAR_WIDTH       80

void PrintProgressBar(int CurrSize, int MaxSize)
{
    static char ProgressBar[BAR_WIDTH+1];
    static char OutputStr[BAR_WIDTH*2];    
    int Progress;
    int HashCount;

    memset(OutputStr, ' ', sizeof(OutputStr));    
    memset(ProgressBar, ' ', sizeof(ProgressBar));
    ProgressBar[BAR_WIDTH] = ']';
    ProgressBar[BAR_WIDTH+1]   = '\0';        
    OutputStr[BAR_WIDTH] = '\0';
      
    if (MaxSize <= 0)
    {
      printf("\n");

      return;
    }

    Progress  = (int)((CurrSize / (float)(MaxSize)) * 100);

    HashCount = (CurrSize * BAR_WIDTH) / MaxSize; 

    ProgressBar[0] = '[';

    for (int i=1; i < HashCount; i++)    
    {
      ProgressBar[i] = '#';
    }

    sprintf(OutputStr,"%s %3d%%: %6d/%6d Blocks", ProgressBar, Progress, CurrSize, MaxSize);
    printf("%s", OutputStr);

    for(int i=0; i < sizeof(OutputStr); i++)
    {
      printf("\b");
    }
    (void)fflush(stdout);

    if (Progress >= 100)
    {
      printf("\n");
    }
}

int main ( void )
{
  int i;

  for (i=0; i <= 13967; i++)
  {
    PrintProgressBar(i,13967);
    for(int j=0; j < 100000; j++);    // Fake delay()
  }

  for (i=0; i <= 900; i++)
  {
    PrintProgressBar(i,900);
    for(int j=0; j < 100000; j++);    // Fake delay()
  }
  
  for (i=0; i <= 50; i++)
  {
    PrintProgressBar(i,50);
    for(int j=0; j < 100000000; j++);    // Fake delay()
  }
  
  for (i=0; i <= 10; i++)
  {
    PrintProgressBar(i,10);
    for(int j=0; j < 100000000; j++);    // Fake delay()
  }

  for (i=0; i <= 4; i++)
  {
    PrintProgressBar(i,4);
    for(int j=0; j < 100000000; j++);    // Fake delay()
  }

  for (i=0; i <= 100; i++)
  {
    PrintProgressBar(i,100);
    for(int j=0; j < 10000000; j++);    // Fake delay()
  }
  
  for (i=0; i <= 200; i++)
  {
    PrintProgressBar(i,200);
    for(int j=0; j < 10000; j++);    // Fake delay()
  }
}
