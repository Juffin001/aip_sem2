#include "queue.h"
#include <QTextEdit>
#include <vector>
#include <algorithm>

Str::Str(QString v) :  val(v) {}

QString Str::print() {
    return val + "\n";
}

void Str::set_val(QString V) {
    val = V.trimmed();
}


Num::Num(QString v) :  val(v.toInt()) {}

QString Num::print() {
    return QString::number(val) + "\n";
}

void Num::set_val(QString V) {
    val = V.trimmed().toInt();
}

Queue::Queue() : len(0), root(nullptr), last(nullptr) {}

void Queue::print(QTextEdit* textEdit) {
    QString ans = "Количество элементов: " + QString::number(len) + "\n";
    if (!root) {
        textEdit->setText(ans);;
        return;
    }
    El *now;
    now = root;
    for (int i = 0; i < len; ++i) {
        ans += now->print();
        now = now->next;
    }
    textEdit->setText(ans);
}


void Queue::add(El *v) {
    if (len == 0) {
        root = v;
        last = v;
        root->next = nullptr;
        last->next = nullptr;
        len++;
    }
    else {
        El *ptr = root;
        root = v;
        root->next = ptr;
        len++;
    }
}

void Queue::delete_last() {
    if (len == 0) throw QueueEmptyException();
    El *ptr = root;
    for (int i = 0; i < len - 2; ++i) {
        ptr = ptr->next;
    }
    ptr->next = nullptr;
    delete last;
    last = ptr;
    len--;
}

Sort_Queue::Sort_Queue() : Queue() {}
void Sort_Queue::sort_queue() {
    if (len == 0) throw NoWordsException();
    std::vector<QString> vec;
    El *ptr = root;
    for (int i = 0; i < len; ++i) {
        vec.push_back(ptr->print());
        ptr = ptr->next;
    }
    std::sort(vec.begin(), vec.end());
    ptr = root;
    for (int i = 0; i < len; ++i) {
        ptr->set_val(vec[i]);
        ptr = ptr->next;
    }
}
