//DOCUMENTATION:
/*
////////////////////////////////////////////

Authors: Mostafa Bahri
Program: KnightTour
Lang:    C++
Date:    11/5/2015

Description:
implementing the Warnsdorff's Algorithm for
solving Knight Tour problem.
note:
for tie situations, Euclidean distance is used.

MAIN FILE 


////////////////////////////////////////////
*/

#include <algorithm>
#include <vector>
#include <array>
#include <cmath>
using namespace std;

const int SIZE = 8;

struct square{
private:
	pair<int, int> pos;
	//number of current adjacent squares
	int numOfAdjs;
	bool visited;
	friend class KnightTourClass;
};
class KnightTourClass
{
public:
	KnightTourClass(int i, int j);
	KnightTourClass();
	void setFirstSq(int x, int y);
	void MainActivity();
	const vector<pair<int, int>>& getPath();
private:
	//the main matrix, storing squares
	array<array<square, SIZE>, SIZE> board;
	square currSquare;
	//for storing the tour
	vector<pair<int, int> >path;
	vector<square> adjcnts(const square &sq) const;
	//better to be protected
	//Private methods
protected:
	void adjNumbering(square &sq);
	square findBestSq(vector<square> &vs) const;
	void AdjcntsBoundChecking(int i, int j, vector<square>& vs, bool term) const;
	void adjNumberingBoundChecking(int x, int y, int &total, bool term) const;
	void setCurrSquare(square& sq);
};
