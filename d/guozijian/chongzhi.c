// Room: /d/guozijian/chongzhi.c 
 
inherit ROOM; 
 
void create() 
{ 
	set("short", "��־��");
	set("long", @LONG
�����ǳ�־�ã��Ǽ���ѧϰ�ĵط����������м�����������
���飬����������ǰ��ҡ���Դ��������������������ʱ�䲻
����
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
		"north" : __DIR__"shuaixing",
]));

	setup();
	replace_program(ROOM);
}
