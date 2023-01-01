build:
	gcc -c src/main.c  -g
	gcc -c src/cube.c  -g 
	gcc -c src/utils.c -g
	gcc -o cube main.o cube.o utils.o -lm
	
	if [ ! -d obj ];then mkdir obj; fi
	
	for i in *.o;do mv $$i obj ;done 
	
clean:
	rm obj/*.o
	rm cube
	rm -d obj
	
