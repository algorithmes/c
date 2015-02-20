#include <stdio.h>
#include <stdlib.h>

int main()
{
    int X, N, T[100], PP, i, j, test;

    printf("Enter N:"); //Array Elements' number
    scanf("%d", &N);
    printf("Enter X:"); //Integer's value to search for nearest
    scanf("%d", &X);
    printf("Elements of array  :");
    for(i=0;i<N;i++)
    {
        scanf("%d", &T[i]);
    }

    for(i=0;i<N;i++)
    {
        test = 1;
        for(j=0;j<N;j++)
        {
            if( abs(X-T[j]) < abs(X-T[i]) )
                test = 0;
        }

        if(test == 1)
            printf("Nearest Element of X = %d is: %d", X, T[i]);
    }
    system("pause");
    return 0;
}
