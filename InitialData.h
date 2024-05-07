#pragma once

using namespace System;
using namespace System::Collections::Generic;

[Serializable]
public ref class InitialData {
private:
	List<String^>^ data;
	List<String^>^ templates;
public:
	InitialData(List<String^>^ data, List<String^>^ templates) {
		this->data = data;
		this->templates = templates;
	}

	List<String^>^ getData() {
		return this->data;
	}

	List<String^>^ getTemplates() {
		return this->templates;
	}
};