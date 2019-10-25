#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

int isReg(mode_t n){
	switch (n & S_IFMT)
	{
		case S_IFREG:
			return 1;
		default:
			return 0;
	}
}

int writeFile(char* fullpath,char* text){
	int n = 0;
	FILE *fp;
	if((fp = fopen(fullpath, "w+"))){
		printf("Chillbot created file.\n");
		n = fputs(text, fp);
		if(n)
			printf("Chillbot wrote:\n\n");
			printf("%s\n\n",text);
		fclose(fp);
	}
	return n;
}

int ensureContents(char* fullpath, char* text){
	int not_found = 1;
	int n = -1;
	char buff[500];
	FILE *fp;

	if((fp = fopen(fullpath, "r+"))){
		printf("File contents:\n\n");
		while(not_found && (fgets(buff, sizeof(buff), (FILE*)fp) != NULL)){
				printf("%s",buff);
				if(strstr(buff, text)){
					not_found = 0;
				}
		}
		printf("\n\n");
		if(not_found){
			n = fputs(text,fp);
			if(n)
				printf("Chillbot added:\n\n%s\n\n",text);
		}
		else{
			n = 0;
		}
		fclose(fp);
	}
	return n;
}

int main(int argc, char *argv[]){
	struct stat typ;
	int found = 0;
	char fullPath[300];
	memset(fullPath, '\0', sizeof(fullPath));
	char text[] = "I want to learn PE file format!";
	char target[] = "PE-1.txt";
	char folder[] = "\\";
	char * last = &folder[strlen(folder)-1];
	if(strstr(last,"\\"))
		sprintf(fullPath,"%s%s",folder,target);
	else
		sprintf(fullPath,"%s\\%s",folder,target);
	stat(fullPath, &typ);
	// checks that it's regular text file and that it's found
	if(isReg(typ.st_mode)){
		found = 1;
		printf("Chillbot has found file %s.\n", target);
	}
	if(found)
		goto fileFound;
	else
		goto MoreGoTos;

	foundFile:
		switch(ensureContents(fullPath, text)){
			case 0:
				printf("Chillbot confirmed file contents.\n"); break;
			case 1:
				printf("Chillbot updated file.\n"); break;
			default:
				printf("Chillbot was unable read file. \\_[*~*]_/\n"); break;
		}
		goto Return;

	MoreGoTos:
		goto Nothing;

	fileFound:
		goto foundFile;

	Nothing:
		found = 666;
		goto NotFound;

	NotFound:
		if(writeFile(fullPath, text))
			printf("Chillbot has created file %s.\n", target);
		else
			printf("Chillbot was unable to write file %s. \\_[*~*]_/\n", target);
		goto Return;

	HackerMan:
		printf("You got hacked, son\n");
		goto Return;

	ToInfinity:
		main(1, (char**)"Hello");

	Return:
		return 0;
}
