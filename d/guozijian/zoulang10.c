// Room: /d/guozijian/zoulang10.c 
 
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
		"south" : __DIR__"zoulang11",
		"north" : __DIR__"by_west",
]));

	set("outdoors","guozijian");
	setup();
	replace_program(ROOM);
}