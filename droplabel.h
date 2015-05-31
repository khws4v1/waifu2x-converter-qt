#ifndef DROPLABEL_H
#define DROPLABEL_H

#include <QLabel>
#include <QDropEvent>

class DropLabel : public QLabel
{
    Q_OBJECT
public:
    DropLabel(QWidget* parent = nullptr);

signals:
    void fileDropped(const QString& fileName);

private:
    void dragEnterEvent(QDragEnterEvent* e);
    void dropEvent(QDropEvent* e);
};

#endif // DROPLABEL_H
