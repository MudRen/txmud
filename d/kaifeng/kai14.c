// Room: /u/w/wangs/b/kai14.c

inherit ROOM;

void create()
{
	set("short", "���к���");
	set("long", @LONG
���������е�С���ϣ�����������ˮ֮�����Ƕ���������
���㣬ϸ�����֦��΢�紵������������ϣ�����С�������
ˮ֮�е�������׷����Ϸ���㲻�ɵ����������������кӴ�
������˵��䣬������е�����ȥ�ˡ�
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"kai13",
  "northeast" : __DIR__"kai15",
]));

	set("outdoors","kaifeng");
	setup();
	replace_program(ROOM);
}
