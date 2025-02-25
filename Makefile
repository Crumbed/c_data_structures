C=gcc

# Create binary
out: main.o vector.o linked_list.o
	$(C) main.o vector.o linked_list.o -o out

# Ceate object files
main.o: main.c
	$(C) -c main.c

vector.o: vector.c
	$(C) -c vector.c

linked_list.o: linked_list.c
	$(C) -c linked_list.c

clean:
	rm *.o out
