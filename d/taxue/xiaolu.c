// xiaolu.c
// by dicky

inherit ROOM;

void create()
{
	set("short", "蜿蜒小路");
	set("long", @LONG
这是一条小碎石铺就的蜿蜒的上山小路，路旁是高大蔽日的松树
林，偶尔回荡着几声鸟鸣。
LONG);
	set("outdoors", "taxue");

	set("exits", ([ 
	"south" : __DIR__"houmen",
	"north" : __DIR__"shulin",
	]));

	setup();
	replace_program(ROOM);
}
