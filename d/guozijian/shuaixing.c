// Room: /d/guozijian/shuaixing.c 
 
inherit ROOM; 
 
void create() 
{ 
	set("short", "率性堂");
	set("long", @LONG
这里是率性堂，是监生学习的地方，在这里主要是修文行，
朝廷的官员多半是在这里学习了三年之后，才通过殿试，为朝廷
出力的，当然能来这里的也都不是一般人物，不是官宦子弟，就
是各地的举人。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
		"south" : __DIR__"chongzhi",
		"north" : __DIR__"chengxin",
		"west" : __DIR__"yongdao3",
]));

	set("objects", ([
		__DIR__"npc/teacher"	: 1,
		__DIR__"npc/shusheng"   : 2,
	]));
	setup();
	replace_program(ROOM);
}