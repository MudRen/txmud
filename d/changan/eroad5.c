// /d/changan/eroad5  连德街

inherit ROOM;

void create()
{
        set("short", "连德街");
        set("long", @LONG
这里长安城的东大街，离东大门不远，在这里居住的人，都
不是很富有所以也就是说这里是长安城贫民居住的地方。不远处
有几个赤身的小孩在嬉戏着，街边上一个苍老的老妇人在做着针
线活儿。连德街有此向南北延伸，东面是一家学馆，不时传出来
阵阵朗朗的读书声。
LONG
        );

	set("exits", ([
                "north"           : __DIR__"eroad6",
                "south"           : __DIR__"eroad4",
]) );
	set("outdoors","changan");

	setup();
	replace_program(ROOM);
}
