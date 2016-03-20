// јвтоматически создаваемые классы-оболочки IDispatch, созданные при помощи мастера добавлени€ класса из библиотеки типов

#import "C:\\Program Files (x86)\\Microsoft Office\\Office15\\MSWORD.OLB" no_namespace
// CDocumentEvents класс-оболочка

class CDocumentEvents : public COleDispatchDriver
{
public:
	CDocumentEvents(){} // ¬ызывает конструктор по умолчанию дл€ COleDispatchDriver
	CDocumentEvents(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CDocumentEvents(const CDocumentEvents& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// јтрибуты
public:

	// ќперации
public:


	// DocumentEvents методы
public:
	void New()
	{
		InvokeHelper(0x4, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	void Open()
	{
		InvokeHelper(0x5, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	void Close()
	{
		InvokeHelper(0x6, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	// DocumentEvents свойства
public:

};
