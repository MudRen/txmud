// Room: /d/guozijian/yongdao2.c 
 
inherit ROOM; 
 
void create() 
{ 
	set("short", "��");
	set("long", @LONG
������һ������ש�̳ɵ��������߳�������ݣ�������
����һ���Ʒ�������������̫ѧ�ţ���������ͤ�������ǹ�ͤ��
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"north" : __DIR__"pailou",
		"south" : __DIR__"tx_gate",
]));

	set("outdoors","guozijian");
	setup();
	replace_program(ROOM);
}
