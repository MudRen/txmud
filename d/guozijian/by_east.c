// Room: /d/guozijian/by_east.c 
 
inherit ROOM; 
 
void create() 
{ 
	set("short", "��Ӻ���");
	set("long", @LONG
������Ǳ�Ӻ��ǻʵۺ��зǳ���λ��ѧ�߽�ѧ�ĵط���
�������ƺ�ΰ�����Ͽ��кö��οյ��������ޡ�ɽˮ�����Ľ�
�ܼⶥ����ÿһ�Ǿ���Ƕ��һ�������飬�������ﲻ�����ţ���
���������ء�
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