#ifndef DIALOGBDFORM_H
#define DIALOGBDFORM_H

#include <QDialog>

namespace Ui {
class DialogBDForm;
}

class DialogBDForm : public QDialog
{
    Q_OBJECT

public:
    explicit DialogBDForm(QWidget *parent = nullptr);
    ~DialogBDForm();

private:
    Ui::DialogBDForm *ui;
};

#endif // DIALOGBDFORM_H
