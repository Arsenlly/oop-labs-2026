#include <QMessageBox>

#include "error.h"

void error_message(err_t rc)
{
    switch (rc) {
    case ERR_UNKNOWN_TYPE_REQ:
        QMessageBox::critical(NULL, "Ошибка", "Неизвестная команда!");
        break;
    case ERR_FILEOPEN:
        QMessageBox::critical(NULL, "Ошибка", "Ошибка при открытии файла!");
        break;
    case ERR_READ_FILE:
        QMessageBox::critical(NULL, "Ошибка", "Ошибка при чтении файла!");
        break;
    case ERR_MEMORY:
        QMessageBox::critical(NULL, "Ошибка", "Ошибка выделения памяти!");
        break;
    case ERR_NO_DATA:
        QMessageBox::critical(NULL, "Ошибка", "Модель не загружена!");
        break;
    default:
        QMessageBox::critical(NULL, "Ошибка", "Неизвестная ошибка!");
        break;
    }
}
