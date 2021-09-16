// Room: /d/hangzhou/zfchaifang.c

inherit ROOM;

void create()
{
	set("short", "柴房");
	set("long", @LONG
这里是一间柴房，墙角堆着成山的柴草，旁边树着一些农具
，西墙的小窗下有一个茅草铺成的地铺，旁边摆了一个粗磁大碗
，看来是长工用的。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"zfpath4",
]));

	setup();
	replace_program(ROOM);
}
