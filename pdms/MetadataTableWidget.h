#ifndef METADATATABLEWIDGET_H
#define METADATATABLEWIDGET_H
// MetadataTableWidget.h
#include <QTableWidget>

class MetadataTableWidget : public QTableWidget {
    Q_OBJECT
public:
    using QTableWidget::QTableWidget;

protected:
    void contextMenuEvent(QContextMenuEvent* event) override;

public slots:
    void onMetadataItemChanged();
};

#endif // METADATATABLEWIDGET_H
