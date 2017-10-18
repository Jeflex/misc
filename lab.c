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
	//Notice in this block we will determine if right or left leaning
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

struct Node * delete(struct Node * node, char * name){
	if(strcmp(name, node->name)==0){
		if(node->leftChild==NULL&&node->rightChild==NULL){
			node=NULL;
		}
		else if((node->leftChild==NULL)||(node->rightChild==NULL)){
			if(node->leftChild!=NULL){
				node=node->leftChild;
			}
			else{
				node=node->rightChild;
			}
		}
		else if((node->leftChild!=NULL)&&(node->rightChild!=NULL)){

			struct Node * temp1 = node->rightChild->leftChild;
			struct Node * temp=node;
			node=node->rightChild;
			node->leftChild=temp->leftChild;
		}
	}
	else{
		if(node->name<name){
			node->rightChild=delete(node->rightChild,name);
		}
		else{
			node->leftChild=delete(node->leftChild,name);
		}
	}
	return node;
}


void search(struct Node * node, char * name){
	//Notice in this block we will determine if right or left leaning
	if(node == NULL){
		printf("\nThis name is not in our list");
	}
	else if(strcmp(name, node->name)==0){
		printf("\nThis name is in our list");
	}
	else if(strcmp(name, node->name)<0){
		search(node -> rightChild, name);
	}
	else if(strcmp(name, node->name)>0){
		search(node -> leftChild, name);
	}
}
//And finally a print method from first to last
void print(struct Node * root){
	if(root != NULL){
		print(root -> rightChild);
		printf("\n%s",root -> name);
		print(root -> leftChild);
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

	//
	//	char *contents;
	//	size_t len = 0;
	//	while(getline(&contents, &len,	ipf)!=EOF){
	//		root=insert(root,contents);
	//	}

	root=insert(root,"Steve Jobs");
	root=insert(root,"Bill Gates");
	root=insert(root,"Jan Doe");
	root=insert(root,"Joey Frazure");
	root=insert(root,"Randy Coture");
	root=insert(root,"Chuck Liddel");
	root=insert(root,"Connor McGreggor");
	print(root);
	printf("\n-------");
	printf("\nSearching for Bill Gates");
	search(root,"Bill Gates");
	printf("\n-------");
	printf("\nRemoving Bill Gates");
	printf("\n---Printing----");
	root=delete(root,"Bill Gates");
	print(root);
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
	//
	//				return 0;
	//			}
	//
	//		}

	fclose(ipf);
	return EXIT_SUCCESS;
}
