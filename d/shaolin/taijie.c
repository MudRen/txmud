// Room: /d/shaolin/taijie.c

inherit ROOM;

void create()
{
	set("short", "̨��");
	set("long", @LONG
�����������µ�ͨ��ǰԺ�㳡��������֮���̨�ס�̧ͷ��
ȥ�����ʵ�ʯ���ƺ�ֱ����ʡ����������ǿ�������Ժ�㳡��
�����������
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"tianwangdian.c",
  "south" : __DIR__"f_square",
]));
	set("no_clean_up", 0);
	set("outdoors", "shaolin");

	setup();
	replace_program(ROOM);
}
