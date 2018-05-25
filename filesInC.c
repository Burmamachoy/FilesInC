#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>

#define sizeBuffer 256
#define sizeBufferBig 4096

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"


char* readFile(char* nameFile, char* ANSI_COLOR);
void writeFile(char* nameFile, char* text);
void appendFile(char* nameFile, char* text);

typedef struct _titles {
	
	char title[sizeBuffer];
	char subTitle1[sizeBuffer];
	char subTitle2[sizeBuffer];
	char subTitle3[sizeBuffer];
	char subTitle4[sizeBuffer];
	
} titles;


int main(int argc, char *argv[]){
	
	titles title;
	
	char opt[2];
	char nameOfFile[sizeBuffer], pwd[sizeBuffer], textDirPath[sizeBuffer], fileName[sizeBuffer], textBuffer[sizeBufferBig];
	char* textBufferStr;
	
	memset(nameOfFile, 0, sizeBuffer);
	memset(pwd, 0, sizeBuffer);
	memset(textDirPath, 0, sizeBuffer);
	memset(textBuffer, 0, sizeBufferBig);
	
	int option;
	
	if(getcwd(pwd, sizeof(pwd)) != NULL)
		printf("%s\n", pwd);
		
	else
		perror("Current Directory not found");
		
	system("clear");
	
	memset(title.title, 0, sizeBuffer);
	memset(title.subTitle1, 0, sizeBuffer);
	memset(title.subTitle2, 0, sizeBuffer);
	memset(title.subTitle3, 0, sizeBuffer);
	memset(title.subTitle4, 0, sizeBuffer);
	
	strcat(pwd, "/");
	strcat(title.title, pwd);
	strcat(title.title, "Titles/Title.txt");
	strcat(title.subTitle1, pwd);
	strcat(title.subTitle1, "Titles/subTitle1.txt");
	strcat(title.subTitle2, pwd);
	strcat(title.subTitle2, "Titles/subTitle2.txt");
	strcat(title.subTitle3, pwd);
	strcat(title.subTitle3, "Titles/subTitle3.txt");
	strcat(title.subTitle4, pwd);
	strcat(title.subTitle4, "Titles/subTitle4.txt");
	
	strcat(textDirPath, pwd);
	strcat(textDirPath, "Text/");
	
	do{
	
		readFile(title.title, ANSI_COLOR_RED);
		printf(" 1. Create a text File\n");
		printf(" 2. Read a File\n");
		printf(" 3. Append a file\n");
		printf(" 4. Delete argument\n");
		//printf(" 4. ls Command\n");
		printf(" 5. Quit\n\n");
		printf(" Enter an option: ");
		scanf("%s", opt);
		system("clear");
		
		option = (int) opt[0] - 48;
		//printf("%d", option);
		
		switch(option){
			
			case 1:
				
				readFile(title.subTitle1, ANSI_COLOR_RED);
				printf(ANSI_COLOR_CYAN"Current directory: \n"ANSI_COLOR_RESET); 
				printf(ANSI_COLOR_CYAN"%s\n"ANSI_COLOR_RESET, textDirPath);
				printf("\n");
				printf("Files on Directory:\n");
				
				system("ls --color Text");
				
				if(argc > 1){
					
					memset(fileName, 0, sizeBuffer);
					strcat(fileName, textDirPath);
					strcat(fileName, argv[1]);
					
					goto TEXT1;
					
				}
				
				printf("\n");
				printf("Name of file: ");
				
				scanf("%s", nameOfFile);
				
				memset(fileName, 0, sizeBuffer);
				strcat(fileName, textDirPath);
				strcat(fileName, nameOfFile);
				
						
				TEXT1:printf("\nText: \n\n");
				
				getchar();
				scanf("%[^\n]",textBuffer);
				
				writeFile(fileName, textBuffer);
				
				printf("\n");
				printf("File Created Successfully On:\n");
				printf("%s\n", textDirPath);
				printf("Press y/Y to continue... ");
				
				do{
						
					scanf("%s", opt);
						
				}while(opt[0] != 89 && opt[0] != 121);
				
				system("clear");
				
			break;
			
			case 2:
				
				readFile(title.subTitle2, ANSI_COLOR_RED);
				
				printf(ANSI_COLOR_CYAN"Current directory: \n"ANSI_COLOR_RESET); 
				printf(ANSI_COLOR_CYAN"%s\n"ANSI_COLOR_RESET, textDirPath);
				printf("\n");
				printf("Files on Directory:\n");
				
				system("ls --color Text");
				
				if(argc > 1){
					
					memset(fileName, 0, sizeBuffer);
					strcat(fileName, textDirPath);
					strcat(fileName, argv[1]);
					
					goto TEXT2;
					
				}
				
				printf("\n");
				printf("Name of file: ");
				
				scanf("%sizeBuffer[^\n]s", nameOfFile);
				
				memset(fileName, 0, sizeBuffer);
				strcat(fileName, textDirPath);
				strcat(fileName, nameOfFile);
				
				TEXT2:printf("\nText: \n\n");
				
				textBufferStr = readFile(fileName, ANSI_COLOR_RESET);
				
				printf("\n\n");
				printf("Press y/Y to continue... ");
				
				opt[0] = 12;
				
				do{
					
					scanf("%s", opt);
					
				}while(opt[0] != 89 && opt[0] != 121);
			
				system("clear");
				
			break;
			
			case 3:
				readFile(title.subTitle3, ANSI_COLOR_RED);
				
				printf(ANSI_COLOR_CYAN"Current directory: \n"ANSI_COLOR_RESET); 
				
				system("pwd");
				
				printf("\n");
				printf("Files on Directory:\n");
				
				system("ls --color Text");
				
				if(argc > 1){
					
					memset(fileName, 0, sizeBuffer);
					strcat(fileName, textDirPath);
					strcat(fileName, argv[1]);
				
					goto TEXT3;
					
				}
				
				printf("\n");
				printf("Name of file: ");
				
				getchar();
				scanf("%[^\n]", nameOfFile);
				
				memset(fileName, 0, sizeBuffer);
				strcat(fileName, textDirPath);
				strcat(fileName, nameOfFile);
				
				TEXT3:printf("\nText: \n\n");
				
				printf("%s", fileName);
				textBufferStr = readFile(fileName, ANSI_COLOR_RESET);
				
				printf("\n\n");
				printf("Enter text: ");
				
				getchar();
				scanf("%[^\n]", textBuffer);
				
				appendFile(fileName, textBuffer);
				
				printf("\n");
				printf("File Appended Successfully\n");
				printf("Press y/Y to continue... ");
				
				opt[0] = 12;
				
				do{
					
					scanf("%s", opt);
					
				}while(opt[0] != 89 && opt[0] != 121);
			
				system("clear");
		
			break;
			
			case 4:
			
				if(argc > 1)
					argc--;
			
				/*readFile("subTitle4.txt", ANSI_COLOR_RED);
				
				printf("\n");
				
				system("pwd");	
				system("ls --color");
				
				printf("\n");
				printf("Press y/Y to continue... ");
				
				do{
						
					scanf("%s", opt);
						
				}while(opt[0] != 89 && opt[0] != 121);
				
				system("clear");*/
				
			break;
		}
		
	}while(opt[0] != 53);
	
	
	
	//char* string = readFile(argv[1]);
	
	
	
	return 0;
	
}

char* readFile(char* nameFile, char* ANSI_COLOR){
	
	FILE *file;
	int str_size, i;
	char *buffer = NULL;
	
	
	file = fopen(nameFile, "r");
	if(file == NULL){
		
		printf("No such a file\n");
		exit(1);
	
	}
	
	fseek(file, 0, SEEK_END);
	str_size = ftell(file);
	rewind(file);
	
	buffer = (char*) malloc(sizeof(char) * (str_size + 1));
	
	fread(buffer, sizeof(char), str_size, file);
	buffer[str_size] = '\0';
	
	printf("%s" "%s" ANSI_COLOR_RESET, ANSI_COLOR, buffer);
	
	fclose(file);
	
	return buffer;
	
	
}

void writeFile(char* nameFile, char* text){
	
	FILE *file;
	
	file = fopen(nameFile, "w");
	if(file == NULL){
		
		printf("Can not create file\n");
		exit(1);
		
	}

	fprintf(file, "%s", text);
	
	fclose(file);

}

void appendFile(char* nameFile, char* text){
	
	FILE *file;
	
	file = fopen(nameFile, "a");
	if(file == NULL){
		
		printf("Can not create file\n");
		exit(1);
	
	}
		
	fprintf(file, "%s", text);
	
	fclose(file);
		
}

