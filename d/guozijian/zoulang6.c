// Room: /d/guozijian/zoulang6.c 
 
inherit ROOM; 
 
void create() 
{ 
	set("short", "����");
	set("long", @LONG
������һ�������Ļ������ȣ������Ʊ�Ӻһ�ܣ����ȵ����
���Ǻ��������ˣ�����������һ��С�ӣ�������ʢ���źɻ�����
����ʹ������ż�����ܿ�������Ĵ�������ι��������˼�
�ɾ�����
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"west" : __DIR__"by_north",
		"east" : __DIR__"zoulang5",
]));

	set("outdoors","guozijian");
	setup();
	replace_program(ROOM);
}