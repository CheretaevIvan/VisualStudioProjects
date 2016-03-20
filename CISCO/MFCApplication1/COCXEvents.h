// јвтоматически создаваемые классы-оболочки IDispatch, созданные при помощи мастера добавлени€ класса из библиотеки типов

#import "C:\\Program Files (x86)\\Microsoft Office\\Office15\\MSWORD.OLB" no_namespace
// COCXEvents класс-оболочка

class COCXEvents : public COleDispatchDriver
{
public:
	COCXEvents(){} // ¬ызывает конструктор по умолчанию дл€ COleDispatchDriver
	COCXEvents(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	COCXEvents(const COCXEvents& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// јтрибуты
public:

	// ќперации
public:


	// OCXEvents методы
public:
	void GotFocus()
	{
		InvokeHelper(0x800100e0, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	void LostFocus()
	{
		InvokeHelper(0x800100e1, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	// OCXEvents свойства
public:

};
