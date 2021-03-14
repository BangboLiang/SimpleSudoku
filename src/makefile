# This is the make file. I just used command lines, because I used sublime to edit.

TAR = Sudoku
OBJS = main.o sudokusolver.o display.o isvalid.o 
CC = g++
RMRF = rm -rf 

$(TAR): $(OBJS)
	$(CC) -Wall $^ -o $@
%.o: %.cpp
	$(CC) -c -Wall $^ -o $@
clean:
	$(RMRF) *.o $(TAR)