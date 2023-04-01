#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QCheckBox>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->lineEdit, &QLineEdit::returnPressed, this, &MainWindow::on_pushButton_clicked);

    ui->headlineLabel->setText("TODO LIST MANAGER : Ajouter, modifier et supprimer des tâches en toute simplicité");
                               ui->headlineLabel->setAlignment(Qt::AlignHCenter);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString task = ui->lineEdit->text();

       if (task == "")
           return;

       QListWidgetItem* item = new QListWidgetItem(ui->listWidget);
       QCheckBox* checkbox = new QCheckBox(task);
       item->setSizeHint(checkbox->sizeHint());
       ui->listWidget->addItem(item);
       ui->listWidget->setItemWidget(item, checkbox);

       ui->lineEdit->clear();
}


void MainWindow::on_pushButton_2_clicked()
{
    QListWidgetItem *it = ui->listWidget->takeItem(ligneSelected);
       delete it;
}

void MainWindow::on_listWidget_currentRowChanged(int currentRow)
{
    ligneSelected = currentRow;
}


void MainWindow::on_pushButton_3_clicked()
{

}


void MainWindow::on_pushButton_4_clicked()
{

}




