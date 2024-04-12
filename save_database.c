/*
NAME:
DATE:
DESCRIPTION:
SAMPLE INPUT:
SAMPLE OUTPUT:
 */

#include "inv.h"


int save_database(hash_t *arr)
{
    main_node *m_temp;                                                                    //take temporary pointers for main node and sub node
    sub_node *s_temp1;
    printf("Enter the filename you want to save the database: ");
    char file_name[20];                                                     
    scanf("%s",file_name);
    if(strstr(file_name,".txt"))                                                          //check if the file is a text file
    {
	FILE *fptr;
	fptr = fopen(file_name,"w");                                                     //open the file in 'write' mode
	for(int i=0;i<27;i++)
	{
	    if(arr[i].link != NULL)
	    {
	        m_temp = arr[i].link;
		while(m_temp != NULL)                                                   //print the main node and subnode data in given text file
		{
		    fprintf(fptr,"#");
		    fprintf(fptr,"%d;",i);
		    fprintf(fptr,"%s;",m_temp->word);
		    fprintf(fptr,"%d",m_temp->filecount);
		    s_temp1 = m_temp->sublink;
		    while(s_temp1 != NULL)
		    {
			fprintf(fptr,";");
			fprintf(fptr,"%s;%d",s_temp1->filename,s_temp1->wordcount);
			s_temp1 = s_temp1->sublink;
		    }
		    m_temp = m_temp->mainlink;
		    fprintf(fptr,"#");
		    fprintf(fptr,"\n");
		}
	    }
	}
	printf("Database is saved successfully\n");
    fclose(fptr);                                                                      //close the file 
    }
    else
    {
	printf("%s file doesnt have \".txt\" extension\n",file_name);
    }
}

