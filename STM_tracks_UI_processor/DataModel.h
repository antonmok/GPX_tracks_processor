#pragma once

#include <vector>
#include <map>

//#include "cpp_stm/stm/stm.h"

// TODO: make singleton
// TODO: file input impl
// TODO: make all values transactional

//using namespace stm;

struct Point
{
	float Lat;
	float Long;
};

// TODO: fine graining? Vector or Point?
// Good news that STM frees a developer from manual synchronizing of threads which radically reduces the amount of concurrent bugs,
// so we just create a better grained models by default.
//using tPoint = TVar<Point>;
using Track = std::vector<Point>;

struct Statistic {
	std::vector<double> data;
};

struct SDataModel
{
	Track track;
	Statistic stat;
};

class CDataModel
{
public:
	CDataModel() {};
	~CDataModel() {};

	/*
	void PutPoint(id, x, y);
	void DrawTracks(dataModePtr);
	void CalcStat(id);
	*/

private:

	std::map<unsigned, SDataModel> dataModel_;
};