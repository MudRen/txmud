// Room: /wiz/louth/c/wwdao2.c

inherit ROOM;

void create()
{
	set("short", "武王道");
	set("long", @LONG
这是成都的武王道。由这里向西是川候武馆。向东就是和记
钱庄。南北方向可以贯通整个武王道。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"wuguan",
  "south" : __DIR__"wwdao3",
  "east" : __DIR__"qianzhuang",
  "north" : __DIR__"wwdao1",
]));

	set("outdoors","chengdu");

	setup();
	replace_program(ROOM);
}
