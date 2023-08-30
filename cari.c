#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <dirent.h>

bool ketemu = false;
const char tentang[] = "cari [nama] [rekrusif 1/0] [direktori]";
typedef struct {
	char alamat[100];
	int jenis;
} Dirs;

int main(int argc, char* argv[]) {
	if (argc < 4) {
		fprintf(stderr, "%s\n", tentang);
		return 1;
	}
	
	DIR *dir;
	struct dirent *ent;
	Dirs* dirs = (Dirs*)malloc(sizeof(Dirs));
	unsigned int jdirs = 1;
	
	dir = opendir(argv[3]);
	if (dir==NULL) {
		perror("direktori tidak ditemukan");
		return 1;
	}
	
	while ((ent = readdir(dir)) != NULL) {
		if (strstr(ent->d_name, argv[1]) != NULL) {
			//char tipe[10];
			//strcpy(tipe, ent->d_type == DT_DIR ? "direktori" : "berkas");
			dirs[jdirs-1].jenis = ent->d_type;
			strcpy(dirs[jdirs-1].alamat, ent->d_name);
			jdirs++;
			dirs = (Dirs*)realloc(dirs, jdirs);
			ketemu = true;
			//fprintf(stderr, "%s/%s\t%s\n", argv[3], ent->d_name, tipe);
		}
	}
	
	for (int i=0; i<jdirs-1; i++) {
		fprintf(stderr, "%s\t%s\n", dirs[i].alamat, dirs[i].jenis == DT_DIR ? "direktori" : "berkas");
	}
	
	if (!ketemu) {
		fprintf(stderr, "%s tidak ditemukan\n", argv[1]);
	} else {
		fprintf(stderr, "%i ditemukan\n", jdirs-1);
	}
	
	closedir(dir);
	free(dirs);
	return 0;
}
