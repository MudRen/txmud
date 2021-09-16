//temple3.c 德木寺后殿。
inherit ROOM;
void create()
{
        set("short", "后殿");
        set("long", @LONG
这里是德木寺的后殿，也是有道德的高僧修行的地方。靠
着两边的墙有两列面壁打坐的僧人，不过最中间的蒲团却空着
没有人坐。另外只有一个正在打扫的老喇嘛，不过他扫来扫去
也只是墙角的一块地方。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
        "south":__DIR__"temple2",
]));
        set("item_desc",([
        "蒲团":"苦海无量，唯德是馨；道德千寻，回头是春。\n",
]));
        set("objects",([
        __DIR__"npc/old_lama":1,
]));
        setup();
}
