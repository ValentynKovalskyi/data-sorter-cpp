#pragma once
#include "InitialData.h"
using namespace System;
using namespace System::IO;
using namespace System::Runtime::Serialization::Formatters::Binary;
using namespace System::Collections::Generic;
using namespace System::Windows::Forms;

public ref class FileOperator {
private:
	String^ currentFileName;
public:

	FileOperator () {
        this->currentFileName = nullptr;
	}

	String^ getCurrentFile() {
		return this->currentFileName;
	}

	System::Boolean saveInitialData(InitialData^ initialData) {
        if (currentFileName == nullptr) {
            String^ fileName = SelectFile();
            if (fileName == nullptr) return false;
            FileStream^ fstr = gcnew FileStream(fileName, FileMode::Create);
            BinaryFormatter^ bf = gcnew BinaryFormatter();
            bf->Serialize(fstr, initialData);
            return true;
        } else {
            try {
                FileStream^ fstr = gcnew FileStream(currentFileName, FileMode::Open);
                BinaryFormatter^ bf = gcnew BinaryFormatter();
                bf->Serialize(fstr, initialData);
                return true;
            }
            catch (...) {
                return false;
            }
        }
	}

     String^ SelectFile() {
        OpenFileDialog^ openFileDialog = gcnew OpenFileDialog();

        openFileDialog->Title = "Choose File";
        openFileDialog->FilterIndex = 1;
        openFileDialog->RestoreDirectory = true;

        if (openFileDialog->ShowDialog() == DialogResult::OK) {
            return openFileDialog->FileName;
        }
        else {
            return nullptr; 
        }
    }

     System::Boolean openInitialData() {
             String^ fileName = SelectFile();
             if (fileName == nullptr) return false;
             FileStream^ fstr = gcnew FileStream(fileName, FileMode::Open);
             BinaryFormatter^ bf = gcnew BinaryFormatter();
             InitialData^ data = dynamic_cast<InitialData^>(bf->Deserialize(fstr));

             for each (String ^ str in data->getData()) {
                 Console::WriteLine(str);
             }

             for each (String ^ str in data->getTemplates()) {
                 Console::WriteLine(str);
             }

             currentFileName = fileName;
             return true;
     }
};