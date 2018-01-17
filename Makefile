PROG = simulation
CC=g++
CPPFLAGS=-c -Wall
OBJS= element.o main.o product.o factory.o

$(PROG) : $(OBJS)
	$(CC) -o $(PROG) $(OBJS)
main.o : main.cpp
	$(CC) $(CPPFLAGS) main.cpp
element.o : element.h element.cpp
	$(CC) $(CPPFLAGS) element.cpp
product.o : product.h product.cpp
	$(CC) $(CPPFLAGS) product.cpp
factory.o : factory.h factory.cpp
	$(CC) $(CPPFLAGS) factory.cpp
clean:
	rm -f $(PROG) $(OBJS)
