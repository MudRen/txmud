// /d/yuehou/center_e.c

inherit ROOM;

void create()
{
        set("short", "广场东侧");
        set("long", @LONG
这里是岳候镇的广场的东侧，这里有不少住家，南面是一家
客栈。
LONG
        );

       set("exits", ([
                "south"             : __DIR__"kezhan",
                "west"             : __DIR__"tcenter",
]) );

       set("outdoors","yuehou");

       setup();
       replace_program(ROOM);
}

