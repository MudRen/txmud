// Room: /d/hangzhou/linneiyuan.c

inherit ROOM;

void create()
{
	set("short", "内院");
	set("long", @LONG
这里是林府的内院，东面有一间大房子，好像是林家的客厅
，门口有两棵三人合抱的梧桐树，向两个卫士一样矗立在那里，
南面则是一排平房，供家丁们居住。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"linguard",
  "west" : __DIR__"linyuanzi",
  "east" : __DIR__"linketing",
  "north" : __DIR__"linpath1",
]));
	set("outdoors", "hangzhou");

	setup();
	replace_program(ROOM);
}
