#pragma once
#include <vector>
#include "knight.h"
namespace KnightTourProgram {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	std::vector<std::pair<int, int>> bPath;
	KnightTourClass KT;


	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			int x = 50, y = 50;

			for (int i = 0; i < 8; ++i)
			{
				for (int j = 0; j < 8; ++j)
				{
					Point p;

					p.X = (x + i * 130);
					p.Y = (y + j * 110);
					Board[i, j] = gcnew Button();
					Board[i, j]->Location = p;
					Board[i, j]->Width = 130;
					Board[i, j]->Height = 110;
					Board[i, j]->Enabled = false;
					Board[i, j]->Font = gcnew Drawing::Font(Board[i, j]->Font->FontFamily, 15);
					Board[i, j]->FlatStyle = FlatStyle::Flat;
					Board[i, j]->FlatAppearance->BorderColor = Color::Black;
					if ((i + j) % 2)
						Board[i, j]->BackColor = Color::White;
					else
						Board[i, j]->BackColor = Color::Gray;
					this->Controls->Add(Board[i, j]);

				}
			}

			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;

			this->Width = 980;
			this->Height = 950;


			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//

		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::ComponentModel::IContainer^  components;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		//VectorWrapper vw;
		/// </summary>

	private: System::Windows::Forms::Button^  button1;

			 cli::array<Button^, 2>^ Board = gcnew cli::array<Button^, 2>(8, 8);
			 Int32 lastI = 0;
			 Int32 lastJ = 0;
			 Int32 cnt = 0;
			 bool valid_inits = false;
	private: System::Windows::Forms::TextBox^  speedTxtbox;

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  xValue;
	private: System::Windows::Forms::TextBox^  yValue;
	private: System::Windows::Forms::Button^  valueBttn;
	private: System::Windows::Forms::Label^  Xlbl;
	private: System::Windows::Forms::Label^  Ylbl;
	private: System::Windows::Forms::Button^  exitBttn;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;

	private: System::Windows::Forms::Timer^  timer1;


#pragma region Windows Form Designer generated code
			 ///DO NOT TOUCH!!!
			 /// <summary>
			 /// Required method for Designer support - do not modify
			 /// the contents of this method with the code editor.
			 /// </summary>
			 void InitializeComponent(void)
			 {
				 this->components = (gcnew System::ComponentModel::Container());
				 System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
				 this->button1 = (gcnew System::Windows::Forms::Button());
				 this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
				 this->speedTxtbox = (gcnew System::Windows::Forms::TextBox());
				 this->label1 = (gcnew System::Windows::Forms::Label());
				 this->xValue = (gcnew System::Windows::Forms::TextBox());
				 this->yValue = (gcnew System::Windows::Forms::TextBox());
				 this->valueBttn = (gcnew System::Windows::Forms::Button());
				 this->Xlbl = (gcnew System::Windows::Forms::Label());
				 this->Ylbl = (gcnew System::Windows::Forms::Label());
				 this->exitBttn = (gcnew System::Windows::Forms::Button());
				 this->label2 = (gcnew System::Windows::Forms::Label());
				 this->label3 = (gcnew System::Windows::Forms::Label());
				 this->SuspendLayout();
				 // 
				 // button1
				 // 
				 this->button1->Enabled = false;
				 this->button1->Location = System::Drawing::Point(1194, 383);
				 this->button1->Name = L"button1";
				 this->button1->Size = System::Drawing::Size(100, 30);
				 this->button1->TabIndex = 0;
				 this->button1->Text = L"Start";
				 this->button1->UseVisualStyleBackColor = true;
				 this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
				 // 
				 // timer1
				 // 
				 this->timer1->Interval = 1000;
				 this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
				 // 
				 // speedTxtbox
				 // 
				 this->speedTxtbox->Enabled = false;
				 this->speedTxtbox->Location = System::Drawing::Point(1195, 442);
				 this->speedTxtbox->Name = L"speedTxtbox";
				 this->speedTxtbox->Size = System::Drawing::Size(100, 22);
				 this->speedTxtbox->TabIndex = 1;
				 this->speedTxtbox->Text = L"300";
				 this->speedTxtbox->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
				 // 
				 // label1
				 // 
				 this->label1->AutoSize = true;
				 this->label1->Enabled = false;
				 this->label1->Location = System::Drawing::Point(1208, 467);
				 this->label1->Name = L"label1";
				 this->label1->Size = System::Drawing::Size(75, 17);
				 this->label1->TabIndex = 2;
				 this->label1->Text = L"speed(ms)";
				 // 
				 // xValue
				 // 
				 this->xValue->Location = System::Drawing::Point(1229, 191);
				 this->xValue->Name = L"xValue";
				 this->xValue->Size = System::Drawing::Size(54, 22);
				 this->xValue->TabIndex = 3;
				 this->xValue->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox2_TextChanged);
				 // 
				 // yValue
				 // 
				 this->yValue->Location = System::Drawing::Point(1229, 234);
				 this->yValue->Name = L"yValue";
				 this->yValue->Size = System::Drawing::Size(54, 22);
				 this->yValue->TabIndex = 4;
				 this->yValue->TextChanged += gcnew System::EventHandler(this, &MyForm::yValue_TextChanged);
				 // 
				 // valueBttn
				 // 
				 this->valueBttn->Location = System::Drawing::Point(1220, 282);
				 this->valueBttn->Name = L"valueBttn";
				 this->valueBttn->Size = System::Drawing::Size(75, 23);
				 this->valueBttn->TabIndex = 5;
				 this->valueBttn->Text = L"Enter";
				 this->valueBttn->UseVisualStyleBackColor = true;
				 this->valueBttn->Click += gcnew System::EventHandler(this, &MyForm::valueBttn_Click);
				 // 
				 // Xlbl
				 // 
				 this->Xlbl->AutoSize = true;
				 this->Xlbl->Location = System::Drawing::Point(1157, 194);
				 this->Xlbl->Name = L"Xlbl";
				 this->Xlbl->Size = System::Drawing::Size(57, 17);
				 this->Xlbl->TabIndex = 6;
				 this->Xlbl->Text = L"Initial X:";
				 this->Xlbl->Click += gcnew System::EventHandler(this, &MyForm::Xlbl_Click);
				 // 
				 // Ylbl
				 // 
				 this->Ylbl->AutoSize = true;
				 this->Ylbl->Location = System::Drawing::Point(1157, 239);
				 this->Ylbl->Name = L"Ylbl";
				 this->Ylbl->Size = System::Drawing::Size(57, 17);
				 this->Ylbl->TabIndex = 7;
				 this->Ylbl->Text = L"Initial Y:";
				 this->Ylbl->Click += gcnew System::EventHandler(this, &MyForm::Ylbl_Click);
				 // 
				 // exitBttn
				 // 
				 this->exitBttn->Location = System::Drawing::Point(1195, 561);
				 this->exitBttn->Name = L"exitBttn";
				 this->exitBttn->Size = System::Drawing::Size(104, 23);
				 this->exitBttn->TabIndex = 8;
				 this->exitBttn->Text = L"Exit";
				 this->exitBttn->UseVisualStyleBackColor = true;
				 this->exitBttn->Click += gcnew System::EventHandler(this, &MyForm::truncBttn_Click);
				 // 
				 // label2
				 // 
				 this->label2->AutoSize = true;
				 this->label2->Location = System::Drawing::Point(1189, 161);
				 this->label2->Name = L"label2";
				 this->label2->Size = System::Drawing::Size(125, 17);
				 this->label2->TabIndex = 9;
				 this->label2->Text = L"Valid Range: [0..7]";
				 this->label2->Click += gcnew System::EventHandler(this, &MyForm::label2_Click);
				 // 
				 // label3
				 // 
				 this->label3->AutoSize = true;
				 this->label3->Enabled = false;
				 this->label3->Location = System::Drawing::Point(1170, 358);
				 this->label3->Name = L"label3";
				 this->label3->Size = System::Drawing::Size(153, 17);
				 this->label3->TabIndex = 10;
				 this->label3->Text = L"Valid Range: [5...5000]";
				 // 
				 // MyForm
				 // 
				 this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
				 this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				 this->AutoSize = true;
				 this->BackColor = System::Drawing::SystemColors::Control;
				 this->ClientSize = System::Drawing::Size(1386, 1037);
				 this->Controls->Add(this->label3);
				 this->Controls->Add(this->label2);
				 this->Controls->Add(this->exitBttn);
				 this->Controls->Add(this->Ylbl);
				 this->Controls->Add(this->Xlbl);
				 this->Controls->Add(this->valueBttn);
				 this->Controls->Add(this->yValue);
				 this->Controls->Add(this->xValue);
				 this->Controls->Add(this->label1);
				 this->Controls->Add(this->speedTxtbox);
				 this->Controls->Add(this->button1);
				 this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
				 this->Name = L"MyForm";
				 this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
				 this->Text = L"Knight Tour";
				 this->ResumeLayout(false);
				 this->PerformLayout();

			 }
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

					 int _time = Convert::ToInt32(this->speedTxtbox->Text);
					 if (_time >= 5 && _time <= 5000){

						 KT.MainActivity();
						 bPath = KT.getPath();
						 timer1->Interval = _time;
						 timer1->Start();
					 }
					 else{
						 MessageBox::Show("Invalid Speed!");
					 }

	}
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {

				 if (cnt < int(bPath.size()) - 1){
					 cnt++;
					 int j = bPath[cnt].first;
					 int i = bPath[cnt].second;
					 int lastJ = bPath[cnt - 1].first;
					 int lastI = bPath[cnt - 1].second;
					 Board[i, j]->BackgroundImage = Image::FromFile("knightPic.png");

					 Board[lastI, lastJ]->BackgroundImage = nullptr;
					 Board[lastI, lastJ]->BackColor = Color::LightYellow;
					 Board[lastI, lastJ]->Text = Convert::ToString(cnt);
				 }
				 else{
					 timer1->Stop();
					 MessageBox::Show("Tour Done!", "FINISHED");
					 this->button1->Enabled = false;
					 this->speedTxtbox->Enabled = false;
					 this->xValue->Enabled = false;
					 this->yValue->Enabled = false;
					 this->valueBttn->Enabled = false;
					 this->label1->Enabled = false;
					 this->Xlbl->Enabled = false;
					 this->Ylbl->Enabled = false;
					 this->label2->Enabled = false;
					 this->label3->Enabled = false;
				 }
	}
	private: System::Void textBox2_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void valueBttn_Click(System::Object^  sender, System::EventArgs^  e) {
				 String^ xText = this->xValue->Text;
				 String^ yText = this->yValue->Text;
				 int init_x = Convert::ToInt32(xText);
				 int init_y = Convert::ToInt32(yText);
				 if (xText == "" || yText == ""){
					 MessageBox::Show("Initialization Required!\nEnter the values, please.");
				 }
				 else if (init_x<0 || init_x>7 || init_y<0 || init_y>7){
					 MessageBox::Show("Invalid Range!\n");
				 }
				 else {
					 valid_inits = true;
					 KT.setFirstSq(init_x, init_y);
					 Board[init_y, init_x]->BackgroundImage = Image::FromFile("knightPic.png");
					 this->button1->Enabled = true;
					 this->speedTxtbox->Enabled = true;
					 this->label1->Enabled = true;
					 this->label3->Enabled = true;
				 }

	}
	private: System::Void truncBttn_Click(System::Object^  sender, System::EventArgs^  e) {
				 exit(0);
	}

private: System::Void label2_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void Ylbl_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void Xlbl_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void yValue_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
};
}
