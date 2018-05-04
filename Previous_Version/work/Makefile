worm1:
	g++ -g -o run WormSeg.cpp -lpthread 
	./run -t 1 -f 10 -e jpeg -i ../input/
gdb:	
	gdb ./run -t 48 -f 100 -e jpeg -i ../input/
wormAll:
	g++ -g -o run WormSeg.cpp -lpthread 
	./run -t 1 
	./run -t 2
	./run -t 4
	./run -t 8
	./run -t 12
	./run -t 24
	./run -t 48
	./run -t 96
	./run -t 192

run1:
	g++ -g -o run sam.cpp -lpthread
	./run
rub:
	g++ -g -o run2 rub.cpp -lpthread
	./run2
rub2:
	g++ -g -o run3 rub2.cpp -lpthread
	./run3
test1:
	g++ -g -o test test1.cpp -lpthread
	./test 10 1 ../data2/3840_2160
all:
	g++ -g -o test test1.cpp -lpthread
	./test 1 1 ../data2/3840_2160
	./test 10 1 ../data2/3840_2160
	./test 100 1 ../data2/3840_2160
	./test 1 2 ../data2/3840_2160
	./test 10 2 ../data2/3840_2160
	./test 100 2 ../data2/3840_2160
	./test 1 1 ../data2/1920_1080/
	./test 10 1 ../data2/1920_1080/
	./test 100 1 ../data2/1920_1080/
	./test 1 2 ../data2/1920_1080/
	./test 10 2 ../data2/1920_1080/
	./test 100 2 ../data2/1920_1080/
test2:
	g++ -g -o test test1.cpp -lpthread
	./test 100 2
test3:
	g++ -g -o test test2.cpp -lpthread
	./test 1 1
