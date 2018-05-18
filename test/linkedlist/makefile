CC=g++
CFLAGS=-Wall
CXXFLAGS=-std=c++11
TARGET=linkedlisttest

SRCS = ./main.cpp

INC = -I./ \
	-I../ \
	-I../../src/include
LIBPATH = -L../lib
LIB = -lpthread -lgtest
OBJS = $(SRCS:.cpp=.o)

$(TARGET):$(OBJS)
	$(CC) $(CFLAGS) $(CXXFLAGS) -o $@ $^ $(LIBPATH) $(LIB)
.PHONY:clean
clean:
	rm -fr $(TARGET) $(OBJS)

%.o:%.cpp
	$(CC) $(CFLAGS) $(CXXFLAGS) $(INC) -o $@ -c $<