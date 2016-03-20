// ������������� ����������� ������-�������� IDispatch, ��������� ��� ������ ������� ���������� ������ �� ���������� �����

#import "C:\\Program Files (x86)\\Microsoft Office\\Office15\\MSWORD.OLB" no_namespace
// CAdjustments �����-��������

class CAdjustments : public COleDispatchDriver
{
public:
	CAdjustments(){} // �������� ����������� �� ��������� ��� COleDispatchDriver
	CAdjustments(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CAdjustments(const CAdjustments& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// ��������
public:

	// ��������
public:


	// Adjustments ������
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
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	long get_Count()
	{
		long result;
		InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	float get_Item(long Index)
	{
		float result;
		static BYTE parms[] = VTS_I4;
		InvokeHelper(0x0, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, parms, Index);
		return result;
	}
	void put_Item(long Index, float newValue)
	{
		static BYTE parms[] = VTS_I4 VTS_R4;
		InvokeHelper(0x0, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, Index, newValue);
	}

	// Adjustments ��������
public:

};
