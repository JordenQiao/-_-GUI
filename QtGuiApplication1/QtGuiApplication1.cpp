#include "QtGuiApplication1.h"

QtGuiApplication1::QtGuiApplication1(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

void QtGuiApplication1::on_btn_nd_add_clicked()
{
	QString context = ui.ledt_nd_add->text();
	if (!ui.ledt_nd_add->text().isEmpty()) {
		ui.list_dl->addItem(ui.ledt_nd_add->text());
		ui.ledt_nd_add->clear();
	}
}

void QtGuiApplication1::on_btn_dl_clear_clicked()
{
	ui.list_dl->clear();
}

void QtGuiApplication1::on_btn_dl_delete_clicked()
{
	QList<QListWidgetItem*> list = ui.list_dl->selectedItems();
	if (list.size() == 0)
		return;
	ui.list_dl->takeItem(ui.list_dl->row(list[0]));
}

void QtGuiApplication1::on_btn_import_clicked()
{
	QString filepath = QFileDialog::getOpenFileName(this, "ѡ��Ҫ������ļ�", "/", "�ı��ļ� (*.txt);; �����ļ� (*.*);;");
	qDebug() << "path=" << filepath;
	QFile file(filepath);
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
		qDebug() << "file open failed!";
		return;
	}
	QTextStream in(&file);
	QString line = in.readLine(0);
	int cnt = line.toInt();
	while (!in.atEnd()) {
		line = in.readLine();
		ui.list_dl->addItem(line);
	}
}

void QtGuiApplication1::on_btn_run_clicked()
{

}
