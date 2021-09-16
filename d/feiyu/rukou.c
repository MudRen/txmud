// Room: /wiz/find/huapu/rukou.c

inherit ROOM;

void create()
{
	set("short", "小路");
	set("long", @LONG
这里是一条幽静的小土路，路边长满了青青的小草，北面不
远是一个竹条编成的栅栏门。
LONG
	);

	set("exits",([
	"north" : __DIR__"hua_pu/entry",
	"south" : __DIR__"road3",
]));

	set("outdoors","feiyu");

	setup();
	replace_program(ROOM);
}
