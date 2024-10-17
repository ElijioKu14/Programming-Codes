#include <stdio.h>
#include <math.h>
void sortarrays(int a[],int b[],int l)
{
    int i,j;
    i = 0;
    while (i<l)
    {
        //finding the smallest number in the subarray
        int index_of_smallest = i;
        for(j=i; j<l; j++)
        {
            if (a[j]<a[index_of_smallest])
                index_of_smallest = j;
        }

        //swapping
        int temp = a[i];
        int temp2 = b[i];
        a[i] = a[index_of_smallest];
        b[i] = b[index_of_smallest];
        a[index_of_smallest] = temp;
        b[index_of_smallest] = temp2;
        ++i;
    }
}

int main(void)
{
    int test_cases,N;
    float m,highest=0;

    //Scans the first line (test cases).
    //and declares the answers array
    scanf("%d",&test_cases);
    float answers[test_cases];
    float x[100],y[100];

    //Scans the number of points, and creates the array
    for(int i=0;i<test_cases;++i){
        scanf("%d",&N);
        highest=0;
    //Scans the points and stores them on an array
        for(int j=0;j<N;++j){
            scanf("%f %f",&x[j],&y[j]);
        }

    //Sorts both arrays in order of x
        sortarrays(x,y,N);

    //Computes the distance
        for(int k=N-1;k>=0;--k){
            if(k==N-1){highest=y[k];answers[i]+=highest;}
            else if(y[k]>highest){
                    m=(y[k+1]-y[k])/(x[k+1]-x[k]);
                    answers[i]+=sqrt(pow(y[k]-highest,2)+pow((y[k]-highest)/m,2));
                    highest=y[k];
                    }
        }

    }

    //Prints the answers
    for(int i=0;i<test_cases;++i){
        printf("%.2f\n",answers[i]);
    }
    return 0;
}