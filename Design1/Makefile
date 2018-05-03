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

worm1:
	$(CC) $(FLAGS) $(EXEFILE)  $(SRC_DIR)$(FILE) $(LIBS) 

runworm:
	$(EXE) -t 1 -f 10 -e jpeg -i ../input/
gdb:	
	gdb $(EXE) 
wormAll:
	$(EXE) -t 1 -f 100 -e jpeg -i ../input/
	$(EXE) -t 2 -f 100 -e jpeg -i ../input/
	$(EXE) -t 4 -f 100 -e jpeg -i ../input/
	$(EXE) -t 8 -f 100 -e jpeg -i ../input/
	$(EXE) -t 12 -f 100 -e jpeg -i ../input/
	$(EXE) -t 24 -f 100 -e jpeg -i ../input/
	$(EXE) -t 48 -f 100 -e jpeg -i ../input/
	$(EXE) -t 96 -f 100 -e jpeg -i ../input/
	$(EXE) -t 192 -f 100 -e jpeg -i ../input/

