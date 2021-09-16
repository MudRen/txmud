// dt_fenduo.c

inherit ROOM;

void create()
{
        set("short", "大厅");
        set("long", @LONG
大厅里空空荡荡的，只有几捆干草散落在地上，发出一股霉
味。整个屋子的墙壁上都蒙着一层灰，通往里屋的的木门也腐烂
得不成样子，似乎稍微碰一下都会断裂。
LONG
);

        set("no_clean_up", 0);
        set("no_sleep_room", 0);
        set("exits", ([
                "north" : __DIR__"dt_fenduo_2",
                "west" : __DIR__"dt_fenduo_1",
                "south" : "/d/datong/pojiudayuan",
                "east" : __DIR__"dt_fenduo_3",
        ]));

        set("objects",([
        ]));

        setup();
        replace_program(ROOM);
}
