#ifndef QUEUE_H
#define QUEUE_H

#include <QString>
#include <QTextEdit>

class El {
public:
    El *next;
    virtual QString print()=0;
    virtual ~El() = default;
    virtual void set_val(QString V)=0;
    El(): next(nullptr) {}
};

class Str : public El {
private:
    QString val;
public:
    Str(QString v);
    Str();
    virtual QString print() override; //get_val
    virtual void set_val(QString V) override;
    ~Str() override = default;
};

class Num : public El {
private:
    int val;
public:
    Num(QString v);
    Num();
    virtual QString print() override; //get_val
    virtual void set_val(QString V) override;
    ~Num() override = default;
};

class Queue
{
public:
    El *root, *last;
    int len;
    Queue();
    void add(El *v);
    void delete_last();
    void print(QTextEdit* textEdit);
};

class Sort_Queue : public Queue {
public:
    Sort_Queue();
    void sort_queue();
};

class QueueEmptyException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Очередь пуста. Невозможно удалить элемент.";
    }
};

class NoWordsException : public std::exception {
public:
    const char* what() const noexcept override {
        return "В очереди нет слов для сортировки.";
    }
};

#endif
