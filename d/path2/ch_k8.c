// Room: /d/path2/ch_k8.c

inherit ROOM;

void create()
{
	set("short", "黄土路");
	set("long", @LONG
这是一条黄土大路，路的两边不远就是闻名的太行山脉了。
放眼望去，一片片绿树荫荫，你不由得加快了脚步。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"ch_k7",
  "south" : __DIR__"ch_k9",
]));
	set("no_clean_up", 0);
	set("outdoors", "path2");
	setup();
	replace_program(ROOM);
}
