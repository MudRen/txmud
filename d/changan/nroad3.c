// /d/changan/nroad3  麒祥街

inherit ROOM;

void create()
{
        set("short", "麒祥街");
        set("long", @LONG
这里是长安城的北大街，由于靠近城门，来来往往的行人开
始多了起来，有时还能看见几趟镖车经过，一些巡捕在这里巡逻。
北面是长安武馆，富家子弟都来这里学一些武功强身健体，也不
乏一些武功好手学成于此出入江湖。
LONG
        );

	set("exits", ([
		"north"		  : __DIR__"wuguan",
                "west"            : __DIR__"nroad4",
                "east"            : __DIR__"nroad2", ]) );

	set("outdoors","changan");

	set("objects",([
	NPC_DIR"xunpu" : 2,
]));
        setup();
	replace_program(ROOM);
}
