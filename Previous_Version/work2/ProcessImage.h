#define NANOSECOND 1000000000
#define PR 1
int MAXAREA=0;

int **REC;
int **LOG;
int LogSize=0;
void BlurImage(unsigned char *img_data, int width, int height, unsigned char *blur, int Pos, int, int, int*, int*, int *);
void ProcessImage(unsigned char *img_data, int width, int height, int Pos, int *, int*, int *);
int readlog(int size);

int readlog(int recordSize)
{
	double input;
	double total = 0.0;
	char path[wormArg->log.length() + 1];
	strcpy(path, wormArg->log.c_str());
	int size = 0;
	
	FILE *picture;
	picture = fopen(path, "r");
	if (picture == NULL)
	{
		cout << "File Won't open\n";
		return 0;
	}
	fseek(picture, 0, SEEK_END);
	size = ftell(picture);
	fseek(picture, 0, SEEK_SET);
	fclose(picture);
	LogSize=size;
	int**  AsCent = new int*[size];
	for (int i = 0; i < size; ++i)
		AsCent[i] = new int[2];
	ifstream myfile;
	myfile.open(path);
	int i = 0;
	int j = 0;
	//cout<<"---SIZE:"<<recordSize<<endl;
	if (myfile.is_open())
	{
		//Enter input
		while (myfile.eof() == false&&i<recordSize)
		{
			j++;
			myfile >> input;
			if (j == 3)
			{
//				cout<<"*"<<i<<endl;
				LOG[i][0] = (int)input;
			}
			else if (j == 4)
			{
				LOG[i++][1] = (int)input;
			}
			else if (j == 5)
			{
				j = 0;
			}

			//total = total + input;
		}//end while
		myfile.close();
	}//end if
	else
		cout << "Error opening file\n";
	//system("pause");
	//for (j = 0; j<i; j++)
	//	cout << "\n --" <<j<<"   "<< LOG[j][0] << "   " << LOG[j][1];
	return 0;
}

void ProcessImage(unsigned char *img_data, int width, int height, int Pos, int *GX, int *GY, int *area)
{
int Area = 0;
        if (*GX != 0)
        {
                int H = wormArg->search_win_size;
                int W = wormArg->search_win_size;
                int WD = wormArg->search_win_size / 2;
                unsigned char *blur = new unsigned char[H*W];
                unsigned char *img1 = new unsigned char[H*W];
                register int x1 = LOG[Pos%LogSize][0] - WD, y1 = LOG[Pos%LogSize][1] - WD;
                //register int x1 = *GX - WD, y1 = *GY - WD;
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
                BlurImage(img1, W, H, blur, Pos, x1, y1, GX, GY, &Area);
                int A1 = (int)(MAXAREA*.5);
                if (Area < A1)
                {
                //      cout<<"\n\t Alert - "<<Pos<<"  "<<MAXAREA<<"  "<<Area;
                        unsigned char *blur1 = new unsigned char[height*width];
                        BlurImage(img_data, width, height, blur1, Pos, 0, 0, GX, GY, &Area);
                //      cout<<"\n-------- Alert - "<<Pos<<"  "<<MAXAREA<<"  "<<Area;
                        free(blur1);
                }
                if(MAXAREA < Area)
                MAXAREA = Area;
                free(img1);
                free(blur);
        }
        else
        {
                unsigned char *blur = new unsigned char[height*width];
                BlurImage(img_data, width, height, blur, Pos, 0, 0, GX, GY, area);
                if(MAXAREA < *area)
                MAXAREA = *area;
                free(blur);

        }


}
void BlurImage(unsigned char *img_data, int w, int h, unsigned char *blur, int Pos, int x1, int y1, int *GX, int *GY, int *Area)
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
		*GX = cx;
		*GY = cy;
		*Area = area;
		REC[Pos][0] = Pos;
		REC[Pos][1] = cy;
		REC[Pos][2] = cx;
		REC[Pos][3] = area;
	}
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
