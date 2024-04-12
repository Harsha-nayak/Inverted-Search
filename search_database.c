/*
NAME:
DATE:
DESCRIPTION:
SAMPLE INPUT:
SAMPLE OUTPUT:
 */

#include "inv.h"

int search_database(hash_t *arr)
{
    char word_name[20];                                                                        //declare variable
    printf("Enter the word you want to search: ");
    scanf("%s",word_name);
    main_node *m_temp;									       //declare temporary pointers for main node and sub node
    sub_node *s_temp1;
    int flag = 0;
    for(int i=0;i<27;i++)
    {
	if(arr[i].link != NULL)                                                               
	{
	    m_temp = arr[i].link;
	    while(m_temp != NULL)
	    {
		if(!strcmp(m_temp->word,word_name))                                           //if word matches with the curent main node data,print the data
		{
		    flag = 1;
		    printf("Index\tWord\tfilecount\tfilename\tWordcount\n");
		    printf("%d\t",i);
		    printf("%s\t",m_temp->word);
		    printf("%d\t",m_temp->filecount);
		    s_temp1 = m_temp->sublink;
		    while(s_temp1 != NULL)
		    {
			printf("\t%s\t\t%d\t",s_temp1->filename,s_temp1->wordcount);
			s_temp1 = s_temp1->sublink;
		    }
		    printf("\n");
		}
		m_temp = m_temp->mainlink;
	    }
	}
    }
    if(flag != 1)                                                                            //if word is not present in hash table
    printf("ERROR:\"%s\" doesnt exist in database\n",word_name);
}



