// Room: /d/hangzhou/guardgroup1.c

inherit ROOM;

void create()
{
	set("short", "�ھ��쾮");
	set("long", @LONG
�������ھ����䣬ѵ���ĵط�����������һ����ʯ�·��һ
ֱͨ���������·���ֵ������ϳ���һ�����˺ϱ�������������
�°���һ�����������ı����ܡ�
LONG
	);
	set("outdoors", "hangzhou");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"guardgroup2",
  "north" : __DIR__"guardgroup",
]));

	setup();
	replace_program(ROOM);
}
