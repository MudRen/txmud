// Room: /d/guozijian/shuaixing.c 
 
inherit ROOM; 
 
void create() 
{ 
	set("short", "������");
	set("long", @LONG
�����������ã��Ǽ���ѧϰ�ĵط�����������Ҫ�������У�
��͢�Ĺ�Ա�����������ѧϰ������֮�󣬲�ͨ�����ԣ�Ϊ��͢
�����ģ���Ȼ���������Ҳ������һ��������ǹٻ��ӵܣ���
�Ǹ��صľ��ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
		"south" : __DIR__"chongzhi",
		"north" : __DIR__"chengxin",
		"west" : __DIR__"yongdao3",
]));

	set("objects", ([
		__DIR__"npc/teacher"	: 1,
		__DIR__"npc/shusheng"   : 2,
	]));
	setup();
	replace_program(ROOM);
}