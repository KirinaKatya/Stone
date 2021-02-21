#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <stdbool.h>
#include "Functions.h"
#include "List.h"



int main(int argc, char *argv[]) {
	printf("|----------------------------|\n");
	printf("| Perfect School Database TM |\n");
	printf("|----------------------------|\n\n");
	char* fileName = (char*)malloc(sizeof(char) * 80);
	strcpy(fileName, argv[1]);
	Node* head = NULL;
	head = initFromFile(head, fileName);

	char* choice = (char*)malloc(sizeof(char) * 10);
	bool working = true;

	while (working) {
		printMenu();
		printf("\nYour action choice: ");
		scanf("%s", choice);
		char* tmp = (char*)malloc(sizeof(char) * 20);
		Node* toFind;

		switch (atoi(choice)) {
		case 1:
			head = addNewAssignment(head);
			break;
		case 2:
			printf("Enter Class: ");
			scanf("%s", tmp);
			toFind = findByClass(head, tmp);
			if (toFind == NULL) {
				printf("There is no Class %s\n", tmp);
			}
			else {
				printSplittedInfo(splitIntoStructure(toFind));
			}
			free(tmp);
			break;
		case 3:
			printf("Enter Classhead's lastname: ");
			scanf("%s", tmp);
			toFind = findByClasshead(head, tmp);
			if (toFind == NULL) {
				printf("There is no Classhead %s\n", tmp);
			}
			else {
				printSplittedInfo(splitIntoStructure(toFind));
			}
			free(tmp);
			break;
		case 4:
			printf("Enter Teacher's lastame: ");
			scanf("%s", tmp);
			toFind = findByTeacher(head, tmp);
			if (toFind == NULL) {
				printf("There is no Teacher %s\n", tmp);
			}
			else {
				printSplittedInfo(splitIntoStructure(toFind));
			}
			free(tmp);
			break;
		case 5:
			printf("\n");
			printAll(head);
			printf("\n");
			break;
		case 6:
			changeData(head);
			break;
		case 7:
			head = deleteByClass(head);
			break;
		default:
			saveToFile(head, fileName);
			working = false;
		}
		saveToFile(head, fileName);
	}

	// End of program ====================================================================
	freeList(head);
	free(fileName);
	free(choice);
	return 0;
}
