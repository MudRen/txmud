// Room: /d/guozijian/yongdao3.c 
 
inherit ROOM; 
 
void create() 
{ 
	set("short", "��");
	set("long", @LONG
������һ������ש�̳ɵ�����������ֲ�˼����߲ˣ��ǹ�
������ʹ�õģ�����Щ�ع���Ȼ�ĸо����������������á�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"west" : __DIR__"shiqiao2",
		"east" : __DIR__"shuaixing",
]));

	set("outdoors","guozijian");
	setup();
	replace_program(ROOM);
}
