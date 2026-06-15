#ifndef TEXTEDITOR_H
#define TEXTEDITOR_H

#include <string>
#include <list>
#include <vector>

class TextEditor {
private:
    std::list<std::string> document_lines_;
    std::list<std::string> undo_stack_;
    std::list<std::string> redo_stack_;

public:
    TextEditor() = default;

    void append(const std::string& line);
    void undo();
    void redo();
    std::vector<std::string> getDocument() const;
    void printDocument() const;
};

#endif // TEXTEDITOR_H
