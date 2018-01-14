#include <cstdio>

char s[100];
int a[200]={0};

int main()
{
    int max=0;
    scanf("%s",s);
    for(int i=0;s[i]!=0;i++)
    {
        if(s[i] == '9') a['6']++;
        else a[s[i]]++;
    }
    a['6'] = (a['6']+1)/2;
    for(int i=0;i<200;i++)
        if(max < a[i]) max = a[i];
    printf("%d",max);
    return 0;
}