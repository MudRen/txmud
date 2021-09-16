// Room: /d/path2/ch_k14.c

inherit ROOM;

void create()
{
	set("short", "土路");
	set("long", @LONG
这是一条黄土小路，路边杂草丛生，你四下望去，只见一片
凄凉。路上行人很少，偶尔有几个农夫挑着担子经过。再向西不
远，就是候马集了。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
	"east" : __DIR__"ch_k13",
	"west" : "/d/houmaji",
	"northeast" : __DIR__"q1",
]));

	set("outdoors", "path2");
	setup();
	replace_program(ROOM);
}
