C=gcc

# Create binary
out: main.o vector.o
	$(C) main.o vector.o -o out

# Ceate object files
main.o: main.c
	$(C) -c main.c

vector.o: vector.c
	$(C) -c vector.c

clean:
	rm *.o out
