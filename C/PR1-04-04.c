#include <stdio.h>
int main(void) {
  int alice = 0;
  int bob = 0;

  char oneA = '\0';
  char twoB = '\0';
  

  for (int turns = 0; turns <5; turns++) {
      scanf("%c%c ", &oneA, &twoB);

      oneA = tolower(oneA);
      twoB = tolower(twoB);


      if ((oneA == 'p' && twoB == 'r') || (oneA == 'r' && twoB == 's') || (oneA == 's' && twoB == 'p')) {
        alice++;
      }
    		else if ((twoB == 'p' &&  oneA == 'r') || (twoB == 'r' && oneA == 's') || (twoB == 's' && oneA == 'p')){
       			 bob++;
     				 }


  }

    if (alice == bob) {
      printf("Draw");
    }
  		else if (bob > alice) {
      		printf("Bob");
    	}
  				else if (alice > bob) {
     				 printf("Alice");
    			}
}