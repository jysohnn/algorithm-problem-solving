#include <stdio.h>
int main()
{
	int m,d,num=0;
	scanf("%d %d",&m,&d);
	switch(m){
		case 12: num=num+30;
		case 11: num=num+31;
		case 10: num=num+30;
		case 9: num=num+31;
	    case 8: num=num+31;
	    case 7: num=num+30;
	    case 6: num=num+31;
	    case 5: num=num+30;
	    case 4: num=num+31;
	    case 3: num=num+28;
	    case 2: num=num+31;
		case 1: break;
	}
	num=num+d;
	switch(num%7){
		case 1: printf("MON\n");break;
	    case 2: printf("TUE\n");break;
	    case 3: printf("WED\n");break;
	    case 4: printf("THU\n");break;
	    case 5: printf("FRI\n");break;
	    case 6: printf("SAT\n");break;
	    case 0: printf("SUN\n");break;
	}
	return 0;
}