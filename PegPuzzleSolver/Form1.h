#pragma once
#include "PuzzleSolver.h"

namespace PegPuzzleSolver {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
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
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  startButton;
	private: System::Windows::Forms::TextBox^  solutionBox;
	protected: 


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->startButton = (gcnew System::Windows::Forms::Button());
			this->solutionBox = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// startButton
			// 
			this->startButton->Location = System::Drawing::Point(215, 354);
			this->startButton->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->startButton->Name = L"startButton";
			this->startButton->Size = System::Drawing::Size(112, 35);
			this->startButton->TabIndex = 0;
			this->startButton->Text = L"Start";
			this->startButton->UseVisualStyleBackColor = true;
			this->startButton->Click += gcnew System::EventHandler(this, &Form1::startButton_Click);
			// 
			// solutionBox
			// 
			this->solutionBox->Location = System::Drawing::Point(52, 51);
			this->solutionBox->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->solutionBox->Multiline = true;
			this->solutionBox->Name = L"solutionBox";
			this->solutionBox->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->solutionBox->Size = System::Drawing::Size(428, 277);
			this->solutionBox->TabIndex = 1;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(532, 403);
			this->Controls->Add(this->solutionBox);
			this->Controls->Add(this->startButton);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->Name = L"Form1";
			this->Text = L"Peg Puzzle Solver";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void startButton_Click(System::Object^  sender, System::EventArgs^  e) {
				 PuzzleSolver ps;

				 solutionBox->Text = "";

				 for(int i = 0; i < 15; i++)
				 {
					 solutionBox->Text += ps.getBoard(i);
				 }
			 }
	};
}

