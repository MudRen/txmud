// Room: chengxf1.c

inherit ROOM;

void create()
{
	set("short", "前院");
	set("long", @LONG
这里是长安丞相府的前院，四下种着不少的垂柳，一个小水
池里正潺潺的流着水，有几个家院在这里扫着地，从这里向南就
出了大门了，向西是通着军议厅的走廊，向东有一条曲径，向北
走就是大厅了。
LONG
	);

        set("exits", ([
  "south" : __DIR__"chengxf",
  "north" : __DIR__"chengxf6",
  "east" : __DIR__"chengxf2",
  "west" : __DIR__"chengxf4",
]));
        set("outdoors","chengxf");
	set("cannot_build_home",1);
	set("NORIDE","家丁拦住你说道：当朝丞相府第文官下轿，武官下马。\n");

        setup();

	replace_program(ROOM);
}