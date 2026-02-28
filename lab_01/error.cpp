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
    case ERR_NO_POINTS:
        QMessageBox::critical(NULL, "Ошибка", "Модель не загружена!");
        break;
    case ERR_NO_EDGES:
        QMessageBox::critical(NULL, "Ошибка", "Модель не загружена!");
        break;
    case ERR_NO_SCENE:
        QMessageBox::critical(NULL, "Ошибка", "Сцена не загружена!");
        break;
    case ERR_RANGE_N_POINTS:
        QMessageBox::critical(NULL, "Ошибка", "Количество точек должно быть больше нуля!");
        break;
    case ERR_RANGE_N_EDGES:
        QMessageBox::critical(NULL, "Ошибка", "Количество рёбер должно быть больше нуля!");
        break;
    default:
        QMessageBox::critical(NULL, "Ошибка", "Неизвестная ошибка!");
        break;
    }
}
