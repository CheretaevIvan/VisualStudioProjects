// ������������� ����������� ������-�������� IDispatch, ��������� ��� ������ ������� ���������� ������ �� ���������� �����

#import "C:\\Program Files (x86)\\Microsoft Office\\Office15\\MSWORD.OLB" no_namespace
// CListTemplate �����-��������

class CListTemplate : public COleDispatchDriver
{
public:
	CListTemplate(){} // �������� ����������� �� ��������� ��� COleDispatchDriver
	CListTemplate(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CListTemplate(const CListTemplate& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// ��������
public:

	// ��������
public:


	// ListTemplate ������
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
	BOOL get_OutlineNumbered()
	{
		BOOL result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	void put_OutlineNumbered(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL;
		InvokeHelper(0x1, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	CString get_Name()
	{
		CString result;
		InvokeHelper(0x3, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	void put_Name(LPCTSTR newValue)
	{
		static BYTE parms[] = VTS_BSTR;
		InvokeHelper(0x3, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	LPDISPATCH get_ListLevels()
	{
		LPDISPATCH result;
		InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH Convert(VARIANT * Level)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_PVARIANT;
		InvokeHelper(0x65, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, Level);
		return result;
	}

	// ListTemplate ��������
public:

};
