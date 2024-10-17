#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
struct POINT {int x; int y;}; //declaration of struct Point with objects x and y
int main(void) {
	// vecScent information for previously recorded losses robot left
	vector<int> vecScent; //declaration of vector vecScent of type int

	 // szIns stores the instructions, szOri stores the directions
	char szIns[100], szOri[4] = {'N', 'E', 'S', 'W'};

	 // ptSize records size of the map
	 //ptPos records current position
	 // ptOri records the direction corresponding offset
	POINT ptSize, ptPos, ptOri[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

	cin >> ptSize.x >> ptSize.y; 	 // Input Map Size


	for (char cOri; cin >> ptPos.x >> ptPos.y >> cOri >> szIns; ) {  	 // loop processes each input of a robot
		int nOri = find(&szOri[0], &szOri[4], cOri) - &szOri[0], i = 0; // determine the direction corresponding to the initial number
		for (; szIns[i] != 0; ++i) { 		 // loop process every step of the move
			if (szIns[i] != 'F') { 			 // turn left or turn right
				nOri = (nOri + (szIns[i] == 'L' ? 3 : 1)) % 4;
				continue;
			}

			POINT ptNew = {ptPos.x + ptOri[nOri].x, ptPos.y + ptOri[nOri].y}; // move forward, to be moved to the calculated coordinates
			if (ptNew.x >= 0 && ptNew.x <= ptSize.x && ptNew.y >= 0 && ptNew.y <= ptSize.y) { 		// If this move did not cause the loss, save the new coordinates

					ptPos = ptNew;
					continue;
			}
// Otherwise, encoded by the loss of the position and orientation before loss
			int nScent = ptPos.y * 51 + ptPos.x;// + nOri * 51 * 51;
			vector<int>::iterator iEnd = vecScent.end(); 		// Find in history if there is a robot in this loss
			if (find(vecScent.begin(), iEnd, nScent) == iEnd) { // If this had not been a loss, the loss of the current robot
				vecScent.push_back(nScent); 	// record loss of information
				break;
			}
		}

		cout << ptPos.x << ' ' << ptPos.y << ' ' << szOri[nOri]; //output position and direction
		cout << ((szIns[i] == 0) ? "" : " LOST") << endl; //output "LOST" if the condition is met
	}
	return 0;
}