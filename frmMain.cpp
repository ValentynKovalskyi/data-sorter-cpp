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
    frmMain::resultGrid->Columns->Clear();

    DataSorter ^ dataSorter = gcnew DataSorter(frmMain::getDataGridRows(frmMain::initialDataGrid, true), 
        frmMain::getDataGridRows(frmMain::regexGrid, true));
    Dictionary<Regex^, List<String^>^>^ sortedData = dataSorter->execute();

    this->visualizeResult(sortedData);
    this->statusMainLabel->Text = "Execution time: " + dataSorter->getExecutionTime().ToString() + " ms";
}

void frmMain::visualizeResult(Dictionary<Regex^, List<String^>^>^ result) {
    for each (Regex ^ regex in result->Keys) {
        Console::WriteLine(regex->ToString());
        Console::WriteLine("~~~~~~~~~~~~~~~");
        List <String^>^ strList;
        result->TryGetValue(regex, strList);
        frmMain::resultGrid->Columns->Add(regex->ToString(), regex->ToString());
        for (int index = 0; index < strList->Count; ++index) {
            String^ str = strList[index];
            frmMain::resultGrid->Rows->Add();
            frmMain::resultGrid->Rows[index]->Cells[regex->ToString()]->Value = str;
            Console::WriteLine("  " + str);
        }
        Console::WriteLine();
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