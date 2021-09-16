// Room: /wiz/louth/a/taoyuan9.c

inherit ROOM;

void create()
{
	set("short", "小路");
	set("long", @LONG
来到这里，竟置身于一个极其精致的花园，红梅绿竹，青松
翠柏，各处布置的都独具匠心。池塘中有数对鸳鸯悠游其间，池
塘旁还有几只白鹤，真是一处人间仙境。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"taoyuan8",
  "north" : __DIR__"taoyuan10",
]));
       set("outdoors","feiyu");
	setup();
	replace_program(ROOM);
}
