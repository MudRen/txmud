// Room: /wiz/uudd/path2/k_s02.c

inherit ROOM;

void create()
{
	set("short", "�ٵ�");
	set("long", @LONG
����һ������̹���Ĺٵ���ȫ��ʯ���̳ɡ�·���߸���һ��
һ�����ˮ������Ϊ�˷�ֹ·�ϻ�ˮ���ڵģ�������֮ʱҲ����
��·���ߵ�ũ����ˮ������һ�����á�·�����������������У�
��ʱ��һ��������ɳ۶���������һ·���̡�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"k_s03",
  "east" : __DIR__"k_s01",
]));

	setup();
	set("outdoors", "shaolin");
	replace_program(ROOM);
}