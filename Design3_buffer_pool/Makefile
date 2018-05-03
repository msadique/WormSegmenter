INC_DIR= ./inc/
SRC_DIR= ./src/
FLAGS = -g
FLAGS += -Wall -Werror
FLAGS += -I$(INC_DIR)
FLAGS += -o
EXEFILE = wormseg
EXE = ./wormseg

FILE =WormSeg.cpp
LIBS = -lm -lpthread
CC=g++

wormSeg:
	$(CC) $(FLAGS) $(EXEFILE)  $(SRC_DIR)$(FILE) $(LIBS)

runworm:
	$(EXE) -t 24 -R 20 -f 100 -e jpeg -i ../input/
gdb:
	gdb $(EXE)


wormAll:
	g++ -g -o run WormSeg.cpp -lpthread 
	$(EXE) -t 24 -R 19 -f 1000 -e jpeg -i ../data/che2_hr_nf7/input/
	$(EXE) -t 24 -R 20 -f 1000 -e jpeg -i ../data/che2_hr_nf7/input/
	$(EXE) -t 24 -R 21 -f 1000 -e jpeg -i ../data/che2_hr_nf7/input/
	$(EXE) -t 24 -R 22 -f 1000 -e jpeg -i ../data/che2_hr_nf7/input/
	$(EXE) -t 24 -R 23 -f 1000 -e jpeg -i ../data/che2_hr_nf7/input/
	$(EXE) -t 48 -R 40 -f 1000 -e jpeg -i ../data/che2_hr_nf7/input/
	$(EXE) -t 48 -R 41 -f 1000 -e jpeg -i ../data/che2_hr_nf7/input/
	$(EXE) -t 48 -R 42 -f 1000 -e jpeg -i ../data/che2_hr_nf7/input/
	$(EXE) -t 48 -R 43 -f 1000 -e jpeg -i ../data/che2_hr_nf7/input/
	$(EXE) -t 48 -R 44 -f 1000 -e jpeg -i ../data/che2_hr_nf7/input/
	$(EXE) -t 48 -R 45 -f 1000 -e jpeg -i ../data/che2_hr_nf7/input/
	$(EXE) -t 48 -R 46 -f 1000 -e jpeg -i ../data/che2_hr_nf7/input/
	$(EXE) -t 96 -R 80 -f 1000 -e jpeg -i ../data/che2_hr_nf7/input/
	$(EXE) -t 96 -R 82 -f 1000 -e jpeg -i ../data/che2_hr_nf7/input/
	$(EXE) -t 96 -R 84 -f 1000 -e jpeg -i ../data/che2_hr_nf7/input/
	$(EXE) -t 96 -R 86 -f 1000 -e jpeg -i ../data/che2_hr_nf7/input/
	$(EXE) -t 96 -R 88 -f 1000 -e jpeg -i ../data/che2_hr_nf7/input/
	$(EXE) -t 96 -R 90 -f 1000 -e jpeg -i ../data/che2_hr_nf7/input/
	$(EXE) -t 96 -R 92 -f 1000 -e jpeg -i ../data/che2_hr_nf7/input/
	$(EXE) -t 96 -R 94 -f 1000 -e jpeg -i ../data/che2_hr_nf7/input/

wormAll2:
	g++ -g -o run WormSeg.cpp -lpthread 
	$(EXE) -t 24 -R 19 -f 1000 -e jpg -i ../data/che2_hr_nf7/input/
	$(EXE) -t 24 -R 20 -f 1000 -e jpg -i ../data/che2_hr_nf7/input/
	$(EXE) -t 24 -R 21 -f 1000 -e jpg -i ../data/che2_hr_nf7/input/
	$(EXE) -t 24 -R 22 -f 1000 -e jpg -i ../data/che2_hr_nf7/input/
	$(EXE) -t 48 -R 40 -f 1000 -e jpg -i ../data/che2_hr_nf7/input/
	$(EXE) -t 48 -R 41 -f 1000 -e jpg -i ../data/che2_hr_nf7/input/
	$(EXE) -t 48 -R 42 -f 1000 -e jpg -i ../data/che2_hr_nf7/input/
	$(EXE) -t 48 -R 43 -f 1000 -e jpg -i ../data/che2_hr_nf7/input/
	$(EXE) -t 48 -R 44 -f 1000 -e jpg -i ../data/che2_hr_nf7/input/
	$(EXE) -t 96 -R 80 -f 1000 -e jpg -i ../data/che2_hr_nf7/input/
	$(EXE) -t 96 -R 82 -f 1000 -e jpg -i ../data/che2_hr_nf7/input/
	$(EXE) -t 96 -R 84 -f 1000 -e jpg -i ../data/che2_hr_nf7/input/
	$(EXE) -t 96 -R 86 -f 1000 -e jpg -i ../data/che2_hr_nf7/input/
	$(EXE) -t 96 -R 88 -f 1000 -e jpg -i ../data/che2_hr_nf7/input/
	$(EXE) -t 96 -R 90 -f 1000 -e jpg -i ../data/che2_hr_nf7/input/

wormAll3:
	g++ -g -o run WormSeg.cpp -lpthread 
	$(EXE) -t 96 -R 60 -f 1000 -e jpg -i ../data/che2_hr_nf7/input/
	$(EXE) -t 96 -R 64 -f 1000 -e jpg -i ../data/che2_hr_nf7/input/
	$(EXE) -t 96 -R 66 -f 1000 -e jpg -i ../data/che2_hr_nf7/input/
	$(EXE) -t 96 -R 68 -f 1000 -e jpg -i ../data/che2_hr_nf7/input/
