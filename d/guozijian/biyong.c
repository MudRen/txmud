// Room: /d/guozijian/biyong.c 
 
inherit ROOM; 
 
void create() 
{ 
	set("short", "辟雍殿");
	set("long", @LONG
这里就是辟雍殿，是皇帝和有非常地位的学者讲学的地方。
这里气势宏伟，梁上刻有好多镂空的珍禽异兽、山水花鸟，四角
攒尖顶，并每一角均镶嵌了一个火龙珠，殿前檐乾隆御书“辟雍”
二字。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
		"west" : __DIR__"zoulang12",
		"east" : __DIR__"zoulang1",
		"south" : __DIR__"shiqiao1",
		"north" : __DIR__"dianzhong",
]));

	setup();
	replace_program(ROOM);
}
