#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string>
#include <QMessageBox>
#include <QString>
#include <QFileDialog>
#include "crypto.h"
#include "aboutdialog.h"

using namespace std;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(this->width(), this->height());

}

MainWindow::~MainWindow()
{
    delete ui;
}

//An event handler for the Encryption button
void MainWindow::on_btnEncrypt_clicked()
{

  string path = ui->txtPath->toPlainText().toStdString();
  string password = ui->txtPassword->toPlainText().toStdString();
  if(path == "" or password == ""){
      QMessageBox::about(this,"Error!","YOU FORGOT TO ENTER THE PATH OR THE PASSWORD!!");
    }
  else if (!crypto::is_digits(password)){
      QMessageBox::about(this,"Error!","YOU PASSWORD SHOULD NOT CONTAIN CHARACHTERS INSTED USE NUMBERS ONLY!");
    }
  else{
      ofstream out;
      ifstream in;


      string target = crypto::read_file(in,path);
      string encrypted = crypto::encrypt(target,password);
      crypto::write_to_file(out,encrypted,path);
      QMessageBox::about(this,"Done","Your file is encrypted successfully.");

    }
}

//An event handler for the Decryption button
void MainWindow::on_btnBrowse_clicked()
{
    QString filePath = QFileDialog::getOpenFileName(this,"Slect a file","c://","Text Files (*.txt)");
    ui->txtPath->setPlainText(filePath);
}

void MainWindow::on_btnDecrypt_clicked()
{
  string path = ui->txtPath->toPlainText().toStdString();
  string password = ui->txtPassword->toPlainText().toStdString();
  if(path == "" or password == ""){
      QMessageBox::about(this,"Error!","YOU FORGOT TO ENTER THE PATH OR THE PASSWORD.");
    }
  else if (!crypto::is_digits(password)){
      QMessageBox::about(this,"Error!","YOU PASSWORD SHOULD NOT CONTAIN CHARACHTERS INSTED USE NUMBERS ONLY!!");
    }
  else{
  ofstream out;
  ifstream in;

  string f;
  f = crypto::read_file(in,path);
  string ss = crypto::decrypt(f,password);
  crypto::write_to_file(out,ss,path);
  QMessageBox::about(this,"Done","Your file is decrypted successfully.");
    }

}

void MainWindow::on_actionTeam_triggered()
{

    AboutDialog about;
    about.setModal(true);
    about.exec();
}


