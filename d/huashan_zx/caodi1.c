// Room: caodi.c by pian

inherit ROOM;
void create()
{
	set("short","草地");
	set("long",@LONG
这里是一一片草地，其间有些许姹紫嫣红的小花点缀其间，
虫鸣风轻，东边有一个小小的石亭，西边是院中央的青石阶。
LONG
);
	set("exits", ([ /* sizeof() == 2 */
	"east" : __DIR__"ting2",
	"west":__DIR__"shidao2",
]));
	set("outdoors", "huashan_p");
	setup();
	replace_program(ROOM);
}