// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "f_Main.h"
#include "f_Register.h"
#include <IOUtils.hpp>
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "IdBaseComponent"
#pragma link "IdComponent"
#pragma link "IdHTTP"
#pragma link "IdTCPClient"
#pragma link "IdTCPConnection"
#pragma resource "*.dfm"
TfMain *fMain;

// ---------------------------------------------------------------------------
__fastcall TfMain::TfMain(TComponent* Owner) : TForm(Owner) {
}

// ---------------------------------------------------------------------------
void __fastcall TfMain::sbOpenBookClick(TObject *Sender) {
	odOpenBook->Execute(this->Handle);
}

// ---------------------------------------------------------------------------
void __fastcall TfMain::odOpenBookCanClose(TObject *Sender, bool &CanClose) {
	mBook->Lines->LoadFromFile(odOpenBook->FileName);

	TListItem* Item = lvLib->Items->Add();
	Item->Caption = ExtractFileName(odOpenBook->FileName);
	Item->GroupID = 0;
	Item->SubItems->Add(odOpenBook->FileName); //path [0]
	Item->SubItems->Add("1"); //bookmark [1]
	Item->SubItems->Add(IntToStr(mBook->Text.Length())); //size [2]
	lbBookName->Caption = Item->Caption;

	CurBook = Item;

	tsReading->TabVisible = true;
	pcMenuPages->ActivePage = tsReading;
}

// ---------------------------------------------------------------------------
void __fastcall TfMain::sbDeleteBookClick(TObject *Sender) {
	if (lvLib->Selected){
		lvLib->Selected->Delete();

		if(CurBook == lvLib->Selected)
        	CurBook = 0;
	}
}

// ---------------------------------------------------------------------------
void __fastcall TfMain::pcMenuPagesMouseUp
	(TObject *Sender, TMouseButton Button, TShiftState Shift, int X, int Y) {
	if (pcMenuPages->ActivePage == tsWeb)
		wbLibs->Navigate(leServer->Text);
}
// ---------------------------------------------------------------------------

void __fastcall TfMain::sbBookmarkClick(TObject *Sender)
{
	if(CurBook){
		CurBook->SubItems->Strings[1] = IntToStr(mBook->SelStart); //adding bookmark
	}
}
//---------------------------------------------------------------------------

void __fastcall TfMain::lvLibDblClick(TObject *Sender)
{
	if(lvLib->Selected){
    	tsReading->TabVisible = true;
		pcMenuPages->ActivePage = tsReading;

		CurBook = lvLib->Selected;
		lbBookName->Caption = CurBook->Caption;
		mBook->Lines->LoadFromFile(CurBook->SubItems->Strings[0]);
		mBook->SelStart = StrToInt(CurBook->SubItems->Strings[1]);
		mBook->SelLength = 1;
	}
}
//---------------------------------------------------------------------------


void __fastcall TfMain::sbBackClick(TObject *Sender)
{
	unsigned short Key = VK_PRIOR;
	fMain->KeyDown(Key, TShiftState()); //Page up
}
//---------------------------------------------------------------------------



void __fastcall TfMain::FormClose(TObject *Sender, TCloseAction &Action)
{
	TFile f;
	TStringList* sl = new(TStringList);

	for(int i = 0; i < lvLib->Items->Count; i++)
		sl->Add(lvLib->Items->Item[i]->SubItems->Strings[0] + '=' +
			lvLib->Items->Item[i]->SubItems->Strings[1] + '/' +
			lvLib->Items->Item[i]->SubItems->Strings[2]);

	sl->SaveToFile(ExtractFileDir(Application->ExeName) + "\\Library.lb");
	sl->Clear();

	sl->Add("Login=" + leLogin->Text);
	if(cbRememberPass->Checked)
		sl->Add("Pass=" + lePass->Text);
	else
		sl->Add("Pass=");
	if(cbRememberPass->Checked)
		sl->Add("RememberPass=1");
	else
		sl->Add("RememberPass=0");
	sl->Add("Server=" + leServer->Text);

	sl->SaveToFile(ExtractFileDir(Application->ExeName) + "\\Settings.ini");

	sl->~TStringList();
}
//---------------------------------------------------------------------------

void __fastcall TfMain::FormShow(TObject *Sender)
{
	TStringList* sl = new(TStringList);
	sl->NameValueSeparator = '=';

	TFile f;

	if(f.Exists(ExtractFileDir(Application->ExeName) + "\\Library.lb")){
		sl->LoadFromFile(GetCurrentDir() + "\\Library.lb");

		for(int i = 0; i < sl->Count; i++){
			TListItem* Item = lvLib->Items->Add();
			Item->Caption = ExtractFileName(sl->Names[i]);
			Item->GroupID = 0;
			Item->SubItems->Add(sl->Names[i]); //path [0]

			TStringList* ss = new(TStringList);
			ss->NameValueSeparator = '/';
			ss->Add(sl->ValueFromIndex[i]);

			Item->SubItems->Add(ss->Names[0]); //bookmark [1]
			Item->SubItems->Add(ss->ValueFromIndex[0]); //size [2]

			ss->~TStringList();
		}
	}

	sl->Clear();

	if(f.Exists(ExtractFileDir(Application->ExeName) + "\\Settings.ini")){
		sl->LoadFromFile(GetCurrentDir() + "\\Settings.ini");

		leLogin->Text = sl->ValueFromIndex[0];
		lePass->Text = sl->ValueFromIndex[1];
		if(sl->ValueFromIndex[2] == "1")
			cbRememberPass->Checked = true;
		else
            cbRememberPass->Checked = false;
		leServer->Text = sl->ValueFromIndex[3];
	}

	sl->~TStringList();
}
//---------------------------------------------------------------------------

void __fastcall TfMain::leServerExit(TObject *Sender)
{
	if(leServer->Text == "")
		leServer->Text = "localhost:3000";
}
//---------------------------------------------------------------------------


void __fastcall TfMain::btnRegisterClick(TObject *Sender)
{
	fRegister->ShowModal();
}
//---------------------------------------------------------------------------

