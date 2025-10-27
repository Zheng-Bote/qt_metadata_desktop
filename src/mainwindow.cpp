#include "mainwindow.hpp"
#include "includes/rz_config.h"
#include "ui_mainwindow.h"

#include "includes/rz_qt_metatags.hpp"

#include <QFuture>
#include <QFutureWatcher>
#include <QThread>
#include <QtConcurrent>

#include <QFileDialog>
#include <QTableWidgetItem>

#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //qApp->setWindowIcon(QIcon(":/Eo_circle_green_letter-m.png"));
    //setWindowIcon(QIcon(":/Eo_circle_green_letter-m.png"));

    settings = new QSettings;
    initializeDB();

    initializeExif();
    initializeIptc();
    initializeXmp();

    ui->menubar->setNativeMenuBar(false);

    ui->action_open_DB->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_O));
    ui->action_save->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_S));
    ui->action_About->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_A));

    ui->tabWidget->adjustSize();
    ui->tabWidget->setCurrentWidget(0);
    ui->tabWidget->setCurrentIndex(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);
}

void MainWindow::initializeDB()
{
    readSettings();
    qDebug() << "DB: " << settingsHash.value("pathFilenameDb");
    ui->statusbar->showMessage(getFileName(settingsHash.value("pathFilenameDb")));

    myDb = new SQLite3;
    //QString testDb = "test.db";

    myDb->openDb(settingsHash["pathFilenameDb"]);
    myDb->createTable("EXIF");
    myDb->createTable("IPTC");
    myDb->createTable("XMP");

    initializeTable("EXIF");
    initializeTable("IPTC");
    initializeTable("XMP");

    /* due to SQLite 
    QFuture<void> futureExif = QtConcurrent::run(&MainWindow::initializeExifTable, this);
    QFuture<void> futureIptc = QtConcurrent::run(&MainWindow::initializeIptcTable, this);
    QFuture<void> futureXmp = QtConcurrent::run(&MainWindow::initializeXmpTable, this);
    */
}

void MainWindow::initializeModel(QSqlTableModel *model, QString tableName)
{
    model->setTable(tableName);
    qDebug() << "Database: " << model->database();
    qDebug() << "Table: " << model->tableName();
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    if (model->select()) {
        qDebug() << "select OK";
        qDebug() << "rows: " << model->rowCount();
    } else {
        qDebug() << "select NOK";
    }

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Attribute"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Value"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Description"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Active"));
}

void MainWindow::initializeExif()
{
    modelExif = new QSqlTableModel;
    initializeModel(modelExif, "EXIF");
    ui->tableView_exif->setModel(modelExif);
    ui->tableView_exif->hideColumn(0);
    ui->tableView_exif->setWindowTitle("Exif");
    ui->tableView_exif->resizeColumnsToContents();
    ui->tableView_exif->resizeRowsToContents();
    ui->tableView_exif->setSortingEnabled(true);
    ui->tableView_exif->show();
}

void MainWindow::initializeIptc()
{
    modelIptc = new QSqlTableModel;
    initializeModel(modelIptc, "IPTC");
    ui->tableView_iptc->setModel(modelIptc);
    ui->tableView_iptc->hideColumn(0);
    ui->tableView_iptc->setWindowTitle("IPTC");
    ui->tableView_iptc->resizeColumnsToContents();
    ui->tableView_iptc->resizeRowsToContents();
    ui->tableView_iptc->setSortingEnabled(true);
    ui->tableView_iptc->show();
}

void MainWindow::initializeXmp()
{
    modelXmp = new QSqlTableModel;
    initializeModel(modelXmp, "XMP");
    ui->tableView_xmp->setModel(modelXmp);
    ui->tableView_xmp->hideColumn(0);
    ui->tableView_xmp->setWindowTitle("XMP");
    ui->tableView_xmp->resizeColumnsToContents();
    ui->tableView_xmp->resizeRowsToContents();
    ui->tableView_xmp->setSortingEnabled(true);
    ui->tableView_xmp->show();
}

const void MainWindow::initializeTable(QString table)
{
    MetaTags metaTags;

    if (table.contains("EXIF")) {
        for (auto i = metaTags.exifMetaTags.cbegin(), end = metaTags.exifMetaTags.cend(); i != end;
             ++i) {
            QString query = "insert into " + table + " (attribute, description) values('" + i.key()
                            + "', '" + i.value() + "')";
            myDb->insertData(query);
        }
        return;
    }
    if (table.contains("IPTC")) {
        for (auto i = metaTags.iptcMetaTags.cbegin(), end = metaTags.iptcMetaTags.cend(); i != end;
             ++i) {
            QString query = "insert into " + table + " (attribute, description) values('" + i.key()
                            + "', '" + i.value() + "')";
            myDb->insertData(query);
        }
        return;
    }
    if (table.contains("XMP")) {
        for (auto i = metaTags.xmpMetaTags.cbegin(), end = metaTags.xmpMetaTags.cend(); i != end;
             ++i) {
            QString query = "insert into " + table + " (attribute, description) values('" + i.key()
                            + "', '" + i.value() + "')";
            myDb->insertData(query);
        }
        return;
    }

    myDb->insertData("commit()");
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    bool unsafedData{false};

    if (settingsHash["exif_changed"].compare("true") == 0) {
        unsafedData = true;
    }
    if (settingsHash["iptc_changed"].compare("true") == 0) {
        unsafedData = true;
    }
    if (settingsHash["xmp_changed"].compare("true") == 0) {
        unsafedData = true;
    }

    if (unsafedData == false) {
        event->accept();
        return;
    }

    QMessageBox::StandardButton response;

    response = QMessageBox::question(this,
                                     tr("Confirmation"),
                                     tr("Are you sure you want to exit without saving data?"),
                                     QMessageBox::Yes | QMessageBox::No);

    if (response == QMessageBox::Yes) {
        event->accept();
    } else {
        event->ignore();
    }
}

void MainWindow::on_tabWidget_tabBarClicked(int index) {}

void MainWindow::on_action_save_triggered()
{
    if (settingsHash["exif_changed"].compare("true") == 0) {
        modelExif->submitAll();
    }
    if (settingsHash["iptc_changed"].compare("true") == 0) {
        modelIptc->submitAll();
    }
    if (settingsHash["xmp_changed"].compare("true") == 0) {
        modelXmp->submitAll();
    }

    qDebug() << "on_action_save_triggered: saved";
}

void MainWindow::readSettings()
{
    QHash<QString, QString>::const_iterator i = settingsHash.constBegin();
    while (i != settingsHash.constEnd()) {
        qDebug() << i.key() << ": " << i.value();
        ++i;
    }

    //settingsHash["pathFilenameDb"]
    //    = settings->value("db", QCoreApplication::applicationName() + ".sqlite").toString();
}

void MainWindow::writeSettings(QString attribute, QString &value)
{
    if (attribute.compare("pathToDbFile") == 0) {
        settingsHash["pathFilenameDb"] = value;
        settingsHash["dir"] = getFilePath(value);
        ui->statusbar->showMessage(getFileName(value));
    }
}

void MainWindow::on_action_open_DB_triggered()
{
    QString pathToDbFile = QFileDialog::getOpenFileName(this,
                                                        tr("Open File"),
                                                        settingsHash.value("dir"),
                                                        tr("SQLite (*.db *.sqlite)"));

    if (pathToDbFile.isEmpty() == false) {
        qDebug() << "db file: " << pathToDbFile;
        writeSettings("pathToDbFile", pathToDbFile);

        initializeDB();

        initializeExif();
        initializeIptc();
        initializeXmp();
    }
}

QString MainWindow::getFileName(QString pathToFile)
{
    QFile file(pathToFile);
    QFileInfo fileInfo(pathToFile);
    qDebug() << "fileName: " << fileInfo.fileName();
    return fileInfo.fileName();
}

QString MainWindow::getFilePath(QString &pathToFile)
{
    QFile file(pathToFile);
    QFileInfo fileInfo(pathToFile);
    qDebug() << "absolutePath: " << fileInfo.absolutePath();
    return fileInfo.absolutePath();
}

void MainWindow::on_tableView_exif_clicked(const QModelIndex &index)
{
    settingsHash["exif_changed"] = "true";
}

void MainWindow::on_tableView_iptc_clicked(const QModelIndex &index)
{
    settingsHash["iptc_changed"] = "true";
}

void MainWindow::on_tableView_xmp_clicked(const QModelIndex &index)
{
    settingsHash["xmp_changed"] = "true";
}

void MainWindow::on_action_About_triggered()
{
    QString text = tr(qApp->applicationDisplayName().toStdString().c_str()) + " v"
                   + qApp->applicationVersion() + "\n\n";
    QString setInformativeText = "<p>" + tr(PROG_DESCRIPTION) + "<p>";
    setInformativeText.append("<p>Copyright (c) 2025 ZHENG Robert</p>");
    setInformativeText.append("<br><a href=\"");
    setInformativeText.append(PROG_HOMEPAGE);
    setInformativeText.append("\" alt=\"Github repository\">");
    setInformativeText.append(qApp->applicationName() + " " + tr("at") + " Github</a>");

    QMessageBox msgBox(this);
    msgBox.setWindowTitle(tr("About") + " " + qApp->applicationDisplayName());
    msgBox.setIcon(QMessageBox::Information);
    msgBox.setTextFormat(Qt::RichText);
    msgBox.setText(text);
    msgBox.setInformativeText(setInformativeText);
    //msgBox.setFixedWidth(400);
    msgBox.exec();
}
