//miss_room.c 小姐居室
inherit ROOM;
void create()
{
        set("short","小姐居室");
        set("long", @LONG
这里是头人女儿的居室。虽然收拾的干干净净，但是可以看
出，这里已经好久没有住人了。看着这绮丽的房间，你有点奇怪
房间的主人到哪里去了。
LONG
        );
        set("exits", ([
        "south":__DIR__"backyard2",
]));
        setup();
}
