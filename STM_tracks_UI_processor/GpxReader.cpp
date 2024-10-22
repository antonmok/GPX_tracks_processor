#include "pch.h"
#include "GpxReader.h"
#include <thread>
#include <iostream>

using namespace pugi;

CGpxReader& CGpxReader::Instance()
{
	static CGpxReader singletonInstance;
	return singletonInstance;
}

void CGpxReader::ClearXml()
{
	for (auto& gpxXml : gpxXmls_)
		gpxXml.doc.reset();
}

CGpxReader::~CGpxReader()
{
}

bool CGpxReader::Run(fs::path gpxFilesPath)
{
	gpxFilesPath_ = gpxFilesPath;

	if (gpxFilesPath_.empty() || !fs::exists(gpxFilesPath_))
	{
		std::wcout << L"Path not exist or empty: " << gpxFilesPath_ << std::endl;
		return false;
	}
	else
	{
		for (auto const& dir_item : fs::directory_iterator(gpxFilesPath_))
		{
			std::ifstream stream(dir_item.path());
			xml_document doc;

			if (doc.load(stream))
				gpxXmls_.emplace_back(std::move(doc), 0);
		}

		threadRunning_ = true;
		std::thread readerThread(&CGpxReader::ReaderThread, this);
		readerThread.detach();

		return true;
	}
}

// simulate appending segments
void CGpxReader::ReaderThread()
{
	while (threadRunning_)
	{
		for (auto const& gpxXml : gpxXmls_)
		{
			xml_node record = gpxXml.doc.child(L"gpx").child(L"trk");

			std::wstring recordName(record.child(L"name").text().get());	/// console is govno

			xml_node segments = record.child(L"trkseg");

			unsigned count{ 0 };
			for (auto& trk : segments.children())
				++count;

			std::cout << "Nodes count: " << count << std::endl;
		}

		SleepEx(100, TRUE);
	}
}

void CGpxReader::Stop()
{
	threadRunning_ = false;
	SleepEx(100, TRUE);

	ClearXml();
}
