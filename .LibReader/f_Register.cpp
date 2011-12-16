//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "f_Main.h"
#include "f_Register.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfRegister *fRegister;
//---------------------------------------------------------------------------
__fastcall TfRegister::TfRegister(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfRegister::btnRegisterClick(TObject *Sender)
{
	if(leLogin->Text == ""){
		ShowMessage("������� �����");
		return;
	}

	if(lePass->Text == ""){
		ShowMessage("������� ������");
		return;
	}

	if(lePass->Text != lePassConfirm->Text){
		ShowMessage("��������� ������������ ��������� ������");
		return;
	}

	fMain->leLogin->Text = leLogin->Text;
	fMain->lePass->Text = lePass->Text;

	fMain->cbRememberPass->Checked = cbRememberPass->Checked;
	fRegister->Close();
}
//---------------------------------------------------------------------------
