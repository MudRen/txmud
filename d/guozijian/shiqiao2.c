// Room: /d/guozijian/shiqiao2.c 
 
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
		"west" : __DIR__"by_east",
		"east" : __DIR__"yongdao3",
]));

	set("outdoors","guozijian");
	setup();
	replace_program(ROOM);
}
