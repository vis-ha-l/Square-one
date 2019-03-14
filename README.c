# Square-one
#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int hourglassSum(int arr_rows, int arr_columns, int **arr) 
{
    int run;
    int sum;
    int high=-64;
    for(int l=0;l<arr_rows-2;l++)
    for(int i=0;i<arr_columns-2;i++)
    {
        run=0;sum=0;
        for(int k=l;k<l+3;k++)
        {
            if(run==0||run==2)
            {
                for(int j=i;j<i+3;j++)
                sum+=arr[k][j];
            }
            else
            {
                sum +=arr[k][i+1];
            }
            run++;
        }            
        if(sum>high)
        high=sum;
    }
    return high;
}    


int main(int argc,char *argv[])
{
    int arr_rows = 6;
    int arr_columns = 6;
    int b; int i;
    int j=0; int k=0;
    int **arr=malloc(6*(sizeof(int*)));
    
    for(int z=0;z<6;z++)
    {
        *(arr+z)=malloc(6*(sizeof(int)));
    }
    for(i=1;i<argc;i++)
    {
        b=atoi(argv[i]);
        if(b)
        {
            arr[j][k]=b;
            k++;
        }    
        else
        {
            k=0;
            j++;
        }     
    }
    for(int x=0;x<6;x++)
    {
        
        for(int y=0;y<6;y++){
            printf("%d",arr[x][y]);

        }
        printf("\n");    
    }
    
    
    if(k==6&&j==5&&arr[5][5])
    {
        int result = hourglassSum(arr_rows, arr_columns,arr);
        printf("%d\n", result);
    }
    else
    {
        printf("Invalid entry");
    }
    
    return 0;
    free(arr);
    for(int z=0;z<6;z++)
    {
        free(*(arr+z));
    }
}
