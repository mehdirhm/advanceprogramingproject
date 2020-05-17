#ifndef ABOUTME_H
#define ABOUTME_H

#include <QMainWindow>

namespace Ui {
class aboutme;
}

class aboutme : public QMainWindow
{
    Q_OBJECT

public:
    explicit aboutme(QWidget *parent = nullptr);
    ~aboutme();

private:
    Ui::aboutme *ui;
};

#endif // ABOUTME_H
