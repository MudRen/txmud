// /d/changan/eroad7  连德街

inherit ROOM;

void create()
{
        set("short", "连德街");
        set("long", @LONG
这是长安城的东大街，由于靠近长安城的东北角，想必是生
意也不不大好做，所以在这里做生意的人很少，来往的人也就更
少了，到是东面的一家小酒馆不时传出阵阵喧哗笑骂声，那里是
平民百姓们的聚集地，要打探什么消息到是个好地方。
LONG
        );
       set("exits", ([
		"east"		  : __DIR__"jiuguan",
                "north"           : __DIR__"eroad8",
                "south"           : __DIR__"eroad6",
]) );
        set("outdoors","changan");

	set("objects",([
	NPC_DIR"xunpu" : 1,
]));
        setup();
	replace_program(ROOM);
}
