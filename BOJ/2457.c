#include <stdio.h>
#include <stdlib.h>

int imp=1;

typedef struct
{
    int l;
    int r;
} b;

int date(int m,int d)
{
    switch(m)
    {
        case 1:return d;
        case 2:return d+31;
        case 3:return d+59;
        case 4:return d+90;
        case 5:return d+120;
        case 6:return d+151;
        case 7:return d+181;
        case 8:return d+212;
        case 9:return d+243;
        case 10:return d+273;
        case 11:return d+304;
        case 12:return d+334;
    }
    return 0;
};

int f(b* a,int left_b,int right_b,int n)
{
    int i,check=0,max_l=left_b-1,min_r=right_b+1,j=0;
    b* x;
    for(i=0;i<n;i++)
    {   
        if(a[i].l > left_b && a[i].r < right_b) check++;
    }
    if(check!=0) x=(b*)malloc(sizeof(b)*check);
    
    for(i=0;i<n;i++)
    {   
        if(a[i].l <= left_b && a[i].r >= left_b && a[i].r > max_l) max_l=a[i].r;
        if(a[i].l <= right_b && a[i].r >= right_b && a[i].l < min_r) min_r=a[i].l;
        if(a[i].l > left_b && a[i].r < right_b) {x[j].l=a[i].l;x[j].r=a[i].r;j++;}
    }
    
    free(a);
    
    if(max_l>=right_b) return 1;
    if(min_r<=left_b) return 1; 
    if(min_r-max_l <= 1) return 2;
    else
    {   
        if(check==0) {imp=0; return 0;}
        else return 2+f(x,max_l+1,min_r-1,check);
    }
};

int main()
{
    int n,i,s;
    scanf("%d",&n);
    b* a=(b*)malloc(sizeof(b)*n);
    for(i=0;i<n;i++)
    {
        int x,y,z,k;
        scanf("%d %d %d %d",&x,&y,&z,&k);
        a[i].l=date(x,y);
        a[i].r=date(z,k)-1;
    }
    s=f(a,date(3,1),date(11,30),n);
    if(imp) printf("%d",s);
    else printf("0");
    return 0;
}