// ������������� ����������� ������-�������� IDispatch, ��������� ��� ������ ������� ���������� ������ �� ���������� �����

#import "C:\\Program Files (x86)\\Microsoft Office\\Office15\\MSWORD.OLB" no_namespace
// CChartData �����-��������

class CChartData : public COleDispatchDriver
{
public:
	CChartData(){} // �������� ����������� �� ��������� ��� COleDispatchDriver
	CChartData(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CChartData(const CChartData& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// ��������
public:

	// ��������
public:


	// ChartData ������
public:
	LPDISPATCH get_Workbook()
	{
		LPDISPATCH result;
		InvokeHelper(0x60020000, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	void Activate()
	{
		InvokeHelper(0x60020001, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	BOOL get_IsLinked()
	{
		BOOL result;
		InvokeHelper(0x60020002, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	void BreakLink()
	{
		InvokeHelper(0x60020003, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	void ActivateChartDataWindow()
	{
		InvokeHelper(0x60020004, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	// ChartData ��������
public:

};
