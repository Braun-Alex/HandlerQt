#include "handler.h"
#include "./ui_handler.h"
const QString RED_COLOR="color: rgb(255,0,0);",
              GREEN_COLOR="color: rgb(0,255,0);";
Handler::Handler(QWidget *the_widget):QMainWindow(the_widget),
    ui(new Ui::Handler)
{
    ui->setupUi(this);
    the_error.setIcon(QMessageBox::Critical);
    the_error.setWindowTitle("Помилка відкриття XML файлу");
    the_error.setText("Відкритий файл не є файлом типу XML!");
    ui->Save->setDisabled(true);
    ui->Status->setStyleSheet(RED_COLOR);
    ui->Name_value->setDisabled(true);
    ui->Faculty_value->setDisabled(true);
    ui->Chair_value->setDisabled(true);
    ui->Specialization_value->setDisabled(true);
    ui->Form_value->setDisabled(true);
    ui->Studying_begin_value->setDisabled(true);
    ui->Exams_schedule_value->setDisabled(true);
    ui->Offsets_schedule_value->setDisabled(true);
    ui->Reporting_form_value->setDisabled(true);
    ui->Reporting_schedule_value->setDisabled(true);
}
void Handler::OpenXMLFile()
{
the_database.clear();
QString the_path=the_dialog.getOpenFileUrl().path();
if (the_path.isEmpty()) return;
the_path.erase(the_path.begin(),std::next(the_path.begin()));
the_file.setFileName(the_path);
int i=0;
std::string entered_value;
std::map<std::pair<std::string,std::string>,bool> entered_data;
if (ui->Name_value->isEnabled()&&!ui->Name_value->text().isEmpty())
{
    std::istringstream the_stream(ui->Name_value->text().toStdString());
    while (!the_stream.eof())
    {
    std::getline(the_stream,entered_value,';');
    entered_data[make_pair(the_keys[0].toStdString(),entered_value)]=
            true;
    }
}
if (ui->Faculty_value->isEnabled()&&
        !ui->Faculty_value->text().isEmpty())
{
    std::istringstream the_stream(
                ui->Faculty_value->text().toStdString());
    while (!the_stream.eof())
    {
    std::getline(the_stream,entered_value,';');
    entered_data[make_pair(the_keys[1].toStdString(),entered_value)]=
            true;
    }
}
if (ui->Chair_value->isEnabled()&&!ui->Chair_value->text().isEmpty())
{
    std::istringstream the_stream(
                ui->Chair_value->text().toStdString());
    while (!the_stream.eof())
    {
    std::getline(the_stream,entered_value,';');
    entered_data[make_pair(the_keys[2].toStdString(),entered_value)]=
            true;
    }
}
if (ui->Specialization_value->isEnabled()&&
        !ui->Specialization_value->text().isEmpty())
{
    std::istringstream the_stream(
                ui->Specialization_value->text().toStdString());
    while (!the_stream.eof())
    {
    std::getline(the_stream,entered_value,';');
    entered_data[make_pair(the_keys[3].toStdString(),entered_value)]=
            true;
    }
}
if (ui->Form_value->isEnabled()&&!ui->Form_value->text().isEmpty())
{
    std::istringstream the_stream(
                ui->Form_value->text().toStdString());
    while (!the_stream.eof())
    {
    std::getline(the_stream,entered_value,';');
    entered_data[make_pair(the_keys[4].toStdString(),entered_value)]=
            true;
    }
}
if (ui->Studying_begin_value->isEnabled()&&
        !ui->Studying_begin_value->text().isEmpty())
{
    std::istringstream the_stream(
                ui->Studying_begin_value->text().toStdString());
    while (!the_stream.eof())
    {
    std::getline(the_stream,entered_value,';');
    entered_data[make_pair(the_keys[5].toStdString(),entered_value)]=
            true;
    }
}
if (ui->Exams_schedule_value->isEnabled()&&
        !ui->Exams_schedule_value->text().isEmpty())
{
    std::istringstream the_stream(
                ui->Exams_schedule_value->text().toStdString());
    while (!the_stream.eof())
    {
    std::getline(the_stream,entered_value,';');
    entered_data[make_pair(the_keys[6].toStdString(),entered_value)]=
            true;
    }
}
if (ui->Offsets_schedule_value->isEnabled()&&
        !ui->Offsets_schedule_value->text().isEmpty())
{
    std::istringstream the_stream(
                ui->Offsets_schedule_value->text().toStdString());
    while (!the_stream.eof())
    {
    std::getline(the_stream,entered_value,';');
    entered_data[make_pair(the_keys[7].toStdString(),entered_value)]=
            true;
    }
}
if (ui->Reporting_form_value->isEnabled()&&
        !ui->Reporting_form_value->text().isEmpty())
{
    std::istringstream the_stream(
                ui->Reporting_form_value->text().toStdString());
    while (!the_stream.eof())
    {
    std::getline(the_stream,entered_value,';');
    entered_data[make_pair(the_keys[8].toStdString(),entered_value)]=
            true;
    }
}
if (ui->Reporting_schedule_value->isEnabled()&&
        !ui->Reporting_schedule_value->text().isEmpty())
{
    std::istringstream the_stream(
                ui->Reporting_schedule_value->text().toStdString());
    while (!the_stream.eof())
    {
    std::getline(the_stream,entered_value,';');
    entered_data[make_pair(the_keys[9].toStdString(),entered_value)]=
            true;
    }
}
the_database=the_filter->Process(the_file,entered_data,
                                 the_error,the_keys);
if (the_database.empty())
{
ui->Status->setStyleSheet(RED_COLOR);
ui->Status->setText("Обраним критеріям пошуку не відповідає жоден аспірант!");
return;
}
ui->Option->setDisabled(true);
ui->Name->setDisabled(true);
ui->Faculty->setDisabled(true);
ui->Chair->setDisabled(true);
ui->Specialization->setDisabled(true);
ui->Form->setDisabled(true);
ui->Studying_begin->setDisabled(true);
ui->Exams_schedule->setDisabled(true);
ui->Offsets_schedule->setDisabled(true);
ui->Reporting_form->setDisabled(true);
ui->Reporting_schedule->setDisabled(true);
ui->Name_value->setDisabled(true);
ui->Faculty_value->setDisabled(true);
ui->Chair_value->setDisabled(true);
ui->Specialization_value->setDisabled(true);
ui->Form_value->setDisabled(true);
ui->Studying_begin_value->setDisabled(true);
ui->Exams_schedule_value->setDisabled(true);
ui->Offsets_schedule_value->setDisabled(true);
ui->Reporting_form_value->setDisabled(true);
ui->Reporting_schedule_value->setDisabled(true);
ui->Save->setDisabled(false);
ui->Open->setDisabled(true);
ui->Status->setStyleSheet(GREEN_COLOR);
ui->Status->setText("Відфільтровано файл "+the_path+"!");
}
void Handler::ChangeFilter()
{
if (ui->Option->currentText()=="SAX")
the_filter->Initialize(new SAX_Filter());
else if (ui->Option->currentText()=="DOM")
the_filter->Initialize(new DOM_Filter());
else the_filter->Initialize(new Algorithms_Filter());
}
void Handler::ChangeNameOption()
{
if (ui->Name->checkState()==Qt::CheckState::Checked)
ui->Name_value->setDisabled(false);
else ui->Name_value->setDisabled(true);
}
void Handler::ChangeFacultyOption()
{
if (ui->Faculty->checkState()==Qt::CheckState::Checked)
ui->Faculty_value->setDisabled(false);
else ui->Faculty_value->setDisabled(true);
}
void Handler::ChangeChairOption()
{
if (ui->Chair->checkState()==Qt::CheckState::Checked)
ui->Chair_value->setDisabled(false);
else ui->Chair_value->setDisabled(true);
}
void Handler::ChangeSpecializationOption()
{
if (ui->Specialization->checkState()==Qt::CheckState::Checked)
ui->Specialization_value->setDisabled(false);
else ui->Specialization_value->setDisabled(true);
}
void Handler::ChangeFormOption()
{
if (ui->Form->checkState()==Qt::CheckState::Checked)
ui->Form_value->setDisabled(false);
else ui->Form_value->setDisabled(true);
}
void Handler::ChangeStudyingBeginOption()
{
if (ui->Studying_begin->checkState()==Qt::CheckState::Checked)
ui->Studying_begin_value->setDisabled(false);
else ui->Studying_begin_value->setDisabled(true);
}
void Handler::ChangeExamsScheduleOption()
{
if (ui->Exams_schedule->checkState()==Qt::CheckState::Checked)
ui->Exams_schedule_value->setDisabled(false);
else ui->Exams_schedule_value->setDisabled(true);
}
void Handler::ChangeOffsetsScheduleOption()
{
if (ui->Offsets_schedule->checkState()==Qt::CheckState::Checked)
ui->Offsets_schedule_value->setDisabled(false);
else ui->Offsets_schedule_value->setDisabled(true);
}
void Handler::ChangeReportingFormOption()
{
if (ui->Reporting_form->checkState()==Qt::CheckState::Checked)
ui->Reporting_form_value->setDisabled(false);
else ui->Reporting_form_value->setDisabled(true);
}
void Handler::ChangeReportingScheduleOption()
{
if (ui->Reporting_schedule->checkState()==Qt::CheckState::Checked)
ui->Reporting_schedule_value->setDisabled(false);
else ui->Reporting_schedule_value->setDisabled(true);
}
void Handler::SaveHTMLFile()
{
QString the_path=the_dialog.getSaveFileUrl(nullptr,QString(),
                                           QUrl(),"html",
                                           nullptr,
                                           QFileDialog::Options(),
                                           QStringList()).path();
if (the_path.isEmpty()) return;
the_path+=".html";
the_path.erase(the_path.begin(),std::next(the_path.begin()));
the_file.setFileName(the_path);
the_file.open(QIODeviceBase::WriteOnly);
the_file.write("<!DOCTYPE HTML>\n"
               "<html>\n"
               "<link rel=\"stylesheet\" href=\"Table.css\">\n"
               "<body>\n"
               "<table>\n");
the_file.write("<tr>\n");
for (const auto &the_header:the_headers)
{
the_file.write(QString("<th>"+the_header+"</th>\n").toUtf8());
}
the_file.write("</tr>\n");
for (const auto &the_data:the_database)
{
the_file.write("<tr>\n");
for (const auto &the_value:the_data)
the_file.write(QString("<td>"+the_value+"</td>\n").toUtf8());
the_file.write("</tr>\n");
}
the_file.write("</table>\n"
               "</body>\n"
               "</html>");
the_file.close();
ui->Option->setDisabled(false);
ui->Name->setDisabled(false);
ui->Faculty->setDisabled(false);
ui->Chair->setDisabled(false);
ui->Specialization->setDisabled(false);
ui->Form->setDisabled(false);
ui->Studying_begin->setDisabled(false);
ui->Exams_schedule->setDisabled(false);
ui->Offsets_schedule->setDisabled(false);
ui->Reporting_form->setDisabled(false);
ui->Reporting_schedule->setDisabled(false);
if (ui->Name->isChecked()) ui->Name_value->setDisabled(false);
if (ui->Faculty->isChecked()) ui->Faculty_value->setDisabled(false);
if (ui->Chair->isChecked()) ui->Chair_value->setDisabled(false);
if (ui->Specialization->isChecked())
    ui->Specialization_value->setDisabled(false);
if (ui->Form->isChecked()) ui->Form_value->setDisabled(false);
if (ui->Studying_begin->isChecked())
    ui->Studying_begin_value->setDisabled(false);
if (ui->Exams_schedule->isChecked())
    ui->Exams_schedule_value->setDisabled(false);
if (ui->Offsets_schedule->isChecked())
    ui->Offsets_schedule_value->setDisabled(false);
if (ui->Reporting_form->isChecked())
    ui->Reporting_form_value->setDisabled(false);
if (ui->Reporting_schedule->isChecked())
    ui->Reporting_schedule_value->setDisabled(false);
ui->Save->setDisabled(true);
ui->Open->setDisabled(false);
ui->Status->setStyleSheet(GREEN_COLOR);
ui->Status->setText("Збережено файл "+the_path+"!");
}
Handler::~Handler()
{
    delete the_filter;
    delete ui;
}
bool operator==(const std::pair<std::string,std::string>
                &the_first_pair,
                const std::pair<std::string,std::string>
                &the_second_pair)
{
    return std::tie(the_first_pair.first,the_first_pair.second)==
            std::tie(the_second_pair.second,the_second_pair.second);
}
std::vector<std::vector<QString>>
Strategy_Filter::Filter(QFile &the_file,
std::map<std::pair<std::string,std::string>,bool>
&the_data,QMessageBox &the_error,
const std::vector<QString> &the_keys) {}
Strategy_Filter::~Strategy_Filter() {}
Initializer::Initializer(Strategy_Filter* entered_filter):
the_filter(entered_filter) {}
Initializer::~Initializer()
{
if (the_filter!=nullptr) delete the_filter;
}
void Initializer::Initialize(Strategy_Filter* entered_filter)
{
if (the_filter!=nullptr) delete the_filter;
the_filter=entered_filter;
}
std::vector<std::vector<QString>>
Initializer::Process(QFile &the_file,
std::map<std::pair<std::string,std::string>,bool>
&the_data,QMessageBox &the_error,
const std::vector<QString> &the_keys)
{
return the_filter->Filter(the_file,the_data,the_error,the_keys);
}
std::vector<std::vector<QString>>
SAX_Filter::Filter(QFile &the_file,
std::map<std::pair<std::string,std::string>,bool>
&the_data,QMessageBox &the_error,
const std::vector<QString> &the_keys)
{
    the_file.open(QIODeviceBase::ReadOnly);
    QXmlStreamReader the_xml(the_file.readAll());
    the_file.close();
    QString the_key,the_value;
    QXmlStreamReader::TokenType the_token=the_xml.readNext();
    if (the_token!=QXmlStreamReader::StartDocument)
    {
    the_error.show();
    return {};
    }
    the_token=the_xml.readNext();
    if (the_token!=QXmlStreamReader::StartElement||
        the_xml.name().toString()!="humans")
    {
    the_error.setWindowTitle("Помилка парсингу XML файлу");
    the_error.setText("Відкритий файл XML не має корінного тегу <humans>!");
    the_error.show();
    return {};
    }
    the_xml.readNext();
    the_token=the_xml.readNext();
    std::vector<QString> the_human;
    std::vector<std::vector<QString>> the_parsed_data;
    std::set<std::string> the_set;
    for (const auto &[the_key,the_value]:the_data)
        the_set.insert(the_key.first);
    auto the_predicate=[&](const std::vector<QString> &the_value)
    {
    int l=0;
    for (const auto &the_field:the_value)
    {
        if (the_data.count({the_keys[l].toStdString(),
                           the_field.toStdString()})==0&&the_set.count(
             the_keys[l].toStdString())==1) return true;
        ++l;
    }
    return false;
    };
    auto ReadNode=[&](std::vector<QString> &entered_vector)
    {
        for (auto &the_field:entered_vector)
        {
        the_key=the_xml.name().toString();
        if (the_token!=QXmlStreamReader::StartElement||
            the_key!=the_field)
        {
        the_error.setWindowTitle("Помилка парсингу XML файлу");
        the_error.setText("Відкритий файл XML не містить тегу <"+
                          the_field+">!");
        the_error.show();
        return false;
        }
        the_xml.readNext();
        the_value=the_xml.text().toString();
        the_token=the_xml.readNext();
        the_key=the_xml.name().toString();
        if (the_token!=QXmlStreamReader::EndElement||
            the_key!=the_field)
        {
        the_error.setWindowTitle("Помилка парсингу XML файлу");
        the_error.setText("Відкритий файл XML не містить тегу </"+
                          the_field+">!");
        the_error.show();
        return false;
        }
        the_field=the_value;
        the_xml.readNext();
        the_token=the_xml.readNext();
        }
        return true;
    };
    while (the_token!=QXmlStreamReader::EndElement&&
           the_key!="humans")
    {
    if (the_token!=QXmlStreamReader::StartElement||
        the_xml.name().toString()!="human")
    {
    the_error.setWindowTitle("Помилка парсингу XML файлу");
    the_error.setText("Відкритий файл XML не містить тегу <human>!");
    the_error.show();
    return {};
    }
    the_xml.readNext();
    the_token=the_xml.readNext();
    the_human=the_keys;
    if (!ReadNode(the_human)) return {};
    if (!the_predicate(the_human)) the_parsed_data.push_back(
                std::move(the_human));
    if (the_token!=QXmlStreamReader::EndElement||
        the_xml.name().toString()!="human")
    {
    the_error.setWindowTitle("Помилка парсингу XML файлу");
    the_error.setText("Відкритий файл XML не містить тегу </human>!");
    the_error.show();
    return {};
    }
    the_xml.readNext();
    the_token=the_xml.readNext();
    }
    return the_parsed_data;
}
std::vector<std::vector<QString>>
DOM_Filter::Filter(QFile &the_file,
std::map<std::pair<std::string,std::string>,bool>
&the_data,QMessageBox &the_error,
const std::vector<QString> &the_keys)
{
    the_file.open(QIODevice::ReadOnly);
    QDomDocument the_document;
    the_document.setContent(the_file.readAll());
    the_file.close();
    if (!the_document.isDocument())
    {
        the_error.setWindowTitle("Помилка парсингу XML файлу");
        the_error.setText("Відкритий файл XML не має корінного тегу <humans>");
        the_error.show();
        return {};
    }
    std::vector<QString> the_human=the_keys;
    std::vector<std::vector<QString>> the_parsed_data;
    std::set<std::string> the_set;
    for (const auto &[the_key,the_value]:the_data)
        the_set.insert(the_key.first);
    auto the_predicate=[&](const std::vector<QString> &the_value)
    {
    int l=0;
    for (const auto &the_field:the_value)
    {
        if (the_data.count({the_keys[l].toStdString(),
                           the_field.toStdString()})==0&&the_set.count(
             the_keys[l].toStdString())==1) return true;
        ++l;
    }
    return false;
    };
    QDomElement the_whole_document=the_document.documentElement();
    QDomNode the_move_node=the_whole_document.firstChild();
    while (!the_move_node.isNull())
    {
        for (int i=0; !the_move_node.toElement().isNull(); ++i)
        {
        the_human[i]=the_move_node.toElement().text();
        the_move_node=the_move_node.nextSibling();
        }
        if (std::tie(the_human)!=std::tie(the_keys)&&
                !the_predicate(the_human))
            the_parsed_data.push_back(std::move(the_human));
    }
    return the_parsed_data;
}
std::vector<std::vector<QString>>
Algorithms_Filter::Filter(QFile &the_file,
std::map<std::pair<std::string,std::string>,bool>
&the_data,QMessageBox &the_error,
const std::vector<QString> &the_keys)
{
    the_file.open(QIODeviceBase::ReadOnly);
    QXmlStreamReader the_xml(the_file.readAll());
    the_file.close();
    QString the_key,the_value;
    QXmlStreamReader::TokenType the_token=the_xml.readNext();
    if (the_token!=QXmlStreamReader::StartDocument)
    {
    the_error.show();
    return {};
    }
    the_token=the_xml.readNext();
    if (the_token!=QXmlStreamReader::StartElement||
        the_xml.name().toString()!="humans")
    {
    the_error.setWindowTitle("Помилка парсингу XML файлу");
    the_error.setText("Відкритий файл XML не має корінного тегу <humans>!");
    the_error.show();
    return {};
    }
    the_xml.readNext();
    the_token=the_xml.readNext();
    std::vector<QString> the_human;
    std::vector<std::vector<QString>> the_parsed_data;
    auto ReadNode=[&](std::vector<QString> &entered_vector)
    {
        for (auto &the_field:entered_vector)
        {
        the_key=the_xml.name().toString();
        if (the_token!=QXmlStreamReader::StartElement||
            the_key!=the_field)
        {
        the_error.setWindowTitle("Помилка парсингу XML файлу");
        the_error.setText("Відкритий файл XML не містить тегу <"+
                          the_field+">!");
        the_error.show();
        return false;
        }
        the_xml.readNext();
        the_value=the_xml.text().toString();
        the_token=the_xml.readNext();
        the_key=the_xml.name().toString();
        if (the_token!=QXmlStreamReader::EndElement||
            the_key!=the_field)
        {
        the_error.setWindowTitle("Помилка парсингу XML файлу");
        the_error.setText("Відкритий файл XML не містить тегу </"+
                          the_field+">!");
        the_error.show();
        return false;
        }
        the_field=the_value;
        the_xml.readNext();
        the_token=the_xml.readNext();
        }
        return true;
    };
    while (the_token!=QXmlStreamReader::EndElement&&
           the_key!="humans")
    {
    if (the_token!=QXmlStreamReader::StartElement||
        the_xml.name().toString()!="human")
    {
    the_error.setWindowTitle("Помилка парсингу XML файлу");
    the_error.setText("Відкритий файл XML не містить тегу <human>!");
    the_error.show();
    return {};
    }
    the_xml.readNext();
    the_token=the_xml.readNext();
    the_human=the_keys;
    if (!ReadNode(the_human)) return {};
    the_parsed_data.push_back(std::move(the_human));
    if (the_token!=QXmlStreamReader::EndElement||
        the_xml.name().toString()!="human")
    {
    the_error.setWindowTitle("Помилка парсингу XML файлу");
    the_error.setText("Відкритий файл XML не містить тегу </human>!");
    the_error.show();
    return {};
    }
    the_xml.readNext();
    the_token=the_xml.readNext();
    }
    if (the_data.empty()) return the_parsed_data;
    std::vector<std::vector<QString>> the_necessary_data;
    std::set<std::string> the_set;
    for (const auto &[the_key,the_value]:the_data)
        the_set.insert(the_key.first);
    the_necessary_data.reserve(the_parsed_data.size());
    for (size_t i=0; i<the_parsed_data.size(); ++i)
        for (size_t k=0; k<the_parsed_data[i].size(); ++k)
            if (the_data.count(make_pair(the_keys[k].toStdString(),
                        the_parsed_data[i][k].toStdString()))==1)
            {
                the_necessary_data.push_back(
                            std::move(the_parsed_data[i]));
                break;
            }
    auto the_predicate=[&](const std::vector<QString> &the_value)
    {
    int l=0;
    for (const auto &the_field:the_value)
    {
        if (the_data.count({the_keys[l].toStdString(),
                           the_field.toStdString()})==0&&the_set.count(
             the_keys[l].toStdString())==1) return true;
        ++l;
    }
    return false;
    };
    the_necessary_data.erase(std::remove_if(
    the_necessary_data.begin(),the_necessary_data.end(),
                                 the_predicate),
                             the_necessary_data.end());
    return the_necessary_data;
}
TestFilter::TestFilter(QObject* the_test_filter):
    QObject(the_test_filter)
{
the_test_file.setFileName("C:/Users/Lamaba/Desktop/Table.xml");
}
TestFilter::~TestFilter()
{
delete the_filter;
}
void TestFilter::TestSAXFilter()
{
the_filter->Initialize(new SAX_Filter());
QCOMPARE(the_filter->Process(the_test_file,the_test_choice,the_test_error,
                           the_keys),the_test_database);
}
void TestFilter::TestDOMFilter()
{
the_filter->Initialize(new DOM_Filter());
QCOMPARE(the_filter->Process(the_test_file,the_test_choice,the_test_error,
                           the_keys),the_test_database);
}
void TestFilter::TestAlgorithmsFilter()
{
the_filter->Initialize(new Algorithms_Filter());
QCOMPARE(the_filter->Process(the_test_file,the_test_choice,the_test_error,
                           the_keys),the_test_database);
}
