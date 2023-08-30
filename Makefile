CC=gcc

ifeq ($(OS), Windows_NT)
	exe=cari.exe
else
	exe=cari
endif

build:
	$(CC) cari.c -o $(exe)
	strip $(exe)

clean:
	rm $(exe)
