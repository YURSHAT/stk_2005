// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'ElTreeMLGen.pas' rev: 6.00

#ifndef ElTreeMLGenHPP
#define ElTreeMLGenHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <ElMlGen.hpp>	// Pascal unit
#include <ElStrUtils.hpp>	// Pascal unit
#include <ElHeader.hpp>	// Pascal unit
#include <ElTree.hpp>	// Pascal unit
#include <ElTools.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Eltreemlgen
{
//-- type declarations -------------------------------------------------------
typedef void __fastcall (__closure *TMLTreeGenOwnerDrawEvent)(System::TObject* Sender, Eltree::TElTreeItem* Item, int SectionIndex, const Types::TRect &MaxRect, AnsiString &ReplacementString);

typedef void __fastcall (__closure *TMLTreeGenImageEvent)(System::TObject* Sender, Controls::TImageList* ImageList, int ImageIndex, AnsiString &ReplacementString);

typedef void __fastcall (__closure *TMlTreeGenItemGenerateEvent)(System::TObject* Sender, Eltree::TElTreeItem* Item, bool &Generate);

typedef void __fastcall (__closure *TMlTreeGenItemGeneratedEvent)(System::TObject* Sender, Eltree::TElTreeItem* Item);

class DELPHICLASS TElTreeMLGenerator;
class PASCALIMPLEMENTATION TElTreeMLGenerator : public Elmlgen::TCustomElMLGen 
{
	typedef Elmlgen::TCustomElMLGen inherited;
	
private:
	TMLTreeGenImageEvent FOnImage;
	
protected:
	bool FBusy;
	Eltree::TElTreeItem* FCurItem;
	int FCurItemIdx;
	Elheader::TElHeaderSection* FCurSection;
	int FCurSectionIdx;
	bool FGenerateColumns;
	bool FGenerateHeader;
	bool FGenerateHiddenItems;
	bool FGenerateImages;
	bool FGenerateInvisibleItems;
	bool FHeaderOnEveryPage;
	int FItemsPerPage;
	int FLastItemIdx;
	int FLastSectionIdx;
	TMlTreeGenItemGenerateEvent FOnItemGenerate;
	TMlTreeGenItemGeneratedEvent FOnItemGenerated;
	TMLTreeGenOwnerDrawEvent FOnOwnerDraw;
	int FRelItemIdx;
	int FRelSectionIdx;
	Eltree::TCustomElTree* FTree;
	Eltree::TElCellStyle* VirtStyle;
	virtual void __fastcall AfterExecute(void);
	virtual void __fastcall BeforeExecute(void);
	AnsiString __fastcall BuildTree(Eltree::TElTreeItem* Item);
	AnsiString __fastcall DrawCell(Eltree::TElTreeItem* Item, int SectionIndex);
	AnsiString __fastcall DrawHeaderSection(int SectionIndex);
	virtual void __fastcall IfFound(AnsiString IfName, Elmlgen::TStringParameters* TagParameters, bool &ResultValue);
	virtual void __fastcall IsTag(AnsiString TagName, bool &IsTag);
	virtual void __fastcall LoopIteration(int LoopNumb, AnsiString LoopName, Elmlgen::TStringParameters* TagParameters, bool &LoopDone);
	virtual void __fastcall MacroFound(AnsiString MacroName, Elmlgen::TStringParameters* TagParameters, AnsiString &MacroResult, bool &UseTranslationTable);
	void __fastcall SetGenerateColumns(bool Value);
	void __fastcall SetGenerateHeader(bool Value);
	void __fastcall SetGenerateHiddenItems(bool Value);
	void __fastcall SetGenerateInvisibleItems(bool Value);
	void __fastcall SetHeaderOnEveryPage(bool Value);
	void __fastcall SetItemsPerPage(int Value);
	void __fastcall SetTree(Eltree::TCustomElTree* Value);
	virtual void __fastcall TagFound(AnsiString Tag, const bool TagClosed, Elmlgen::TStringParameters* TagParameters);
	virtual void __fastcall TriggerImageEvent(Controls::TImageList* ImageList, int ImageIndex, AnsiString &ReplacementString);
	virtual void __fastcall TriggerItemGeneratedEvent(Eltree::TElTreeItem* Item);
	virtual void __fastcall TriggerItemGenerateEvent(Eltree::TElTreeItem* Item, bool &Generate);
	virtual void __fastcall TriggerOwnerDrawEvent(Eltree::TElTreeItem* Item, int SectionIndex, const Types::TRect &MaxRect, AnsiString &ReplacementString);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	
public:
	__fastcall virtual TElTreeMLGenerator(Classes::TComponent* AOwner);
	__fastcall virtual ~TElTreeMLGenerator(void);
	__property Eltree::TElTreeItem* CurrentItem = {read=FCurItem};
	__property Elheader::TElHeaderSection* CurrentSection = {read=FCurSection};
	
__published:
	__property bool GenerateColumns = {read=FGenerateColumns, write=SetGenerateColumns, nodefault};
	__property bool GenerateHeader = {read=FGenerateHeader, write=SetGenerateHeader, default=1};
	__property bool GenerateHiddenItems = {read=FGenerateHiddenItems, write=SetGenerateHiddenItems, nodefault};
	__property bool GenerateInvisibleItems = {read=FGenerateInvisibleItems, write=SetGenerateInvisibleItems, nodefault};
	__property bool HeaderOnEveryPage = {read=FHeaderOnEveryPage, write=SetHeaderOnEveryPage, nodefault};
	__property int ItemsPerPage = {read=FItemsPerPage, write=SetItemsPerPage, default=0};
	__property OnAfterExecute ;
	__property OnBeforeExecute ;
	__property OnIfFound ;
	__property TMLTreeGenImageEvent OnImage = {read=FOnImage, write=FOnImage};
	__property TMlTreeGenItemGenerateEvent OnItemGenerate = {read=FOnItemGenerate, write=FOnItemGenerate};
	__property TMlTreeGenItemGeneratedEvent OnItemGenerated = {read=FOnItemGenerated, write=FOnItemGenerated};
	__property OnLoopIteration ;
	__property OnMacroFound ;
	__property TMLTreeGenOwnerDrawEvent OnOwnerDraw = {read=FOnOwnerDraw, write=FOnOwnerDraw};
	__property OnPageBegin ;
	__property OnPageEnd ;
	__property OnTagFound ;
	__property OnWriteString ;
	__property TagPrefix ;
	__property Template ;
	__property Eltree::TCustomElTree* Tree = {read=FTree, write=SetTree};
public:
	#pragma option push -w-inl
	/* TBaseElMLGen.CreateFrom */ inline __fastcall TElTreeMLGenerator(Elmlgen::TBaseElMLGen* AOwner) : Elmlgen::TCustomElMLGen(AOwner) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE void __fastcall Register(void);

}	/* namespace Eltreemlgen */
using namespace Eltreemlgen;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// ElTreeMLGen
