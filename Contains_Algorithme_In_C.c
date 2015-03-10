#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i, j, k=1;
    char str[20],sub[20];
    printf("Saisir string:");
    gets(str);
    printf("saisir substring:");
    gets(sub);
    for(i=0;i < strlen(str); i++)
    {
        if(sub[0] == str[i])
        {
            for(j=i+1;j<strlen(sub)+i;j++)
            {
                if(str[j] == sub[k]){
                    k++;
                }else{
                    k=0;
                    break;
                }
            }
            if(k == strlen(sub))
            {
                printf("OK DONE");
                return 0;
            }
        }
    }
    printf("Not Exist");
    return -1;
}
