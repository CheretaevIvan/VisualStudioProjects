// јвтоматически создаваемые классы-оболочки IDispatch, созданные при помощи мастера добавлени€ класса из библиотеки типов

#import "C:\\Program Files (x86)\\Microsoft Office\\Office15\\MSWORD.OLB" no_namespace
// CReadabilityStatistic класс-оболочка

class CReadabilityStatistic : public COleDispatchDriver
{
public:
	CReadabilityStatistic(){} // ¬ызывает конструктор по умолчанию дл€ COleDispatchDriver
	CReadabilityStatistic(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CReadabilityStatistic(const CReadabilityStatistic& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// јтрибуты
public:

	// ќперации
public:


	// ReadabilityStatistic методы
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
	CString get_Name()
	{
		CString result;
		InvokeHelper(0x0, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	float get_Value()
	{
		float result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	// ReadabilityStatistic свойства
public:

};
