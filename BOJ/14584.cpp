#include <cstdio>
#include <cstring>

int n;
char s[101];
bool check[20][26] = {0};

void encode(char* w, int x)
{   
    for(int i=0;w[i] != 0;i++)
        w[i] = (w[i]-'a'+x) % 26 + 'a';
}

int main()
{
    int len;
    int sol;
    scanf("%s",s);
    len = strlen(s);
    scanf("%d",&n);
    for(int l=0;l<n;l++)
    {
        char w[21];
        int llen;
        scanf("%s",w);
        llen = strlen(w);
        for(int i=0;i<26;i++)
        {
            encode(w,i);
                        for(int j=0;s[j] != 0;j++)
            {
                int k;
                for(k=0;w[k] != 0;k++)
                    if(j+k >= len || s[j+k] != w[k]) break;
                if(k == llen) check[l][i] = 1;
            }
            encode(w,26-i);
        }
    }
    for(int i=0;i<26;i++)
    {
        int j;
        for(j=0;j<n;j++)
            if(check[j][i]) sol = 26-i;
    }
    encode(s,sol);
    printf("%s",s);
    return 0;
}