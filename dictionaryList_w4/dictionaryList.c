#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning (disable:4996)

struct dictionary {
	int val;
	int key;
	struct dictionary* next;
	struct dictionary* prev;
};
struct dictionary* head = NULL;
struct dictionary* tail = NULL;
struct dictionary* search(int);
void addItem(int, int);
void removeKey(int);
void releaseTheList();
int main()
{
	int k = 0, v = 0;
	int keyfound=0,checkIfRemove=0;
	char userResponses = NULL;
	struct dictionary* valKey;
	while (userResponses != 'E') {
		printf("dear user,there is options for you to build your dictionary:\n1. A-add item\n2. R-remove item you want\n3. P-to see val for your key\n4. E-to exit:");
		scanf(" %c", &userResponses);
	switch (userResponses)
	{
		case  'A':
			printf("please enter number for key and number for val:\n");
			scanf(" %d %d", &k, &v);
			addItem(k, v);
			break;
		case 'R':
			printf("please enter the key you want to remove:\n");
			scanf(" %d",&keyfound );
			removeKey(keyfound);
			break;
		case 'P':
			printf("please enter the key you want to see his val:\n");
			scanf(" %d", &keyfound);
			valKey=search(keyfound);
			if (!valKey) {
				printf("wrong selection, no key found\n");
			}
			else {
				printf("the val's key is:%d\n", valKey->val);
			}
			break;
		default:
			printf("wrong selection, pls be more sharp");
			break;
	}
	}
	releaseTheList();
}
void addItem(int key, int val) {
	struct dictionary* temp=(struct dictionary*)malloc(sizeof(struct dictionary));
	temp->val = val;
	temp->key = key;
	if (!head) {
		head = temp;
		tail = temp;
		temp->next = NULL;
		temp->prev = NULL;
		return 0;
	}
	else {
		temp->next = NULL;
		temp->prev = tail;
		tail->next = temp;
		tail = temp;
		return 0;
	}
}
struct dictionary* search(int key) {
	struct dictionary* foundKey = head;
	while (foundKey) {
		if (foundKey->key == key) {
			return foundKey;
		}
		foundKey = foundKey->next;
	}
	return 0;
}
void removeKey(int key) {
	struct dictionary* deleteKey= search(key);
	if (!deleteKey) {
		printf("wrong selection,no key found to remove.\n");
		return 0;
	}
	if (deleteKey == head && deleteKey == tail) {
		head = NULL;
		tail = NULL;
		free(deleteKey);
	}
	else if (deleteKey==head) {
		head=head->next;
		head->prev = NULL;
		free(deleteKey);
	}
	else if (deleteKey == tail) {
			tail = tail->prev;
			tail->next = NULL;
			free(deleteKey);
	}
	else {
	deleteKey->prev->next = deleteKey->next;
	deleteKey->next->prev = deleteKey->prev;
	free(deleteKey);
	}
	return 0;
}
void releaseTheList() {
	struct item* freeTheList = head;
	while (head) {
		free(freeTheList);
		head=head->next;
	}
}
