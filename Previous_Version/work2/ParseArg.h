#include<iostream>
#include <fstream>
#include <string>
#include<stdlib.h>
#include <sstream>
#include <dirent.h>
#include <stdio.h>
#include <sys/types.h>
#include <argp.h>
using namespace std;
typedef struct Arguments {
	string project;
	string input;
	string output;
	int pthread;
	int padding;
	int frames;
	string extension;
	int width;
	int height;
	int area_min;
	int area_max;
	int search_win_size;
	int blur_radius;
	int threshold_win_size;
	float threshold_ratio;
	string log;
	int TotalFiles;
	bool verbose;

	Arguments() : input("../data/set1/input"),
		output("output.txt"),
		pthread(1),
		padding(7),
		frames(1000),
		extension("jpeg"),
		width(640),
		height(480),
		area_min(200),
		area_max(400),
		search_win_size(200),
		blur_radius(3),
		threshold_win_size(25),
		threshold_ratio(0.9),
		log("../data/set1/log.txt"),
		TotalFiles(100000),
		verbose(true) {}
} WormArg;


	WormArg *wormArg=new WormArg();
static int parse_opt(int key, char *arg) {
	switch (key) {
	case 'P':
		wormArg->project = arg;
		cout<<"New  Project: "<<arg<<endl;
		break;

	case 'i':
		wormArg->input = arg;
		cout<<"New  Input : "<<arg <<endl;
		break;

	case 'o':
		wormArg->output = arg;
		cout<<"New  Ouput: "<< arg <<endl;
		break;
	case 't':
		wormArg->pthread = atoi(arg);
		cout<<"New  Pthread: "<<arg <<endl;
		break;

	case 'p':
		wormArg->padding = atoi(arg);
		cout<<"New  Paging: "<<arg <<endl;
		break;

	case 'f':
		wormArg->frames = atoi(arg);
		cout<<"New  Frames: "<< arg<<endl;
		break;

	case 'e':
		wormArg->extension = arg;
		cout<<"New  Extension: "<< arg<<endl;
		break;

	case 'w':
		wormArg->width = atoi(arg);
		cout<<"New  Width: "<< arg<<endl;
		break;

	case 'h':
		wormArg->height = atoi(arg);
		cout<<"New  Height: "<<arg <<endl;
		break;

	case 'a':
		wormArg->area_min = atoi(arg);
		cout<<"New  Area_min: "<<arg <<endl;
		break;

	case 'A':
		wormArg->area_max = atoi(arg);
		cout<<"New  Area_max: "<<arg <<endl;
		break;

	case 's':
		wormArg->search_win_size = atoi(arg);
		cout<<"New  Search_win_size: "<< arg<<endl;
		break;

	case 'b':
		wormArg->blur_radius = atoi(arg);
		cout<<"New Blur_radius : "<< arg<<endl;
		break;

	case 'W':
		wormArg->threshold_win_size = atoi(arg);
		cout<<"New  Threshold_win_size: "<< arg<<endl;
		break;

	case 'r':
		wormArg->threshold_ratio = atof(arg);
		cout<<"New  Threshold_ratio: "<<arg <<endl;
		break;

	case 'l':
		wormArg->log = arg;
		cout<<"New  Log File: "<< arg<<endl;
		break;

	case 'v':
		wormArg->verbose = true;             //Needs correction.
		cout<<"Verbose Activited "<<endl;
		break;

	default:
		cout<<"Unknown Argument " <<endl;
		return ARGP_ERR_UNKNOWN;
	}

	return 0;
}
void parse_arg(int argc, char **argv)
{
	DIR *dp;
  	int files=0;
  	struct dirent *ep;     
	struct argp_option options[] = {
		{ "project",               'P', "NAME",       0,                    "The name of the project to process." },
		{ "input",                 'i', "PATH",       OPTION_ARG_OPTIONAL,  "Path to input images." },
		{ "output",                'o', "FILE PATH",  OPTION_ARG_OPTIONAL,  "Output file path." },
		{ "pThreads",              't', "NUMBER",     OPTION_ARG_OPTIONAL,  "Number of threads." },
		{ "padding",               'p', "NUMBER",     OPTION_ARG_OPTIONAL,  "Number of digits in the file name." },
		{ "frames",                'f', "FRAMES",     OPTION_ARG_OPTIONAL,  "Number of frames to be processed per Thread." },
		{ "extension",             'e', "STRING",     OPTION_ARG_OPTIONAL,  "Extension of the image files." },
		{ "width",                 'w', "WIDTH",      OPTION_ARG_OPTIONAL,  "The horizontal resolution of the image." },
		{ "height",                'h', "HEIGHT",     OPTION_ARG_OPTIONAL,  "The vertical resolution of the image." },
		{ "area_min",              'a', "NUMBER",     OPTION_ARG_OPTIONAL,  "The lower bound for a candidate worm component." },
		{ "area_max",              'A', "NUMBER",     OPTION_ARG_OPTIONAL,  "The upper bound for a candidate worm component." },
		{ "search_win_size",       's', "NUMBER",     OPTION_ARG_OPTIONAL,  "Width and height of crop area." },
		{ "blur_radius",           'b', "NUMBER",     OPTION_ARG_OPTIONAL,  "Width and height of the sliding window used in the box blur." },
		{ "threshold_win_size",    'W', "NUMBER",     OPTION_ARG_OPTIONAL,  "Width and height of the sliding window used in the dynamic threshold." },
		{ "threshold_ratio",       'r', "FLOAT",      OPTION_ARG_OPTIONAL,  "Pixel intensity." },
		{ "log",                   'l', "FILE PATH",  OPTION_ARG_OPTIONAL,  "Path to log file." },
		{ "verbose",               'v', "BOOLEAN",    OPTION_ARG_OPTIONAL,  "Produce verbose output." },
		{ 0 }
	};
	for(int i=0;i<argc;i++)
	{
		if(argv[i][0]=='-')
		{
			if(argv[i+1][0]!='-')
			{
				parse_opt(argv[i][1],argv[i+1]);i++;
			}
		}
	}
	 char input[wormArg->input.length()+1];
         strcpy(input, wormArg->input.c_str());
  	dp = opendir (input);
	if (dp != NULL)
  	{
    		while (ep = readdir (dp))
      			files++;

    		(void) closedir (dp);
  	}
  	else
    		perror ("Couldn't open the directory");
	wormArg->TotalFiles=files;
}
