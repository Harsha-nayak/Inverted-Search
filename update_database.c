/*
NAME:
DATE:
DESCRIPTION:
SAMPLE INPUT:
SAMPLE OUTPUT:
 */

#include "inv.h"

int update_database(hash_t *arr)
{
    char file_name[20];                                              //declare char array to store backup file name
    printf("Enter backup filename: ");
    scanf("%s",file_name);

    FILE *fptr = fopen(file_name,"r");                               //open the backup file in read mode 

    if(fptr == NULL)
    {
	perror("Backup file is not present\n");
	return 0;
    }

    char str[100];
    main_node *temp;
    while(fscanf(fptr,"%s",str) != EOF)                                //store the contents of file line by line to str
    {
	int index = atoi(strtok(str+1,";"));                           //obtain index from file content

	if(arr[index].link == NULL)
	{
	    main_node *m_n = malloc(sizeof(main_node));                //create main node and save the data through backup file contents
	    m_n->mainlink = NULL;
	    temp = m_n;
	    strcpy(m_n->word,strtok(NULL,";"));
	    m_n->filecount = atoi(strtok(NULL,";"));
	    sub_node *s_n = malloc(sizeof(sub_node));
	    m_n->sublink = s_n;
	    strcpy(s_n->filename,strtok(NULL,";"));
	    s_n->wordcount = atoi(strtok(NULL,";"));
	    sub_node *prev = s_n;
	    for(int i=1;i<(m_n->filecount);i++)                        //save the data to subnodes according to backup file data
	    {
		sub_node *s_n = malloc(sizeof(sub_node));
		if( i == (m_n->filecount)-1)
		{
		    strcpy(s_n->filename,strtok(NULL,";"));
		    s_n->wordcount = atoi(strtok(NULL,"#"));
		}
		else
		{
		    strcpy(s_n->filename,strtok(NULL,";"));
		    s_n->wordcount = atoi(strtok(NULL,";"));
		}
		prev->sublink = s_n;
		prev = s_n;
	    }
	    arr[index].link = m_n;                                    //update hasht table link to main node address
	}
	else                                                          //enter if arr[index].link is not NULL
	{
	    main_node *m_n = malloc(sizeof(main_node));               //create main node and copy the data through backup file content
	    strcpy(m_n->word,strtok(NULL,";"));
	    m_n->filecount = atoi(strtok(NULL,";"));
	    sub_node *s_n = malloc(sizeof(sub_node));
	    m_n->sublink = s_n;
	    strcpy(s_n->filename,strtok(NULL,";"));
	    s_n->wordcount = atoi(strtok(NULL,";"));
	    sub_node *prev = s_n;
	    for(int i=1;i<(m_n->filecount);i++)                      //copy subnodes data 
	    {
		sub_node *s_n = malloc(sizeof(sub_node));
		if( i == (m_n->filecount)-1)
		{
		    strcpy(s_n->filename,strtok(NULL,";"));
		    s_n->wordcount = atoi(strtok(NULL,"#"));
		}
		else
		{
		    strcpy(s_n->filename,strtok(NULL,";"));
		    s_n->wordcount = atoi(strtok(NULL,";"));
		}
		prev->sublink = s_n;
		prev = s_n;
	    }
	    temp->mainlink = m_n;                                    //make prev mainnode mainlink to current mainnode
	    temp = m_n;                                              //update temp address
	}
    }
    printf("Database is updated successfully\n");
    fclose(fptr);                                                    //close the file
}


