#define NANOSECOND 1000000000
#define PR 1
int MAXAREA=0;
int GX =0;
int GY =0;


int **REC;
int BlurImage(unsigned char *img_data, int w, int h, unsigned char *blur, int Pos, int x1, int y1);
void ProcessImage(unsigned char *img_data, int width, int height, int Pos);

void ProcessImage(unsigned char *img_data, int width, int height, int Pos)
{
	int Area = 0;
	if (GX != 0)
	{
		int H = wormArg->search_win_size;
		int W = wormArg->search_win_size;
		int WD = wormArg->search_win_size / 2;
		unsigned char *blur = new unsigned char[H*W];
		unsigned char *img1 = new unsigned char[H*W];
		register int x1 = GX - WD, y1 = GY - WD;
		register int x2 = x1 + W, y2 = y1 + H;
		register int cx, cy, r, c;
		if (x2 > height)
			x2 = height;
		if (y2 > width)
			y2 = width;
		if (x1 < 0)
			x1 = 0;
		if (y1 < 0)
			y1 = 0;
		W = x2 - x1;
		H = y2 - y1;
		for (cx = x1, r = 0; cx < x2; cx++, r++)
			for (cy = y1, c = 0; cy < y2; cy++, c++)
			{
				*(img1 + (r*W) + c) = *(img_data + (cx*width) + cy);
			}
		Area = BlurImage(img1, W, H, blur, Pos, x1, y1);
		int A1 = (int)(MAXAREA*.4);
		if (Area < A1)
		{
			//cout<<"\n\t Alert - "<<Pos<<"  "<<MAXAREA<<"  "<<Area;
			unsigned char *blur1 = new unsigned char[height*width];
			BlurImage(img_data, width, height, blur1, Pos, 0, 0);
		//	cout<<"\n-------- Alert - "<<Pos<<"  "<<MAXAREA<<"  "<<Area;
			free(blur1);
		}
		free(img1);
		free(blur);
	}
	else
	{
		unsigned char *blur = new unsigned char[height*width];
		BlurImage(img_data, width, height, blur, Pos, 0, 0);
		free(blur);

	}

}
int BlurImage(unsigned char *img_data, int w, int h, unsigned char *blur, int Pos, int x1, int y1)
{
	register int s = wormArg->blur_radius/2;
	register int i = 0, j = 0, k = 0, l = 0, data = 0, hit = 0, area = 0;
	register long cx = 0, cy = 0;
	register unsigned char br;
	int check[300];
	for (i = 0; i < 300; i++)
		check[i] = 0;
	for (i = 0; i < h; i++)
		for (j = 0; j < w; j++)
		{
			hit = 0;
			data = 0;
			for (k = i - s; k <= (i + s); k++)
				for (l = j - s; l <= (j + s); l++)
				{
					if (k >= 0 && l >= 0 && l < w&&k < h)
					{
						data += (*(img_data + (k * w) + l));
						hit++;
					}
				}
			br = (unsigned char)(data / hit);

			if (br <= (255*wormArg->threshold_ratio))
			{
				area++;
				cx += i;
				cy += j;
			}
			*(blur + (i*w) + j) = (unsigned char)(data);
			check[data / hit]++;
		}
	if (area != 0) {
		cx = x1 + (int)(cx / area);
		cy = y1 + (int)(cy / area);
		GX = cx;
		GY = cy;
		REC[Pos][0] = Pos;
		REC[Pos][1] = cy;
		REC[Pos][2] = cx;
		REC[Pos][3] = area;
		if(MAXAREA < area)
			MAXAREA = area;
		
	}
	return area;
}
static int filepath(int num, char *path)
{
	char extn[wormArg->extension.length() + 1];
	strcpy(extn, wormArg->extension.c_str());
	char input[wormArg->input.length() + 1];
	strcpy(input, wormArg->input.c_str());
	num = num % wormArg->TotalFiles;
	int padding = 7;
	char format[NAME_MAX];
	if (path == NULL)
		return -1;

	if (sprintf(format, "%s/%%0%dd.%s", input, wormArg->padding, extn) <= 0) {
		return -1;
	}
	if (sprintf(path, format, num) <= 0) {
		return -1;
	}

	return 0;
}

unsigned long long get_ns()
{
	struct timespec ts = { 0 };
	if (clock_gettime(CLOCK_MONOTONIC, &ts) < 0)
	{
		return 0;
	}
	return ts.tv_sec * NANOSECOND + ts.tv_nsec;
}
