// gouzijian  国子监

#include <room.h>

inherit ROOM;
void create()
{
        set("short", "国子监");
        set("long", @LONG
这里是国子监，长安城的百姓称这里为“太学”，这里平时
是朝中翰林们研究学问的地方，科举时这里则是考场，人们常说
这里可以是步入官场的天堂，也可以是让举子梦幻成为泡影的地
狱。这里墨香纸飞，有几个太学学生在朗朗的读着书。这里向南
出门是玄武大街。
LONG
        );
       set("exits", ([
                "south"            : __DIR__"nhroad1", ]) );
        setup();
}

