// Начнем с директив препроцессора. ADD_H – это произвольное уникальное имя (обычно используется имя заголовочного файла)
#ifndef SOURCE_H
#define SOURCE_H

void console_set_text_color(int text_color, int background_color);

void console_gotoxy(int column, int line);

void console_hide_cursor();

WORD console_get_vk();

// Заканчиваем директивой препроцессора
#endif
