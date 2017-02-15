#include "sort.h"
#include <stdbool.h>
/**
 * insertion_sort_list - insertion sort
 * @list: linked list of listint_t list
 */
void insertion_sort_list(listint_t **list)
{

      int n;
    	listint_t *cur, *ptr,*tmp;
    	cur = *list; /* cur: temp head representing the list to be searched */
    	if (cur->next==NULL)   /*there is only one element in list*/
    		return;
    	
    	cur=cur->next;
    	while(cur!=NULL)  /*reaching the last node*/
    	{
    		n=0;
    		ptr=cur;
    		tmp=cur->prev;
    		cur=cur->next;
    		while (tmp!=NULL && tmp->n>ptr->n) /*comparision starts*/
    		{
    			n++;
    			tmp=tmp->prev;
			    while ((*list)->prev != NULL)
			    *list = (*list)->prev;
			    print_list(*list);
    		}
    		if (n)
    		{
    			
    			ptr->prev->next=ptr->next;
    			if (ptr->next!=NULL)
    			ptr->next->prev=ptr->prev;
    	
    			if (tmp==NULL)  /* currently compared node is the smalles*/
    			{
    				tmp=*list;
    				ptr->prev=NULL;
    				ptr->next=tmp;
    				ptr->next->prev=ptr;
    				*list=ptr;
    			}
    			else  /* currently compared & swapped node lies in between somewhere in sorted list*/
    			{
    				tmp=tmp->next;
    				tmp->prev->next=ptr;
    				ptr->prev=tmp->prev;
    				tmp->prev=ptr;
    				ptr->next=tmp;
    			}
    		}
    	}
    }
