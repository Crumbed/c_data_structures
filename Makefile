C=gcc

# Create binary
out: main.o
	$(C) main.o -o out

# Ceate object files
main.o: main.c
	$(C) -c main.c

clean:
	rm *.o out
