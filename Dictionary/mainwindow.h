#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void searchAndAddToComboBox( const QString& prefix);




private slots:

    void on_findButton_clicked();

    void on_textEdit_textChanged();

    void on_addButton_clicked();

    void on_delButton_clicked();

    void on_suggestBox_currentRowChanged(int currentRow);

    void findOnComboBox(int index);

    void setWordNum();



private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
