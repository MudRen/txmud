// Room: /wiz/louth/a/road6.c

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
  "west" : __DIR__"yaxinroom",
  "northeast" : __DIR__"road5",
]));
       set("outdoors","feiyu");
	setup();
	replace_program(ROOM);
}
