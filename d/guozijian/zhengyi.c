// Room: /d/guozijian/zhengyi.c 
 
inherit ROOM; 
 
void create() 
{ 
	set("short", "正义堂");
	set("long", @LONG
这里是正义堂，是监生学习的地方，在这里主要是修德行，
朝廷的官员每隔一端时间，就得来这里修行一段时间。桌子旁边
的几个监生正学习先帝的著作，虽然没有穿官府，但从老师说话
的客气程度，至少也是二品以上。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
		"north" : __DIR__"xiudao",
]));

	setup();
	replace_program(ROOM);
}
