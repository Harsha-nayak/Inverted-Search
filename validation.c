#include"inv.h"

extern slist_t *head;

int validate(int argc,char *argv[])
{
    if(argc > 1)                                                                           //checking if file names have passed as arguments
    {
	if(check(argc,argv) == SUCCESS)
	{
	    printf("INFO:Validation success.\n");
	} 
	else
	{
	    printf("ERROR:Validation failed!\n");
	}
    }
    else
    {
	printf("ERROR:Please pass file names as arguments.\n");
    }
}

int check(int argc,char **argv)
{  
    printf("INFO:Validating...\n");
    head = NULL;                                                                           //declaring a node for linking files
    for(int i = 1;i <= (argc-1);i++)  
    {  
	if(check_extn(argv[i]) == SUCCESS)
	{
	    if(file_open(argv[i]) == SUCCESS)
	    {
		printf("INFO:\"%s\" file exist.\n",argv[i]);
		if(file_size(argv[i]) == SUCCESS)
		{
		    if(file_duplicate(&head,argv[i]) == SUCCESS)
		    {
			printf("INFO:\"%s\" successfully added.\n",argv[i]);
		    }
		    else
		    {
			printf("ERROR:\"%s\" is a duplicate file.\n",argv[i]);
			continue;
		    }
		}
		else
		{
		    printf("ERROR:\"%s\" file is empty.\n",argv[i]);
		    continue;
		}
	    }
	    else
	    {
		printf("ERROR:\"%s\" file doesnt exist.\n",argv[i]);
		continue;
	    }
	}
	else
	{
	    printf("ERROR:\"%s\" doesnt have .txt extension.\n",argv[i]);
	    continue;
	}
    }
    return SUCCESS;
}

int check_extn(char *argv)                                                               //to check the extension of file names
{
    if(strstr(argv,".txt"))
    {
	return SUCCESS;
    }
    return FAILURE;
}

int file_open(char *argv)                                                               //to check if files exist or not
{
    FILE *fptr = fopen(argv,"r");
    if(fptr != NULL)
    {
	return SUCCESS;
    }
    return FAILURE;
}

int file_size(char *argv)                                                              //to check if files are empty or not
{
    FILE *fptr = fopen(argv,"r");
    fseek(fptr,0,SEEK_END);
    if(ftell(fptr))
	return SUCCESS;
    return FAILURE;
}

int file_duplicate(slist_t **head,char *argv)                                         //to check if files are duplicate
{
    if(*head == NULL)                                                                 //if no list is created,create list and update head
    {
	*head = create_node(argv);
	return SUCCESS;
    }

    slist_t *ptr1 = *head;                                                           //declare and initilise two pointers 
    slist_t *ptr2 = NULL;
    while(ptr1 != NULL)                                                              //traverse pointer through the list 
    {
	if(!strcmp(ptr1->str,argv))                                                  //if given file name is present in the list,return FAILURE
	{
	    return FAILURE;
	}
	ptr2 = ptr1;
	ptr1 = ptr1->link;
    }
    ptr2->link = create_node(argv);                                                 //insert the new node at last 
    return SUCCESS;
}

slist_t *create_node(char *fname)                                                   //to create new node
{
    slist_t *new = malloc(sizeof(slist_t));
    strcpy(new->str,fname);                                                          
    new->link = NULL;
    return new;                                                                     //return address of new node
}
