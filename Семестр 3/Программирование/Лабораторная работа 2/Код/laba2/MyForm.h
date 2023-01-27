#pragma once
#include <vector>
#include <algorithm>

namespace laba2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
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
	private: System::Windows::Forms::Label^ n_label;
	protected:
	private: System::Windows::Forms::Label^ m_label;
	private: System::Windows::Forms::TextBox^ n_box;
	private: System::Windows::Forms::TextBox^ m_box;
	private: System::Windows::Forms::Button^ apply_size_button;
	private: System::Windows::Forms::Button^ calculate_button;
	private: System::Windows::Forms::DataGridView^ matrix;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle3 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle4 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->n_label = (gcnew System::Windows::Forms::Label());
			this->m_label = (gcnew System::Windows::Forms::Label());
			this->n_box = (gcnew System::Windows::Forms::TextBox());
			this->m_box = (gcnew System::Windows::Forms::TextBox());
			this->apply_size_button = (gcnew System::Windows::Forms::Button());
			this->calculate_button = (gcnew System::Windows::Forms::Button());
			this->matrix = (gcnew System::Windows::Forms::DataGridView());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->matrix))->BeginInit();
			this->SuspendLayout();
			// 
			// n_label
			// 
			this->n_label->AutoSize = true;
			this->n_label->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 13.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->n_label->ForeColor = System::Drawing::Color::SlateBlue;
			this->n_label->Location = System::Drawing::Point(81, 98);
			this->n_label->Name = L"n_label";
			this->n_label->Size = System::Drawing::Size(51, 52);
			this->n_label->TabIndex = 0;
			this->n_label->Text = L"N";
			this->n_label->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// m_label
			// 
			this->m_label->AutoSize = true;
			this->m_label->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 13.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->m_label->ForeColor = System::Drawing::Color::SlateBlue;
			this->m_label->Location = System::Drawing::Point(81, 174);
			this->m_label->Name = L"m_label";
			this->m_label->Size = System::Drawing::Size(53, 52);
			this->m_label->TabIndex = 1;
			this->m_label->Text = L"M";
			this->m_label->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// n_box
			// 
			this->n_box->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->n_box->Location = System::Drawing::Point(140, 98);
			this->n_box->Name = L"n_box";
			this->n_box->Size = System::Drawing::Size(100, 52);
			this->n_box->TabIndex = 2;
			this->n_box->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// m_box
			// 
			this->m_box->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->m_box->Location = System::Drawing::Point(140, 174);
			this->m_box->Name = L"m_box";
			this->m_box->Size = System::Drawing::Size(100, 52);
			this->m_box->TabIndex = 3;
			this->m_box->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// apply_size_button
			// 
			this->apply_size_button->BackColor = System::Drawing::Color::SlateBlue;
			this->apply_size_button->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 13.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->apply_size_button->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->apply_size_button->Location = System::Drawing::Point(68, 249);
			this->apply_size_button->Name = L"apply_size_button";
			this->apply_size_button->Size = System::Drawing::Size(228, 68);
			this->apply_size_button->TabIndex = 4;
			this->apply_size_button->Text = L"Apply Size";
			this->apply_size_button->UseVisualStyleBackColor = false;
			this->apply_size_button->Click += gcnew System::EventHandler(this, &MyForm::apply_size_button_Click);
			// 
			// calculate_button
			// 
			this->calculate_button->BackColor = System::Drawing::Color::SlateBlue;
			this->calculate_button->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 13.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->calculate_button->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->calculate_button->Location = System::Drawing::Point(430, 811);
			this->calculate_button->Name = L"calculate_button";
			this->calculate_button->Size = System::Drawing::Size(265, 77);
			this->calculate_button->TabIndex = 5;
			this->calculate_button->Text = L"Calculate";
			this->calculate_button->UseVisualStyleBackColor = false;
			this->calculate_button->Click += gcnew System::EventHandler(this, &MyForm::calculate_button_Click);
			// 
			// matrix
			// 
			this->matrix->AllowUserToAddRows = false;
			this->matrix->AllowUserToResizeColumns = false;
			this->matrix->AllowUserToResizeRows = false;
			this->matrix->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::AllCells;
			this->matrix->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllCells;
			this->matrix->BackgroundColor = System::Drawing::Color::LightPink;
			this->matrix->BorderStyle = System::Windows::Forms::BorderStyle::None;
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle1->BackColor = System::Drawing::Color::SlateBlue;
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 13.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::Color::MediumAquamarine;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->matrix->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
			this->matrix->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->matrix->ColumnHeadersVisible = false;
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle2->BackColor = System::Drawing::Color::SlateBlue;
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 13.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle2->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::Color::MediumAquamarine;
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->matrix->DefaultCellStyle = dataGridViewCellStyle2;
			this->matrix->EnableHeadersVisualStyles = false;
			this->matrix->GridColor = System::Drawing::SystemColors::ButtonHighlight;
			this->matrix->Location = System::Drawing::Point(329, 76);
			this->matrix->Margin = System::Windows::Forms::Padding(6);
			this->matrix->Name = L"matrix";
			dataGridViewCellStyle3->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle3->BackColor = System::Drawing::Color::SlateBlue;
			dataGridViewCellStyle3->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 13.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle3->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			dataGridViewCellStyle3->SelectionBackColor = System::Drawing::Color::MediumAquamarine;
			dataGridViewCellStyle3->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle3->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->matrix->RowHeadersDefaultCellStyle = dataGridViewCellStyle3;
			this->matrix->RowHeadersVisible = false;
			this->matrix->RowHeadersWidth = 82;
			dataGridViewCellStyle4->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle4->BackColor = System::Drawing::Color::SlateBlue;
			dataGridViewCellStyle4->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 13.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle4->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			dataGridViewCellStyle4->SelectionBackColor = System::Drawing::Color::MediumAquamarine;
			dataGridViewCellStyle4->SelectionForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->matrix->RowsDefaultCellStyle = dataGridViewCellStyle4;
			this->matrix->RowTemplate->Height = 33;
			this->matrix->Size = System::Drawing::Size(779, 671);
			this->matrix->TabIndex = 6;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::LightPink;
			this->ClientSize = System::Drawing::Size(1137, 934);
			this->Controls->Add(this->matrix);
			this->Controls->Add(this->calculate_button);
			this->Controls->Add(this->apply_size_button);
			this->Controls->Add(this->m_box);
			this->Controls->Add(this->n_box);
			this->Controls->Add(this->m_label);
			this->Controls->Add(this->n_label);
			this->Cursor = System::Windows::Forms::Cursors::Default;
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->matrix))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void apply_size_button_Click(System::Object^ sender, System::EventArgs^ e) {
		matrix->RowCount = Convert::ToInt32(n_box->Text);
		matrix->ColumnCount = Convert::ToInt32(m_box->Text);
	}
	private: System::Void calculate_button_Click(System::Object^ sender, System::EventArgs^ e) {
		unsigned int i, j, k;
		int minelem;
		std::vector<int> vec;
		int a[15][15];
		int N = Convert::ToUInt32(n_box->Text);
		int M = Convert::ToUInt32(m_box->Text);
		for (i = 0; i < N; i++)
			for (j = 0; j < M; j++)
				a[i][j] = (System::Convert::ToInt32(matrix->Rows[i]->Cells[j]->Value));

		for (i = 0; i < N; i++) {
			for (j = 0; j < M; j++) vec.push_back(a[i][j]);
			minelem = *std::min_element(vec.begin(), vec.end());
			if (vec.size() > 0)
				if (vec[1] == minelem) {
					std::sort(vec.begin(), vec.end(), std::greater<int>());
					for (k = 0; k < M; k++) a[i][k] -= 2;
				}
			vec.clear();
		}
		for (i = 0; i < N; i++)
			for (j = 0; j < M; j++)
				matrix->Rows[i]->Cells[j]->Value = a[i][j];
	}
	};
}
