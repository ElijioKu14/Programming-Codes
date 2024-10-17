#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int n,m,i,j,a,b,cases,no_quotes,s[101],e[101]; //declaration of integere

int days[13]={0,31,28,31,30,31,30,31,31,30,31,30,31}; //array showing the days in a month

char c[147000];

int leap(int ly) //this takes care of the leap years that exist and returns the integer values

{

	return (ly%400==0)||((ly%4==0)&&(ly%100));

}
//this function gets the date
void get_date(int day)
{
    int y,month; //declare of y and m, y for year and m for month

    for(y=1700;day>365+leap(y);y++)// y is initialized to 1700, days must be more than a year and the leap year
        day-=365+leap(y); //the condition as long as the for loop is not broken

	for(month=1;day>days[month]+(month==2&&leap(y));month++) //this is for month as it is initialized to 1, to represent january

		day-=days[month]+(month==2&&leap(y));//as long as the for loop is not broken will the result be attained by subtracting

	printf("%d/%d/%d",month,day,y);// displays the month, date and year

}

int f(int x)
{
	int i,tmp,sum;

	tmp=x/10000; //have the input parameter be divided by 10000

	sum=0;//initialize of sum

	for(i=1700;i<tmp;i++) //for loop as long as i is less than the temp then can proceed

	{

		sum+=365;// calculate the sum with the days of the years already being included

		if(leap(i)) //if it is a leap year then

			sum++;// iterate the sum again

	}

	tmp=x%10000/100; //this is the modulus of x MOD 10000/100

	for(i=1;i<tmp;i++) //for as u less than temp then

	{

		sum+=days[i]; //have the arrays of day being added

		if(i==2&&leap(x/10000)) //when i==2 it is the month affected by leap year

			sum++;

	}

	return sum+x%100; //this returns the value calculated

}

void fill(int a,int b,int x) //this function utilizes the above function

{

	int a1,b1; //declares two int variables

	a1=f(a);// when a is inputted to the function of f, then the result will be stored into a1/

	b1=f(b); //when b is inputted into the same function then it is stored in b1.

	memset(&c[a1],x,b1-a1+1);// this is used to fill a block of memory with this value
	//&c[a1] is the starting address of memory to be filled, x is the value to be filled, and the last one is the number of bytes to be filled starting from the first argument to be filled

}

int main() //main function

{

	while(scanf("%d%d",&n,&m)&&n+m) //while (inserts value)

	{

		memset(c,0,sizeof(c)); //this is the memset function being utilized once again

		for(i=0;i<n;i++) //as long as i is less than n then

			scanf("%d%d",&s[i],&e[i]); //enter the pairs of dates and date ranges

		for(i=0;i<m;i++) //as long as i is less than m then can enter a and b to be inputted into the fill function

		{

			scanf("%d%d",&a,&b);

			fill(a,b,2);//inputs these values into the function known as fill

		}

		for(i=0;i<n;i++) //for i less than n, then

			fill(s[i],e[i],1);//put these values in the fill.

		printf("Case %d:\n",++cases); //this is the amount of cases

		no_quotes=1; // being intialized to 1.

		for(i=0;i<147000;i++) //as long as i is less than 47000 then

			if(c[i]>1) //if c[i] is more than 1 then

			{

				no_quotes=0; //this is a flag

				get_date(i); //i is used for the get_date function

				if(c[i+1]<2)

					printf("\n"); //this prints a space

				else

				{

					printf(" to "); //prints "to"

					for(j=i;c[j]>1;j++); //this gives the date range end.

					get_date(j-1);

					printf("\n");

					i=j;//assigning j values to i.

				}
			}
			if(no_quotes) //if (1) then display that code.
				printf("No additional quotes are required.\n");
	}
	return 0;
}