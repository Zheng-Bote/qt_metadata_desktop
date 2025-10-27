#pragma once

#include <QCloseEvent>
#include <QMainWindow>

#include <QSqlRecord>
#include <QSqlTableModel>
#include <QTableView>

#include <QDir>
#include <QHash>

#include <QSettings>
#include <qapplication.h>

#include "includes/sqlite3.hpp"

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

private slots:
    void on_tabWidget_tabBarClicked(int index);

    void on_action_save_triggered();

    void on_action_open_DB_triggered();

    void on_tableView_exif_clicked(const QModelIndex &index);

    void on_tableView_iptc_clicked(const QModelIndex &index);

    void on_tableView_xmp_clicked(const QModelIndex &index);

    void on_action_About_triggered();

private:
    Ui::MainWindow *ui;

    QSqlTableModel *modelExif;
    QSqlTableModel *modelIptc;
    QSqlTableModel *modelXmp;
    SQLite3 *myDb;

    QSettings *settings;
    QHash<QString, QString> settingsHash{{"pathFilenameBaseDb",
                                          QApplication::applicationName() + ".sqlite"},
                                         {"pathFilenameDb",
                                          QApplication::applicationName() + ".sqlite"},
                                         {"dir", QDir::homePath()},
                                         {"exif_changed", "false"},
                                         {"iptc_changed", "false"},
                                         {"xmp_changed", "false"}};

    QString getFileName(QString pathToFile);
    QString getFilePath(QString &pathToFile);

    void readSettings();
    void writeSettings(QString attribute, QString &value);

    void resizeEvent(QResizeEvent *event);

    void initializeDB();
    void initializeModel(QSqlTableModel *model, QString tableName);

    void initializeExif();
    void initializeIptc();
    void initializeXmp();

    const void initializeTable(QString table);

    void closeEvent(QCloseEvent *event);
};
