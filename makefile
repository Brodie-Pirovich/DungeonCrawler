CC=gcc
CFLAGS=-Wall -g
OBJ=ai.o fileIO.o game.o linkedList.o
EXEC=DungeonCrawler

$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

ai.o: ai.c ai.h game.h linkedList.h
	$(CC) $(CFLAGS) -c ai.c

fileIO.o: fileIO.c fileIO.h game.h ai.h
	$(CC) $(CFLAGS) -c fileIO.c


game.o: game.c game.h ai.h fileIO.h linkedList.h
	$(CC) $(CFLAGS) -c game.c


linkedList.o: linkedList.c linkedList.h
	$(CC) $(CFLAGS) -c linkedList.c

clean:
	rm -f $(EXEC) $(OBJ)