CC=gcc

build:
	$(CC) cari.c -o cari
	strip cari

clean:
	rm cari
