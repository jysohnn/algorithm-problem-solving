#include <cstdio>
#include <cstring>

int main()
{
    char a[51],b[51];
    scanf("%s %s",a,b);
    int al = strlen(a);
    int bl = strlen(b);

    if(al > bl)
    {
        int max=0;
        for(int i=0;i<=al-bl;i++)
        {
            int check=0;
            for(int j=0;j<bl;j++)
                if(a[j+i] == b[j]) check++;
            if(max < check) max = check;
        }
        printf("%d",bl-max);
    }
    else
    {
        int max=0;
        for(int i=0;i<=bl-al;i++)
        {
            int check=0;
            for(int j=0;j<al;j++)
                if(a[j] == b[j+i]) check++;
            if(max < check) max = check;
        }
        printf("%d",al-max);
    }
    return 0;
}