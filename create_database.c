
#include"inv.h"

int create_database(slist_t **head,hash_t *arr) 
{
    char buf[20];
    if(create_hash_table(arr,27) == SUCCESS)                            //Check if hash table is created
    {
	printf("INFO:Hash table created successfully\n");
    }

    FILE *fptr;
    slist_t *temp = *head;                                        

    while(temp != NULL)                                                //traverse through list
    {
	fptr = fopen(temp->str,"r");
	while(fscanf(fptr,"%s",buf) != EOF)                           //store the contents of file in buf
	{
	    link(arr,buf,temp->str);                                  //function to create hash table with contents
	}
	temp = temp->link;
    }
    return SUCCESS;
}


int create_hash_table(hash_t *arr,int size)                                    //initialisation of hash table
{
    for(int i=0;i<size;i++) 
    {
	arr[i].index = i;
	arr[i].link = NULL;
    }
    return SUCCESS;
}

int link(hash_t *arr,char *buf,char *fname)
{
    int index = toupper(buf[0]) % 65;                                            //calculate index of the hash table
    if(arr[index].link == NULL)                                                  //check if index is NULL
    {
	arr[index].link = mainnode(buf,fname);                                   
    }
    else
    {
	main_node *m_n = arr[index].link;
	while(m_n != NULL)                                                       //traverse through main nodes
	{
	    if(!strcmp(m_n->word,buf))
	    {
		if(!strcmp(m_n->sublink->filename,fname))
		{
		    m_n->sublink->wordcount++;
		}
		else
		{
		    m_n->filecount++;
		    sub_node *s_n = m_n->sublink;
		    while(s_n->sublink != NULL)                                //traverse through sub nodes
			s_n = s_n->sublink;
		    s_n->sublink = create_subnode(fname);
		    return 0;
		}
		return 0;
	    }
	    m_n = m_n->mainlink;
	}
	m_n = arr[index].link;
	while(m_n->mainlink != NULL)
	    m_n = m_n->mainlink;
	m_n->mainlink = mainnode(buf,fname);
    }
}

main_node *mainnode(char *buf,char *fname)                                     //function to create and initialise main node
{
    main_node *new = malloc(sizeof(main_node));
    new->filecount = 1;
    strcpy(new->word,buf);
    new->sublink = create_subnode(fname);
    new->mainlink = NULL;
    return new;
}

sub_node *create_subnode(char *fname)                                         //function to create and initialise sub node
{
    sub_node *new = malloc(sizeof(sub_node));
    new->wordcount = 1;
    strcpy(new->filename,fname);
    new->sublink = NULL;
    return new; 
}
