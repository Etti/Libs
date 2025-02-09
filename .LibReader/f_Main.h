//---------------------------------------------------------------------------

#ifndef f_MainH
#define f_MainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "IdBaseComponent.hpp"
#include "IdComponent.hpp"
#include "IdHTTP.hpp"
#include "IdTCPClient.hpp"
#include "IdTCPConnection.hpp"
#include <ComCtrls.hpp>
#include <Buttons.hpp>
#include <OleCtrls.hpp>
#include <SHDocVw.hpp>
#include <Dialogs.hpp>
#include <ExtDlgs.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TfMain : public TForm
{
__published:	// IDE-managed Components
	TIdHTTP *IdHTTP1;
	TPageControl *pcMenuPages;
	TTabSheet *tsReading;
	TTabSheet *tsLib;
	TTabSheet *tsWeb;
	TTabSheet *tsSettings;
	TSpeedButton *sbBookmark;
	TLabel *lbBookName;
	TMemo *mBook;
	TSpeedButton *sbOpenBook;
	TSpeedButton *sbDeleteBook;
	TListView *lvLib;
	TWebBrowser *wbLibs;
	TOpenTextFileDialog *odOpenBook;
	TGroupBox *gbAuth;
	TLabeledEdit *leLogin;
	TLabeledEdit *lePass;
	TButton *btnRegister;
	TCheckBox *cbRememberPass;
	TGroupBox *gbServer;
	TLabeledEdit *leServer;
	void __fastcall sbOpenBookClick(TObject *Sender);
	void __fastcall odOpenBookCanClose(TObject *Sender, bool &CanClose);
	void __fastcall sbDeleteBookClick(TObject *Sender);
	void __fastcall pcMenuPagesMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall sbBookmarkClick(TObject *Sender);
	void __fastcall lvLibDblClick(TObject *Sender);
	void __fastcall sbBackClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall leServerExit(TObject *Sender);
	void __fastcall btnRegisterClick(TObject *Sender);
private:	// User declarations
	TListItem* CurBook;
public:		// User declarations
	__fastcall TfMain(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfMain *fMain;
//---------------------------------------------------------------------------
#endif
