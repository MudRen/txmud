// Room: /d/guozijian/by_west.c 
 
inherit ROOM; 
 
void create() 
{ 
	set("short", "��Ӻ������");
	set("long", @LONG
������Ǳ�Ӻ��ǻʵۺ��зǳ���λ��ѧ�߽�ѧ�ĵط���
�������ƺ�ΰ�����Ͽ��кö��οյ��������ޡ�ɽˮ�����Ľ�
�ܼⶥ����ÿһ�Ǿ���Ƕ��һ�������飬�������ﲻ�����ţ���
���������ء�
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
		"east" : __DIR__"dianzhong",
		"west" : __DIR__"shiqiao4",
		"south" : __DIR__"zoulang10",
		"north" : __DIR__"zoulang9",
]));

	setup();
	replace_program(ROOM);
}