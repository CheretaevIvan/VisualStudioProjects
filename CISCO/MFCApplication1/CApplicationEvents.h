// јвтоматически создаваемые классы-оболочки IDispatch, созданные при помощи мастера добавлени€ класса из библиотеки типов

#import "C:\\Program Files (x86)\\Microsoft Office\\Office15\\MSWORD.OLB" no_namespace
// CApplicationEvents класс-оболочка

class CApplicationEvents : public COleDispatchDriver
{
public:
	CApplicationEvents(){} // ¬ызывает конструктор по умолчанию дл€ COleDispatchDriver
	CApplicationEvents(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CApplicationEvents(const CApplicationEvents& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// јтрибуты
public:

	// ќперации
public:


	// ApplicationEvents методы
public:

	// ApplicationEvents свойства
public:

};
