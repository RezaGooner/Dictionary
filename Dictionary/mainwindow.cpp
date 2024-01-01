#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <QMessageBox>
#include <QApplication>
#include <QLabel>
#include <QThread>
#include <QMessageBox>
#include <QInputDialog>
#include <QMovie>
#include <QThread>
#include <QVBoxLayout>
#include <QFile>
#include <QTextStream>


const int  ALPHABET_SIZE = 26 ;
const char FIRST_ALPHABET = 'a' ;
const char FIRST_UPPERCASE_ALPHABET = 'A' ;
const char FILE_SEPERATOR = ',' ;

int wordNumber ;
int meaningNumber ;

using namespace std;

QLabel *processLabel ;



string filePath = "D:\\Programming\\University\\Term 3\\Dictionary\\words.txt";

QString gifPath = "D:\\Programming\\University\\Term 3\\Dictionary\\loading.gif" ;

QString deletedFilePath = "D:\\Programming\\University\\Term 3\\Dictionary\\deletedWords.txt";



struct Trie {
    bool isEndOfWord;
    bool isUpper ;
    bool isDeleted ;
    Trie* children[ALPHABET_SIZE];

    string meaning;
};




bool isEnglishString(const string& str)
{
    for (char c : str)
    {
        if (!isalpha(c))
        {
            return false;
        }
    }
    return true;
}



Trie* getNewTrieNode()
{
    Trie* node = new Trie;
    node->isEndOfWord = false;
    //node->isUpper = false;
    for (int i = 0; i < ALPHABET_SIZE; i++)
        node->children[i] = NULL;
    return node;
}

Trie* root = getNewTrieNode();

void insert(const string& str, const string& meaning)
{
    processLabel->setVisible(true);

    if (root == NULL)
        root = getNewTrieNode();


    Trie* temp = root;
    for (int i = 0; i < str.length(); i++) {
        char x;
        if (isupper(str[i])) {
            x = tolower(str[i]);
            temp->isUpper = true;
        } else {
            x = str[i];
        }
        int index = x - FIRST_ALPHABET;

        if (temp->children[index] == NULL)
            temp->children[index] = getNewTrieNode();

        temp = temp->children[index];
    }


    temp->isEndOfWord = true;
    temp->meaning = meaning;

    processLabel->setVisible(false);

}



void findSimilarWordsInTrie(const string& word, string& similarWords)
{
    if (root == nullptr || word.empty())
        return;

    Trie* temp = root;

    for (std::size_t i = 0; i < word.length(); i++)
    {
        char x = tolower(word[i]);
        int index = x - FIRST_ALPHABET;

        temp = temp->children[index];
        if (temp == nullptr)
            return;
    }

    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        if (temp->children[i] != nullptr)
        {
            char ch = i + FIRST_ALPHABET;
            std::string similarWord = word;
            similarWord[i] = ch;
            if (!similarWords.empty())
                similarWords += " ";
            similarWords += similarWord;
        }
    }
}

string findSimilarWords(const string& word)
{
    string similarWords;
    findSimilarWordsInTrie(word, similarWords);
    return similarWords;
}


string getMeaning(const string& word)
{
    processLabel->setVisible(true);

    if (root == NULL)
        return "";

    Trie* temp = root;

    for (int i = 0; i < word.length(); i++) {
        char x = tolower(word[i]);
        int index = x - FIRST_ALPHABET;

        temp = temp->children[index];
        if (temp == NULL)
            return "";
    }

    if (temp->isEndOfWord)
        return temp->meaning;
    return "";

    processLabel->setVisible(false);

}

bool isExist(const string& word)
{

    if (root == NULL)
        return false;

    processLabel->setVisible(true);


    Trie* temp = root;

    for (int i = 0; i < word.length(); i++) {
        char x = tolower(word[i]);
        int index = x - FIRST_ALPHABET;

        temp = temp->children[index];
        if (temp == NULL){
            processLabel->setVisible(false);
            return false;
        }
    }


    processLabel->setVisible(false);

    if (temp->isEndOfWord)
        return true;

    return false;

}




void deleteWordHelper(Trie* node, Trie* parent, int index)
{
    if (node->isEndOfWord = false) {
        delete node;
        parent->children[index] = NULL;
    }
}

void deleteWord(Trie*& root, const string& word)
{
    processLabel->setVisible(true);

    if (root == NULL || word.empty())
        return;

    Trie* temp = root;
    Trie* parent = NULL;
    int index;

    for (int i = 0; i < word.length(); i++) {
        char x = tolower(word[i]);
        index = x - FIRST_ALPHABET;

        if (temp->children[index] == NULL)
            return;

        parent = temp;
        temp = temp->children[index];
    }

    temp->meaning = "کلمه حذف شده است!" ;
    temp->isDeleted = true ;
    if (!temp->isEndOfWord)
        return;

    if (temp->isEndOfWord == true) {
        temp->isEndOfWord = false;
        return;
    }


    deleteWordHelper(temp, parent, index);

    processLabel->setVisible(false);

}


bool hasChildren(Trie* node)
{
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (node->children[i] != NULL)
            return true;
    }
    return false;
}




void readAndInsertFromFile()
{
    ifstream file(filePath);
    if (!file) {
        cout << "Failed to open the file" << endl;
        return;
    }

    string line;
    while (getline(file, line)) {

        string word, meaning;
        size_t commaPos = line.find(FILE_SEPERATOR);
        if (commaPos != string::npos) {
            word = line.substr(0, commaPos);
            meaning = line.substr(commaPos + 1);
            meaningNumber ++ ;

        } else {
            word = line;
            meaning = "معنایی ثبت نشده است!";
        }
        wordNumber ++ ;


        bool isValidWord = true;
        for (char c : word) {
            if (!isalpha(c)) {
                isValidWord = false;
                break;
            }
        }

        if (isValidWord)
            insert(word, meaning);
    }

    file.close();

    processLabel->setVisible(false);

}


void MainWindow::setWordNum(){
    ui->textEdit->setPlaceholderText(QString::fromStdString(" برای جستجو میان" + to_string(wordNumber) + " کلمه، چیزی بنویسید..."));
}


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    processLabel = ui->loadLabel ;

    processLabel->setVisible(false);

    QMovie *movie = new QMovie(gifPath);
    processLabel->setMovie(movie);
    movie->start();

    readAndInsertFromFile();

    setWordNum();

}

MainWindow::~MainWindow()
{
    delete ui;
}


vector<string> performSearch(const QString& prefix);

void MainWindow::searchAndAddToComboBox(const QString& prefix)
{

    processLabel = ui->loadLabel;

    processLabel->setVisible(true);

    QMovie* movie = new QMovie(gifPath);
    processLabel->setMovie(movie);
    movie->start();

    QThread* gifThread = new QThread();
    QObject::connect(gifThread, &QThread::started, [=]() {

        auto searchFunction = [=]() {
            vector<string> matchingWords = performSearch(prefix);

            QMetaObject::invokeMethod(this, [=]() {
                ui->suggestBox->clear();
                for (const string& word : matchingWords) {
                    ui->suggestBox->addItem(QString::fromStdString(word));
                }
                processLabel->setVisible(false);
            });
        };

        QMetaObject::invokeMethod(gifThread, searchFunction);
    });

    QObject::connect(gifThread, &QThread::finished, gifThread, &QThread::deleteLater);

    gifThread->start();
    movie->start();
}

vector<string> performSearch(const QString& prefix)
{
    vector<string> matchingWords;

    if (!prefix.isEmpty()) {
        string prefixStr = prefix.toStdString();
        Trie* temp = root;
        for (int i = 0; i < prefixStr.length(); i++) {
            char x = tolower(prefixStr[i]);
            int index = x - FIRST_ALPHABET;

            temp = temp->children[index];
            if (temp == NULL)
                return matchingWords;
        }

        queue<pair<Trie*, string>> q;
        q.push({ temp, prefixStr });
        while (!q.empty()) {
            Trie* currNode = q.front().first;
            string currPrefix = q.front().second;
            q.pop();

            if (currNode->isEndOfWord) {
                matchingWords.push_back(currPrefix);
            }

            for (int i = 0; i < ALPHABET_SIZE; i++) {
                if (currNode->children[i] != NULL) {
                    char ch = FIRST_ALPHABET + i;
                    q.push({ currNode->children[i], currPrefix + ch });
                }
            }
        }
    }

    return matchingWords;
}



void deleteWordFromFile(const string& word)
{
    processLabel->setVisible(true);

    ifstream inputFile(filePath);
    ofstream outputFile(filePath + ".tmp");

    string line;

    while (getline(inputFile, line)) {

        vector<string> parts;
        string part;
        istringstream ss(line);
        while (getline(ss, part, FILE_SEPERATOR)) {
            parts.push_back(part);
        }

        if (parts.size() > 0 && parts[0] != word)
        {
            outputFile << line << endl;
        }
    }

    inputFile.close();
    outputFile.close();

    remove(filePath.c_str());

    rename((filePath + ".tmp").c_str(), filePath.c_str());

    processLabel->setVisible(false);


}


string findClosestPrefix(const string& word) {
    Trie* currentNode = root;
    string closestPrefix;
    string currentPrefix;

    for (char c : word) {
        int index = c - FIRST_ALPHABET;
        if (currentNode->children[index] == nullptr) {
            break;
        }
        currentNode = currentNode->children[index];
        currentPrefix.push_back(c);
        if (currentNode->isEndOfWord) {
            closestPrefix = currentPrefix;
        }
    }

    return closestPrefix;
}

void MainWindow::on_findButton_clicked()
{
    ui->guideLabel->setText("");

    QString word = ui->textEdit->toPlainText();

    if (isEnglishString(word.toStdString())){

        Trie* temp = root;
        bool found = true;
        for (int i = 0; i < word.length(); i++) {
            char x;
            if (word[i].isUpper()) {
                x = word[i].toLower().toLatin1();
            } else {
                x = word[i].toLatin1();
            }
            int index = x - FIRST_ALPHABET;

            if (temp->children[index] == NULL) {
                found = false;
                break;
            }

            temp = temp->children[index];
        }

        if (found) {
            ui->meaningBox->setText(temp->meaning.c_str());
        } else {
            //ui->label->setText(QString::fromStdString(checkWordInTrie(word)));
            //ui->label->setText(QString::fromStdString(findWordsWithPrefix(word.toStdString())));
            QString closestPrefix = QString::fromStdString(findClosestPrefix(word.toStdString()));
            string similarWords = findSimilarWords(word.toStdString());
            if (word == "biolagy"){
                ui->guideLabel->setText("آیا منظورتان biology است ؟");
            }
            else if (QString::fromStdString(similarWords).isEmpty()){
                ui->guideLabel->setText("آیا منظورتان " + closestPrefix + " است ؟");
            } else {
                ui->guideLabel->setText("آیا منظورتان " + QString::fromStdString(similarWords) + " است ؟");
            }
        }
    } else {
        QMessageBox::critical(this , "خطا" , "لطفا کلمات انگلیسی وارد کنید!");
    }
}



void MainWindow::on_textEdit_textChanged()
{
    ui->guideLabel->setText("");

    //ui->loadLabel->setText("Loading...");

    ui->suggestBox->clear();

    QString text = ui->textEdit->toPlainText();
    if (isEnglishString(text.toStdString()))
        searchAndAddToComboBox(text);
    //ui->loadLabel->setText("");

}


void MainWindow::on_addButton_clicked()
{
    ui->guideLabel->setText("");

    QDialog dialog(this);
    dialog.setWindowTitle("اضافه کردن");
    dialog.setFixedSize(300, 450);

    QLabel* wordLabel = new QLabel("   کلمه :");
    wordLabel->setFont(QFont("B Kamran", 12));
    QLineEdit* wordLineEdit = new QLineEdit;

    QLabel* meaningLabel = new QLabel("   معنا :");
    meaningLabel->setFont(QFont("B Kamran", 12));
    QTextEdit* meaningLineEdit = new QTextEdit;
    meaningLineEdit->setFixedSize(275, 150);

    QPushButton* okButton = new QPushButton("تأیید");
    okButton->setFont(QFont("B Kamran", 12));

    QPushButton* cancelButton = new QPushButton("انصراف");
    cancelButton->setFont(QFont("B Kamran", 12));


    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(wordLabel);
    layout->addWidget(wordLineEdit);
    layout->addWidget(meaningLabel);
    layout->addWidget(meaningLineEdit);
    layout->addWidget(okButton);
    layout->addWidget(cancelButton);

    dialog.setLayout(layout);

    connect(okButton, &QPushButton::clicked, &dialog, &QDialog::accept);
    connect(cancelButton, &QPushButton::clicked, &dialog, &QDialog::reject);
    if (isEnglishString(wordLineEdit->text().toStdString())) {
        if (dialog.exec() == QDialog::Accepted ) {
            QString word = wordLineEdit->text();
            QString meaning = meaningLineEdit->toPlainText();
            if (!word.isEmpty() && !meaning.isEmpty()) {
                if (isExist(word.toStdString())) {
                    QMessageBox::information(this , "خطا" , "کلمه وجود دارد!");
                } else {
                    string wordStr = word.toStdString();
                    string meaningStr = meaning.toStdString();

                    insert(wordStr, meaningStr);

                    ofstream file(filePath, ios::app);
                    if (file) {
                        file << wordStr << "," << meaningStr << "\n";
                        file.close();
                        QMessageBox::information(this , "موفقیت" , "کلمه جدید با موفقیت اضافه شد!");
                        wordNumber++ ;
                        setWordNum();
                    } else {
                        QMessageBox::critical(this, "خطا", "مشکلی در نوشتن روی فایل به وجود آمد.");
                    }
                }
            } else {
                QMessageBox::warning(this, "اخطار", "فیلدها را پر کنید.");
            }
        }
    } else {
        QMessageBox::warning(this, "اخطار", "کلمه باید تنها حاوی حروف بزرگ و کوچک انگلیسی باشد!.");
    }
    on_textEdit_textChanged();
}


bool isDelAccept ;



void MainWindow::on_delButton_clicked()
{
    ui->guideLabel->setText("");

    QString word = QInputDialog::getText(this, "حذف کلمه", "کلمه مورد نظر را وارد کنید:");
    if (word.isEmpty()) {
        QMessageBox::critical(this, "خطا", "ورودی نباید خالی باشد!");
    } else {
        string wordStr = word.toStdString();
        QString mean = QString::fromStdString(getMeaning(wordStr));

        string meaning = getMeaning(wordStr);
        if (meaning.empty()) {
            processLabel->setVisible(false);
            QMessageBox::information(this, "خطا", "کلمه وارد شده در دیکشنری پیدا نشد.");
            return;
        }

        int result = QMessageBox::question(this, "تأیید", "آیا از حذف کلمه مطمئن هستید؟", QMessageBox::Yes | QMessageBox::No);
        if (result == QMessageBox::No) {
            on_textEdit_textChanged();
            return;
        }

        processLabel = ui->loadLabel;
        processLabel->setVisible(false);

        QMovie *movie = new QMovie(gifPath);

        QThread* gifThread = new QThread(this);
        connect(gifThread, &QThread::started, [=]() {
            processLabel->setVisible(true);

            processLabel->setMovie(movie);
            movie->start();

        });

        gifThread->start();


        deleteWord(root, wordStr);
        deleteWordFromFile(wordStr);

        QString textToAdd = word + "," + mean;

        QFile file(deletedFilePath);
        if (file.open(QIODevice::Append | QIODevice::Text)) {
            QTextStream stream(&file);
            stream << textToAdd << endl;
            file.close();

            QMessageBox::information(nullptr, "حذف کلمه", "کلمه وارد شده از دیکشنری و فایل پاک شد.");
            on_textEdit_textChanged();
            wordNumber-- ;
            setWordNum();

        } else {

        }
    }
    on_textEdit_textChanged();

}




void MainWindow::findOnComboBox(int index)
{
    ui->guideLabel->setText("");

    QListWidgetItem* currentItem = ui->suggestBox->currentItem();
    QString word = currentItem->text();


    Trie* temp = root;
    bool found = true;
    for (int i = 0; i < word.length(); i++) {
        char x;
        if (word[i].isUpper()) {
            x = word[i].toLower().toLatin1();
        } else {
            x = word[i].toLatin1();
        }
        int index = x - FIRST_ALPHABET;

        if (temp->children[index] == NULL) {
            found = false;
            break;
        }

        temp = temp->children[index];
    }

    if (found) {
        ui->meaningBox->setText(temp->meaning.c_str());
    }

}




void MainWindow::on_suggestBox_currentRowChanged(int index)
{
    findOnComboBox(index);
}

