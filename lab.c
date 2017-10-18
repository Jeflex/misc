/*
 ============================================================================
 Name        : lab1.c
 Author      : Phillip Hassoun
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

//Lets make a struct outside that will define our Binary Search Tree

struct Node{
	struct Node *leftChild, *rightChild;
	char * name;
};

//Next let's define some functions that are nessesary for our struct to be a dst
struct Node * newNode(char * name){
	struct Node * node = (struct Node *) malloc(sizeof(struct Node));
	node->name = name;
	node->leftChild   = NULL;
	node->rightChild  = NULL;
	return(node);
}

struct Node * insert(struct Node * node, char * name){
	if(node == NULL){
		return newNode(name);
	}
	else if(strcmp(name, node->name)<0){
		node -> rightChild = insert(node -> rightChild, name);
	}
	else if(strcmp(name, node->name)>0){
		node -> leftChild =insert(node -> leftChild, name);
	}
	else{
		return node;
	}


	return node;
}

//And finally a print method from first to last
void print(struct Node * root){
	if(root != NULL){
		print(root -> leftChild);
		print(root -> rightChild);
		printf("%s\n",root -> name);
	}
}



int main(void) {
	//First we must read the file
	FILE *ipf,*opf;

	ipf=fopen("names.txt","r");

	if(ipf==NULL){
		fprintf(stderr,"\nPlease make a names.txt file");
		return 0;
	}

	//While reading we want to insert
	struct Node * root = NULL;
	int i,lines =0;


	char *contents;
	size_t len = 0;
	while(getline(&contents, &len,	ipf)!=EOF){
		root=insert(root,contents);
	}

	//	root=insert(root,"Ateve Jobs");
	//	root=insert(root,"Bhil B");
	//	root=insert(root,"Chh al");

	print(root);

	fclose(ipf);

	//		int select =0;
	//		while(select!=4){
	//			printf("\nPlease enter an option:");
	//			printf("\n1 - To add");
	//			printf("\n2 - To delete");
	//			printf("\n3 - To search");
	//			printf("\n4 - To Exit");
	//			scanf("%i",&select);
	//			return 0;
	//			if(select==1){
	//				print(root);
	//				select=4;
	//			}
	//			else if(select==2){
	//
	//			}
	//			else if(select==3){
	//
	//			}
	//			else if(select==4){
	//
	//			}
	//			else{
	//				printf("\nFuck");
	//				return 0;
	//			}
	//
	//		}
	return EXIT_SUCCESS;
}
