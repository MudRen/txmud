// wroad3  永泰路

inherit ROOM;

void create()
{
        set("short", "永泰路");
        set("long", @LONG
这里是长安城西大街北边，是长安城最繁华的地段之一，京
城著名商号总店都在附近，平日里白天熙熙攘攘、人流不断，晚
上也要灯火通明直至深夜不休。不时还有持刀的御林军、衙役在
这里来来回回的巡逻。宽阔的街道向南北两方向延伸，东面是京
城著名的书店“汇文阁”。
LONG
        );

	set("exits", ([
		"east"		   : __DIR__"bookroom",
		"north"            : __DIR__"wroad2",
		"south"            : __DIR__"wroad4",
]) );
	set("outdoors","changan");
	setup();
	replace_program(ROOM);
}