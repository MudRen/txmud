inherit ROOM;

void create()
{
        set("short", "桃花源");
        set("long", @LONG
没想好 呵呵
LONG
);

        set("exits", ([
                "east"  : __DIR__"qianyuan",
                "west"  : __DIR__"houmen",
                "south"  : __DIR__"chufang",
]) );
        set("outdoors","jinghai");

        setup();
        replace_program(ROOM);
}

