#pragma once

#include "frmAbout.h"
#include <iostream>
#include "FileOperator.h"
#include "DataSorter.h"

namespace OSmetod {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Text::RegularExpressions;

	public ref class frmMain : public System::Windows::Forms::Form
	{
	public:
		frmMain(void)
		{
			InitializeComponent();
			frmabout = gcnew frmAbout();
			this->fileOperator = gcnew FileOperator();
			this->dataSorter = gcnew DataSorter();
		}

		System::Void executeMainTask();
		List<String^>^ getDataGridRows(DataGridView^ dataGrid, bool enabledOnly);
		void visualizeResult();
		void visualizeResultByString();
		bool saveInitialData();
		bool openInitialData();
	private: System::Windows::Forms::RadioButton^ sortByStringsRB;
	public:

	private: System::Windows::Forms::RadioButton^ sortByTemplatesRB;
	public:

	protected:
		FileOperator^ fileOperator;
		DataSorter^ dataSorter;
		~frmMain()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^ topMenu;
	private: System::Windows::Forms::ToolStripMenuItem^ topMenuFileItem;
	private: System::Windows::Forms::ToolStripMenuItem^ tmFileNew;
	private: System::Windows::Forms::ToolStripMenuItem^ tmFileLoad;
	private: System::Windows::Forms::ToolStripMenuItem^ tmFileSave;
	protected:





	protected:

	protected:




	private: System::Windows::Forms::ToolStripSeparator^ toolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^ tmFileClose;

	private: System::Windows::Forms::ToolStripMenuItem^ topMenuProcessItem;
	private: System::Windows::Forms::ToolStripMenuItem^ tmProcessStart;





	private: System::Windows::Forms::ToolStripMenuItem^ tmsiInfo;
	private: System::Windows::Forms::ToolStripMenuItem^ tmInfoHelp;
	private: System::Windows::Forms::ToolStripMenuItem^ tmInfoAbout;










	private: System::Windows::Forms::ToolStrip^ tsMain;
	private: System::Windows::Forms::ToolStripButton^ tsbNew;
	private: System::Windows::Forms::ToolStripButton^ tsbOpen;
	private: System::Windows::Forms::ToolStripButton^ tsbSave;




	private: System::Windows::Forms::ToolStripSeparator^ toolStripSeparator1;
	private: System::Windows::Forms::ToolStripButton^ executeButton;





	private: System::Windows::Forms::ToolStripSeparator^ toolStripSeparator2;
	private: System::Windows::Forms::ToolStripButton^ tsbAbout;

	private: System::Windows::Forms::ImageList^ imageList1;




























	private: System::Windows::Forms::ContextMenuStrip^ contextMenuStrip1;


	private: System::Windows::Forms::ContextMenuStrip^ contextMenuStrip2;
	private: System::Windows::Forms::ContextMenuStrip^ contextMenuStrip3;







private: System::Windows::Forms::Panel^ mainPanel;
private: System::Windows::Forms::DataGridView^ initialDataGrid;
private: System::Windows::Forms::DataGridView^ regexGrid;
private: System::Windows::Forms::Panel^ resultPanel;







private: System::Windows::Forms::ToolStrip^ toolStrip2;
private: System::Windows::Forms::ToolStripLabel^ toolStripLabel2;


private: System::Windows::Forms::DataGridView^ dataGridView3;

private: System::Windows::Forms::DataGridViewTextBoxColumn^ initialDataStringCol;
private: System::Windows::Forms::DataGridViewCheckBoxColumn^ initialDataEnabledCol;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ regexGridTemplateCol;
private: System::Windows::Forms::DataGridViewCheckBoxColumn^ regexGridEnabledCol;
private: System::Windows::Forms::DataGridView^ resultGrid;
private: System::Windows::Forms::ListBox^ additionalInfoBox;
private: System::Windows::Forms::StatusStrip^ statusStrip;

private: System::Windows::Forms::ToolStripStatusLabel^ toolStripStatusLabel1;
private: System::Windows::Forms::ToolStripProgressBar^ statusProgress;
private: System::Windows::Forms::ToolStripStatusLabel^ statusMainLabel;
private: System::Windows::Forms::SplitContainer^ initialDataContainer;






































	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(frmMain::typeid));
			this->topMenu = (gcnew System::Windows::Forms::MenuStrip());
			this->topMenuFileItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tmFileNew = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tmFileLoad = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tmFileSave = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->tmFileClose = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->topMenuProcessItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tmProcessStart = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tmsiInfo = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tmInfoHelp = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tmInfoAbout = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tsMain = (gcnew System::Windows::Forms::ToolStrip());
			this->tsbNew = (gcnew System::Windows::Forms::ToolStripButton());
			this->tsbOpen = (gcnew System::Windows::Forms::ToolStripButton());
			this->tsbSave = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripSeparator1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->executeButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripSeparator2 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->tsbAbout = (gcnew System::Windows::Forms::ToolStripButton());
			this->imageList1 = (gcnew System::Windows::Forms::ImageList(this->components));
			this->contextMenuStrip1 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->contextMenuStrip2 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->contextMenuStrip3 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->initialDataGrid = (gcnew System::Windows::Forms::DataGridView());
			this->initialDataStringCol = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->initialDataEnabledCol = (gcnew System::Windows::Forms::DataGridViewCheckBoxColumn());
			this->mainPanel = (gcnew System::Windows::Forms::Panel());
			this->initialDataContainer = (gcnew System::Windows::Forms::SplitContainer());
			this->regexGrid = (gcnew System::Windows::Forms::DataGridView());
			this->regexGridTemplateCol = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->regexGridEnabledCol = (gcnew System::Windows::Forms::DataGridViewCheckBoxColumn());
			this->resultPanel = (gcnew System::Windows::Forms::Panel());
			this->sortByTemplatesRB = (gcnew System::Windows::Forms::RadioButton());
			this->sortByStringsRB = (gcnew System::Windows::Forms::RadioButton());
			this->resultGrid = (gcnew System::Windows::Forms::DataGridView());
			this->additionalInfoBox = (gcnew System::Windows::Forms::ListBox());
			this->toolStrip2 = (gcnew System::Windows::Forms::ToolStrip());
			this->toolStripLabel2 = (gcnew System::Windows::Forms::ToolStripLabel());
			this->dataGridView3 = (gcnew System::Windows::Forms::DataGridView());
			this->statusStrip = (gcnew System::Windows::Forms::StatusStrip());
			this->toolStripStatusLabel1 = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->statusProgress = (gcnew System::Windows::Forms::ToolStripProgressBar());
			this->statusMainLabel = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->topMenu->SuspendLayout();
			this->tsMain->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->initialDataGrid))->BeginInit();
			this->mainPanel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->initialDataContainer))->BeginInit();
			this->initialDataContainer->Panel1->SuspendLayout();
			this->initialDataContainer->Panel2->SuspendLayout();
			this->initialDataContainer->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->regexGrid))->BeginInit();
			this->resultPanel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->resultGrid))->BeginInit();
			this->toolStrip2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView3))->BeginInit();
			this->statusStrip->SuspendLayout();
			this->SuspendLayout();
			// 
			// topMenu
			// 
			this->topMenu->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->topMenuFileItem, this->topMenuProcessItem,
					this->tmsiInfo
			});
			this->topMenu->Location = System::Drawing::Point(0, 0);
			this->topMenu->Name = L"topMenu";
			this->topMenu->Size = System::Drawing::Size(1108, 24);
			this->topMenu->TabIndex = 0;
			this->topMenu->Text = L"menuStrip1";
			// 
			// topMenuFileItem
			// 
			this->topMenuFileItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->tmFileNew,
					this->tmFileLoad, this->tmFileSave, this->toolStripMenuItem1, this->tmFileClose
			});
			this->topMenuFileItem->Name = L"topMenuFileItem";
			this->topMenuFileItem->Size = System::Drawing::Size(48, 20);
			this->topMenuFileItem->Text = L"Файл";
			// 
			// tmFileNew
			// 
			this->tmFileNew->Name = L"tmFileNew";
			this->tmFileNew->Size = System::Drawing::Size(180, 22);
			this->tmFileNew->Text = L"Новий";
			// 
			// tmFileLoad
			// 
			this->tmFileLoad->Name = L"tmFileLoad";
			this->tmFileLoad->Size = System::Drawing::Size(180, 22);
			this->tmFileLoad->Text = L"Відкрити";
			this->tmFileLoad->Click += gcnew System::EventHandler(this, &frmMain::tmFileLoad_Click);
			// 
			// tmFileSave
			// 
			this->tmFileSave->Name = L"tmFileSave";
			this->tmFileSave->Size = System::Drawing::Size(180, 22);
			this->tmFileSave->Text = L"Зберегти";
			this->tmFileSave->Click += gcnew System::EventHandler(this, &frmMain::tmFileSave_Click);
			// 
			// toolStripMenuItem1
			// 
			this->toolStripMenuItem1->Name = L"toolStripMenuItem1";
			this->toolStripMenuItem1->Size = System::Drawing::Size(177, 6);
			// 
			// tmFileClose
			// 
			this->tmFileClose->Name = L"tmFileClose";
			this->tmFileClose->Size = System::Drawing::Size(180, 22);
			this->tmFileClose->Text = L"Закрити";
			this->tmFileClose->Click += gcnew System::EventHandler(this, &frmMain::tsbexit_Click);
			// 
			// topMenuProcessItem
			// 
			this->topMenuProcessItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->tmProcessStart });
			this->topMenuProcessItem->Name = L"topMenuProcessItem";
			this->topMenuProcessItem->Size = System::Drawing::Size(61, 20);
			this->topMenuProcessItem->Text = L"Процес";
			this->topMenuProcessItem->Click += gcnew System::EventHandler(this, &frmMain::topMenuProcessItem_Click);
			// 
			// tmProcessStart
			// 
			this->tmProcessStart->Name = L"tmProcessStart";
			this->tmProcessStart->Size = System::Drawing::Size(180, 22);
			this->tmProcessStart->Text = L"Почати";
			// 
			// tmsiInfo
			// 
			this->tmsiInfo->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->tmInfoHelp,
					this->tmInfoAbout
			});
			this->tmsiInfo->Name = L"tmsiInfo";
			this->tmsiInfo->Size = System::Drawing::Size(83, 20);
			this->tmsiInfo->Text = L"Інформація";
			// 
			// tmInfoHelp
			// 
			this->tmInfoHelp->Name = L"tmInfoHelp";
			this->tmInfoHelp->Size = System::Drawing::Size(180, 22);
			this->tmInfoHelp->Text = L"Допомога";
			// 
			// tmInfoAbout
			// 
			this->tmInfoAbout->Name = L"tmInfoAbout";
			this->tmInfoAbout->Size = System::Drawing::Size(180, 22);
			this->tmInfoAbout->Text = L"Про програму";
			this->tmInfoAbout->Click += gcnew System::EventHandler(this, &frmMain::tsbInfo_Click);
			// 
			// tsMain
			// 
			this->tsMain->ImageScalingSize = System::Drawing::Size(32, 32);
			this->tsMain->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(7) {
				this->tsbNew, this->tsbOpen,
					this->tsbSave, this->toolStripSeparator1, this->executeButton, this->toolStripSeparator2, this->tsbAbout
			});
			this->tsMain->Location = System::Drawing::Point(0, 24);
			this->tsMain->Name = L"tsMain";
			this->tsMain->Size = System::Drawing::Size(1108, 39);
			this->tsMain->TabIndex = 1;
			// 
			// tsbNew
			// 
			this->tsbNew->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->tsbNew->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"tsbNew.Image")));
			this->tsbNew->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->tsbNew->Name = L"tsbNew";
			this->tsbNew->Size = System::Drawing::Size(36, 36);
			this->tsbNew->Text = L"New";
			this->tsbNew->Click += gcnew System::EventHandler(this, &frmMain::tsbNew_Click);
			this->tsbNew->MouseEnter += gcnew System::EventHandler(this, &frmMain::tsbNew_MouseEnter);
			this->tsbNew->MouseLeave += gcnew System::EventHandler(this, &frmMain::tsbNew_MouseLeave);
			// 
			// tsbOpen
			// 
			this->tsbOpen->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->tsbOpen->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"tsbOpen.Image")));
			this->tsbOpen->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->tsbOpen->Name = L"tsbOpen";
			this->tsbOpen->Size = System::Drawing::Size(36, 36);
			this->tsbOpen->Text = L"toolStripButton4";
			// 
			// tsbSave
			// 
			this->tsbSave->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->tsbSave->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"tsbSave.Image")));
			this->tsbSave->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->tsbSave->Name = L"tsbSave";
			this->tsbSave->Size = System::Drawing::Size(36, 36);
			this->tsbSave->Text = L"toolStripButton3";
			// 
			// toolStripSeparator1
			// 
			this->toolStripSeparator1->Name = L"toolStripSeparator1";
			this->toolStripSeparator1->Size = System::Drawing::Size(6, 39);
			// 
			// executeButton
			// 
			this->executeButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->executeButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"executeButton.Image")));
			this->executeButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->executeButton->Name = L"executeButton";
			this->executeButton->Size = System::Drawing::Size(36, 36);
			this->executeButton->Text = L"Execute";
			this->executeButton->Click += gcnew System::EventHandler(this, &frmMain::executeButton_Click);
			// 
			// toolStripSeparator2
			// 
			this->toolStripSeparator2->Name = L"toolStripSeparator2";
			this->toolStripSeparator2->Size = System::Drawing::Size(6, 39);
			// 
			// tsbAbout
			// 
			this->tsbAbout->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->tsbAbout->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"tsbAbout.Image")));
			this->tsbAbout->ImageScaling = System::Windows::Forms::ToolStripItemImageScaling::None;
			this->tsbAbout->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->tsbAbout->Name = L"tsbAbout";
			this->tsbAbout->Size = System::Drawing::Size(36, 36);
			this->tsbAbout->Text = L"toolStripButton1";
			this->tsbAbout->Click += gcnew System::EventHandler(this, &frmMain::tsbInfo_Click);
			// 
			// imageList1
			// 
			this->imageList1->ImageStream = (cli::safe_cast<System::Windows::Forms::ImageListStreamer^>(resources->GetObject(L"imageList1.ImageStream")));
			this->imageList1->TransparentColor = System::Drawing::Color::Transparent;
			this->imageList1->Images->SetKeyName(0, L"document_empty.png");
			this->imageList1->Images->SetKeyName(1, L"folder.png");
			this->imageList1->Images->SetKeyName(2, L"disk.png");
			this->imageList1->Images->SetKeyName(3, L"control_play_blue.png");
			this->imageList1->Images->SetKeyName(4, L"control_stop_blue.png");
			this->imageList1->Images->SetKeyName(5, L"information.png");
			// 
			// contextMenuStrip1
			// 
			this->contextMenuStrip1->Name = L"contextMenuStrip1";
			this->contextMenuStrip1->Size = System::Drawing::Size(61, 4);
			// 
			// contextMenuStrip2
			// 
			this->contextMenuStrip2->Name = L"contextMenuStrip2";
			this->contextMenuStrip2->Size = System::Drawing::Size(61, 4);
			// 
			// contextMenuStrip3
			// 
			this->contextMenuStrip3->Name = L"contextMenuStrip3";
			this->contextMenuStrip3->Size = System::Drawing::Size(61, 4);
			// 
			// initialDataGrid
			// 
			this->initialDataGrid->AllowUserToResizeColumns = false;
			this->initialDataGrid->AllowUserToResizeRows = false;
			this->initialDataGrid->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->initialDataGrid->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->initialDataGrid->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Sunken;
			this->initialDataGrid->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->initialDataGrid->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
				this->initialDataStringCol,
					this->initialDataEnabledCol
			});
			this->initialDataGrid->Cursor = System::Windows::Forms::Cursors::Hand;
			this->initialDataGrid->Dock = System::Windows::Forms::DockStyle::Fill;
			this->initialDataGrid->Location = System::Drawing::Point(0, 0);
			this->initialDataGrid->Name = L"initialDataGrid";
			this->initialDataGrid->RowHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Sunken;
			this->initialDataGrid->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->initialDataGrid->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->initialDataGrid->Size = System::Drawing::Size(232, 409);
			this->initialDataGrid->TabIndex = 0;
			this->initialDataGrid->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &frmMain::dataGridView1_CellContentClick);
			this->initialDataGrid->RowsAdded += gcnew System::Windows::Forms::DataGridViewRowsAddedEventHandler(this, &frmMain::initialDataGrid_RowsAdded);
			// 
			// initialDataStringCol
			// 
			this->initialDataStringCol->FillWeight = 149.2386F;
			this->initialDataStringCol->HeaderText = L"String";
			this->initialDataStringCol->Name = L"initialDataStringCol";
			// 
			// initialDataEnabledCol
			// 
			this->initialDataEnabledCol->FillWeight = 50.76142F;
			this->initialDataEnabledCol->HeaderText = L"Enabled";
			this->initialDataEnabledCol->Name = L"initialDataEnabledCol";
			// 
			// mainPanel
			// 
			this->mainPanel->Controls->Add(this->initialDataContainer);
			this->mainPanel->Controls->Add(this->resultPanel);
			this->mainPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->mainPanel->Location = System::Drawing::Point(0, 63);
			this->mainPanel->Name = L"mainPanel";
			this->mainPanel->Size = System::Drawing::Size(1108, 441);
			this->mainPanel->TabIndex = 4;
			// 
			// initialDataContainer
			// 
			this->initialDataContainer->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom));
			this->initialDataContainer->Location = System::Drawing::Point(0, 3);
			this->initialDataContainer->Name = L"initialDataContainer";
			// 
			// initialDataContainer.Panel1
			// 
			this->initialDataContainer->Panel1->Controls->Add(this->initialDataGrid);
			// 
			// initialDataContainer.Panel2
			// 
			this->initialDataContainer->Panel2->Controls->Add(this->regexGrid);
			this->initialDataContainer->Size = System::Drawing::Size(484, 409);
			this->initialDataContainer->SplitterDistance = 232;
			this->initialDataContainer->TabIndex = 5;
			// 
			// regexGrid
			// 
			this->regexGrid->AllowUserToResizeColumns = false;
			this->regexGrid->AllowUserToResizeRows = false;
			this->regexGrid->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->regexGrid->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->regexGrid->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Sunken;
			this->regexGrid->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->regexGrid->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
				this->regexGridTemplateCol,
					this->regexGridEnabledCol
			});
			this->regexGrid->Cursor = System::Windows::Forms::Cursors::Hand;
			this->regexGrid->Dock = System::Windows::Forms::DockStyle::Fill;
			this->regexGrid->Location = System::Drawing::Point(0, 0);
			this->regexGrid->Name = L"regexGrid";
			this->regexGrid->RowHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Sunken;
			this->regexGrid->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->regexGrid->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->regexGrid->Size = System::Drawing::Size(248, 409);
			this->regexGrid->TabIndex = 3;
			this->regexGrid->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &frmMain::dataGridView2_CellContentClick);
			this->regexGrid->RowsAdded += gcnew System::Windows::Forms::DataGridViewRowsAddedEventHandler(this, &frmMain::regexGrid_RowsAdded);
			// 
			// regexGridTemplateCol
			// 
			this->regexGridTemplateCol->FillWeight = 149.2386F;
			this->regexGridTemplateCol->HeaderText = L"Template";
			this->regexGridTemplateCol->Name = L"regexGridTemplateCol";
			// 
			// regexGridEnabledCol
			// 
			this->regexGridEnabledCol->FillWeight = 50.76142F;
			this->regexGridEnabledCol->HeaderText = L"Enabled";
			this->regexGridEnabledCol->Name = L"regexGridEnabledCol";
			// 
			// resultPanel
			// 
			this->resultPanel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Right));
			this->resultPanel->Controls->Add(this->sortByTemplatesRB);
			this->resultPanel->Controls->Add(this->sortByStringsRB);
			this->resultPanel->Controls->Add(this->resultGrid);
			this->resultPanel->Controls->Add(this->additionalInfoBox);
			this->resultPanel->Controls->Add(this->toolStrip2);
			this->resultPanel->Controls->Add(this->dataGridView3);
			this->resultPanel->Location = System::Drawing::Point(487, 0);
			this->resultPanel->Name = L"resultPanel";
			this->resultPanel->Size = System::Drawing::Size(633, 441);
			this->resultPanel->TabIndex = 2;
			// 
			// sortByTemplatesRB
			// 
			this->sortByTemplatesRB->AutoSize = true;
			this->sortByTemplatesRB->Checked = true;
			this->sortByTemplatesRB->Location = System::Drawing::Point(55, 2);
			this->sortByTemplatesRB->Name = L"sortByTemplatesRB";
			this->sortByTemplatesRB->Size = System::Drawing::Size(70, 17);
			this->sortByTemplatesRB->TabIndex = 5;
			this->sortByTemplatesRB->TabStop = true;
			this->sortByTemplatesRB->Text = L"templates";
			this->sortByTemplatesRB->UseVisualStyleBackColor = true;
			this->sortByTemplatesRB->CheckedChanged += gcnew System::EventHandler(this, &frmMain::templatesRB_CheckedChanged);
			// 
			// sortByStringsRB
			// 
			this->sortByStringsRB->AutoSize = true;
			this->sortByStringsRB->Location = System::Drawing::Point(131, 3);
			this->sortByStringsRB->Name = L"sortByStringsRB";
			this->sortByStringsRB->Size = System::Drawing::Size(55, 17);
			this->sortByStringsRB->TabIndex = 6;
			this->sortByStringsRB->Text = L"strings";
			this->sortByStringsRB->UseVisualStyleBackColor = true;
			this->sortByStringsRB->CheckedChanged += gcnew System::EventHandler(this, &frmMain::stringsRB_CheckedChanged);
			// 
			// resultGrid
			// 
			this->resultGrid->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->resultGrid->Dock = System::Windows::Forms::DockStyle::Fill;
			this->resultGrid->Location = System::Drawing::Point(0, 25);
			this->resultGrid->Name = L"resultGrid";
			this->resultGrid->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::CellSelect;
			this->resultGrid->Size = System::Drawing::Size(452, 416);
			this->resultGrid->TabIndex = 4;
			// 
			// additionalInfoBox
			// 
			this->additionalInfoBox->Dock = System::Windows::Forms::DockStyle::Right;
			this->additionalInfoBox->FormattingEnabled = true;
			this->additionalInfoBox->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"sdfsdf", L"sdfsdf", L"sdfsdf" });
			this->additionalInfoBox->Location = System::Drawing::Point(452, 25);
			this->additionalInfoBox->Name = L"additionalInfoBox";
			this->additionalInfoBox->Size = System::Drawing::Size(181, 416);
			this->additionalInfoBox->TabIndex = 3;
			this->additionalInfoBox->SelectedIndexChanged += gcnew System::EventHandler(this, &frmMain::listBox1_SelectedIndexChanged);
			// 
			// toolStrip2
			// 
			this->toolStrip2->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->toolStripLabel2 });
			this->toolStrip2->Location = System::Drawing::Point(0, 0);
			this->toolStrip2->Name = L"toolStrip2";
			this->toolStrip2->Size = System::Drawing::Size(633, 25);
			this->toolStrip2->TabIndex = 1;
			this->toolStrip2->Text = L"toolStrip2";
			// 
			// toolStripLabel2
			// 
			this->toolStripLabel2->Name = L"toolStripLabel2";
			this->toolStripLabel2->Size = System::Drawing::Size(44, 22);
			this->toolStripLabel2->Text = L"Sort by";
			// 
			// dataGridView3
			// 
			this->dataGridView3->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataGridView3->Location = System::Drawing::Point(0, 0);
			this->dataGridView3->Name = L"dataGridView3";
			this->dataGridView3->Size = System::Drawing::Size(633, 441);
			this->dataGridView3->TabIndex = 0;
			// 
			// statusStrip
			// 
			this->statusStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->toolStripStatusLabel1,
					this->statusProgress, this->statusMainLabel
			});
			this->statusStrip->Location = System::Drawing::Point(0, 478);
			this->statusStrip->Name = L"statusStrip";
			this->statusStrip->Size = System::Drawing::Size(1108, 26);
			this->statusStrip->TabIndex = 5;
			this->statusStrip->Text = L"statusStrip1";
			// 
			// toolStripStatusLabel1
			// 
			this->toolStripStatusLabel1->Name = L"toolStripStatusLabel1";
			this->toolStripStatusLabel1->Size = System::Drawing::Size(52, 21);
			this->toolStripStatusLabel1->Text = L"Progress";
			this->toolStripStatusLabel1->Click += gcnew System::EventHandler(this, &frmMain::toolStripStatusLabel1_Click);
			// 
			// statusProgress
			// 
			this->statusProgress->Name = L"statusProgress";
			this->statusProgress->Overflow = System::Windows::Forms::ToolStripItemOverflow::Never;
			this->statusProgress->Size = System::Drawing::Size(250, 20);
			// 
			// statusMainLabel
			// 
			this->statusMainLabel->Name = L"statusMainLabel";
			this->statusMainLabel->Size = System::Drawing::Size(0, 21);
			// 
			// frmMain
			// 
			this->ClientSize = System::Drawing::Size(1108, 504);
			this->Controls->Add(this->statusStrip);
			this->Controls->Add(this->mainPanel);
			this->Controls->Add(this->tsMain);
			this->Controls->Add(this->topMenu);
			this->MainMenuStrip = this->topMenu;
			this->Name = L"frmMain";
			this->Text = L"Data Sorter";
			this->Load += gcnew System::EventHandler(this, &frmMain::frmMain_Load);
			this->topMenu->ResumeLayout(false);
			this->topMenu->PerformLayout();
			this->tsMain->ResumeLayout(false);
			this->tsMain->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->initialDataGrid))->EndInit();
			this->mainPanel->ResumeLayout(false);
			this->initialDataContainer->Panel1->ResumeLayout(false);
			this->initialDataContainer->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->initialDataContainer))->EndInit();
			this->initialDataContainer->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->regexGrid))->EndInit();
			this->resultPanel->ResumeLayout(false);
			this->resultPanel->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->resultGrid))->EndInit();
			this->toolStrip2->ResumeLayout(false);
			this->toolStrip2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView3))->EndInit();
			this->statusStrip->ResumeLayout(false);
			this->statusStrip->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		private: frmAbout^ frmabout;

	private: System::Void tsbInfo_Click(System::Object^ sender, System::EventArgs^ e) {
		frmabout->ShowDialog();
	}
private: System::Void executeButton_Click(System::Object^ sender, System::EventArgs^ e);
private: void doprogress(float value) {
	if (statusProgress->Value != (int)value) statusProgress->Value = int(value);
	Application::DoEvents();
}

private: System::Void tsbNew_Click(System::Object^ sender, System::EventArgs^ e) {
	
}
private: System::Void tsbexit_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}
private: System::Void lvMain_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void frmMain_Load(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void listView1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void tspMain_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void scView_Panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void scView_Panel2_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void tslInfo_Click(System::Object^ sender, System::EventArgs^ e) {
}

private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label1_Click_1(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void dataGridView_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
}
private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
}
private: System::Void toolStripComboBox1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void listBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void dataGridView2_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
}
private: System::Void toolStripStatusLabel1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void tsbNew_MouseEnter(System::Object^ sender, System::EventArgs^ e) {
	statusMainLabel->Text = "Create new file with initial data";
}
private: System::Void tsbNew_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
	statusMainLabel->Text = "";
}
private: System::Void tmFileSave_Click(System::Object^ sender, System::EventArgs^ e) {
	saveInitialData();
}
private: System::Void tmFileLoad_Click(System::Object^ sender, System::EventArgs^ e) {
	openInitialData();
}
private: System::Void initialDataGrid_RowsAdded(System::Object^ sender, System::Windows::Forms::DataGridViewRowsAddedEventArgs ^ e) {
	Console::WriteLine(e->RowIndex);
	this->initialDataGrid->Rows[e->RowIndex - 1]->Cells[1]->Value = true;
}
private: System::Void regexGrid_RowsAdded(System::Object^ sender, System::Windows::Forms::DataGridViewRowsAddedEventArgs ^ e) {
	Console::WriteLine(e->RowIndex);
	this->regexGrid->Rows[e->RowIndex - 1]->Cells[1]->Value = true;
}
private: System::Void templatesRB_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->sortByTemplatesRB->Checked) {
		this->visualizeResult();
	}
}
private: System::Void stringsRB_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	Console::WriteLine("asd1");
	if (this->sortByStringsRB->Checked) {
		Console::WriteLine("asd");
		this->visualizeResultByString();
	}
}
private: System::Void topMenuProcessItem_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
