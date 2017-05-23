class Solution {
public:
	vector<int> constructRectangle(int area) {
		vector<int> v;

		int sqrt = sqrt_int(area);
		if (sqrt * sqrt == area)
		{
			v.push_back(sqrt);
			v.push_back(sqrt);
		}
		else
		{
			int W = sqrt;

			while (W < area && area % W != 0)
				W++;

			int L = area / W;

			if (W < L)
			{
				v.push_back(L);
				v.push_back(W);
			}
			else
			{
				v.push_back(W);
				v.push_back(L);
			}
		}

		return v;
	}
private:
	int sqrt_int(int num)
	{
		double sqrtD = num;
		double preSqrtD = sqrtD;

		//Xn+1 = (Xn+num/Xn)/2
		do
		{
			preSqrtD = sqrtD;
			sqrtD = (sqrtD + num/sqrtD) / 2.0;
		} while (abs(sqrtD - preSqrtD) > 0.1);

		return (int)sqrtD;
	}

	double abs(double num)
	{
		if (num < 0)
			num = -num;

		return num;
	}
};