worm1:
	g++ -g -o run WormSeg.cpp -lpthread 
	 ./run -t 4 -f 1000 -e jpeg -i ../data/che2_hr_nf7/input/ -l ../data/che2_hr_nf7/log/log.txt -s 300
wormAll:
	g++ -g -o run WormSeg.cpp -lpthread 
	./run -t 1 -f 1000 -e jpeg -i ../data/che2_hr_nf7/input/ -l ../data/che2_hr_nf7/log/log.txt -s 300
	./run -t 2 -f 1000 -e jpeg -i ../data/che2_hr_nf7/input/ -l ../data/che2_hr_nf7/log/log.txt -s 300
	./run -t 4 -f 1000 -e jpeg -i ../data/che2_hr_nf7/input/ -l ../data/che2_hr_nf7/log/log.txt -s 300
	./run -t 8 -f 1000 -e jpeg -i ../data/che2_hr_nf7/input/ -l ../data/che2_hr_nf7/log/log.txt -s 300
	./run -t 12 -f 1000 -e jpeg -i ../data/che2_hr_nf7/input/ -l ../data/che2_hr_nf7/log/log.txt -s 300
	./run -t 24 -f 1000 -e jpeg -i ../data/che2_hr_nf7/input/ -l ../data/che2_hr_nf7/log/log.txt -s 300
	./run -t 48 -f 1000 -e jpeg -i ../data/che2_hr_nf7/input/ -l ../data/che2_hr_nf7/log/log.txt -s 300
	./run -t 92 -f 1000 -e jpeg -i ../data/che2_hr_nf7/input/ -l ../data/che2_hr_nf7/log/log.txt -s 300
	./run -t 192 -f 1000 -e jpeg -i ../data/che2_hr_nf7/input/ -l ../data/che2_hr_nf7/log/log.txt -s 300
wormAll2:
	g++ -g -o run WormSeg.cpp -lpthread
	./run -t 1 -f 1000 -e jpg -i ../data/n2_f8/input/ -l ../data/n2_f8/log/log.txt -s 300
	./run -t 2 -f 1000 -e jpg -i ../data/n2_f8/input/ -l ../data/n2_f8/log/log.txt -s 300
	./run -t 4 -f 1000 -e jpg -i ../data/n2_f8/input/ -l ../data/n2_f8/log/log.txt -s 300
	./run -t 8 -f 1000 -e jpg -i ../data/n2_f8/input/ -l ../data/n2_f8/log/log.txt -s 300
	./run -t 12 -f 1000 -e jpg -i ../data/n2_f8/input/ -l ../data/n2_f8/log/log.txt -s 300
	./run -t 24 -f 1000 -e jpg -i ../data/n2_f8/input/ -l ../data/n2_f8/log/log.txt -s 300
	./run -t 48 -f 1000 -e jpg -i ../data/n2_f8/input/ -l ../data/n2_f8/log/log.txt -s 300
	./run -t 92 -f 1000 -e jpg -i ../data/n2_f8/input/ -l ../data/n2_f8/log/log.txt -s 300
	./run -t 192 -f 1000 -e jpg -i ../data/n2_f8/input/ -l ../data/n2_f8/log/log.txt -s 300

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
