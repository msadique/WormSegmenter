#include <stdio.h>
#include <stdbool.h>

int **REC;
int AVGAREA=0;
int AVGCount=0;
int findConnectedComponent( unsigned char *thresholdData, int x, 	
								int y, int w, int h, int *area,int *cx, int *cy)
{
	if ( ! (*(thresholdData + (x * w) + y)))  //Check if Threshold value present or not
		return 0;
	*(thresholdData + (x * w) + y) = 0; 		//if threadhold value present change into zero 
	*area=*area+1;							// calculate area and Centroid
	*cx +=x;
	*cy +=y;
	for (int i = x - 1; i <= x + 1; i++) 
	{     // check surrounding pixel  in x and y cordinate
		if (i < 0 || i >= h) continue;
		for (int j = y - 1; j <= y + 1; j++) 
		{
			if (j < 0 || j >= w) continue;
			if (*(thresholdData + (i * w) + j)) 
			{
		       findConnectedComponent(thresholdData, i, j, w, h,area,cx,cy);  // if surrounding pixel contains threshold value then Call this function recursively 
			}
		}
	}
	return 0;
}

int LargestConnectedComponent(unsigned char *thresholdData, int x, int y, 
						int w, int h, int *area2,int Pos,int x1,int y1)
{
  
		int area=0,cx=0,cy=0;
		int s1=x-25<0?0:x-25;
		int s2=x+25>h?h:x+25;
	for(int i=s1;i<s2;i++)   // Centroid is calculate during Threshold value calculation based on that value largest component is calculated.
	{
		if(*(thresholdData + (i * w) + y))
		{
			area=0,cx=0,cy=0;
			findConnectedComponent(thresholdData, i, y, w, h,&area,&cx,&cy);  
			if(	AVGAREA	==	0	)
			{
				AVGAREA=area;
				AVGCount++;
			}
			if(area>(AVGAREA*.7)) // largest component is larger than 70% avg value then save records 
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
	}						// if small section wont find largest component then it will check complete window for largest component
	int largeArea=0;
	for (int i = 0; i < h; i++) 
	{
		for (int j = 0; j < w; j++) 
		{
			if (*(thresholdData + (i * w) + j)) 
			{
				area=0,cx=0,cy=0;
				findConnectedComponent(thresholdData, i, y, w, h,&area,&cx,&cy);
				if (area > largeArea)
				{
					findConnectedComponent(thresholdData, i, y, w, h,&area,&cx,&cy);
					if( AVGAREA==0 )
					{
						AVGAREA=area;
						AVGCount++;
					}
					if( area > ( AVGAREA * .7 )) // largest component is larger than 70% avg value then save records
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

