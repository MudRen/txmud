// Room: /u/w/wangs/b/kai71.c

inherit ROOM;

void create()
{
	set("short", "中心街");
	set("long", @LONG
中心街是开封府最繁华的地域，街的一侧连接着中心广场，
另一侧店铺林立，人涌入潮，若是到了晚间，这里更是流光异彩
亮如白昼，各种小吃、摊贩尽数汇聚于此，实为开封一大异景，
所以当地人又把这条中心街叫作“玉带围腰”。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"kai73",
  "north" : __DIR__"kai72",
  "west" : __DIR__"kai68",
  "east" : __DIR__"kai74",
]));

	set("outdoors","kaifeng");
	setup();
	replace_program(ROOM);
}
