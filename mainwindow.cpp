#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QCheckBox>
#include <QInputDialog>
#include <QFont>
#include <QComboBox>


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

    // Ajouter la couleur de fond rouge
    checkbox->setStyleSheet("background-color: red");

    item->setSizeHint(checkbox->sizeHint());

    ui->listWidget->addItem(item);
    ui->listWidget->setItemWidget(item, checkbox);

    ui->lineEdit->clear();
}


void MainWindow::on_pushButton_2_clicked()
{

    QListWidgetItem *item2 = ui->listWidget_2->takeItem(ligneSelected);
    delete item2;

    QListWidgetItem *item = ui->listWidget->takeItem(ligneSelected);
       delete item;
}

void MainWindow::on_listWidget_currentRowChanged(int currentRow)
{
    ligneSelected = currentRow;
}

void MainWindow::on_listWidget_2_currentRowChanged(int currentRow)
{
    ligneSelected = currentRow;
}


void MainWindow::on_pushButton_3_clicked()
{
    for (int i = 0; i < ui->listWidget->count(); i++) {
        QListWidgetItem* item = ui->listWidget->item(i);
        QCheckBox* checkbox = qobject_cast<QCheckBox*>(ui->listWidget->itemWidget(item));
        if (checkbox && checkbox->isChecked()) {
            ui->listWidget->takeItem(i);
            delete item;
            i--;
        }
    }

    for (int i = 0; i < ui->listWidget_2->count(); i++) {
        QListWidgetItem* item = ui->listWidget_2->item(i);
        QCheckBox* checkbox = qobject_cast<QCheckBox*>(ui->listWidget_2->itemWidget(item));
        if (checkbox && checkbox->isChecked()) {
            ui->listWidget_2->takeItem(i);
            delete item;
            i--;
        }
    }
}


void MainWindow::on_pushButton_4_clicked()
{
    if (ligneSelected == -1) // Vérifie si un élément est sélectionné
           return;

    QListWidgetItem* item = ui->listWidget->item(ligneSelected);
    QCheckBox* checkbox = qobject_cast<QCheckBox*>(ui->listWidget->itemWidget(item));

    if (!checkbox) // Vérifie si l'item est un QCheckBox
           return;

    QString task = checkbox->text(); // Récupère le texte du QCheckBox

    // Crée une boîte de dialogue pour demander à l'utilisateur de modifier la tâche
    bool ok;
    QString newTask = QInputDialog::getText(this, tr("TODO LIST"), tr("Modifier la tâche :"), QLineEdit::Normal, task, &ok);

        if (ok && !newTask.isEmpty()) { // Si l'utilisateur a cliqué sur OK et que le texte n'est pas vide
           checkbox->setText(newTask); // Met à jour le texte du QCheckBox avec la nouvelle tâche
    }
}

void MainWindow::on_pushButton_5_clicked()
{
    for (int i = 0; i < ui->listWidget->count(); i++) {
        QListWidgetItem* item = ui->listWidget->item(i);
        QCheckBox* checkbox = qobject_cast<QCheckBox*>(ui->listWidget->itemWidget(item));
        if (checkbox && checkbox->isChecked()) {
            QListWidgetItem* newItem = new QListWidgetItem(ui->listWidget_2);
            QCheckBox* newCheckbox = new QCheckBox(checkbox->text(), ui->listWidget_2);
            newCheckbox->setChecked(true);
            newItem->setSizeHint(newCheckbox->sizeHint());
            newItem->setBackground(QBrush(Qt::green));
            ui->listWidget_2->addItem(newItem);
            ui->listWidget_2->setItemWidget(newItem, newCheckbox);
            ui->listWidget->takeItem(i);
            i--;
        }
    }
}

