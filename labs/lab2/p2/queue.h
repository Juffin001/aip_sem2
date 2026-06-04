#ifndef QUEUE_H
#define QUEUE_H

#include <QString>
#include <QTextEdit>

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

template <typename T>
class Queue
{
private:
    struct Node {
        T data;
        Node *next;
        Node(T d) : data(d), next(nullptr) {}
    };
    Node *head, *tail;
    int len;
public:
    Queue() : head(nullptr), tail(nullptr), len(0) {};
    void add(T data);
    void delete_last();
    void sort();
    QString print_i(int i);
};

template <typename T>
void Queue<T>::add(T data) {
    Node *n = new Node(data);
    if (len == 0) {
        head = n;
        tail = n;
    }
    if (len > 0) {
        tail->next = n;
        tail = n;
    }
    len++;
}

template <typename T>
void Queue<T>::delete_last() {
    if (len <= 0) throw QueueEmptyException();
    if (len == 1) {
        tail = nullptr;
        delete head;
        head = nullptr;
        len--;
        return;
    }
    if (len==2) {
        delete tail;
        head->next = nullptr;
        tail = head;
        len--;
        return;
    }
    Node *ptr = head;
    for (int i = 0; i < len - 2; ++i) {
        ptr = ptr->next;
    }
    ptr->next = nullptr;
    delete tail;
    tail = ptr;
    len--;
}

template <typename T>
void Queue<T>::sort() {
    while (1) {
        bool end = 1;
        Node *ptr = head;
        for (int i = 0; i < len - 1; ++i) {
            if (ptr->data > ptr->next->data) {
                T _data = ptr->next->data;
                ptr->next->data = ptr->data;
                ptr->data = _data;
                end = 0;
            }
            ptr = ptr->next;
        }
        if (end) return;
    }
}

template <typename T>
QString Queue<T>::print_i(int i) {
    Node *ptr = head;
    for (int _i = 0; _i < i; ++_i) {
        ptr = ptr->next;
    }
    return QVariant(ptr->data).toString();
}

class contain_both_queues {
private:
    Queue<QString> q_str;
    Queue<int> q_int;
    std::vector<bool> bul; // 0 - QString 1 - int
    int len;
public:
    contain_both_queues() : q_str(), q_int(), bul(), len(0) {}
    void add(QString s);
    void delete_last();
    void sort();
    void print(QTextEdit* textEdit);
};

void contain_both_queues::add(QString s) {
    bool is_int;
    s.toInt(&is_int);
    if (is_int)
        q_int.add(s.toInt());
    else
        q_str.add(s);
    bul.push_back(is_int);
    len++;
}

void contain_both_queues::delete_last() {
    if (bul.back())
        q_int.delete_last();
    else
        q_str.delete_last();
    len--;
    bul.pop_back();
}

void contain_both_queues::sort() {
    q_str.sort();
}

void contain_both_queues::print(QTextEdit* textEdit) {
    int i_int = 0, i_str = 0;
    QString ans;
    for (int i = 0; i < len; ++i) {
        if (bul[i]) {
            ans += q_int.print_i(i_int);
            i_int++;
        }
        else {
            ans += q_str.print_i(i_str);
            i_str++;
        }
        ans += "\n";
    }
    textEdit->setText(ans);
}

#endif
