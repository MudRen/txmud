// Room: /d/guozijian/xi_jiting.c 
 
inherit ROOM; 
 
void create() 
{ 
	set("short", "����ͤ");
	set("long", @LONG
����������ͤ��������һƬ�̵أ�ż����һ��ֻ����������
ȥ�����߷��ӵ��Ŷ����ţ�������һ����ʯ����
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"east" : __DIR__"yongdao1",
]));

	set("outdoors","guozijian");
	setup();
	replace_program(ROOM);
}
