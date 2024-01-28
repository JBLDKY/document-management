#include "MetadataTableWidget.h"
#include <QMenu>
#include <QContextMenuEvent>


void MetadataTableWidget::contextMenuEvent(QContextMenuEvent* event) {
    QMenu menu(this);
    QAction* removeRowAction = menu.addAction("Remove Row");
    QAction* addRowAction = menu.addAction("Add Row");

    QAction* selectedAction = menu.exec(event->globalPos());

    if (selectedAction == removeRowAction) {
        int currentRow = this->currentRow();
        if (currentRow >= 0) {
            this->removeRow(currentRow);
        }
    }

    if (selectedAction == addRowAction) {
        int currentRow = this->currentRow();
        this->insertRow(currentRow + 1);
    }
}

void MetadataTableWidget::onMetadataItemChanged() {
    int lastRow = this->rowCount() - 1;
     if (lastRow < 0) {
        // No rows in the table
        return;
     }

     bool isLastRowFilled = true;
     for (int col = 0; col < this->columnCount(); col++) {
         if (this->item(lastRow, col) == nullptr ||
             this->item(lastRow, col)->text().isEmpty()) {
             isLastRowFilled = false;
             break;
         }
     }

     if (isLastRowFilled) {
         this->insertRow(lastRow + 1);
     }
}
