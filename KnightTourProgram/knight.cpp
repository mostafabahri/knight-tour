#include "knight.h"

//IMPLEMNTATION of knight.h
KnightTourClass::KnightTourClass(int x, int y)
{

	//initializing the squares values
	for (size_t i = 0; i < board.size(); i++){
		for (size_t j = 0; j < board[i].size(); j++){
			board[i][j].pos = make_pair(i, j);
			board[i][j].numOfAdjs = 0;
			board[i][j].visited = false;
		}
	}

	//setting the first move
	setFirstSq(x, y);
	this->MainActivity();
}

KnightTourClass::KnightTourClass()
{

	for (size_t i = 0; i < board.size(); i++){
		for (size_t j = 0; j < board[i].size(); j++){
			board[i][j].pos = make_pair(i, j);
			board[i][j].numOfAdjs = 0;
			board[i][j].visited = false;
		}
	}
}

void KnightTourClass::setFirstSq(int x, int y)
{
	setCurrSquare(board[x][y]);
	return;
}

void KnightTourClass::MainActivity()
{
	bool pathFinished = false;

	while (!pathFinished){
		//finding valid adjacencies, storing in the vector
		vector<square> adjToProcess = adjcnts(currSquare);
		//empty() indicates there is no adjacent, therefore path finished
		if (!adjToProcess.empty()){
			for (auto &item : adjToProcess){
				adjNumbering(item);
			}
			//finding the most appropriate square to move
			setCurrSquare(findBestSq(adjToProcess));
		}
		else {
			pathFinished = true;
		}
	}
	return;
}

const vector<pair<int, int>>& KnightTourClass::getPath()
{
	return path;
}

void KnightTourClass::setCurrSquare(square& sq)
{
	board[sq.pos.first][sq.pos.second].visited = true;
	path.push_back(sq.pos);
	currSquare = sq;
}

void KnightTourClass::AdjcntsBoundChecking(int i, int j, vector<square>& vs, bool term) const
{
	//term==1 works for i, term==0 works for j
	auto validBound = [](int bnd)->bool{return (bnd >= 0 && bnd <= SIZE - 1); };

	if (term){
		if (validBound(i)){
			if (validBound(j - 1) && !board[i][j - 1].visited)
				vs.push_back(board[i][j - 1]);

			if (validBound(j + 1) && !board[i][j + 1].visited)
				vs.push_back(board[i][j + 1]);
		}
	}
	else {
		if (validBound(j)){
			if (validBound(i - 1) && !board[i - 1][j].visited)
				vs.push_back(board[i - 1][j]);

			if (validBound(i + 1) && !board[i + 1][j].visited)
				vs.push_back(board[i + 1][j]);
		}
	}

}


vector<square> KnightTourClass::adjcnts(const square &sq) const
{
	vector<square> vs;
	int i = sq.pos.first;
	int j = sq.pos.second;
	AdjcntsBoundChecking(i - 2, j, vs, 1);
	AdjcntsBoundChecking(i + 2, j, vs, 1);
	AdjcntsBoundChecking(i, j - 2, vs, 0);
	AdjcntsBoundChecking(i, j + 2, vs, 0);

	return vs;
}


void KnightTourClass::adjNumberingBoundChecking(int x, int y, int &total, bool term) const
{
	auto validBound = [](int bnd)->bool{return (bnd >= 0 && bnd <= SIZE - 1); };

	if (term){
		if (validBound(x)){
			if (validBound(y - 1) && !board[x][y - 1].visited)
				total++;

			if (validBound(y + 1) && !board[x][y + 1].visited)
				total++;
		}
	}
	else {
		if (validBound(y)){
			if (validBound(x - 1) && !board[x - 1][y].visited)
				total++;

			if (validBound(x + 1) && !board[x + 1][y].visited)
				total++;
		}
	}
	return;
}
void KnightTourClass::adjNumbering(square &sq)
{
	//using square.numOfAdjs
	int total = 0;
	int i = sq.pos.first;
	int j = sq.pos.second;

	adjNumberingBoundChecking(i - 2, j, total, 1);
	adjNumberingBoundChecking(i + 2, j, total, 1);
	adjNumberingBoundChecking(i, j - 2, total, 0);
	adjNumberingBoundChecking(i, j + 2, total, 0);

	sq.numOfAdjs = total;
	return;
}
inline double euclid(pair<int, int> X) {
	double x1 = static_cast<double>(X.first);
	double y1 = static_cast<double>(X.second);
	double x2 = 3.5;
	double y2 = 3.5;
	return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}
//using min_element and storing the best option
square KnightTourClass::findBestSq(vector<square> &vs) const
{
	square minElem = *min_element(cbegin(vs), cend(vs),
		[](square foo, square bar){ return foo.numOfAdjs < bar.numOfAdjs; });
	vector<square> mins;
	for (const auto &item : vs){
		if (minElem.numOfAdjs == item.numOfAdjs) {
			mins.push_back(item);
		}
	}
	//using Euclidean distance to the center of the checkboard
	//Roth Algorithm[1]
	square answer;
	if (mins.size()>1){
		answer = *min_element(cbegin(mins), cend(mins),
			[](square foo, square bar){return euclid(foo.pos) < euclid(bar.pos); });
		//comparing by the eculid's ;
	}
	else{
		answer = mins.front();
	}

	//the algorithm to find the best when tie happens
	return answer;
}