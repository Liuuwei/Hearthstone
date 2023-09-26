//
// Created by Liuwei on 2023/9/25.
//

#ifndef LUSHI_WINDOW_H
#define LUSHI_WINDOW_H

#include <vector>
#include <memory>
#include <ncurses.h>

#include "Util.h"

class Window {
public:
    Window() = default;
    Window(int line, int cols, int x, int y);
    Window(const std::shared_ptr<Window>& father, int line, int cols, int x, int y);
    ~Window();

    [[nodiscard]] int line() const { return line_; }
    [[nodiscard]] int cols() const { return cols_; }
    [[nodiscard]] int x() const { return x_; }
    [[nodiscard]] int y() const { return y_; }

    [[nodiscard]] WINDOW* get() const { return window_; }
    [[nodiscard]] std::unordered_map<Util::Location, std::shared_ptr<Window>>& sonMap() { return sonMap_; }
    [[nodiscard]] std::vector<std::shared_ptr<Window>>& sonVector() { return sonVector_; }
    void addSon(const std::shared_ptr<Window>& window);
    void addSon(Util::Location location, const std::shared_ptr<Window>& window);


    void addStr(int x, int y, const std::string& str);
    void box();
    void clear();
    void refresh();

private:
    int line_ = 0;
    int cols_ = 0;
    int x_ = 0;
    int y_ = 0;
    int pX_ = 1; // 打印的x坐标
    int pY_ = 1; // 打印的y坐标
    std::string str_; // 打印的内容
    bool box_ = false; // 打印框
    WINDOW* window_ = nullptr;
    std::weak_ptr<Window> father_;
    std::unordered_map<Util::Location, std::shared_ptr<Window>> sonMap_;
    std::vector<std::shared_ptr<Window>> sonVector_;
};


#endif //LUSHI_WINDOW_H
