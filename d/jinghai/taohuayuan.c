inherit ROOM;

void create()
{
        set("short", "�һ�Դ");
        set("long", @LONG
û��� �Ǻ�
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

