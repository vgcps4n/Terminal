#include<stdio.h>
#include<string.h>
#include<dirent.h>

void dir(){
	DIR *dp;
	struct dirent *ep;
	dp = opendir ("./");
	if (dp != NULL){
		while (ep = readdir (dp))
			puts (ep->d_name);
		(void) closedir (dp);
    }
	else
		perror ("Couldn't open the directory");
	return;
}

void create(char name[]){
	FILE *fp;
	fp = fopen(name, "w");
	fclose(fp);
	return;
}

bool write(char name[]){
	FILE *fp;
	int content;
	fp = fopen(name, "r+");
	if(fp == NULL)
		return 0;
	printf("Enter content: ");
	getchar();
	do{
		content = getchar();
		putc(content, fp);
	}while(content != '\n');
	fclose(fp);
	return 1;
}

bool print(char name[]){
	FILE *fp;
	int c;
	fp = fopen(name,"r");
	if(fp == NULL)
		return 0;
	while(1){
		c = fgetc(fp);
		if(feof(fp)){
			break;
		}
		printf("%c", c);
	}
	fclose(fp);
	printf("\n");
	return 1;
}

int newname(char name[]){
	char newname[20];
	int ret;
	scanf("%s", newname);
	ret = rename(name, newname);
	return ret;
}

int del(char name[]){
	int ret;
	ret = remove(name);
	return ret;
}

int main(){
	char filename[20], cmd[10];
	int n;
	printf("dir, create; rename; input; output; delete; exit\n");
	while(1){
		scanf("%s", cmd);
		if(strcmp(cmd, "exit") == 0) break;
		if(strcmp(cmd, "dir") == 0){
			dir();
			continue;
		}
		scanf("%s", filename);
		if(strcmp(cmd, "create") == 0){
			create(filename);
			printf("File created.\n");
		}
		if(strcmp(cmd, "input") == 0){
			if(write(filename))
				printf("Content written.\n");
			else
				printf("File not found.\n");
		}
		if(strcmp(cmd, "output") == 0){
			if(!print(filename))
				printf("File not found.\n");
		}
		if(strcmp(cmd, "rename") == 0){
			if(newname(filename)){
				printf("Error.\n");
			}else{
				printf("File renamed.\n");
			}
		}
		if(strcmp(cmd, "delete") == 0){
			if(del(filename)){
				printf("Error.\n");
			}else{
				printf("File deleted.\n");
			}
		}
		
	}
	return 0;
}