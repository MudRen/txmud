// shroad2  南环路

inherit ROOM;

void create()
{
        set("short", "南环路");
        set("long", @LONG
这里是长安城的南环路，是长安四条主街道之一，从这里的
向北一过金水桥就是皇宫了，所有进皇宫的粮车、水车、进宫上
朝的官员、出京公干的钦差等等，都必路过这里，两边排满了锦
衣卫，偶尔也能看见一些太监进进出出。往南是南安大道直通长
安城的南门。
LONG
        );

	set("exits", ([
                "west"             : __DIR__"shroad1",
                "east"             : __DIR__"shroad3",
                "south"            : __DIR__"sroad9",
                "north"            : __DIR__"jingsq1",
]) );

	set("outdoors","changan");
        setup();
	replace_program(ROOM);
}
