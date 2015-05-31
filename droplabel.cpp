#include "droplabel.h"

#include <QMimeData>
#include <QUrl>

DropLabel::DropLabel(QWidget *parent)
    : QLabel(tr("Drop image file here"), parent)
{
    setAcceptDrops(true);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
}

void DropLabel::dragEnterEvent(QDragEnterEvent *e)
{
    if (e->mimeData()->hasUrls())
        if (e->mimeData()->urls().first().isLocalFile())
            e->acceptProposedAction();
}

void DropLabel::dropEvent(QDropEvent *e)
{
    emit fileDropped(e->mimeData()->urls().first().toLocalFile());
}
