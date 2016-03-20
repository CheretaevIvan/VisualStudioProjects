// ������������� ����������� ������-�������� IDispatch, ��������� ��� ������ ������� ���������� ������ �� ���������� �����

#import "C:\\Program Files (x86)\\Microsoft Office\\Office15\\MSWORD.OLB" no_namespace
// COCXEvents �����-��������

class COCXEvents : public COleDispatchDriver
{
public:
	COCXEvents(){} // �������� ����������� �� ��������� ��� COleDispatchDriver
	COCXEvents(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	COCXEvents(const COCXEvents& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// ��������
public:

	// ��������
public:


	// OCXEvents ������
public:
	void GotFocus()
	{
		InvokeHelper(0x800100e0, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	void LostFocus()
	{
		InvokeHelper(0x800100e1, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	// OCXEvents ��������
public:

};
