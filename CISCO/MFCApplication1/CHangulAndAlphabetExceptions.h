// ������������� ����������� ������-�������� IDispatch, ��������� ��� ������ ������� ���������� ������ �� ���������� �����

#import "C:\\Program Files (x86)\\Microsoft Office\\Office15\\MSWORD.OLB" no_namespace
// CHangulAndAlphabetExceptions �����-��������

class CHangulAndAlphabetExceptions : public COleDispatchDriver
{
public:
	CHangulAndAlphabetExceptions(){} // �������� ����������� �� ��������� ��� COleDispatchDriver
	CHangulAndAlphabetExceptions(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CHangulAndAlphabetExceptions(const CHangulAndAlphabetExceptions& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// ��������
public:

	// ��������
public:


	// HangulAndAlphabetExceptions ������
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
	LPUNKNOWN get__NewEnum()
	{
		LPUNKNOWN result;
		InvokeHelper(0xfffffffc, DISPATCH_PROPERTYGET, VT_UNKNOWN, (void*)&result, NULL);
		return result;
	}
	long get_Count()
	{
		long result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH Item(VARIANT * Index)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_PVARIANT;
		InvokeHelper(0x0, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, Index);
		return result;
	}
	LPDISPATCH Add(LPCTSTR Name)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_BSTR;
		InvokeHelper(0x65, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, Name);
		return result;
	}

	// HangulAndAlphabetExceptions ��������
public:

};
