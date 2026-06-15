#include "TextEditor.h"
#include<iostream>

int main() {
    TextEditor editor;
    std::string a,b,c;
    std::getline(std::cin, a);
    std::getline(std::cin, b);
    std::getline(std::cin, c);
    editor.append(a);
    editor.append(b);
    editor.printDocument();

    editor.undo();
    editor.printDocument();

    editor.undo();
    editor.printDocument();

    editor.undo();
    editor.printDocument();

    editor.redo();
    editor.printDocument();

    editor.redo();
    editor.printDocument();

    editor.redo();
    editor.printDocument();

    editor.append(c);
    editor.printDocument();

    editor.redo();
    editor.printDocument();

    editor.undo();
    editor.printDocument();
    return 0;
}
