// kongdi.c 小空地 

inherit ROOM;
void create()
{
        set("short", "小空地");
        set("long", @LONG
你的眼前出现一片小空地，空地上有几只小鸡在琢米，空地
的后面有一个小屋，门上贴着退了色的福字，门口的左边有柴堆
和水缸。
LONG
        );
       set("exits", ([
                "west"              : __DIR__"shulin2",
                "east"              : __DIR__"xiaowu",
                     ]) );
       set("outdoors","wenchuan");
       setup();
       replace_program(ROOM);
}
