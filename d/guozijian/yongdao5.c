// Room: /d/guozijian/yongdao5.c 
 
inherit ROOM; 
 
void create() 
{ 
	set("short", "��");
	set("long", @LONG
������һ������ש�̳ɵ�����������ֲ�˼����߲ˣ��ǹ�
������ʹ�õģ�����Щ�ع���Ȼ�ĸо������������޵��á�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"east" : __DIR__"shiqiao4",
		"west" : __DIR__"xiudao",
]));

	set("outdoors","guozijian");
	setup();
	replace_program(ROOM);
}
