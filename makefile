EXEC = run
CC = g++
CFLAGS = -c -Wall

# $(EXEC) has the value of shell variable EXEC, which is "run".
# run depends on the files main.o util.o heap.o
$(EXEC) : main.o util.o Heap.o
# run is created by the command g++ -o run main.o util.o
# note that the TAB before $(CC) is REQUIRED...
	$(CC) -o $(EXEC) main.o util.o Heap.o

# main.o depends on the files main.h main.cpp
main.o :  main.cpp
# main.o is created by the command g++ -c -Wall main.cpp
# note that the TAB before $(CC) is REQUIRED...
	$(CC) $(CFLAGS) main.cpp

util.o : util.h util.cpp
	$(CC) $(CFLAGS) util.cpp

heap.o : Heap.h Heap.cpp
	$(CC) $(CFLAGS) Heap.cpp

clean :
	rm *.o
