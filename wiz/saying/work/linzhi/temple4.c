//temple4.c 错宗工巴寺侧殿。
inherit ROOM;
void create()
{
        set("short", "侧殿");
        set("long", @LONG
这里是错宗工巴寺的侧殿，是济嘎活佛的师弟巴彦喇嘛修行
的地方。侧殿里香烟缭绕，正面佛龛上供着过去现在未来三尊佛
像，一个喇嘛面对房门，正在蒲团上打坐，感觉到有人进来，张
开眼冲你微笑了一下，又入定了。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
        "north" : __DIR__"temple1",
]));
        set("objects",([
        __DIR__"npc/lama2" : 1,
]));
        setup();
}
