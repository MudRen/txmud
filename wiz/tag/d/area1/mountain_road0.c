///////////////////////////////////////////////////
//新的区域area1
//mountain_road0.c

inherit ROOM;

void create()
{
        set("short", "半山腰");
        set("long", @LONG
你努力地往山顶爬去，极其险峻的山势使你不敢有任
何轻举妄动，每一个动作都要敏捷、准确和有力。
LONG
        );
        set("outdoors", "area1");
        set(SAFE_ENV, 1);
        set("no_sleep_room",1);
        
        setup();
        replace_program(ROOM);
}
///////////////////////////////////////////////////
