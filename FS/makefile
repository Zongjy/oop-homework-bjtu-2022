CFLAGS +=-Wall -g -D_FILE_OFFSET_BITS=64
CC =g++
TARGET =fs
SRC =fs.cpp

$(TARGET):$(SRC)
	$(CC) $(SRC) main.cpp $(CFLAGS) -o $@

clean:
	-rm -f $(TARGET)