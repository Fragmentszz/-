// XlsxWriter.cpp : 定义静态库的函数。
//

#include<direct.h>
#include"XlsxWriter.h"
// TODO: 这是一个库函数示例
using namespace std;
using namespace OpenXLSX;
XlsxWriter::XlsxWriter(std::string filepath, std::string sheetname)
{
	doc.open(filepath);
	if (!doc.isOpen()) {
		doc.create(filepath);
		doc.open(filepath);
	}
	wb = doc.workbook();
	if (!wb.sheetExists(sheetname)) {
		wb.addWorksheet(sheetname);
	}
	ws = wb.worksheet(sheetname);
	nown = ws.rowCount() + 1;
	m = ws.columnCount();
	nowm = 0;
}

void XlsxWriter::writeRow(ANS& ans)
{
	nown++, nowm = 0;
	for (int i = 0; i < ans.dim; i++)
	{
		ws.cell(nown, i + 1).value() = ans[i];
	}
}

void XlsxWriter::write(ld x)
{
	++nowm;
	ws.cell(nown, nowm).value() = x;
}
void XlsxWriter::writeAns(ANS& ans)
{
	for (int i = 0; i < ans.dim; i++)
	{
		++nowm;
		ws.cell(nown,nowm).value() = ans[i];
	}
}

void XlsxWriter::nextRow()
{
	++nown; nowm = 0;
}
MyCell XlsxWriter::operator()(int rindex, int cindex)
{
	return MyCell(ws.cell(rindex, cindex));
}

XlsxWriter::~XlsxWriter()
{
	doc.save();
	doc.close();
}


/*====================*/

//template<typename _T>
//void MyCell::operator=(_T value)
//{
//	this->value() = value;
//}

void MyCell::operator=(int value)
{
	this->value() = value;
}

void MyCell::operator=(double value)
{
	this->value() = value;
}
void MyCell::operator=(std::string s)
{
	this->value() = s;
}

MyCell::MyCell(OpenXLSX::XLCell c):OpenXLSX::XLCell(c)
{

}