#include <stdio.h>
#include <stdbool.h>

int **REC;
int AVGAREA=0;
int AVGCount=0;
int findConnectedComponent(unsigned char *thresholdData, int x, int y, int w, int h, int *area,int *cx, int *cy)
{

  if (!(*(thresholdData + (x * w) + y)))
    return 0;
  *(thresholdData + (x * w) + y) = 0;
  *area=*area+1;
  *cx +=x;
  *cy +=y;
  for (int i = x - 1; i <= x + 1; i++) {
    if (i < 0 || i >= h) continue;
    for (int j = y - 1; j <= y + 1; j++) {
      if (j < 0 || j >= w) continue;
      if (*(thresholdData + (i * w) + j)) {
        findConnectedComponent(thresholdData, i, j, w, h,area,cx,cy);
      }
    }
  }
}

int LargestConnectedComponent(unsigned char *thresholdData, int x, int y, int w, int h, int *area2,int Pos,int x1,int y1)
{
  
		int area=0,cx=0,cy=0;
	for(int i=x-25;i<x+25;i++)
	{
		if(*(thresholdData + (i * w) + y))
		{
			area=0,cx=0,cy=0;
			findConnectedComponent(thresholdData, i, y, w, h,&area,&cx,&cy);
			if(AVGAREA==0)
			{AVGAREA=area;AVGCount++;}
			if(area>(AVGAREA*.7))
			{
				REC[Pos][0] = Pos;
        	        	REC[Pos][1] = y1+(cy/area);
                		REC[Pos][2] = x1+(cx/area);
                		REC[Pos][3] = area;
				long int avg = AVGAREA*AVGCount + area;
				AVGCount++;
				AVGAREA = avg/AVGCount;
				*area2= area;
				return 0;
			}
		}
	}
	int largeArea=0;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (*(thresholdData + (i * w) + j)) 
	{
		area=0,cx=0,cy=0;
		findConnectedComponent(thresholdData, i, y, w, h,&area,&cx,&cy);
        	if (area > largeArea)
		{
			findConnectedComponent(thresholdData, i, y, w, h,&area,&cx,&cy);
			if(AVGAREA==0)
			{AVGAREA=area;AVGCount++;}
			if(area>(AVGAREA*.7))
			{
				REC[Pos][0] = Pos;
        	        	REC[Pos][1] = y1+(cy/area);
                		REC[Pos][2] = x1+(cx/area);
                		REC[Pos][3] = area;
				long int avg = AVGAREA*AVGCount + area;
				AVGCount++;
				AVGAREA = avg/AVGCount;
			}
			largeArea = area;
		}		
	}
	}
	}
	long int avg = ((long int)AVGAREA)*AVGCount + area;
        AVGCount++;
        AVGAREA = avg/AVGCount;
	*area2=area;
	return 0;
	
}

