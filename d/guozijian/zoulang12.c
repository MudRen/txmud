// Room: /open/guozijian/zoulang12.c 
 
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
		"west" : __DIR__"zoulang11",
		"east" : __DIR__"biyong",
]));

	set("outdoors","guozijian");
	setup();
	replace_program(ROOM);
}