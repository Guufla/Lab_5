#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	char letter;
	struct node* next;
} node;

// Returns number of nodes in the linkedList.
int length(node* head)
{
	node* tmp = head;
	int size = 1;
	while(tmp->next != NULL){
		++size;
		tmp = tmp->next;
	}
	return size;
}

// parses the string in the linkedList
//  if the linked list is head -> |a|->|b|->|c|
//  then toCString function wil return "abc"
char* toCString(node* head)
{

	node* tmp = head;
	char* str=malloc(sizeof(char)*(length(head)+1));
	int stringPosition = 0;
	while (tmp->next != NULL) {
        *(str + stringPosition) = tmp->letter;
        stringPosition++;
        tmp = tmp->next;
	}
	*(str + stringPosition) = tmp->letter;
	stringPosition++;

    *(str + stringPosition) = '\0';

    return str;
}

// inserts character to the linkedlist
// f the linked list is head -> |a|->|b|->|c|
// then insertChar(&head, 'x') will update the linked list as foolows:
// head -> |a|->|b|->|c|->|x|
void insertChar(node** pHead, char c)
{
	node* tmp = *pHead;
	node* newNode = (node*)malloc(sizeof(node));

	newNode->letter = c;
    newNode->next = NULL;

	if(*pHead == NULL){
    	*pHead = newNode;
	}
	else{
		while(tmp->next !=NULL){
			tmp = tmp->next;
		}
		tmp->next = newNode;
	}
	
}

// deletes all nodes in the linkedList.
void deleteList(node** pHead)
{

	node* tmp = *pHead;
    while (tmp != NULL) {
        *pHead = tmp->next;
        free(tmp);
        tmp = *pHead;
    }
    *pHead = NULL;
}

int main(void)
{
	int i, strLen, numInputs;
	node* head = NULL;
	char* str;
	char c;
	FILE* inFile = fopen("input.txt","r");

	fscanf(inFile, " %d\n", &numInputs);
	
	while (numInputs-- > 0)
	{
		fscanf(inFile, " %d\n", &strLen);


		for (i = 0; i < strLen; i++)
		{
			fscanf(inFile," %c", &c);
			insertChar(&head, c);
			
		}

		str = toCString(head);
		printf("String is : %s\n", str);

		free(str);
		deleteList(&head);

		if (head != NULL)
		{
			printf("deleteList is not correct!");
			break;
		}
	}

	fclose(inFile);
}