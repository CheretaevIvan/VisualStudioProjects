// ������������� ����������� ������-�������� IDispatch, ��������� ��� ������ ������� ���������� ������ �� ���������� �����

#import "C:\\Program Files (x86)\\Microsoft Office\\Office15\\MSWORD.OLB" no_namespace
// CApplicationEvents0 �����-��������

class CApplicationEvents0 : public COleDispatchDriver
{
public:
	CApplicationEvents0(){} // �������� ����������� �� ��������� ��� COleDispatchDriver
	CApplicationEvents0(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CApplicationEvents0(const CApplicationEvents0& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// ��������
public:

	// ��������
public:


	// IApplicationEvents ������
public:
	void Startup()
	{
		InvokeHelper(0x1, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	void Quit()
	{
		InvokeHelper(0x2, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	void DocumentChange()
	{
		InvokeHelper(0x3, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	// IApplicationEvents ��������
public:

};
