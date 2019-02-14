#include<stdio.h>
#include<string.h>

void create(char name[]){
	FILE *fp;
	fp = fopen(name, "w");
	fclose(fp);
	return;
}

void write(char name[]){
	FILE *fp;
	int content;
	fp=fopen(name, "a");
	getchar();
	printf("Enter content: ");
	while((content = getchar()) != '\n'){
		putc(content, fp);
	}
	fclose(fp);
	return;
}

void rewrite(char name[]){
	FILE *fp;
	int content;
	fp = fopen(name, "w");
	printf("Enter content: ");
	while((content = getchar()) != '\n'){
		putc(content, fp);
	}
	fclose(fp);
	return;
}

void print(char name[]){
	FILE *fp;
	int c;
	fp = fopen(name,"r");
	while(1){
		c = fgetc(fp);
		if(feof(fp)){
			break;
		}
		printf("%c", c);
	}
	fclose(fp);
	printf("\n");
	return;
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
	printf("create; rename; input; rewrite; output; delete; exit\n");
	while(1){
		scanf("%s", cmd);
		if(strcmp(cmd, "exit") == 0) break;
		scanf("%s", filename);
		if(strcmp(cmd, "create") == 0){
			create(filename);
			printf("File created.\n");
		}
		if(strcmp(cmd, "input") == 0){
			write(filename);
			printf("Content written.\n");
		}
		if(strcmp(cmd, "rewrite") == 0){
			rewrite(filename);
			printf("Content rewritten.\n");
		}
		if(strcmp(cmd, "output") == 0){
			print(filename);
		}
		if(strcmp(cmd, "rename") == 0){
			if(newname(filename)){
				printf("Error.");
			}else{
				printf("File renamed.\n");
			}
		}
		if(strcmp(cmd, "delete") == 0){
			if(del(filename)){
				printf("Error.");
			}else{
				printf("File deleted.\n");
			}
		}
	}
	return 0;
}