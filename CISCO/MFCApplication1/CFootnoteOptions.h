// ������������� ����������� ������-�������� IDispatch, ��������� ��� ������ ������� ���������� ������ �� ���������� �����

#import "C:\\Program Files (x86)\\Microsoft Office\\Office15\\MSWORD.OLB" no_namespace
// CFootnoteOptions �����-��������

class CFootnoteOptions : public COleDispatchDriver
{
public:
	CFootnoteOptions(){} // �������� ����������� �� ��������� ��� COleDispatchDriver
	CFootnoteOptions(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CFootnoteOptions(const CFootnoteOptions& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// ��������
public:

	// ��������
public:


	// FootnoteOptions ������
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
	long get_Location()
	{
		long result;
		InvokeHelper(0x64, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_Location(long newValue)
	{
		static BYTE parms[] = VTS_I4;
		InvokeHelper(0x64, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	long get_NumberStyle()
	{
		long result;
		InvokeHelper(0x65, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_NumberStyle(long newValue)
	{
		static BYTE parms[] = VTS_I4;
		InvokeHelper(0x65, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	long get_StartingNumber()
	{
		long result;
		InvokeHelper(0x66, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_StartingNumber(long newValue)
	{
		static BYTE parms[] = VTS_I4;
		InvokeHelper(0x66, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	long get_NumberingRule()
	{
		long result;
		InvokeHelper(0x67, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_NumberingRule(long newValue)
	{
		static BYTE parms[] = VTS_I4;
		InvokeHelper(0x67, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	long get_LayoutColumns()
	{
		long result;
		InvokeHelper(0x68, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_LayoutColumns(long newValue)
	{
		static BYTE parms[] = VTS_I4;
		InvokeHelper(0x68, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}

	// FootnoteOptions ��������
public:

};
