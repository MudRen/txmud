//road2.c 小路。
inherit ROOM;
void create()
{
        set("short","小路");
        set("long", @LONG
这里是头人府通向后院的小路。两旁种了一些树，再远处就
是高高的围墙，跟小花园的气氛天差地别。你暗暗地想：人要是
住在这种环境里，早就给憋死了。前方就是后院。
LONG
        );
        set("exits", ([
        "south":__DIR__"garden",
        "enter":__DIR__"backyard",
]));
        set("outdoors","linzhi");
        setup();
}
