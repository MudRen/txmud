// Room: /wiz/louth/a/road5.c

inherit ROOM;

void create()
{
	set("short", "碎石路");
	set("long", @LONG
这是从梅花园出来的一条碎石铺就的小路，各色的碎石拼出
的图案花鸟，显见这里的主人不是寻常之辈。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"road6",
  "north" : __DIR__"road4",
]));
       set("outdoors","feiyu");
	setup();
	replace_program(ROOM);
}
