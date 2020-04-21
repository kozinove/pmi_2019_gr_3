#pragma once

#include "Polynom.h"
#include <string>
#include <iostream>
#include <msclr\marshal_cppstd.h>


namespace lab4 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::TextBox^  textBox5;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Label^  label11;

	protected:

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(79, 150);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(773, 20);
			this->textBox1->TabIndex = 0;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(900, 147);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(145, 23);
			this->button1->TabIndex = 1;
			this->button1->Text = L"CALCULATE\r\n";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(76, 123);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(76, 19);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Polynom A";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(79, 238);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(773, 20);
			this->textBox2->TabIndex = 3;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(76, 216);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(76, 19);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Polynom B";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(900, 236);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(145, 23);
			this->button2->TabIndex = 5;
			this->button2->Text = L"CALCULATE";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(168, 216);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(0, 19);
			this->label3->TabIndex = 6;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(158, 123);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(0, 19);
			this->label4->TabIndex = 7;
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"SUM", L"SUB", L"MUL" });
			this->comboBox1->Location = System::Drawing::Point(900, 290);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(145, 21);
			this->comboBox1->TabIndex = 8;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBox1_SelectedIndexChanged);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(21, 396);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(0, 19);
			this->label5->TabIndex = 9;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(77, 77);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(204, 13);
			this->label6->TabIndex = 10;
			this->label6->Text = L"INPUT EXAMPLE: 12x0y3z10 - 10x1y4z3";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(22, 362);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(55, 13);
			this->label7->TabIndex = 11;
			this->label7->Text = L"OUTPUT:";
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(900, 317);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(145, 23);
			this->button3->TabIndex = 12;
			this->button3->Text = L"CALCULATE";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(941, 57);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(104, 20);
			this->textBox3->TabIndex = 13;
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(941, 83);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(104, 20);
			this->textBox4->TabIndex = 14;
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(941, 109);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(104, 20);
			this->textBox5->TabIndex = 15;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(918, 60);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(17, 13);
			this->label8->TabIndex = 16;
			this->label8->Text = L"X:";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(918, 86);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(17, 13);
			this->label9->TabIndex = 17;
			this->label9->Text = L"Y:";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(918, 112);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(17, 13);
			this->label10->TabIndex = 18;
			this->label10->Text = L"Z:";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(76, 362);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(0, 13);
			this->label11->TabIndex = 19;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1113, 450);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		std::string str = msclr::interop::marshal_as<std::string>(textBox1->Text);
		PolynomCList *A = new PolynomCList;
		A->maxgp(str);
		A->ffstr(str);
		double x = atof((msclr::interop::marshal_as<std::string>(textBox3->Text)).c_str());
		double y = atof((msclr::interop::marshal_as<std::string>(textBox4->Text)).c_str());
		double z = atof((msclr::interop::marshal_as<std::string>(textBox5->Text)).c_str());
		std::string s = " -- RESULT = ";
		double res = A->calculate(x, y, z);
		s.append((std::to_string(res)));
		label4->Text = msclr::interop::marshal_as<String^>(s);
	}
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		std::string str = msclr::interop::marshal_as<std::string>(textBox2->Text);
		PolynomCList *B = new PolynomCList;
		B->maxgp(str);
		B->ffstr(str);
		double x = atof((msclr::interop::marshal_as<std::string>(textBox3->Text)).c_str());
		double y = atof((msclr::interop::marshal_as<std::string>(textBox4->Text)).c_str());
		double z = atof((msclr::interop::marshal_as<std::string>(textBox5->Text)).c_str());
		std::string s = " -- RESULT = ";
		double res = B->calculate(x,y,z);
		s.append((std::to_string(res)));
		label3->Text = msclr::interop::marshal_as<String^>(s);
	}
public: System::Void comboBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
	int index = comboBox1->SelectedIndex;
	std::string str1 = msclr::interop::marshal_as<std::string>(textBox1->Text);
	std::string str2 = msclr::interop::marshal_as<std::string>(textBox2->Text);
	PolynomCList A;
	PolynomCList B;
	A.maxgp(str1);
	B.maxgp(str2);
	A.ffstr(str1);
	B.ffstr(str2);
	PolynomCList RES;
	switch (index) {
	case 0: 
		RES = A + B;
		label5->Text = msclr::interop::marshal_as<System::String^>(RES.ptos());
		break;
	case 1:
		RES = A - B;
		label5->Text = msclr::interop::marshal_as<System::String^>(RES.ptos());
		break;
	case 2:
		RES = A * B;
		label5->Text = msclr::interop::marshal_as<System::String^>(RES.ptos());
		break;
	default:
		break;
	}
}
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
	int index = comboBox1->SelectedIndex;
	std::string str1 = msclr::interop::marshal_as<std::string>(textBox1->Text);
	std::string str2 = msclr::interop::marshal_as<std::string>(textBox2->Text);
	PolynomCList A;
	PolynomCList B;
	A.maxgp(str1);
	B.maxgp(str2);
	A.ffstr(str1);
	B.ffstr(str2);
	PolynomCList RES;
	switch (index) {
	case 0:
		RES = A + B;
		break;
	case 1:
		RES = A - B;
		break;
	case 2:
		RES = A * B;
		break;
	default:
		break;
	}
	double x = atof((msclr::interop::marshal_as<std::string>(textBox3->Text)).c_str());
	double y = atof((msclr::interop::marshal_as<std::string>(textBox4->Text)).c_str());
	double z = atof((msclr::interop::marshal_as<std::string>(textBox5->Text)).c_str());
	std::string s = "  RESULT = ";
	double res = RES.calculate(x, y, z);
	s.append((std::to_string(res)));
	label11->Text = msclr::interop::marshal_as<String^>(s);
}
};
}