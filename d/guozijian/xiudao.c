// Room: /d/guozijian/xiudao.c 
 
inherit ROOM; 
 
void create() 
{ 
	set("short", "�޵���");
	set("long", @LONG
�������޵��ã��Ǽ���ѧϰ�ĵط�����������Ҫ���޵��У�
��͢�Ĺ�Աÿ��һ��ʱ�䣬�͵�����������һ��ʱ�䡣��Ȼ����
�����û�йٵĵȼ��ˣ������»���ҪС�ģ��������������
������һ������㶨��һ˫�ߴ�СЬ��
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
		"south" : __DIR__"zhengyi",
		"north" : __DIR__"guangye",
		"east" : __DIR__"yongdao5",
]));

	setup();
	replace_program(ROOM);
}
