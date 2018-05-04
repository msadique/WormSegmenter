#include <iostream>
#include <cstdlib>
#include <functional>
#include <argp.h>
#include <pthread.h>
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include"ParseArg.h"
#include"ProcessImage.h"
#define TH 20
pthread_mutex_t lock;
using namespace std;
int TSIZE = wormArg->pthread*wormArg->frames;
static int filepath(int num, char *path);
int gi=0;
void *wait(void *pth)
{
	int i;
	int id = *((int *) pth);
	char str[40];

	int width, height, channels;
	while(gi<TSIZE)
	{
		pthread_mutex_lock(&lock);
		if(gi>=TSIZE) break;
		int i = gi++;
		pthread_mutex_unlock(&lock);	
		filepath(i, str);
		unsigned char *img_data = stbi_load(str, &width, &height, &channels, 1);
		if (img_data == NULL)
		{
			pthread_exit(NULL);
		}
		if (PR == 1)
			ProcessImage(img_data, width, height, i);
		free(img_data);
	}
	pthread_exit(NULL);
	free(pth);

}

int main(int argc, char **argv) {
	cout<<"---------------------------------------------------------------------------------------"<<endl;
	int rc, i;
	parse_arg(argc, argv);
	TSIZE = wormArg->pthread*wormArg->frames;
	cout<<"Total Files Processed = "<<TSIZE<<endl;
	REC = new int*[TSIZE];
	for (i = 0; i < TSIZE; i++)
		REC[i] = new int[4];

	pthread_t threads[wormArg->pthread];
	pthread_attr_t attr;
	void *status;

	long long st = get_ns();
	// Initialize and set thread joinable
	if (pthread_mutex_init(&lock, NULL) != 0)
	{
		printf("\n mutex init failed\n");
		return 1;
	}
	for (i = 0; i < wormArg->pthread; i++) 
	{
		cout << "main() : creating thread, " << i << endl;
		int * arg = new int();
		*arg=i;
		rc = pthread_create(&threads[i], NULL, wait, arg);

		if (rc) {
			cout << "Error:unable to create thread," << rc << endl;
			exit(-1);
		}
	}

	// free attribute and wait for the other threads
	for (i = 0; i < wormArg->pthread; i++) {
		rc = pthread_join(threads[i], &status);
		if (rc) {
			cout << "Error:unable to join," << rc << endl;
			exit(-1);
		}

	}

	cout << "Main: program exiting." << endl;

	std::cout << "\nTotal Process Time :- " << float(get_ns() - st) / NANOSECOND << "\n";
	long tarea=0;
	if (PR == 1)
	{
		FILE * pFile;
		int i;
		char name[100];

		pFile = fopen("output.txt", "w");
		for (i = 0; i < wormArg->pthread*wormArg->frames; i++)
		{
			fprintf(pFile, "%d %d %d %d\n", REC[i][0], REC[i][1], REC[i][2], REC[i][3]);
			tarea +=REC[i][3];
		}
		fclose(pFile);
	}
	cout<<"Total Area : "<<tarea<<endl;
	for (i = 0; i < TSIZE; i++)
	{
		delete[] REC[i];
	}
		delete[] REC;
	cout<<"---------------------------------------------------------------------------------------"<<endl;
	pthread_exit(NULL);
}

