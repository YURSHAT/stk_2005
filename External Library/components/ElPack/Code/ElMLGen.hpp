// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'ElMlGen.pas' rev: 6.00

#ifndef ElMlGenHPP
#define ElMlGenHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Elmlgen
{
//-- type declarations -------------------------------------------------------
typedef DynamicArray<AnsiString >  TDynamicString;

#pragma pack(push, 4)
struct TStringsRec
{
	AnsiString ValueName;
	AnsiString Value;
} ;
#pragma pack(pop)

typedef DynamicArray<TStringsRec >  TArrayOfStringsRec;

typedef void __fastcall (__closure *TMlPageEvent)(System::TObject* Sender, int PageNumb);

class DELPHICLASS TStringParameters;
typedef void __fastcall (__closure *TMlIfFoundEvent)(System::TObject* Sender, AnsiString IfName, TStringParameters* TagParameters, bool &ResultValue);

typedef void __fastcall (__closure *TMlLoopIterateEvent)(System::TObject* Sender, int LoopNumb, AnsiString LoopName, TStringParameters* TagParameters, bool &LoopDone);

typedef void __fastcall (__closure *TMlMacroFoundEvent)(System::TObject* Sender, AnsiString MacroName, TStringParameters* TagParameters, AnsiString &MacroResult, bool &UseTranslationTable);

typedef void __fastcall (__closure *TMlWriteStringEvent)(System::TObject* Sender, AnsiString Value);

typedef void __fastcall (__closure *TMlTagFoundEvent)(System::TObject* Sender, AnsiString Tag, const bool TagClosed, TStringParameters* TagParameters);

typedef void __fastcall (__closure *TMlIsTagEvent)(System::TObject* Sender, AnsiString TagName, bool &IsTag);

class PASCALIMPLEMENTATION TStringParameters : public Classes::TPersistent 
{
	typedef Classes::TPersistent inherited;
	
private:
	DynamicArray<TStringsRec >  FData;
	int __fastcall GetCount(void);
	AnsiString __fastcall GetValue(int Index);
	AnsiString __fastcall GetValueByName(AnsiString ValueName);
	AnsiString __fastcall GetValueName(int Index);
	void __fastcall SetCount(int Value);
	void __fastcall SetValue(int Index, const AnsiString Value);
	void __fastcall SetValueByName(AnsiString ValueName, const AnsiString Value);
	void __fastcall SetValueName(int Index, const AnsiString Value);
	
public:
	__fastcall TStringParameters(void);
	__fastcall virtual ~TStringParameters(void);
	int __fastcall AddValue(const AnsiString aValueName, const AnsiString aValue);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	virtual void __fastcall AssignTo(Classes::TPersistent* Dest);
	void __fastcall Clear(void);
	int __fastcall FindItemByName(AnsiString ValueName);
	AnsiString __fastcall GetValueByNameEx(AnsiString ValueName, AnsiString DefaultValue);
	__property int Count = {read=GetCount, write=SetCount, nodefault};
	__property TArrayOfStringsRec Data = {read=FData};
	__property AnsiString Value[int Index] = {read=GetValue, write=SetValue};
	__property AnsiString ValueByName[AnsiString ValueName] = {read=GetValueByName, write=SetValueByName};
	__property AnsiString ValueName[int Index] = {read=GetValueName, write=SetValueName};
};


class DELPHICLASS TTranslationTables;
class DELPHICLASS TTranslationTable;
class PASCALIMPLEMENTATION TTranslationTables : public Classes::TCollection 
{
	typedef Classes::TCollection inherited;
	
public:
	TTranslationTable* operator[](int Index) { return Items[Index]; }
	
private:
	int FDefaultTable;
	TTranslationTable* __fastcall GetItems(int Index);
	void __fastcall SetDefaultTable(int Value);
	void __fastcall SetItems(int Index, TTranslationTable* Value);
	
public:
	__fastcall TTranslationTables(void);
	HIDESBASE TTranslationTable* __fastcall Add(const AnsiString TableName);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	HIDESBASE void __fastcall Clear(void);
	int __fastcall FindTableByName(const AnsiString TableName);
	void __fastcall GetTableNames(Classes::TStrings* Strings);
	__property int DefaultTable = {read=FDefaultTable, write=SetDefaultTable, nodefault};
	__property TTranslationTable* Items[int Index] = {read=GetItems, write=SetItems/*, default*/};
public:
	#pragma option push -w-inl
	/* TCollection.Destroy */ inline __fastcall virtual ~TTranslationTables(void) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TTranslationTable : public Classes::TCollectionItem 
{
	typedef Classes::TCollectionItem inherited;
	
private:
	AnsiString FName;
	TStringParameters* FTable;
	
public:
	__fastcall virtual TTranslationTable(Classes::TCollection* Collection);
	__fastcall virtual ~TTranslationTable(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	AnsiString __fastcall Translate(AnsiString Source);
	__property AnsiString Name = {read=FName, write=FName};
	__property TStringParameters* Table = {read=FTable};
};


typedef DynamicArray<AnsiString >  ElMlGen__5;

typedef DynamicArray<int >  ElMlGen__6;

typedef DynamicArray<int >  ElMlGen__7;

typedef DynamicArray<int >  ElMlGen__8;

typedef DynamicArray<int >  ElMlGen__9;

typedef DynamicArray<int >  ElMlGen__01;

typedef DynamicArray<AnsiString >  ElMlGen__11;

typedef DynamicArray<AnsiString >  ElMlGen__21;

class DELPHICLASS TBaseElMLGen;
class PASCALIMPLEMENTATION TBaseElMLGen : public Classes::TComponent 
{
	typedef Classes::TComponent inherited;
	
private:
	bool FCancelJob;
	Classes::TStrings* FCode;
	AnsiString FCommentName;
	Classes::TStrings* FCustomTagNames;
	bool FEnteringInNextPage;
	bool FExecuting;
	DynamicArray<AnsiString >  FIfNames;
	DynamicArray<int >  FLoopBeginPos;
	DynamicArray<int >  FLoopBeginPosRzrv;
	AnsiString FLoopBreak;
	DynamicArray<int >  FLoopCounters;
	DynamicArray<int >  FLoopCountersCurrentPage;
	DynamicArray<int >  FLoopCountersRzrv;
	DynamicArray<AnsiString >  FLoopNames;
	DynamicArray<AnsiString >  FLoopNamesRzrv;
	bool FNewPageProcessing;
	int FPageCount;
	TStringParameters* FParameters;
	AnsiString FSource;
	int FSrcPos;
	TStringParameters* FTagParameters;
	AnsiString FTagPrefix;
	Classes::TStrings* FTemplate;
	TTranslationTable* FTranslationTable;
	TTranslationTables* FTranslationTables;
	void __fastcall CheckEndPos(void);
	bool __fastcall DoCodeBegin(void);
	void __fastcall DoCodeEnd(void);
	bool __fastcall DoCommentBegin(void);
	bool __fastcall DoCommentEnd(void);
	bool __fastcall DoIfDone(const bool SkipUnknown);
	bool __fastcall DoIfElse(void);
	bool __fastcall DoIfFound(void);
	bool __fastcall DoIsTag(const AnsiString TagName);
	AnsiString __fastcall DoMacroFound();
	void __fastcall DoNextPage(void);
	bool __fastcall DoParamBegin(AnsiString &ParamName, int &ParamNumb);
	void __fastcall DoParamEnd(void);
	bool __fastcall DoParamsBegin(void);
	void __fastcall DoParamsEnd(void);
	void __fastcall DoRepeatBegin(void);
	void __fastcall DoRepeatDone(void);
	bool __fastcall DoRepeatSkipDone(void);
	bool __fastcall DoReplaceBegin(AnsiString &ParamName, int &ParamNumb);
	void __fastcall DoReplaceEnd(void);
	void __fastcall DoTagFound(AnsiString TagName);
	void __fastcall DoTranslationBegin(AnsiString &TableName);
	void __fastcall DoTranslationEnd(AnsiString &TableName);
	void __fastcall FreeArrays(void);
	void __fastcall FreeRzrvArrays(void);
	int __fastcall GetLoopCount(void);
	int __fastcall GetLoopCounter(int Index);
	int __fastcall GetLoopCountersCurrentPage(int Index);
	int __fastcall GetLoopCountersCurrentPageStr(AnsiString LoopName);
	int __fastcall GetLoopCounterStr(AnsiString LoopName);
	AnsiString __fastcall GetLoopName(int Index);
	void __fastcall GetTagProp(bool &ClosedTag, TStringParameters* TagOptions);
	void __fastcall PrepareTemplate(void);
	void __fastcall SetCustomTagNames(Classes::TStrings* Value);
	void __fastcall SetTagPrefix(const AnsiString Value);
	void __fastcall SetTemplate(Classes::TStrings* Value);
	void __fastcall TemplateChanged(System::TObject* Sender);
	
protected:
	virtual void __fastcall AfterExecute(void) = 0 ;
	virtual void __fastcall BeforeExecute(void) = 0 ;
	virtual void __fastcall IfFound(AnsiString IfName, TStringParameters* TagParameters, bool &ResultValue) = 0 ;
	virtual void __fastcall IsTag(AnsiString TagName, bool &IsTag);
	virtual void __fastcall LoopIteration(int LoopNumb, AnsiString LoopName, TStringParameters* TagParameters, bool &LoopDone) = 0 ;
	virtual void __fastcall MacroFound(AnsiString MacroName, TStringParameters* TagParameters, AnsiString &MacroResult, bool &UseTranslationTable) = 0 ;
	virtual void __fastcall PageBegin(int PageNumb) = 0 ;
	virtual void __fastcall PageEnd(int PageNumb) = 0 ;
	virtual void __fastcall ProcessMessages(void);
	virtual void __fastcall TagFound(AnsiString Tag, const bool TagClosed, TStringParameters* TagParameters);
	virtual void __fastcall WriteString(AnsiString Value) = 0 ;
	
public:
	__fastcall virtual TBaseElMLGen(Classes::TComponent* AOwner);
	__fastcall TBaseElMLGen(TBaseElMLGen* AOwner);
	__fastcall virtual ~TBaseElMLGen(void);
	virtual void __fastcall Abort(void);
	virtual void __fastcall Execute(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	int __fastcall GetLoopIndex(const AnsiString LoopName);
	void __fastcall LoopBreak(AnsiString LoopName);
	void __fastcall LoopContinue(AnsiString LoopName);
	void __fastcall NextPage(void);
	__property Classes::TStrings* Code = {read=FCode};
	__property Classes::TStrings* CustomTagNames = {read=FCustomTagNames, write=SetCustomTagNames};
	__property bool Executing = {read=FExecuting, nodefault};
	__property int LoopCount = {read=GetLoopCount, nodefault};
	__property int LoopCounter[int Index] = {read=GetLoopCounter};
	__property int LoopCountersCurrentPage[int Index] = {read=GetLoopCountersCurrentPage};
	__property int LoopCountersCurrentPageStr[AnsiString LoopName] = {read=GetLoopCountersCurrentPageStr};
	__property int LoopCounterStr[AnsiString LoopName] = {read=GetLoopCounterStr};
	__property AnsiString LoopName[int Index] = {read=GetLoopName};
	__property int PageCount = {read=FPageCount, nodefault};
	__property TStringParameters* Parameters = {read=FParameters};
	__property AnsiString TagPrefix = {read=FTagPrefix, write=SetTagPrefix};
	__property Classes::TStrings* Template = {read=FTemplate, write=SetTemplate};
	__property TTranslationTables* TranslationTables = {read=FTranslationTables};
};


class DELPHICLASS TCustomElMLGen;
class PASCALIMPLEMENTATION TCustomElMLGen : public TBaseElMLGen 
{
	typedef TBaseElMLGen inherited;
	
private:
	Classes::TNotifyEvent FOnAfterExecute;
	Classes::TNotifyEvent FOnBeforeExecute;
	TMlIfFoundEvent FOnIfFound;
	TMlIsTagEvent FOnIsTag;
	TMlLoopIterateEvent FOnLoopIteration;
	TMlMacroFoundEvent FOnMacroFound;
	TMlPageEvent FOnPageBegin;
	TMlPageEvent FOnPageEnd;
	Classes::TNotifyEvent FOnProcessMessages;
	TMlTagFoundEvent FOnTagFound;
	TMlWriteStringEvent FOnWriteString;
	
protected:
	virtual void __fastcall AfterExecute(void);
	virtual void __fastcall BeforeExecute(void);
	virtual void __fastcall IfFound(AnsiString IfName, TStringParameters* TagParameters, bool &ResultValue);
	virtual void __fastcall IsTag(AnsiString TagName, bool &IsTag);
	virtual void __fastcall LoopIteration(int LoopNumb, AnsiString LoopName, TStringParameters* TagParameters, bool &LoopDone);
	virtual void __fastcall MacroFound(AnsiString MacroName, TStringParameters* TagParameters, AnsiString &MacroResult, bool &UseTranslationTable);
	virtual void __fastcall PageBegin(int PageNumb);
	virtual void __fastcall PageEnd(int PageNumb);
	virtual void __fastcall ProcessMessages(void);
	virtual void __fastcall TagFound(AnsiString Tag, const bool TagClosed, TStringParameters* TagParameters);
	virtual void __fastcall WriteString(AnsiString Value);
	__property Classes::TNotifyEvent OnAfterExecute = {read=FOnAfterExecute, write=FOnAfterExecute};
	__property Classes::TNotifyEvent OnBeforeExecute = {read=FOnBeforeExecute, write=FOnBeforeExecute};
	__property TMlIfFoundEvent OnIfFound = {read=FOnIfFound, write=FOnIfFound};
	__property TMlIsTagEvent OnIsTag = {read=FOnIsTag, write=FOnIsTag};
	__property TMlLoopIterateEvent OnLoopIteration = {read=FOnLoopIteration, write=FOnLoopIteration};
	__property TMlMacroFoundEvent OnMacroFound = {read=FOnMacroFound, write=FOnMacroFound};
	__property TMlPageEvent OnPageBegin = {read=FOnPageBegin, write=FOnPageBegin};
	__property TMlPageEvent OnPageEnd = {read=FOnPageEnd, write=FOnPageEnd};
	__property Classes::TNotifyEvent OnProcessMessages = {read=FOnProcessMessages, write=FOnProcessMessages};
	__property TMlTagFoundEvent OnTagFound = {read=FOnTagFound, write=FOnTagFound};
	__property TMlWriteStringEvent OnWriteString = {read=FOnWriteString, write=FOnWriteString};
public:
	#pragma option push -w-inl
	/* TBaseElMLGen.Create */ inline __fastcall virtual TCustomElMLGen(Classes::TComponent* AOwner) : TBaseElMLGen(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TBaseElMLGen.CreateFrom */ inline __fastcall TCustomElMLGen(TBaseElMLGen* AOwner) : TBaseElMLGen(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TBaseElMLGen.Destroy */ inline __fastcall virtual ~TCustomElMLGen(void) { }
	#pragma option pop
	
};


class DELPHICLASS TElMLGen;
class PASCALIMPLEMENTATION TElMLGen : public TCustomElMLGen 
{
	typedef TCustomElMLGen inherited;
	
__published:
	__property CustomTagNames ;
	__property OnAfterExecute ;
	__property OnBeforeExecute ;
	__property OnIfFound ;
	__property OnIsTag ;
	__property OnLoopIteration ;
	__property OnMacroFound ;
	__property OnPageBegin ;
	__property OnPageEnd ;
	__property OnProcessMessages ;
	__property OnTagFound ;
	__property OnWriteString ;
	__property TagPrefix ;
	__property Template ;
public:
	#pragma option push -w-inl
	/* TBaseElMLGen.Create */ inline __fastcall virtual TElMLGen(Classes::TComponent* AOwner) : TCustomElMLGen(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TBaseElMLGen.CreateFrom */ inline __fastcall TElMLGen(TBaseElMLGen* AOwner) : TCustomElMLGen(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TBaseElMLGen.Destroy */ inline __fastcall virtual ~TElMLGen(void) { }
	#pragma option pop
	
};


class DELPHICLASS MlGenException;
class PASCALIMPLEMENTATION MlGenException : public Sysutils::Exception 
{
	typedef Sysutils::Exception inherited;
	
private:
	TBaseElMLGen* FMlGen;
	
public:
	__fastcall MlGenException(TBaseElMLGen* MlGen, AnsiString Msg);
public:
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall MlGenException(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall MlGenException(int Ident)/* overload */ : Sysutils::Exception(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall MlGenException(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Sysutils::Exception(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall MlGenException(const AnsiString Msg, int AHelpContext) : Sysutils::Exception(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall MlGenException(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall MlGenException(int Ident, int AHelpContext)/* overload */ : Sysutils::Exception(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall MlGenException(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Sysutils::Exception(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~MlGenException(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE System::ResourceString _SCanNotFindValueNameS;
#define Elmlgen_SCanNotFindValueNameS System::LoadResourceString(&Elmlgen::_SCanNotFindValueNameS)
extern PACKAGE System::ResourceString _SDuplicateTranslationTableName;
#define Elmlgen_SDuplicateTranslationTableName System::LoadResourceString(&Elmlgen::_SDuplicateTranslationTableName)
extern PACKAGE System::ResourceString _SCanNotSetDefaultTranslationTableIndexOutOfRange;
#define Elmlgen_SCanNotSetDefaultTranslationTableIndexOutOfRange System::LoadResourceString(&Elmlgen::_SCanNotSetDefaultTranslationTableIndexOutOfRange)
extern PACKAGE System::ResourceString _SNameOfCommentTagMustBeSpecified;
#define Elmlgen_SNameOfCommentTagMustBeSpecified System::LoadResourceString(&Elmlgen::_SNameOfCommentTagMustBeSpecified)
extern PACKAGE System::ResourceString _SErrorInCommentTagDeclaration;
#define Elmlgen_SErrorInCommentTagDeclaration System::LoadResourceString(&Elmlgen::_SErrorInCommentTagDeclaration)
extern PACKAGE System::ResourceString _SConditionWasNotDeclaredOrClosingTagForInnerConditionIsSkipped;
#define Elmlgen_SConditionWasNotDeclaredOrClosingTagForInnerConditionIsSkipped System::LoadResourceString(&Elmlgen::_SConditionWasNotDeclaredOrClosingTagForInnerConditionIsSkipped)
extern PACKAGE System::ResourceString _SErrorInElseTagDeclaration;
#define Elmlgen_SErrorInElseTagDeclaration System::LoadResourceString(&Elmlgen::_SErrorInElseTagDeclaration)
extern PACKAGE System::ResourceString _SNameOfElseTagMustBeSpecified;
#define Elmlgen_SNameOfElseTagMustBeSpecified System::LoadResourceString(&Elmlgen::_SNameOfElseTagMustBeSpecified)
extern PACKAGE System::ResourceString _SErrorInIfTagDeclaration;
#define Elmlgen_SErrorInIfTagDeclaration System::LoadResourceString(&Elmlgen::_SErrorInIfTagDeclaration)
extern PACKAGE System::ResourceString _SNameOfIfTagMustBeSpecified;
#define Elmlgen_SNameOfIfTagMustBeSpecified System::LoadResourceString(&Elmlgen::_SNameOfIfTagMustBeSpecified)
extern PACKAGE System::ResourceString _SErrorInMacroDeclaration;
#define Elmlgen_SErrorInMacroDeclaration System::LoadResourceString(&Elmlgen::_SErrorInMacroDeclaration)
extern PACKAGE System::ResourceString _SNameOfMacroMustBeSpecified;
#define Elmlgen_SNameOfMacroMustBeSpecified System::LoadResourceString(&Elmlgen::_SNameOfMacroMustBeSpecified)
extern PACKAGE System::ResourceString _SNameOfParamTagMustBeSpecified;
#define Elmlgen_SNameOfParamTagMustBeSpecified System::LoadResourceString(&Elmlgen::_SNameOfParamTagMustBeSpecified)
extern PACKAGE System::ResourceString _SErrorInParamTagDeclaration1;
#define Elmlgen_SErrorInParamTagDeclaration1 System::LoadResourceString(&Elmlgen::_SErrorInParamTagDeclaration1)
extern PACKAGE System::ResourceString _SErrorInParamsTagDeclaration1;
#define Elmlgen_SErrorInParamsTagDeclaration1 System::LoadResourceString(&Elmlgen::_SErrorInParamsTagDeclaration1)
extern PACKAGE System::ResourceString _SErrorInRepeatTagDeclaration;
#define Elmlgen_SErrorInRepeatTagDeclaration System::LoadResourceString(&Elmlgen::_SErrorInRepeatTagDeclaration)
extern PACKAGE System::ResourceString _SNameOfRepeatTagMustBeSpecified;
#define Elmlgen_SNameOfRepeatTagMustBeSpecified System::LoadResourceString(&Elmlgen::_SNameOfRepeatTagMustBeSpecified)
extern PACKAGE System::ResourceString _SDuplicateLoopNameS;
#define Elmlgen_SDuplicateLoopNameS System::LoadResourceString(&Elmlgen::_SDuplicateLoopNameS)
extern PACKAGE System::ResourceString _STryingToCloseNotOpenedLoopInternalError;
#define Elmlgen_STryingToCloseNotOpenedLoopInternalError System::LoadResourceString(&Elmlgen::_STryingToCloseNotOpenedLoopInternalError)
extern PACKAGE System::ResourceString _SStringInReplaceTagMustBeSpecified;
#define Elmlgen_SStringInReplaceTagMustBeSpecified System::LoadResourceString(&Elmlgen::_SStringInReplaceTagMustBeSpecified)
extern PACKAGE System::ResourceString _SEmbeddedTranslationTablesAreNotAllowed;
#define Elmlgen_SEmbeddedTranslationTablesAreNotAllowed System::LoadResourceString(&Elmlgen::_SEmbeddedTranslationTablesAreNotAllowed)
extern PACKAGE System::ResourceString _SNameOfTranslationTagMustBeSpecified;
#define Elmlgen_SNameOfTranslationTagMustBeSpecified System::LoadResourceString(&Elmlgen::_SNameOfTranslationTagMustBeSpecified)
extern PACKAGE System::ResourceString _SErrorInTranslationTagDeclaration1;
#define Elmlgen_SErrorInTranslationTagDeclaration1 System::LoadResourceString(&Elmlgen::_SErrorInTranslationTagDeclaration1)
extern PACKAGE System::ResourceString _SNameOfTranslationTagMustBeSpecified1;
#define Elmlgen_SNameOfTranslationTagMustBeSpecified1 System::LoadResourceString(&Elmlgen::_SNameOfTranslationTagMustBeSpecified1)
extern PACKAGE System::ResourceString _STryingToCloseNotPreviouslyOpenedTranslationTableSS;
#define Elmlgen_STryingToCloseNotPreviouslyOpenedTranslationTableSS System::LoadResourceString(&Elmlgen::_STryingToCloseNotPreviouslyOpenedTranslationTableSS)
extern PACKAGE System::ResourceString _SErrorInTemplateDLoopsWereNotClosed;
#define Elmlgen_SErrorInTemplateDLoopsWereNotClosed System::LoadResourceString(&Elmlgen::_SErrorInTemplateDLoopsWereNotClosed)
extern PACKAGE System::ResourceString _SErrorInTemplateDConditionsWereNotClosed;
#define Elmlgen_SErrorInTemplateDConditionsWereNotClosed System::LoadResourceString(&Elmlgen::_SErrorInTemplateDConditionsWereNotClosed)
extern PACKAGE System::ResourceString _SErrorInTemplateNotAllTagsHaveBeenClosed;
#define Elmlgen_SErrorInTemplateNotAllTagsHaveBeenClosed System::LoadResourceString(&Elmlgen::_SErrorInTemplateNotAllTagsHaveBeenClosed)
extern PACKAGE System::ResourceString _SCanNotAnalyzeTag;
#define Elmlgen_SCanNotAnalyzeTag System::LoadResourceString(&Elmlgen::_SCanNotAnalyzeTag)
extern PACKAGE System::ResourceString _SAttemptToCloseTheLoopThatHasNotBeenOpenedBefore;
#define Elmlgen_SAttemptToCloseTheLoopThatHasNotBeenOpenedBefore System::LoadResourceString(&Elmlgen::_SAttemptToCloseTheLoopThatHasNotBeenOpenedBefore)
extern PACKAGE System::ResourceString _SRepeatedRequestForNewPageIsNotAllowed;
#define Elmlgen_SRepeatedRequestForNewPageIsNotAllowed System::LoadResourceString(&Elmlgen::_SRepeatedRequestForNewPageIsNotAllowed)
extern PACKAGE System::ResourceString _SErrorInTemplateParamsDeclaration;
#define Elmlgen_SErrorInTemplateParamsDeclaration System::LoadResourceString(&Elmlgen::_SErrorInTemplateParamsDeclaration)
extern PACKAGE System::ResourceString _SInvalidCharDSInTagPrefixString;
#define Elmlgen_SInvalidCharDSInTagPrefixString System::LoadResourceString(&Elmlgen::_SInvalidCharDSInTagPrefixString)
extern PACKAGE System::ResourceString _SCanTChangeTemplateDuringExecution;
#define Elmlgen_SCanTChangeTemplateDuringExecution System::LoadResourceString(&Elmlgen::_SCanTChangeTemplateDuringExecution)
extern PACKAGE System::ResourceString _SErrorInIfTagDeclaration1;
#define Elmlgen_SErrorInIfTagDeclaration1 System::LoadResourceString(&Elmlgen::_SErrorInIfTagDeclaration1)
extern PACKAGE System::ResourceString _SNameOfIfTagMustBeSpecified1;
#define Elmlgen_SNameOfIfTagMustBeSpecified1 System::LoadResourceString(&Elmlgen::_SNameOfIfTagMustBeSpecified1)
extern PACKAGE System::ResourceString _SErrorInRepeatTagDeclaration1;
#define Elmlgen_SErrorInRepeatTagDeclaration1 System::LoadResourceString(&Elmlgen::_SErrorInRepeatTagDeclaration1)
extern PACKAGE System::ResourceString _SRepeatTagDoesnTHaveMatchingRepeatTag1;
#define Elmlgen_SRepeatTagDoesnTHaveMatchingRepeatTag1 System::LoadResourceString(&Elmlgen::_SRepeatTagDoesnTHaveMatchingRepeatTag1)
extern PACKAGE System::ResourceString _SErrorInReplaceTagDeclaration1;
#define Elmlgen_SErrorInReplaceTagDeclaration1 System::LoadResourceString(&Elmlgen::_SErrorInReplaceTagDeclaration1)
extern PACKAGE System::ResourceString _SErrorWhileDetectingPositionInLineIndexOutOfRange;
#define Elmlgen_SErrorWhileDetectingPositionInLineIndexOutOfRange System::LoadResourceString(&Elmlgen::_SErrorWhileDetectingPositionInLineIndexOutOfRange)
extern PACKAGE System::ResourceString _SCanNotAssignObjectToTranslationTableList;
#define Elmlgen_SCanNotAssignObjectToTranslationTableList System::LoadResourceString(&Elmlgen::_SCanNotAssignObjectToTranslationTableList)
extern PACKAGE System::ResourceString _SIndexOutOfRange;
#define Elmlgen_SIndexOutOfRange System::LoadResourceString(&Elmlgen::_SIndexOutOfRange)
extern PACKAGE System::ResourceString _SLoopNameIsNotFound;
#define Elmlgen_SLoopNameIsNotFound System::LoadResourceString(&Elmlgen::_SLoopNameIsNotFound)
extern PACKAGE System::ResourceString _SErrorInCodeTagDeclaration;
#define Elmlgen_SErrorInCodeTagDeclaration System::LoadResourceString(&Elmlgen::_SErrorInCodeTagDeclaration)
extern PACKAGE System::ResourceString _SLineChar;
#define Elmlgen_SLineChar System::LoadResourceString(&Elmlgen::_SLineChar)
extern PACKAGE System::ResourceString _SError;
#define Elmlgen_SError System::LoadResourceString(&Elmlgen::_SError)
extern PACKAGE System::ResourceString _SCanNotAssignToTranslationTable;
#define Elmlgen_SCanNotAssignToTranslationTable System::LoadResourceString(&Elmlgen::_SCanNotAssignToTranslationTable)
extern PACKAGE System::ResourceString _SUnableToFindPointToReturn;
#define Elmlgen_SUnableToFindPointToReturn System::LoadResourceString(&Elmlgen::_SUnableToFindPointToReturn)
extern PACKAGE System::ResourceString _SUnableToFindPointToReturnPossibleReasonIsDuplicatedLoopName;
#define Elmlgen_SUnableToFindPointToReturnPossibleReasonIsDuplicatedLoopName System::LoadResourceString(&Elmlgen::_SUnableToFindPointToReturnPossibleReasonIsDuplicatedLoopName)
extern PACKAGE void __fastcall Register(void);
extern PACKAGE AnsiString __fastcall CheckPath(AnsiString InpPath, bool IsPath);
extern PACKAGE AnsiString __fastcall GetWordEx(AnsiString S, int &CharNumb, const Sysutils::TSysCharSet &Breaks);
extern PACKAGE int __fastcall PosP(const AnsiString SubStr, AnsiString Value, int BegPos, int EndPos);
extern PACKAGE int __fastcall GetPosOfNewString(const AnsiString Value, int CurPos);
extern PACKAGE AnsiString __fastcall SetStrWidth(AnsiString Value, int Width);
extern PACKAGE void __fastcall GetTextLineByStringPos(const AnsiString Value, int ValuePos, int &Line, int &CharPos);

}	/* namespace Elmlgen */
using namespace Elmlgen;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// ElMlGen
