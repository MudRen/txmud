// Room: /d/guozijian/yongdao4.c 
 
inherit ROOM; 
 
void create() 
{ 
	set("short", "��");
	set("long", @LONG
������һ������ש�̳ɵ���������Ϊܯ���������жӻ�ӭ
�ʵ۵ĵط������ı���ͨ�������á�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"north" : __DIR__"yilun",
		"south" : __DIR__"shiqiao3",
]));

	set("outdoors","guozijian");
	setup();
	replace_program(ROOM);
}
