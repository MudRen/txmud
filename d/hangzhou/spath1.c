// Room: /d/hangzhou/spath1.c

inherit ROOM;

void create()
{
	set("short", "黄土大道");
	set("long", @LONG
一条黄土大道向南延伸而去。北面就是杭州城的南门。路上
来往的行人和商旅和你擦肩而过。过往的车辆不时地扬起尘土，
你不得不向旁边闪躲。路的两边是丛丛的树林，林间小路隐现其
间。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"stree1",
  "south" : __DIR__"spath2",
  "east" : __DIR__"stree3",
  "north" : __DIR__"out_hangzhou_s",
]));
	set("outdoors", "hangzhou");

	setup();
	replace_program(ROOM);
}
