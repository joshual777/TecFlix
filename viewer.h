#ifndef VIEWER_H
#define VIEWER_H

#include <QDialog>

namespace Ui {
class Viewer;
}

class Viewer : public QDialog
{
    Q_OBJECT

public:
    explicit Viewer(QWidget *parent = nullptr);
    ~Viewer();

private:
    Ui::Viewer *ui;
};

#endif // VIEWER_H
