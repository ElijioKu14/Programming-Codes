#include <iostream>
#include <vector>


using namespace std;


int main()
{
    int n;
    while(cin>>n)
    {

       vector<int> seq(n);
       for (int i = 0; i < n; ++i)
        cin >> seq[i];

       vector<int> inc;
       vector<int> dec;
		inc.emplace_back(seq[0]);
		dec.emplace_back(seq[n - 1]);

		vector<int> n1(n);
		vector<int> n2(n);
		n1[0] = 1;
		n2[n - 1] = 1;
		int c1 = 1;
		int c2 = 1;


		for (int i = 1; i < n; ++i)
		{
			//increasing
			if (seq[i] > inc.back())
			{
				inc.emplace_back(seq[i]);

				n1[i] = ++c1;
			}
			else
			{
				//position of next value greater than current one
				auto iterator = lower_bound(inc.begin(), inc.end(), seq[i]);
				//moves the iterator
				*iterator = seq[i];

				n1[i] = (iterator - inc.begin() + 1);
			}

			//decreasing
			int j = n - i - 1;
			if (seq[j] > dec.back())
			{
				dec.emplace_back(seq[j]);
				n2[j] = ++c2;
			}
			else
			{
				auto iterator = lower_bound(dec.begin(), dec.end(), seq[j]);
				*iterator = seq[j];
				n2[j] = (iterator - dec.begin() + 1);
			}
		}

		//Returns minimum count
		int t = min(c1, c2);

		//Looks for the actual biggest sequence
		for (; t > 0; --t)
            for (int i = 0; i < n; ++i)
                if (n1[i] >= t && n2[i] >= t) goto out;

	out:
		cout << t * 2 - 1 << "\n";

    }

}