/*
NAME:
DATE:
DESCRIPTION:
SAMPLE INPUT:
SAMPLE OUTPUT:
 */

#include"inv.h"

int display_database(hash_t *arr)
{
    main_node *m_temp;                                                                      //take temporary pointers for main node and sub node
    sub_node *s_temp1;
    printf("Index\tWord\tfilecount\tfilename\tWordcount\n");
    for(int i=0;i<27;i++)
    {
	if(arr[i].link != NULL)                                                             //if main node is present ,print node data and subnode data
	{
	    m_temp = arr[i].link;
	    while(m_temp != NULL)                                                          //traverse through main node
	    {
	        printf("%d\t",i);
		printf("%s\t",m_temp->word);
		printf("%d\t",m_temp->filecount);
		s_temp1 = m_temp->sublink;
		while(s_temp1 != NULL)                                                     //traverse through sub node
		{
		    printf("\t%s\t\t%d\t",s_temp1->filename,s_temp1->wordcount);
		    s_temp1 = s_temp1->sublink;
		}	     
		m_temp = m_temp->mainlink;
		printf("\n");
	    }
	}
    }
    return 0;
}

