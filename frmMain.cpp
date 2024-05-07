#include "frmMain.h"
#include "DataSorter.h"

using namespace OSmetod;
using namespace System;
using namespace System::Windows::Forms;
using namespace System::Collections::Generic;
using namespace System::Text::RegularExpressions;

[STAThread]
void main() {

    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    frmMain frmmain;

    Application::Run(% frmmain);

}

List<String^>^ frmMain::getDataGridRows(DataGridView^ dataGrid, bool enabledOnly) {
    List<String^>^ resultList = gcnew List<String^>();

    if (dataGrid->Rows->Count == 0)
        return resultList;

    for each (DataGridViewRow^ row in dataGrid->Rows) {
        if (enabledOnly) {
            DataGridViewCheckBoxCell^ checkBoxCell = dynamic_cast<DataGridViewCheckBoxCell^>(row->Cells[1]);
            if (checkBoxCell != nullptr && !Convert::ToBoolean(checkBoxCell->Value)) continue;
        }
        if (row->Cells[0] != nullptr) {
            String^ value = row->Cells[0]->Value->ToString();
            resultList->Add(value);
        }

    }

    return resultList;
}


System::Void frmMain::executeButton_Click(System::Object^ sender, System::EventArgs^ e) {
	frmMain::executeMainTask();
}

System::Void frmMain::executeMainTask() {
    this->dataSorter->setDataList(frmMain::getDataGridRows(frmMain::initialDataGrid, true));
    this->dataSorter->setTemplatesList(frmMain::getDataGridRows(frmMain::regexGrid, true));
    Dictionary<Regex^, List<String^>^>^ sortedData = dataSorter->execute();

    if(this->sortByTemplatesRB->Checked) {
        this->visualizeResult();
    }
    else {
        this->visualizeResultByString();
    }

    this->statusMainLabel->Text = "Execution time: " + dataSorter->getExecutionTime().ToString() + " ms";
}

void frmMain::visualizeResult() {
    frmMain::resultGrid->Columns->Clear();

    for each (Regex ^ regex in this->dataSorter->getLastResult()->Keys) {
        List <String^>^ strList;
        this->dataSorter->getLastResult()->TryGetValue(regex, strList);
        frmMain::resultGrid->Columns->Add(regex->ToString(), regex->ToString());
        for (int index = 0; index < strList->Count; ++index) {
            String^ str = strList[index];
            frmMain::resultGrid->Rows->Add();
            frmMain::resultGrid->Rows[index]->Cells[regex->ToString()]->Value = str;
        }
    }
}

void frmMain::visualizeResultByString() {
    frmMain::resultGrid->Columns->Clear();

    for each (String ^ str in this->dataSorter->getLastResultByString()->Keys) {
        List <Regex^>^ regexList;
        this->dataSorter->getLastResultByString()->TryGetValue(str, regexList);
        frmMain::resultGrid->Columns->Add(str, str);
        for (int index = 0; index < regexList->Count; ++index) {
            Regex^ regex = regexList[index];
            frmMain::resultGrid->Rows->Add();
            frmMain::resultGrid->Rows[index]->Cells[str]->Value = regex->ToString();
        }
    }
}

bool frmMain::saveInitialData() {
    InitialData^ initialData = gcnew InitialData(frmMain::getDataGridRows(frmMain::initialDataGrid, false), 
        frmMain::getDataGridRows(frmMain::regexGrid, false));
    return frmMain::fileOperator->saveInitialData(initialData);
};

bool frmMain::openInitialData() {
    return frmMain::fileOperator->openInitialData();
};