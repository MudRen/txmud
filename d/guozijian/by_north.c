// Room: /d/guozijian/by_north.c 
 
inherit ROOM; 
 
void create() 
{ 
	set("short", "��Ӻ���");
	set("long", @LONG
������Ǳ�Ӻ��ǻʵۺ��зǳ���λ��ѧ�߽�ѧ�ĵط���
�������ƺ�ΰ�����Ͽ��кö��οյ��������ޡ�ɽˮ�����Ľ�
�ܼⶥ����ÿһ�Ǿ���Ƕ��һ�������飬�������ﲻ�����ţ���
���������ء�
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
		"south" : __DIR__"dianzhong",
		"north" : __DIR__"shiqiao3",
		"east" : __DIR__"zoulang6",
		"west" : __DIR__"zoulang7",
]));

	setup();
	replace_program(ROOM);
}