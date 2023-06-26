#include <stddef.h>
#include "ex10_ll_cycle.h"

int ll_has_cycle(node *head) {
    /* TODO: Implement ll_has_cycle */
	node*p1=head;
	node*p2=head;
	while(1)
	{
		if(!p2)return 0;
		p2=p2->next;
		if(!p2)return 0;
		p2=p2->next;
		p1=p1->next;
		if(p1==p2)return 1;
	}
}
