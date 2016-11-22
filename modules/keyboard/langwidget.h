#ifndef LANGWIDGET_H
#define LANGWIDGET_H

#include "contentwidget.h"
#include "indexdelegate.h"
#include "indexview.h"
#include "indexmodel.h"

class QLineEdit;

class LangWidget : public ContentWidget
{
    Q_OBJECT

public:
    explicit LangWidget(QWidget *parent = 0);
    void setModelData(const QList<MetaData>& datas);

signals:
    void click(const QModelIndex& index);

public slots:
    void onSearch(const QString& text);

private:
    QLineEdit* m_search;
    IndexDelegate* m_delegate;
    IndexView* m_view;
    IndexModel* m_model;
    IndexModel* m_searchModel;
};

#endif // LANGWIDGET_H