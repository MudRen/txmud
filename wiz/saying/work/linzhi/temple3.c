//temple3.c 错宗工巴寺侧殿。
inherit ROOM;
void create()
{
        set("short", "侧殿");
        set("long", @LONG
这里是错宗工巴寺的侧殿，是济嘎活佛的师弟门巴喇嘛修行
的地方。侧殿里十分冷清，只有一团火在正面墙壁上燃烧，一个
喇嘛背对着你坐着，对你的到来一点反应也没有。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
        "south" : __DIR__"temple1",
]));
        set("objects",([
        __DIR__"npc/lama1" : 1,
]));
        setup();
}
