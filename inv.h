#ifndef INV_H
#define INV_H

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>


#define SUCCESS 1
#define FAILURE 0

typedef struct node{
    char str[10];              
    struct node *link;                        
}slist_t;

typedef struct mainnode{
    int filecount;                                             //main node creation
    char word[20];
    struct subnode *sublink;
    struct mainnode *mainlink;
}main_node;

typedef struct subnode{
    int wordcount;                                            //subnode creation
    char filename[20];
    struct subnode *sublink;
}sub_node;


typedef struct hashtable{                                    //hash table creation
    int index;
    struct mainnode *link;
}hash_t;


/* Function prototypes */

int validate(int argc,char **argv);

int check(int argc,char **argv);

/* Check extension of the files */

int check_extn(char *argv);

/* Check if file is present */

int file_open(char *argv);

/* Check if file is empty */

int file_size(char *argv);

/*  Check if the file is repeated or not */

int file_duplicate(slist_t **head,char *argv);

/*  Create node of the file and add to the list */

slist_t *create_node(char *fname);

/* Create data base function */

int create_database(slist_t **head,hash_t *arr);

/* To create hash table */

int create_hash_table(hash_t *arr,int size);

/* To display database */

int display_database(hash_t *arr);

/* to link main node and subnode to hash table */

int link(hash_t *arr,char *buf,char *fname);

/* create main node */

main_node *mainnode(char *buf,char *fname);

/* create subnode */

sub_node *create_subnode(char *fname);

/* To display particular index */

int search_database(hash_t *arr);

/* To save database */

int save_database(hash_t *arr);

/* To update database */

int update_database(hash_t *arr);



#endif
