#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BinarySearchTree.h"

#define FILE_NAME "courses.txt"
#define BUFFER_SIZE 1024

int main(int argc, char const *argv[]){
	
	BinTree tree = init_bin_tree();
	Data data;
	Data data1;
	Data tmp;

	char buffer[BUFFER_SIZE];
	char buffer2[BUFFER_SIZE];
	char buffer3[BUFFER_SIZE];

	FILE* f_in = fopen(FILE_NAME, "r");
	if(!f_in){
		printf("Failed to allocate memeory for file pointer\n");
		exit(1);
	}
	printf("\n");
	while((fgets(buffer, sizeof(buffer), f_in)) != NULL){
		data.name = buffer;
		if(fgets(buffer3, sizeof(buffer), f_in))
		data.is_like = atoi(buffer3);
		if(fgets(buffer2, sizeof(buffer), f_in))
		data.semester = buffer2;
		add_BST(&(tree->root), data);
	}

	fclose(f_in);

	data1.name = "linear algebra\n";
	if(search(tree->root, data1, &tmp)){
		//tmp.name[strlen(tmp.name) - 1] = '\0';
		printf("Course %salready taken.\n", tmp.name);
		if(tmp.is_like)
			printf("You liked the course.\n");
		else
			printf("You did not like the course.\n");
		printf("Course was taken during the %s\n", tmp.semester);
	}
	data1.name = "differential equations\n";
	if(search(tree->root, data1, &tmp)){
		//tmp.name[strlen(tmp.name) - 1] = '\0';
		printf("Course %salready taken.\n", tmp.name);
		if(tmp.is_like)
			printf("You liked the course.\n");
		else
			printf("You did not like the course.\n");
		printf("Course was taken during the %s\n", tmp.semester);
	}
		
	print_inorder(tree->root);
	tree->root = empty_tree(tree ,tree->root);
	tree = destroy_tree(tree);
	if(!tree)
		printf("destroy successful.\n");
	return 0;
}

