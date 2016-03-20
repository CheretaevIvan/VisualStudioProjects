// јвтоматически создаваемые классы-оболочки IDispatch, созданные при помощи мастера добавлени€ класса из библиотеки типов

#import "C:\\Program Files (x86)\\Microsoft Office\\Office15\\MSWORD.OLB" no_namespace
// CnlineShapes класс-оболочка

class CnlineShapes : public COleDispatchDriver
{
public:
	CnlineShapes(){} // ¬ызывает конструктор по умолчанию дл€ COleDispatchDriver
	CnlineShapes(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CnlineShapes(const CnlineShapes& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// јтрибуты
public:

	// ќперации
public:


	// InlineShapes методы
public:
	LPDISPATCH get_Application()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	long get_Creator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH get_Parent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	long get_Count()
	{
		long result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	LPUNKNOWN get__NewEnum()
	{
		LPUNKNOWN result;
		InvokeHelper(0xfffffffc, DISPATCH_PROPERTYGET, VT_UNKNOWN, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH Item(long Index)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_I4;
		InvokeHelper(0x0, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, Index);
		return result;
	}
	LPDISPATCH AddPicture(LPCTSTR FileName, VARIANT * LinkToFile, VARIANT * SaveWithDocument, VARIANT * Range)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_BSTR VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0x64, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, FileName, LinkToFile, SaveWithDocument, Range);
		return result;
	}
	LPDISPATCH AddOLEObject(VARIANT * ClassType, VARIANT * FileName, VARIANT * LinkToFile, VARIANT * DisplayAsIcon, VARIANT * IconFileName, VARIANT * IconIndex, VARIANT * IconLabel, VARIANT * Range)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0x18, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, ClassType, FileName, LinkToFile, DisplayAsIcon, IconFileName, IconIndex, IconLabel, Range);
		return result;
	}
	LPDISPATCH AddOLEControl(VARIANT * ClassType, VARIANT * Range)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0x66, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, ClassType, Range);
		return result;
	}
	LPDISPATCH New(LPDISPATCH Range)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_DISPATCH;
		InvokeHelper(0xc8, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, Range);
		return result;
	}
	LPDISPATCH AddHorizontalLine(LPCTSTR FileName, VARIANT * Range)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_BSTR VTS_PVARIANT;
		InvokeHelper(0x68, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, FileName, Range);
		return result;
	}
	LPDISPATCH AddHorizontalLineStandard(VARIANT * Range)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_PVARIANT;
		InvokeHelper(0x69, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, Range);
		return result;
	}
	LPDISPATCH AddPictureBullet(LPCTSTR FileName, VARIANT * Range)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_BSTR VTS_PVARIANT;
		InvokeHelper(0x6a, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, FileName, Range);
		return result;
	}
	LPDISPATCH AddChart(long Type, VARIANT * Range)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_I4 VTS_PVARIANT;
		InvokeHelper(0x6b, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, Type, Range);
		return result;
	}
	LPDISPATCH AddSmartArt(LPDISPATCH Layout, VARIANT * Range)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_DISPATCH VTS_PVARIANT;
		InvokeHelper(0x6c, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, Layout, Range);
		return result;
	}
	LPDISPATCH AddWebVideo(LPCTSTR EmbedCode, VARIANT * VideoWidth, VARIANT * VideoHeight, VARIANT * PosterFrameImage, VARIANT * Url, VARIANT * Range)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_BSTR VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0x6d, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, EmbedCode, VideoWidth, VideoHeight, PosterFrameImage, Url, Range);
		return result;
	}
	LPDISPATCH AddChart2(long Style, long Type, VARIANT * Range, VARIANT * NewLayout)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0x6e, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, Style, Type, Range, NewLayout);
		return result;
	}

	// InlineShapes свойства
public:

};
