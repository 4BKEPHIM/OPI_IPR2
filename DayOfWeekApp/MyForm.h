// MyForm.h - главное окно программы
#pragma once

#include "DateLogic.h"

namespace DayOfWeekApp
{
    using namespace System;
    using namespace System::Drawing;
    using namespace System::Windows::Forms;

    public ref class MyForm : public Form
    {
    public:
        MyForm()
        {
            InitializeComponent();

            // месяцы в выпадающий список
            cmbMonth->Items->Add(L"Январь");
            cmbMonth->Items->Add(L"Февраль");
            cmbMonth->Items->Add(L"Март");
            cmbMonth->Items->Add(L"Апрель");
            cmbMonth->Items->Add(L"Май");
            cmbMonth->Items->Add(L"Июнь");
            cmbMonth->Items->Add(L"Июль");
            cmbMonth->Items->Add(L"Август");
            cmbMonth->Items->Add(L"Сентябрь");
            cmbMonth->Items->Add(L"Октябрь");
            cmbMonth->Items->Add(L"Ноябрь");
            cmbMonth->Items->Add(L"Декабрь");

            // при запуске сразу ставим сегодняшнюю дату
            SetToday();
        }

    private:
        Label^ lblTitle;
        GroupBox^ grpInput;
        Label^ lblDay;
        TextBox^ txtDay;
        Label^ lblMonth;
        ComboBox^ cmbMonth;
        Label^ lblYear;
        TextBox^ txtYear;
        Label^ lblCalendar;
        DateTimePicker^ dtpCalendar;
        Button^ btnCalc;
        Button^ btnToday;
        Button^ btnClear;
        GroupBox^ grpResult;
        Label^ lblResult;
        Label^ lblInfo;
        GroupBox^ grpHistory;
        ListBox^ lstHistory;

        void InitializeComponent()
        {
            lblTitle = gcnew Label();
            lblTitle->Text = L"Определение дня недели по дате";
            lblTitle->Font = gcnew Drawing::Font(L"Segoe UI", 13, FontStyle::Bold);
            lblTitle->AutoSize = true;
            lblTitle->Location = Point(12, 12);

            // ввод даты
            grpInput = gcnew GroupBox();
            grpInput->Text = L"Введите дату";
            grpInput->Location = Point(12, 50);
            grpInput->Size = Drawing::Size(440, 120);

            lblDay = gcnew Label();
            lblDay->Text = L"День:";
            lblDay->AutoSize = true;
            lblDay->Location = Point(15, 32);

            txtDay = gcnew TextBox();
            txtDay->Location = Point(15, 52);
            txtDay->Size = Drawing::Size(60, 25);
            txtDay->MaxLength = 2;
            txtDay->TextAlign = HorizontalAlignment::Center;
            txtDay->KeyPress += gcnew KeyPressEventHandler(this, &MyForm::OnlyDigits);

            lblMonth = gcnew Label();
            lblMonth->Text = L"Месяц:";
            lblMonth->AutoSize = true;
            lblMonth->Location = Point(95, 32);

            cmbMonth = gcnew ComboBox();
            cmbMonth->DropDownStyle = ComboBoxStyle::DropDownList;
            cmbMonth->Location = Point(95, 52);
            cmbMonth->Size = Drawing::Size(150, 25);

            lblYear = gcnew Label();
            lblYear->Text = L"Год:";
            lblYear->AutoSize = true;
            lblYear->Location = Point(265, 32);

            txtYear = gcnew TextBox();
            txtYear->Location = Point(265, 52);
            txtYear->Size = Drawing::Size(80, 25);
            txtYear->MaxLength = 4;
            txtYear->TextAlign = HorizontalAlignment::Center;
            txtYear->KeyPress += gcnew KeyPressEventHandler(this, &MyForm::OnlyDigits);

            lblCalendar = gcnew Label();
            lblCalendar->Text = L"или выберите в календаре:";
            lblCalendar->AutoSize = true;
            lblCalendar->Location = Point(15, 88);

            dtpCalendar = gcnew DateTimePicker();
            dtpCalendar->Format = DateTimePickerFormat::Short;
            dtpCalendar->Location = Point(205, 84);
            dtpCalendar->Size = Drawing::Size(140, 25);
            dtpCalendar->ValueChanged += gcnew EventHandler(this, &MyForm::dtpCalendar_ValueChanged);

            grpInput->Controls->Add(lblDay);
            grpInput->Controls->Add(txtDay);
            grpInput->Controls->Add(lblMonth);
            grpInput->Controls->Add(cmbMonth);
            grpInput->Controls->Add(lblYear);
            grpInput->Controls->Add(txtYear);
            grpInput->Controls->Add(lblCalendar);
            grpInput->Controls->Add(dtpCalendar);

            // кнопки
            btnCalc = gcnew Button();
            btnCalc->Text = L"Определить";
            btnCalc->Location = Point(12, 180);
            btnCalc->Size = Drawing::Size(140, 32);
            btnCalc->Click += gcnew EventHandler(this, &MyForm::btnCalc_Click);

            btnToday = gcnew Button();
            btnToday->Text = L"Сегодня";
            btnToday->Location = Point(162, 180);
            btnToday->Size = Drawing::Size(140, 32);
            btnToday->Click += gcnew EventHandler(this, &MyForm::btnToday_Click);

            btnClear = gcnew Button();
            btnClear->Text = L"Очистить";
            btnClear->Location = Point(312, 180);
            btnClear->Size = Drawing::Size(140, 32);
            btnClear->Click += gcnew EventHandler(this, &MyForm::btnClear_Click);

            // результат
            grpResult = gcnew GroupBox();
            grpResult->Text = L"Результат";
            grpResult->Location = Point(12, 222);
            grpResult->Size = Drawing::Size(440, 95);

            lblResult = gcnew Label();
            lblResult->Font = gcnew Drawing::Font(L"Segoe UI", 16, FontStyle::Bold);
            lblResult->ForeColor = Color::DarkBlue;
            lblResult->Location = Point(15, 22);
            lblResult->Size = Drawing::Size(410, 35);
            lblResult->Text = L"-";

            lblInfo = gcnew Label();
            lblInfo->Location = Point(15, 60);
            lblInfo->Size = Drawing::Size(410, 25);
            lblInfo->Text = L"Введите дату и нажмите \"Определить\".";

            grpResult->Controls->Add(lblResult);
            grpResult->Controls->Add(lblInfo);

            // история
            grpHistory = gcnew GroupBox();
            grpHistory->Text = L"История запросов";
            grpHistory->Location = Point(12, 327);
            grpHistory->Size = Drawing::Size(440, 130);

            lstHistory = gcnew ListBox();
            lstHistory->Location = Point(10, 22);
            lstHistory->Size = Drawing::Size(420, 100);
            grpHistory->Controls->Add(lstHistory);

            // само окно
            this->Text = L"День недели";
            this->Font = gcnew Drawing::Font(L"Segoe UI", 9.75F);
            this->ClientSize = Drawing::Size(464, 469);
            this->FormBorderStyle = Windows::Forms::FormBorderStyle::FixedSingle;
            this->MaximizeBox = false;
            this->StartPosition = FormStartPosition::CenterScreen;
            this->AcceptButton = btnCalc; // Enter = кнопка "Определить"

            this->Controls->Add(lblTitle);
            this->Controls->Add(grpInput);
            this->Controls->Add(btnCalc);
            this->Controls->Add(btnToday);
            this->Controls->Add(btnClear);
            this->Controls->Add(grpResult);
            this->Controls->Add(grpHistory);
        }

        void SetToday()
        {
            DateTime now = DateTime::Today;
            txtDay->Text = now.Day.ToString();
            cmbMonth->SelectedIndex = now.Month - 1;
            txtYear->Text = now.Year.ToString();
            dtpCalendar->Value = now;
        }

        void ShowError(String^ text)
        {
            MessageBox::Show(text, L"Ошибка ввода", MessageBoxButtons::OK, MessageBoxIcon::Warning);
        }

        // в поля дня и года можно вводить только цифры (и стирать Backspace)
        void OnlyDigits(Object^ sender, KeyPressEventArgs^ e)
        {
            if (!Char::IsDigit(e->KeyChar) && e->KeyChar != '\b')
                e->Handled = true;
        }

        // выбрали дату в календаре - переносим ее в поля
        void dtpCalendar_ValueChanged(Object^ sender, EventArgs^ e)
        {
            txtDay->Text = dtpCalendar->Value.Day.ToString();
            cmbMonth->SelectedIndex = dtpCalendar->Value.Month - 1;
            txtYear->Text = dtpCalendar->Value.Year.ToString();
        }

        // кнопка "Определить"
        void btnCalc_Click(Object^ sender, EventArgs^ e)
        {
            // проверяем, что все заполнено
            if (txtDay->Text->Length == 0)
            {
                ShowError(L"Введите день.");
                txtDay->Focus();
                return;
            }
            if (cmbMonth->SelectedIndex == -1)
            {
                ShowError(L"Выберите месяц.");
                cmbMonth->Focus();
                return;
            }
            if (txtYear->Text->Length == 0)
            {
                ShowError(L"Введите год.");
                txtYear->Focus();
                return;
            }

            // переводим текст в числа
            int day, year;
            if (!Int32::TryParse(txtDay->Text, day))
            {
                ShowError(L"День должен быть целым числом.");
                txtDay->Focus();
                return;
            }
            if (!Int32::TryParse(txtYear->Text, year))
            {
                ShowError(L"Год должен быть целым числом.");
                txtYear->Focus();
                return;
            }
            int month = cmbMonth->SelectedIndex + 1;

            // формула Зеллера работает для григорианского календаря,
            // а он появился только в октябре 1582 года
            if (year < 1583 || year > 9999)
            {
                ShowError(L"Год должен быть от 1583 до 9999.");
                txtYear->Focus();
                return;
            }

            // есть ли такой день в этом месяце
            int maxDay = DaysInMonth(month, year);
            if (day < 1 || day > maxDay)
            {
                ShowError(String::Format(L"В месяце \"{0}\" {1} года {2} дн. Введите день от 1 до {2}.",
                    cmbMonth->Text, year, maxDay));
                txtDay->Focus();
                return;
            }

            // считаем
            int w = GetDayOfWeek(day, month, year);
            int n = DayOfYear(day, month, year);

            array<String^>^ dayNames = { L"Понедельник", L"Вторник", L"Среда", L"Четверг",
                L"Пятница", L"Суббота", L"Воскресенье" };
            array<String^>^ monthNames = { L"января", L"февраля", L"марта", L"апреля",
                L"мая", L"июня", L"июля", L"августа", L"сентября", L"октября",
                L"ноября", L"декабря" };

            String^ date = String::Format(L"{0} {1} {2} г.", day, monthNames[month - 1], year);
            String^ leap = L"не високосный";
            if (IsLeapYear(year))
                leap = L"високосный";

            // выводим
            lblResult->Text = dayNames[w - 1];
            lblInfo->Text = date + L" - " + n + L"-й день года, год " + leap + L".";
            lstHistory->Items->Insert(0, date + L" - " + dayNames[w - 1]);

            // календарь Windows умеет только 1753-9998 годы
            if (year >= 1753 && year <= 9998)
                dtpCalendar->Value = DateTime(year, month, day);
        }

        void btnToday_Click(Object^ sender, EventArgs^ e)
        {
            SetToday();
            btnCalc_Click(sender, e);
        }

        void btnClear_Click(Object^ sender, EventArgs^ e)
        {
            txtDay->Text = L"";
            cmbMonth->SelectedIndex = -1;
            txtYear->Text = L"";
            lblResult->Text = L"-";
            lblInfo->Text = L"Введите дату и нажмите \"Определить\".";
            lstHistory->Items->Clear();
            txtDay->Focus();
        }
    };
}
