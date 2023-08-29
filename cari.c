#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

const char tentang[] = "cari [nama] [rekrusif 1/0] [direktori]";
typedef struct {
	
} Dirs;

int main(int argc, char* argv[]) {
	if (argc < 4) {
		fprintf(stderr, "%s\n", tentang);
		return 1;
	}
	
	DIR *dir;
	struct dirent *ent;
	char** dirs = (char**)malloc(sizeof(char*));
	unsigned int jdirs = 1;
	
	dir = opendir(argv[3]);
	if (dir==NULL) {
		perror("direktori tidak ditemukan");
		return 1;
	}
	
	while ((ent = readdir(dir)) != NULL) {
		if (strcmp(ent->d_name, argv[1]) == 0) {
			char tipe[10];
			strcpy(tipe, ent->d_type == DT_DIR ? "direktori" : "berkas");
			dirs[jdirs-1] = (char*)malloc(strlen()*sizeof(char);
			strcpy(dirs[jdirs-1], ent->d_name);
			dirs = (char**)realloc(dirs, sizeof(dirs)/sizeof(char*)+1);
			//fprintf(stderr, "%s/%s\t%s\n", argv[3], ent->d_name, tipe);
		}
	}
	
	closedir(dir);.
	free(dirs)
	return 0;
}
