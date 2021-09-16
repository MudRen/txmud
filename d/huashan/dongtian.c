// Room: /d/huashan/dongtian.c

inherit ROOM;

void create()
{
	set("short", "洞天");
	set("long", @LONG
只见一个宽阔的大厅，中央放着一个石桌，旁边还有两个石
凳，显然曾经有不只一人在这里呆过。在大厅的角落还放着两把
木剑，但由于长年未用，已经不能再使了。东西各有一个石屋，
里面不知道有些什么。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"shibi",
  "south" : __DIR__"shitai",
  "east" : __DIR__"shiwu",
]));

	setup();
	replace_program(ROOM);
}
