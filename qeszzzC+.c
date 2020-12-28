
#include<iostream>
#include<cstdio>
struct sparse
{
    int row,col,val;
};
void readmat(sparse sp[])
{
    printf("enter total number number of rows ,column of matrix and total
    of nonzero values in this\n");
    scanf("%d %d %d",&sp[0].row,&sp[0].col,&sp[0].val);
    printf("now start entering the values by specifying index
    position\n");
    for(int i=1;i<=sp[0].val;i++)
        scanf("%d %d %d",&sp[i].row,&sp[i].col,&sp[i].val);
}
void displaymat(sparse sp[])
{
    int k=1;
    for(int i=0;i<sp[0].row;i++)
    {
        for(int j=0;j<sp[0].col;j++)
        {
             if(k<=sp[0].val&&i==sp[k].row&&j==sp[k].col)
             {
                 printf("%d\t",sp[k].val);
                 k++;
             }
             else
                 printf("0\t");
         }
         printf("\n");
    }

}
int main()
{
    struct sparse sp1[10],sp2[10],sp3[10];
    printf("for first matrix\n");
    readmat(sp1);
    printf("for second matrix\n");
    readmat(sp2);
    displaymat(sp1);
    printf("\n\n");
    displaymat(sp2);
    printf("\n\n");
    displaymat(sp3);
    return 0;
 }
