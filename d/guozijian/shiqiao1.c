// Room: /d/guozijian/shiqiao1.c 
 
inherit ROOM; 
 
void create() 
{ 
	set("short", "ʯ��");
	set("long", @LONG
������һ��Сʯ�ţ��ų����ɶ��ߣ����Ӻ���������ϵ���
���Ͽ���һЩС�֣�������һ��С�ӣ���ˮ�Ǵ�̫ѧ���ⶫ����
ͤ�������ģ����￪���˺ɻ���ʹ��Ӻ�Զ���Ϳ����ŵ�����
�㡣
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"north" : __DIR__"biyong",
		"south" : __DIR__"pailou",
]));

	set("outdoors","guozijian");
	setup();
	replace_program(ROOM);
}
