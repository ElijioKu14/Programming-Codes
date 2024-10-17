#include <stdio.h>
int main(void){


int n;
float sum = 0;

int a;
float avg;

scanf("%d",&n);
int high=n-3;
int arr[n];

if(n>6)
{

    for(int i=0;i<n;i++)
    {
    scanf("%d",&arr[i]);

    }

    for(int i=0;i<n;i++)
    {
        for( int j=i+1;j<n;j++)
        {
        if(arr[i]>arr[j])
        {
        a=arr[i];
        arr[i]=arr[j];
        arr[j]=a;

        }
        }

    } //check if it outputs array in order

    for(int j=3;j<high;j++)

    {

    sum+=arr[j];
    }



avg=sum/(n - 6);
printf("%.2f",avg);

}
else
{
    printf("-1");
}

}