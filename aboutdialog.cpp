#include "aboutdialog.h"
#include "ui_aboutdialog.h"

AboutDialog::AboutDialog(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::AboutDialog)
{
  ui->setupUi(this);
  this->setFixedSize(this->width(), this->height());
}

AboutDialog::~AboutDialog()
{
  delete ui;
}
