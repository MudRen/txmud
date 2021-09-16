// Room: /d/hangzhou/house2.c

inherit ROOM;

void create()
{
	set("short", "民房");
	set("long", @LONG
房间里甚是宽敞，里面摆设朴素而自然，左侧是一个古色古
色的精雅梳妆台，前面摆有两张红木圆椅。右侧墙壁上挂有一幅
美女抚琴图，上面配有几行笔迹清秀的隶体小字，内侧则是一张
红色帐幔垂挂的低矮木榻，看样子是一个颇为殷实的家庭。。
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
	"east" : __DIR__"stoneroad2",
	"west" : __DIR__"house5",
]));

	set("objects",([
	__DIR__"npc/shaonian" : 1,
]));

	setup();
	replace_program(ROOM);
}
