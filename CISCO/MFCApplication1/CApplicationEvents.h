// ������������� ����������� ������-�������� IDispatch, ��������� ��� ������ ������� ���������� ������ �� ���������� �����

#import "C:\\Program Files (x86)\\Microsoft Office\\Office15\\MSWORD.OLB" no_namespace
// CApplicationEvents �����-��������

class CApplicationEvents : public COleDispatchDriver
{
public:
	CApplicationEvents(){} // �������� ����������� �� ��������� ��� COleDispatchDriver
	CApplicationEvents(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CApplicationEvents(const CApplicationEvents& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// ��������
public:

	// ��������
public:


	// ApplicationEvents ������
public:

	// ApplicationEvents ��������
public:

};
