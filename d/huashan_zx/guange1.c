// Room: guange.c by pian
inherit ROOM;
void create()
{
	set("short","枫树林");
	set("long",@LONG
这里是一片望不到边的枫树林。时值仲秋，层林尽染，夕阳
晚风，牧歌低唱，怎么不教人留恋忘返。唏嘘之余，竟也有些许
寒意。远远望见东边有一个小小的草亭，有悠扬的古琴声随风轻
轻传来。
LONG
);
	set("exits", ([ /* sizeof() == 2 */
	"west" : __DIR__"gongmen",
	"east":__DIR__"guange2",
]));
	set("outdoors", "huashan_p");
	setup();
	replace_program(ROOM);
}