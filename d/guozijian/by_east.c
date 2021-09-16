// Room: /d/guozijian/by_east.c 
 
inherit ROOM; 
 
void create() 
{ 
	set("short", "辟雍殿东门");
	set("long", @LONG
这里就是辟雍殿，是皇帝和有非常地位的学者讲学的地方。
这里气势宏伟，梁上刻有好多镂空的珍禽异兽、山水花鸟，四角
攒尖顶，并每一角均镶嵌了一个火龙珠，由于这里不是正门，所
以略显朴素。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
		"west" : __DIR__"dianzhong",
		"east" : __DIR__"shiqiao2",
		"south" : __DIR__"zoulang3",
		"north" : __DIR__"zoulang4",
]));

	setup();
	replace_program(ROOM);
}