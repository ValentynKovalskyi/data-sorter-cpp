#pragma once

	using namespace System;
	using namespace System::Collections::Generic;
	using namespace System::Text::RegularExpressions;

	public ref class DataSorter {
	private:
		List<String^>^ dataList;
		List<String^>^ templatesList;
		Dictionary<Regex^, List<String^>^>^ lastResults;
		Dictionary<String^,List<Regex^>^>^ lastResultsByString;
		long long executionTime;
		List<String^>^ getDataMatchingRegex(Regex^ regex);

	public:
        DataSorter(List<String^>^ dataList, List<String^>^ templatesList);
		DataSorter();

        ~DataSorter();

        List<String^>^ getDataList();

        void setDataList(List<String^>^ data);

		List<String^>^ getTemplatesList();

		void setTemplatesList(List<String^>^ templates);

		Dictionary<Regex^, List<String^>^>^ execute();

		Dictionary<Regex^, List<String^>^>^ getLastResult();
		
		Dictionary<String^, List<Regex^>^>^ getLastResultByString();

		long long getExecutionTime();

		void generateResultsByString();
	};