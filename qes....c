#include<stdio.h>
void addition(int ktemp[3][100], int ltemp[3][100], int k, int l);
int main() {
    int m,n;
    scanf("%d",&m);
    scanf("%d",&n);
    int A[m][n];
    int B[m][n];
    for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++) {
            scanf("%d",&A[i][j]);
        }
    }
    for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++) {
            scanf("%d",&B[i][j]);
        }
    }

    int size = 0;
            for (int i = 0; i < m; i++)
                for (int j = 0; j < n; j++)
                    if (A[i][j] != 0)
                        size++;
            int AS[3][100];
            int y=size;
            size = 0;
            for (int i = 0; i < m; i++)
                for (int j = 0; j < n; j++)
                    if (B[i][j] != 0)
                        size++;
            int BS[3][100];
            int z=size;
            int k = 0;
            for (int i = 0; i < m; i++)
                for (int j = 0; j < n; j++)
                    if (A[i][j] != 0)
                    {
                        AS[0][k] = i;
                        AS[1][k] = j;
                        AS[2][k] = A[i][j];
                        k++;
                    }
            k=0;
            for (int i = 0; i < m; i++)
                for (int j = 0; j < n; j++)
                    if (B[i][j] != 0)
                    {
                        BS[0][k] = i;
                        BS[1][k] = j;
                        BS[2][k] = B[i][j];
                        k++;
                    }

            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < y; j++) {
                    printf("%d ",AS[i][j]);
                }
                printf("\n");
            }
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < z; j++) {
                    printf("%d ",BS[i][j]);
                }
                printf("\n");
            }
            addition(AS,BS,y,z);
    // int kk;
    // scanf("%d",&kk);
    // switch(kk) {
    //     case 1:

    //     break;
    //     case 2:

    //     break;
    //     case 3:
    //     break;
    // }
}
void addition(int ktemp[3][100], int ltemp[3][100], int k, int l)
{
    int i = 0, j = 0, sparse[3][100], x = 0;

    while (i < k && j < l)
    {
        if ((ktemp[0][i] == ltemp[0][j]) && (ltemp[1][j] == ktemp[1][i]))
        {
            printf("Entered this");
            sparse[0][x] = ktemp[0][i];
            sparse[1][x] = ktemp[1][i];
            sparse[2][x] = ltemp[2][j] + ktemp[2][i];
            x++;
            i++;
            j++;
        }
        else
        {
            if (ktemp[0][i] < ltemp[0][j])
            {
                sparse[0][x] = ktemp[0][i];
                sparse[1][x] = ktemp[1][i];
                sparse[2][x] = ktemp[2][i];
                x++;
                i++;
            }

            else
            {
                if ((ktemp[0][i] == ltemp[0][j]) && (ktemp[1][i] < ltemp[1][j]))
                {
                    sparse[0][x] = ktemp[0][i];
                    sparse[1][x] = ktemp[1][i];
                    sparse[2][x] = ktemp[2][i];
                    x++;
                    i++;
                }
                else
                {
                    sparse[0][x] = ktemp[0][j];
                    sparse[1][x] = ktemp[1][j];
                    sparse[2][x] = ktemp[2][j];
                    x++;
                    j++;
                }
            }
        }
    }

    while (i < k)
    {
        sparse[0][x] = ktemp[0][i];
        sparse[1][x] = ktemp[1][i];
        sparse[2][x] = ktemp[2][i];
        x++;
        i++;
    }
    while (j < l)
    {
        sparse[0][x] = ktemp[0][j];
        sparse[1][x] = ktemp[1][j];
        sparse[2][x] = ktemp[2][j];
        x++;
        j++;
    }

    printf("\n Addition Matrix is \n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < x; j++)
        {
            printf("%d", sparse[i][j]);
        }
        printf("\n");
    }
}
