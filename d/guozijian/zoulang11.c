// Room: /d/guozijian/zoulang11.c 
 
inherit ROOM; 
 
void create() 
{ 
	set("short", "����");
	set("long", @LONG
������һ�������Ļ������ȣ������Ʊ�Ӻһ�ܣ����ȵ����
���Ǻ��������ˣ�����������һ��С�ӣ�������ʢ���źɻ�����
����ʹ������ż�����ܿ�������Ĵ�������ι���С�ӵĶ�
����һ����ˮ��ͷ�������峺��ˮ������У���ʱ�м���Сˮ��
����������ϡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"north" : __DIR__"zoulang10",
		"east" : __DIR__"zoulang12",
]));

	set("outdoors","guozijian");
	setup();
	replace_program(ROOM);
}