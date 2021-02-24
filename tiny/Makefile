CC=gcc
CXX=clang++

CFLAGS=-c -Wall -fsanitize=address
CXXFLAGS=-c -Wall -fsanitize=address
ASAN_FLAGS =-fsanitize=address -fno-omit-frame-pointer -Wno-format-security
SOURCE_FILES=src/streams.c src/streams.h src/streamer.cpp

all: smol

smol: $(SOURCR_FILES)
	$(CC)  $(CFLAGS) $(ASAN_FLAGS) -o streams.o src/streams.c
	$(CXX) $(CXXFLAGS) $(ASAN_FLAGS) -o streamer.o src/streamer.cpp
	$(CXX) $(ASAN_FLAGS) -o smol streams.o streamer.o

clean:
	rm -f *.o smol
