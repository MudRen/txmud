// Room: /d/guozijian/biyong.c 
 
inherit ROOM; 
 
void create() 
{ 
	set("short", "��Ӻ��");
	set("long", @LONG
������Ǳ�Ӻ��ǻʵۺ��зǳ���λ��ѧ�߽�ѧ�ĵط���
�������ƺ�ΰ�����Ͽ��кö��οյ��������ޡ�ɽˮ�����Ľ�
�ܼⶥ����ÿһ�Ǿ���Ƕ��һ�������飬��ǰ��Ǭ¡���顰��Ӻ��
���֡�
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
