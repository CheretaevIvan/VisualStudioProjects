#pragma once
#include <map>
#include <algorithm>
#include "Gosper.h"

namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	PointF^ get_min_projection(PointF^, PointF^, PointF^, PointF^);
	PointF^ get_max_projection(PointF^, PointF^, PointF^, PointF^);

	/// <summary>
	/// Сводка для MyForm
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
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
				delete A, B, C, Mouse, current_point, next_point;
			}
		}

	private: System::Int32 Alpha = 60;
	private: System::Int32 Beta = 60;
	private: System::Int32 Gamma = 60;

	private:Point^A, ^ B, ^C, ^Mouse = gcnew Point(0, 0), ^current_point, ^next_point;
	private:array<PointF> ^points = gcnew array<PointF>(0);
	private:array<PointF> ^points_green = gcnew array<PointF>(0);

	private: System::Windows::Forms::Label^  labelAlpha;



	private: System::Windows::Forms::Label^  labelBeta;

	private: System::Windows::Forms::Label^  labelGamma;
	private: System::Windows::Forms::NumericUpDown^  numericUpDownAlpha;
	private: System::Windows::Forms::NumericUpDown^  numericUpDownBeta;
	private: System::Windows::Forms::NumericUpDown^  numericUpDownGamma;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::ErrorProvider^  errorProvider;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::ComponentModel::IContainer^  components;
	protected:

	protected:

	private:
		/// <summary>
		/// Требуется переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Обязательный метод для поддержки конструктора - не изменяйте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->labelAlpha = (gcnew System::Windows::Forms::Label());
			this->labelBeta = (gcnew System::Windows::Forms::Label());
			this->labelGamma = (gcnew System::Windows::Forms::Label());
			this->numericUpDownAlpha = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDownBeta = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDownGamma = (gcnew System::Windows::Forms::NumericUpDown());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->errorProvider = (gcnew System::Windows::Forms::ErrorProvider(this->components));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownAlpha))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownBeta))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownGamma))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProvider))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// labelAlpha
			// 
			this->labelAlpha->AutoSize = true;
			this->labelAlpha->Location = System::Drawing::Point(12, 9);
			this->labelAlpha->Name = L"labelAlpha";
			this->labelAlpha->Size = System::Drawing::Size(87, 13);
			this->labelAlpha->TabIndex = 0;
			this->labelAlpha->Text = L"Введите угол α:";
			// 
			// labelBeta
			// 
			this->labelBeta->AutoSize = true;
			this->labelBeta->Location = System::Drawing::Point(12, 42);
			this->labelBeta->Name = L"labelBeta";
			this->labelBeta->Size = System::Drawing::Size(86, 13);
			this->labelBeta->TabIndex = 2;
			this->labelBeta->Text = L"Введите угол β:";
			// 
			// labelGamma
			// 
			this->labelGamma->AutoSize = true;
			this->labelGamma->Location = System::Drawing::Point(12, 71);
			this->labelGamma->Name = L"labelGamma";
			this->labelGamma->Size = System::Drawing::Size(86, 13);
			this->labelGamma->TabIndex = 4;
			this->labelGamma->Text = L"Введите угол γ:";
			// 
			// numericUpDownAlpha
			// 
			this->numericUpDownAlpha->Location = System::Drawing::Point(104, 7);
			this->numericUpDownAlpha->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 178, 0, 0, 0 });
			this->numericUpDownAlpha->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDownAlpha->Name = L"numericUpDownAlpha";
			this->numericUpDownAlpha->ReadOnly = true;
			this->numericUpDownAlpha->Size = System::Drawing::Size(49, 20);
			this->numericUpDownAlpha->TabIndex = 6;
			this->numericUpDownAlpha->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 60, 0, 0, 0 });
			this->numericUpDownAlpha->ValueChanged += gcnew System::EventHandler(this, &MyForm::numericUpDownAlpha_ValueChanged);
			// 
			// numericUpDownBeta
			// 
			this->numericUpDownBeta->Location = System::Drawing::Point(104, 40);
			this->numericUpDownBeta->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 178, 0, 0, 0 });
			this->numericUpDownBeta->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDownBeta->Name = L"numericUpDownBeta";
			this->numericUpDownBeta->ReadOnly = true;
			this->numericUpDownBeta->Size = System::Drawing::Size(49, 20);
			this->numericUpDownBeta->TabIndex = 7;
			this->numericUpDownBeta->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 60, 0, 0, 0 });
			this->numericUpDownBeta->ValueChanged += gcnew System::EventHandler(this, &MyForm::numericUpDownBeta_ValueChanged);
			// 
			// numericUpDownGamma
			// 
			this->numericUpDownGamma->Location = System::Drawing::Point(104, 69);
			this->numericUpDownGamma->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 178, 0, 0, 0 });
			this->numericUpDownGamma->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDownGamma->Name = L"numericUpDownGamma";
			this->numericUpDownGamma->ReadOnly = true;
			this->numericUpDownGamma->Size = System::Drawing::Size(49, 20);
			this->numericUpDownGamma->TabIndex = 8;
			this->numericUpDownGamma->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 60, 0, 0, 0 });
			this->numericUpDownGamma->ValueChanged += gcnew System::EventHandler(this, &MyForm::numericUpDownGamma_ValueChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(160, 13);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(38, 13);
			this->label1->TabIndex = 9;
			this->label1->Text = L"α = 60";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(160, 71);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(37, 13);
			this->label2->TabIndex = 10;
			this->label2->Text = L"β = 60";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(159, 42);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(37, 13);
			this->label3->TabIndex = 11;
			this->label3->Text = L"γ = 60";
			// 
			// errorProvider
			// 
			this->errorProvider->ContainerControl = this;
			// 
			// pictureBox1
			// 
			this->pictureBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox1->Location = System::Drawing::Point(204, 10);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(358, 199);
			this->pictureBox1->TabIndex = 12;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &MyForm::pictureBox1_Click);
			this->pictureBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::pictureBox1_Paint);
			this->pictureBox1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox1_MouseMove);
			this->pictureBox1->Resize += gcnew System::EventHandler(this, &MyForm::pictureBox1_Resize);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(574, 221);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->numericUpDownGamma);
			this->Controls->Add(this->numericUpDownBeta);
			this->Controls->Add(this->numericUpDownAlpha);
			this->Controls->Add(this->labelGamma);
			this->Controls->Add(this->labelBeta);
			this->Controls->Add(this->labelAlpha);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownAlpha))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownBeta))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownGamma))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProvider))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void numericUpDownAlpha_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
		Int32 newAlpha = Decimal::ToInt32(this->numericUpDownAlpha->Value);
		Int32 newGamma = Gamma - (newAlpha - Alpha);
		try{
			if (newAlpha != Alpha) this->errorProvider->SetError(numericUpDownGamma, "");
			this->numericUpDownGamma->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { newGamma, 0, 0, 0 });
			Gamma = newGamma;
			Alpha = newAlpha;
		}
		catch(System::ArgumentOutOfRangeException^ e){
			this->errorProvider->SetError(numericUpDownGamma, "Угол не может быть равен 0");
			this->numericUpDownAlpha->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { Alpha, 0, 0, 0 });
		}
		delete points;
		points = gcnew array<PointF>(0);
		delete points_green;
		points_green = gcnew array<PointF>(0);
		this->pictureBox1->Refresh();
	}

	private: System::Void numericUpDownBeta_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
		Int32 newBeta = Decimal::ToInt32(this->numericUpDownBeta->Value);
		Int32 newGamma = Gamma - (newBeta - Beta);
		Gamma = newGamma;
		try{
			if (newBeta != Beta) this->errorProvider->SetError(numericUpDownGamma, "");
			Alpha = Decimal::ToInt32(this->numericUpDownAlpha->Value);
			this->numericUpDownGamma->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { newGamma, 0, 0, 0 });
			Beta = newBeta;
		}
		catch(System::ArgumentOutOfRangeException^ e){
			this->errorProvider->SetError(numericUpDownGamma, "Угол не может быть равен 0");
			this->numericUpDownBeta->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { Beta, 0, 0, 0 });
		}
		delete points;
		points = gcnew array<PointF>(0);
		delete points_green;
		points_green = gcnew array<PointF>(0);
		this->pictureBox1->Refresh();
	}

	private: System::Void numericUpDownGamma_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
		this->label2->Text = L"\u03B1 = " + this->numericUpDownGamma->Value.ToString();
		Int32 newGamma = Decimal::ToInt32(this->numericUpDownGamma->Value);
		Int32 newAlpha = Alpha - (newGamma - Gamma);
		try{
			if (newGamma != Gamma) this->errorProvider->SetError(numericUpDownAlpha, "");
			this->numericUpDownAlpha->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { newAlpha, 0, 0, 0 });
			Gamma = newGamma;
			Alpha = newAlpha;
		}
		catch (System::ArgumentOutOfRangeException^ e){
			this->errorProvider->SetError(numericUpDownAlpha, "Угол не может быть равен 0");
			this->numericUpDownGamma->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { Gamma, 0, 0, 0 });
		}
		delete points;
		points = gcnew array<PointF>(0);
		delete points_green;
		points_green = gcnew array<PointF>(0);
		this->pictureBox1->Refresh();
	}

	private: System::Void pictureBox1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
		Graphics^ graphics = e->Graphics;
		RefreshTriangle(graphics);
	}

	private: System::Void pictureBox1_Resize(System::Object^  sender, System::EventArgs^  e) {
		delete points;
		points = gcnew array<PointF>(0);
		delete points_green;
		points_green = gcnew array<PointF>(0);
		this->pictureBox1->Refresh();
	}
			 
	private: System::Void RefreshTriangle(Graphics^ graphics){
		graphics->Clear(Color::White);
		Pen^ pen = gcnew Pen(Color::Black);

		Int32 w = this->pictureBox1->Width;
		Int32 h = this->pictureBox1->Height;

		System::Double AlphaRadian = System::Math::PI * Alpha / 180.0;
		System::Double BetaRadian = System::Math::PI * Beta / 180.0;
		System::Double GammaRadian = System::Math::PI * Gamma / 180.0;

		Int32 wTriang = w - 20, hTriang;

		if (Alpha > 90){
			hTriang = wTriang*Math::Tan(BetaRadian);
			if (hTriang > h - 20){
				hTriang = h - 20;
				wTriang = hTriang / Math::Tan(BetaRadian);
			}
			A = gcnew Point((w - wTriang) / 2 - wTriang*Math::Tan(BetaRadian) / Math::Tan(AlphaRadian), h - 10);
			B = gcnew Point((w + wTriang) / 2, h - 10);
			C = gcnew Point((w - wTriang) / 2, h - hTriang - 10);
		}
		else
			if (Beta > 90){
			hTriang = wTriang*Math::Tan(AlphaRadian);
			if (hTriang > h - 20){
				hTriang = h - 20;
				wTriang = hTriang / Math::Tan(AlphaRadian);
			}
			A = gcnew Point((w - wTriang) / 2, h - 10);
			B = gcnew Point((w + wTriang) / 2 + wTriang*Math::Tan(AlphaRadian) / Math::Tan(BetaRadian), h - 10);
			C = gcnew Point((w + wTriang) / 2, h - hTriang - 10);
			}
			else{
				hTriang = wTriang*Math::Tan(AlphaRadian)*Math::Tan(BetaRadian) / (Math::Tan(AlphaRadian) + Math::Tan(BetaRadian));
				if (hTriang > h - 20){
					hTriang = h - 20;
					wTriang = hTriang*(Math::Tan(AlphaRadian) + Math::Tan(BetaRadian)) / (Math::Tan(AlphaRadian)*Math::Tan(BetaRadian));
				}
				A = gcnew Point((w - wTriang) / 2, h - 10);
				B = gcnew Point((w + wTriang) / 2, h - 10);
				C = gcnew Point((w - wTriang) / 2 + wTriang*System::Math::Tan(BetaRadian) / (System::Math::Tan(AlphaRadian) + System::Math::Tan(BetaRadian)), h - hTriang - 10);
			}	
		
			Drawing::PointF ^min_projection = get_min_projection(Drawing::PointF(Mouse->X, Mouse->Y), gcnew PointF(A->X, A->Y), gcnew PointF(B->X, B->Y), gcnew PointF(C->X, C->Y));
			if (!(min_projection->IsEmpty))
				graphics->DrawLine(Pens::Red, *Mouse, *min_projection);
			array<Point> ^points_triangle = { *A, *B, *C };
			graphics->DrawPolygon(pen, points_triangle);
			if (points->Length)
				graphics->DrawLines(Pens::DarkOrange, points);
			if (points_green->Length)
				graphics->DrawLines(Pens::Green , points_green);

			graphics->DrawString(L"A", Drawing::SystemFonts::DefaultFont, System::Drawing::Brushes::Black, A->X - 10, A->Y - 5);
			graphics->DrawString(L"B", Drawing::SystemFonts::DefaultFont, System::Drawing::Brushes::Black, B->X, B->Y - 5);
			graphics->DrawString(L"C", Drawing::SystemFonts::DefaultFont, System::Drawing::Brushes::Black, C->X + 5, C->Y - 5);

			graphics->DrawString(L"\u03b1", Drawing::SystemFonts::DefaultFont, System::Drawing::Brushes::Black, A->X + 10 * Math::Cos(AlphaRadian / 2), A->Y - 10 * Math::Sin(AlphaRadian / 2) - 10);
			graphics->DrawString(L"\u03b2", Drawing::SystemFonts::DefaultFont, System::Drawing::Brushes::Black, B->X - 10 * Math::Cos(BetaRadian / 2) - 5, B->Y - 10 * Math::Sin(BetaRadian / 2) - 10);
			graphics->DrawString(L"\u03b3", Drawing::SystemFonts::DefaultFont, System::Drawing::Brushes::Black, C->X - 10 * Math::Cos(Math::PI - GammaRadian / 2 - BetaRadian) - 5, C->Y + 10 * Math::Sin(Math::PI - GammaRadian / 2 - BetaRadian) - 5);

	}

	private: System::Void pictureBox1_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		Mouse = gcnew Point(e->X, e->Y);
		this->pictureBox1->Refresh();		
	}

	private: System::Void pictureBox1_Click(System::Object^  sender, System::EventArgs^  e) {
		current_point = Point::Round(*get_min_projection(PointF(Mouse->X, Mouse->Y), gcnew PointF(A->X, A->Y), gcnew PointF(B->X, B->Y), gcnew PointF(C->X, C->Y)));
		start_solution(this->pictureBox1->CreateGraphics());
	}

	private: System::Void start_solution(Graphics^ graphics){
		this->errorProvider->SetError(this->pictureBox1, "");
		Drawing::PointF^ a = gcnew Drawing::PointF(current_point->X, current_point->Y);
		Drawing::PointF^ b = get_max_projection(a, gcnew PointF(A->X, A->Y), gcnew PointF(B->X, B->Y), gcnew PointF(C->X, C->Y));
		points->Resize(points, points->Length + 2);
		points[points->Length - 2] = *a;
		points[points->Length - 1] = *b;

		Gosper<Drawing::PointF^> cicle(get_max_projection, gcnew PointF(A->X, A->Y), gcnew PointF(B->X, B->Y), gcnew PointF(C->X, C->Y));
		int len = cicle.LengthCicle(a);
		this->label1->Text = len.ToString();

		//Drawing::PointF^ c;
		//int i = 0;
		//Drawing::PointF ab = *a - (Drawing ::SizeF(b));
		//while (ab.X*ab.X + ab.Y*ab.Y >= 1)
		//{
		//	a = get_max_projection(a);
		//	if (a->IsEmpty) return;
		//	points->Resize(points, points->Length + 2);

		//	c = get_max_projection(b);
		//	if (c->IsEmpty) return;
		//	points[points->Length - 2] = *c;

		//	b = get_max_projection(c);
		//	if (b->IsEmpty) return;
		//	points[points->Length - 1] = *b;

		//	ab = *a - (Drawing::SizeF(b));
		//	this->pictureBox1->Refresh();
		//}
		//

		//int cicle_lenght = 1;
		//b = get_max_projection(a);
		//ab = *a - (Drawing::SizeF(b));
		//while (ab.X*ab.X + ab.Y*ab.Y >= 1)
		//{
		//	b = get_max_projection(b);
		//	if (b->IsEmpty) return;

		//	ab = *a - (Drawing::SizeF(b));
		//	cicle_lenght++;
		//}
		//points_green->Resize(points_green, cicle_lenght + 1);
		//b = get_max_projection(a);
		//ab = *a - (Drawing::SizeF(b));
		//points_green[0] = *b;
		//points_green[cicle_lenght] = *b;
		//while (ab.X*ab.X + ab.Y*ab.Y >= 1)
		//{

		//	b = get_max_projection(b);
		//	if (b->IsEmpty) return;

		//	ab = *a - (Drawing::SizeF(b));
		//	points_green[--cicle_lenght] = *b;
		//}
		
	}
};

Drawing::PointF^ get_max_projection(Drawing::PointF ^point, Point^ A, Point^ B, Point^ C){
		Point^ dAB = A->operator-(*A, Drawing::Size(*B));
		Point^ dAC = A->operator-(*A, Drawing::Size(*C));
		Point^ dBC = A->operator-(*B, Drawing::Size(*C));
		double pointABy = A->Y;
		double pointABx = point->X;

		double pointACy;
		if (dAC->Y) pointACy = (dAC->X*(point->X - A->X) + dAC->Y*(point->Y) + dAC->X*dAC->X*(A->Y) / dAC->Y) / (dAC->Y + dAC->X*dAC->X / dAC->Y);
		else pointACy = A->Y;
		double pointACx;
		if (dAC->Y) pointACx = A->X + dAC->X*(pointACy - A->Y) / dAC->Y;
		else pointACx = A->X;

		double pointBCy;
		if (dBC->Y) pointBCy = (dBC->X*(point->X - B->X) + dBC->Y*(point->Y) + dBC->X*dBC->X*(B->Y) / dBC->Y) / (dBC->Y + dBC->X*dBC->X / dBC->Y);
		else pointBCy = B->Y;
		double pointBCx;
		if (dBC->Y) pointBCx = B->X + dBC->X*(pointBCy - B->Y) / dBC->Y;
		else pointBCx = B->X;

		double distanceAB = Math::Sqrt((point->X - pointABx)*(point->X - pointABx) + (point->Y - pointABy)*(point->Y - pointABy));
		double distanceAC = Math::Sqrt((point->X - pointACx)*(point->X - pointACx) + (point->Y - pointACy)*(point->Y - pointACy));
		double distanceBC = Math::Sqrt((point->X - pointBCx)*(point->X - pointBCx) + (point->Y - pointBCy)*(point->Y - pointBCy));
		std::map<double, std::pair<double, double>> distance;
		if (Math::Sqrt((A->X - C->X)*(A->X - C->X) + (A->Y - C->Y)*(A->Y - C->Y)) >= Math::Sqrt((A->X - pointACx)*(A->X - pointACx) + (A->Y - pointACy)*(A->Y - pointACy)) + Math::Sqrt((pointACx - C->X)*(pointACx - C->X) + (pointACy - C->Y)*(pointACy - C->Y)))
			distance.insert({ distanceAC, { pointACx, pointACy } });
		if (Math::Sqrt((A->X - B->X)*(A->X - B->X) + (A->Y - B->Y)*(A->Y - B->Y)) >= Math::Sqrt((A->X - pointABx)*(A->X - pointABx) + (A->Y - pointABy)*(A->Y - pointABy)) + Math::Sqrt((pointABx - B->X)*(pointABx - B->X) + (pointABy - B->Y)*(pointABy - B->Y)))
			distance.insert({ distanceAB, { pointABx, pointABy } });
		if (Math::Sqrt((B->X - C->X)*(B->X - C->X) + (B->Y - C->Y)*(B->Y - C->Y)) >= Math::Sqrt((B->X - pointBCx)*(B->X - pointBCx) + (B->Y - pointBCy)*(B->Y - pointBCy)) + Math::Sqrt((pointBCx - C->X)*(pointBCx - C->X) + (pointBCy - C->Y)*(pointBCy - C->Y)))
			distance.insert({ distanceBC, { pointBCx, pointBCy } });

		if (!distance.empty()){
			std::pair<double, double> max_projection = (*std::max_element(distance.begin(), distance.end())).second;
			return gcnew Drawing::PointF(max_projection.first, max_projection.second);
		}
		return Drawing::PointF::Empty;
	}
Drawing::PointF^ get_min_projection(Drawing::PointF ^point, Point^ A, Point^ B, Point^ C){
		try{
			Point^ dAB = A->operator-(*A, Drawing::Size(*B));
			Point^ dAC = A->operator-(*A, Drawing::Size(*C));
			Point^ dBC = A->operator-(*B, Drawing::Size(*C));
			double pointABy = A->Y;
			double pointABx = point->X;

			double pointACy;
			if (dAC->Y) pointACy = (dAC->X*(point->X - A->X) + dAC->Y*(point->Y) + dAC->X*dAC->X*(A->Y) / dAC->Y) / (dAC->Y + dAC->X*dAC->X / dAC->Y);
			else pointACy = A->Y;
			double pointACx;
			if (dAC->Y) pointACx = A->X + dAC->X*(pointACy - A->Y) / dAC->Y;
			else pointACx = A->X;

			double pointBCy;
			if (dBC->Y) pointBCy = (dBC->X*(point->X - B->X) + dBC->Y*(point->Y) + dBC->X*dBC->X*(B->Y) / dBC->Y) / (dBC->Y + dBC->X*dBC->X / dBC->Y);
			else pointBCy = B->Y;
			double pointBCx;
			if (dBC->Y) pointBCx = B->X + dBC->X*(pointBCy - B->Y) / dBC->Y;
			else pointBCx = B->X;

			double distanceAB = Math::Sqrt((point->X - pointABx)*(point->X - pointABx) + (point->Y - pointABy)*(point->Y - pointABy));
			double distanceAC = Math::Sqrt((point->X - pointACx)*(point->X - pointACx) + (point->Y - pointACy)*(point->Y - pointACy));
			double distanceBC = Math::Sqrt((point->X - pointBCx)*(point->X - pointBCx) + (point->Y - pointBCy)*(point->Y - pointBCy));
			std::map<double, std::pair<double, double>> distance;
			if (System::Math::Sqrt((A->X - C->X)*(A->X - C->X) + (A->Y - C->Y)*(A->Y - C->Y)) >= Math::Sqrt((A->X - pointACx)*(A->X - pointACx) + (A->Y - pointACy)*(A->Y - pointACy)) + Math::Sqrt((pointACx - C->X)*(pointACx - C->X) + (pointACy - C->Y)*(pointACy - C->Y)) - 0.00000001)
				distance.insert({ distanceAC, { pointACx, pointACy } });
			if (Math::Sqrt((A->X - B->X)*(A->X - B->X) + (A->Y - B->Y)*(A->Y - B->Y)) >= Math::Sqrt((A->X - pointABx)*(A->X - pointABx) + (A->Y - pointABy)*(A->Y - pointABy)) + Math::Sqrt((pointABx - B->X)*(pointABx - B->X) + (pointABy - B->Y)*(pointABy - B->Y)) - 0.00000001)
				distance.insert({ distanceAB, { pointABx, pointABy } });
			if (Math::Sqrt((B->X - C->X)*(B->X - C->X) + (B->Y - C->Y)*(B->Y - C->Y)) >= Math::Sqrt((B->X - pointBCx)*(B->X - pointBCx) + (B->Y - pointBCy)*(B->Y - pointBCy)) + Math::Sqrt((pointBCx - C->X)*(pointBCx - C->X) + (pointBCy - C->Y)*(pointBCy - C->Y)) - 0.00000001)
				distance.insert({ distanceBC, { pointBCx, pointBCy } });

			if (!distance.empty()){
				std::pair<double, double> min_projection = (*std::min_element(distance.begin(), distance.end())).second;
				return gcnew Drawing::PointF(min_projection.first, min_projection.second);
			}
		}
		catch (...){
			return Drawing::PointF::Empty;
		}
		return Drawing::PointF::Empty;
	}

}

