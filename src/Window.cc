//
// Created by Liuwei on 2023/9/25.
//

#include "Window.h"

Window::Window(int line, int cols, int x, int y) : line_(line), cols_(cols), x_(x), y_(y) {
    initscr();
    keypad(stdscr, TRUE);
    noecho();

    window_ = newwin(line, cols, x, y);
}

Window::Window(const std::shared_ptr<Window>& father, int line, int cols, int x, int y) : father_(father), line_(line), cols_(cols), x_(x), y_(y) {
    initscr();
    keypad(stdscr, TRUE);
    noecho();

    window_ = subwin(father->get(), line_, cols_, father->x() + x_, father->y() + y_);
}

Window::~Window() {
    endwin();
}

void Window::addStr(int x, int y, const std::string& str) {
    pX_ = x;
    pY_ = y;
    str_ = str;
}

void Window::box() {
    box_ = true;
}

void Window::clear() {
    pX_ = 1;
    pY_ = 1;
    str_.clear();
    ::werase(window_);
    ::wrefresh(window_);
}

void Window::refresh() {
    werase(window_);
    if (box_) {
        ::box(window_, ACS_VLINE, ACS_HLINE);
    }
    if (!str_.empty()) {
        mvwaddstr(window_, pX_, pX_, str_.c_str());
    }
    ::wrefresh(window_);

    for (auto& it : sonVector_) {
        it->refresh();
    }

    for (auto& it : sonMap_) {
        it.second->refresh();
    }
}

void Window::addSon(const std::shared_ptr<Window>& window) {
    sonVector_.push_back(window);
}

void Window::addSon(Util::Location location, const std::shared_ptr<Window>& window) {
    sonMap_.insert(std::make_pair(location, window));
}