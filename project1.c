#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include "project2.c"
#include "x.h"


int main(){
	
	int n;
	while(1){
		textcolour(4);
	printf("\n enter 1.new_contact 2.contact_sorting 3.display_contacts 4.calling 5.recent_call_history 6.exit");
	scanf("%d",&n);
	textcolour(7);
	switch(n){
		case 1:{c_create();
		system("cls");
			break;
		}
		case 2:{c_sort();
		printf("\n sorted");
		system("cls");
			break;
		}
		case 3:{c_display();
		
			break;
		}
		case 4:{r_calling();
			break;
		}
		case 5:{r_display();
		
			break;
		}
		case 6:{exit(0);
			break;
		}
	}
	}
}
