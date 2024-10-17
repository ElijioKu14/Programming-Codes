#include <iostream>

using namespace std ;

int main()
{
    int T ; //variable declaration of type int
    string month, day ; //variable declaration of type string
    cin >> T ; //input number test cases
    while(T--) //while test case is not zero, decrease the number of test cases for each loop
    {
        cin >> month >> day ; //input values of moth and day
        int weekend; //number of weekends to be stores
        int days = 0, d = 0 ; //declares variables and sets them to zero
        if(month == "FEB") days = 28 ; //sets the days of the month according to that month
        if(month == "JAN" || month == "MAR" || month == "MAY") days = 31 ; //each month has different amount of days
        if(month == "JUL" || month == "AUG" || month == "OCT" || month == "DEC") days = 31 ;
        if(month == "APR" || month == "JUN" || month == "SEP" || month == "NOV") days = 30 ;
        if(day == "SUN") d = 1 ; //gives each days a number stating from Sunday to Saturday 1-7
        if(day == "MON") d = 2 ;
        if(day == "TUE") d = 3 ;
        if(day == "WED") d = 4 ;
        if(day == "THU") d = 5 ;
        if(day == "FRI") d = 6 ;
        if(day == "SAT") d = 7 ;
        if (days==28) { //if the days is 28 , (28/7)*2 = 8, *2 because of saturday and sunday
            weekend=8;
        }
        if (days==30&&1<=d&&d<=4) { //if the days is 30 , and the day is between Sunday and Wednesday
            weekend=8;
        }
        if (days==30&&(d==5||d==7)) { //if the days is 30 , and the day is thursday or saturday
            weekend=9;
        }
        if (days==30&&d==6) { //if the days is 30 , and the day is friday
            weekend=10;
        }

        if (days==31&&1<=d&&d<=3) {  //if the days is 31, and the day between Sunday and tuesday
            weekend=8;
        }
        if (days==31&&(d==4||d==7)) { //if the days is 31, and the day is wednesday or saturday
            weekend=9;
        }
        if (days==31&&(d==5||d==6)) { //if the days is 31, and the day is thursday or friday
            weekend=10; //total amount of weekends between the starting date compared to the whole month
        }
        cout<<weekend<<endl; //print the number of weekends found
    }
}