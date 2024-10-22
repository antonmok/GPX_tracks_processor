#pragma once

#include <filesystem>
#include "DataModel.h"
#include "pugixml.hpp"
#include <vector>
#include <fstream>

namespace fs = std::filesystem;

struct GpxXml
{
	pugi::xml_document doc;
	unsigned idx;
};

class CGpxReader
{
public:
	static CGpxReader& Instance();

	bool Run(fs::path gpxFilesPath);
	void Stop();

private:

	CGpxReader() {};
	~CGpxReader();
	CGpxReader(CGpxReader const&) = delete;
	CGpxReader& operator= (CGpxReader const&) = delete;

	void ReaderThread();
	void ClearXml();

	bool threadRunning_{ false };

	fs::path gpxFilesPath_;
	std::vector<GpxXml> gpxXmls_;
};
