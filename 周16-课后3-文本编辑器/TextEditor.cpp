#include "TextEditor.h"
#include<iostream>

using namespace std;

void TextEditor::append(const std::string& line) {
    document_lines_.push_back(line);
    redo_stack_.clear();
}

void TextEditor::undo() {
    if(document_lines_.empty()) return;

    undo_stack_.push_back(document_lines_.back());
    document_lines_.pop_back();
}

void TextEditor::redo() {
    if(undo_stack_.empty()) return;

    document_lines_.push_back(undo_stack_.back());
    undo_stack_.pop_back();
    redo_stack_.push_back(document_lines_.back());

}

std::vector<std::string> TextEditor::getDocument() const {
    vector<string> ans;
    for(auto it = document_lines_.begin(); it != document_lines_.end(); ++it) {
        ans.push_back(*it);
    }
    return ans;
}

void TextEditor::printDocument() const {
    std::vector<std::string> doc = getDocument();
    if(doc.empty()) cout << "(empty)" << endl;
    for(const auto& line : doc) {
        std::cout << line << std::endl;
    }
}
