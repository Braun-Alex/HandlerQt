#pragma once
#ifndef HANDLER_H
#define HANDLER_H
#include <QMainWindow>
#include <QLineEdit>
#include <QFileDialog>
#include <QFile>
#include <QMessageBox>
#include <QXmlStreamReader>
#include <QtXml/QDomDocument>
#include <QtTest>
#include <sstream>
#include <set>
bool operator==(const std::pair<std::string,std::string>
                &the_first_pair,
                const std::pair<std::string,std::string>
                &the_second_pair);
class Strategy_Filter
{
public:
std::vector<std::vector<QString>>
virtual Filter(QFile &the_file,
std::map<std::pair<std::string,std::string>,bool>
&the_data,QMessageBox &the_error,
const std::vector<QString> &the_keys);
virtual ~Strategy_Filter();
};
class Initializer
{
public:
Initializer(Strategy_Filter* entered_filter=nullptr);
void Initialize(Strategy_Filter* entered_filter);
std::vector<std::vector<QString>>
Process(QFile &the_file,
std::map<std::pair<std::string,std::string>,bool>
&the_data,QMessageBox &the_error,
const std::vector<QString> &the_keys);
~Initializer();
private:
Strategy_Filter *the_filter;
};
class SAX_Filter:public Strategy_Filter
{
public:
std::vector<std::vector<QString>>
virtual Filter(QFile &the_file,
std::map<std::pair<std::string,std::string>,bool>
&the_data,QMessageBox &the_error,
const std::vector<QString> &the_keys) override;
};
class DOM_Filter:public Strategy_Filter
{
public:
std::vector<std::vector<QString>>
virtual Filter(QFile &the_file,
std::map<std::pair<std::string,std::string>,bool>
&the_data,QMessageBox &the_error,
const std::vector<QString> &the_keys) override;
};
class Algorithms_Filter:public Strategy_Filter
{
public:
std::vector<std::vector<QString>>
virtual Filter(QFile &the_file,
std::map<std::pair<std::string,std::string>,bool>
&the_data,QMessageBox &the_error,
const std::vector<QString> &the_keys) override;
};
QT_BEGIN_NAMESPACE
namespace Ui { class Handler; }
QT_END_NAMESPACE
class Handler:public QMainWindow
{
    Q_OBJECT
public:
    Handler(QWidget *the_widget=nullptr);
    ~Handler();
private slots:
void OpenXMLFile();
void ChangeFilter();
void ChangeNameOption();
void ChangeFacultyOption();
void ChangeChairOption();
void ChangeSpecializationOption();
void ChangeFormOption();
void ChangeStudyingBeginOption();
void ChangeExamsScheduleOption();
void ChangeOffsetsScheduleOption();
void ChangeReportingFormOption();
void ChangeReportingScheduleOption();
void SaveHTMLFile();
private:
    bool IsDone=false;
    Ui::Handler *ui;
    QFile the_file;
    QFileDialog the_dialog;
    QMessageBox the_error;
    std::vector<std::vector<QString>> the_database;
    Initializer* the_filter=new Initializer(new SAX_Filter());
    std::vector<QString> the_keys={"name","faculty","chair",
                                   "specialization","form",
                                   "start_of_studying",
                                   "schedule_of_exams",
                                   "schedule_of_offsets",
                                   "forms_of_reporting",
                                   "schedule_of_reporting"};
    std::array<QString,10> the_headers={"П.І.Б.","Факультет",
                                      "Кафедра","Фах",
                                      "Форма навчання",
                                      "Початок навчання",
                                      "Графік іспитів",
                                      "Графік заліків",
                                      "Форми звітності на кафедрі",
                                      "Терміни звітності на кафедрі"};
};
#endif
class TestFilter:public QObject
{
Q_OBJECT
public:
explicit TestFilter(QObject* the_test_filter=nullptr);
~TestFilter();
private slots:
void TestSAXFilter();
void TestDOMFilter();
void TestAlgorithmsFilter();
private:
Initializer* the_filter=new Initializer(new SAX_Filter());
QFile the_test_file;
std::vector<std::vector<QString>> the_test_database=
{{"Белова Анна Сергіївна","ФКНК","Невідома","Комп'ютерні науки",
 "Денна","01.09.2021","Невідомо","Невідомо","Невідомо","Невідомо"}};
std::vector<QString> the_keys={"name","faculty","chair",
                               "specialization","form",
                               "start_of_studying",
                               "schedule_of_exams",
                               "schedule_of_offsets",
                               "forms_of_reporting",
                               "schedule_of_reporting"};
std::map<std::pair<std::string,std::string>,bool> the_test_choice=
{{{"faculty","ФКНК"},true}};
QMessageBox the_test_error;
};
