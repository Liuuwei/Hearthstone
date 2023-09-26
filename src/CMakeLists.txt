add_library(lushi
        Card/Ghoul.cc
        BattleGround.cc
        Card.cc
        Player.cc
        Util.cc
        Window.cc
        CardCreator.cc
        ../include/CardCreator.h
        CardCreator.cc
        CardWindow.cc
        ../include/CardWindow.h
        ../include/CardWindow.h
)

target_link_libraries(lushi ncurses)