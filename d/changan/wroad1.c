// wroad1  永泰路

inherit ROOM;
void create()
{
        set("short", "永泰路");
        set("long", @LONG
这里是长安城西大街北边，是长安城最繁华的地段之一，京
城著名商号总店都在附近，平日里白天熙熙攘攘、人流不断，晚
上也要灯火通明直至深夜不休。不时还有持刀的御林军、衙役在
这里来来回回的巡逻。从这里向北就是京城著名的麒祥街，东面
是被誉为“天下美食第一楼”的谪仙楼。
LONG
        );
       set("exits", ([
                "north"            : __DIR__"nroad8",
             "west"            : __DIR__"yiguan",
		"east"		   : __DIR__"jiulou",
                "south"            : __DIR__"wroad2", ]) );
       set("outdoors","changan");
        setup();

	replace_program(ROOM);
}