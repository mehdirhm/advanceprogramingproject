#ifndef GUIDEPAGE_H
#define GUIDEPAGE_H

#include <QMainWindow>

namespace Ui {
class GuidePage;
}

class GuidePage : public QMainWindow
{
    Q_OBJECT

public:
    explicit GuidePage(QWidget *parent = nullptr);
    ~GuidePage();

private:
    Ui::GuidePage *ui;
};

#endif // GUIDEPAGE_H
