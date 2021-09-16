// Room: /d/hangzhou/zfshiye.c

inherit ROOM;

void create()
{
	set("short", "师爷房");
	set("long", @LONG
这是本府刘师爷的房间，刘师爷本是苏州人氏，为人精细，
帮助高知府办了不少事情。刘师爷的房间陈设甚是简单，不过书
架上摆得满满的书籍甚是引人注目。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"zfpath5",
]));

	setup();
	replace_program(ROOM);
}
