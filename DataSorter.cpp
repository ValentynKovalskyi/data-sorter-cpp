#include "DataSorter.h"
#include "time.h"
#include <thread>
#include <chrono>

	using namespace System;
	using namespace System::Collections::Generic;
	using namespace System::Text::RegularExpressions;
	using namespace System::Diagnostics;

		DataSorter::DataSorter (List<String^>^ dataList, List<String^>^ templatesList) {
			this->dataList = dataList;
			this->templatesList = templatesList;
			this->lastResults = gcnew Dictionary<Regex^, List<String^>^>();
			this->lastResultsByString = gcnew Dictionary<String^, List<Regex^>^>();
		}
		
		DataSorter::DataSorter () {
			this->dataList = gcnew List<String^>();
			this->templatesList = gcnew List<String^>();
			this->lastResults = gcnew Dictionary<Regex^, List<String^>^>();
			this->lastResultsByString = gcnew Dictionary<String^, List<Regex^>^>();
		}

		DataSorter::~DataSorter() {
			delete dataList;
			delete templatesList;
		}

		List<String^>^ DataSorter::getDataList()
		{
			return this->dataList;
		}

		void DataSorter::setDataList(List<String^>^ data)
		{
			dataList = data;
		}

		List<String^>^ DataSorter::getTemplatesList()
		{
			return this->templatesList;
		}

		void DataSorter::setTemplatesList(List<String^>^ templates)
		{
			templatesList = templates;
		}

		Dictionary<Regex^, List<String^>^>^ DataSorter::execute() {
			this->lastResults->Clear();
			Stopwatch^ stopwatch = gcnew Stopwatch();
			stopwatch->Start();
			for each (String ^ regexStr in this->templatesList) {
				Regex^ regex = gcnew Regex(regexStr);
				this->lastResults->Add(regex, this->getDataMatchingRegex(regex));
			}
			this->generateResultsByString();
			std::this_thread::sleep_for(std::chrono::milliseconds(10));
			stopwatch->Stop();
			this->executionTime = stopwatch->ElapsedMilliseconds;
			return getLastResult();
		}

		Dictionary<Regex^, List<String^>^>^ DataSorter::getLastResult() {
			return this->lastResults;
		}
		
		Dictionary<String^, List<Regex^>^>^ DataSorter::getLastResultByString() {
			return this->lastResultsByString;
		}

		void DataSorter::generateResultsByString() {
			this->lastResultsByString->Clear();

			for each (String ^ str in this->dataList) {
				if (lastResultsByString->ContainsKey(str)) continue;
				List<Regex^>^ matchingRegexes = gcnew List<Regex^>();

				for each (Regex ^ regex in this->lastResults->Keys) {
					MatchCollection^ matches = regex->Matches(str);
					for each (Match ^ match in matches) {
						if (String::Compare(match->Value, str) == 0) matchingRegexes->Add(regex);
					}
				}
				this->lastResultsByString->Add(str, matchingRegexes);
			}
		}

		List<String^>^ DataSorter::getDataMatchingRegex(Regex^ regex) {
			List<String^>^ resultList = gcnew List<String^>();
			for each (String ^ str in this->dataList) {
				MatchCollection^ matches = regex->Matches(str);
				for each (Match ^ match in matches) {
					if(String::Compare(match->Value, str) == 0) resultList->Add(str);
				}
			}
			return resultList;
		}

		long long DataSorter::getExecutionTime() {
			return this->executionTime;
		};

