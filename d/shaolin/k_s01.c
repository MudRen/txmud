// Room: /wiz/uudd/path2/k_s01.c

inherit ROOM;

void create()
{
	set("short", "�ٵ�");
	set("long", @LONG
����һ������̹���Ĺٵ���ȫ��ʯ���̳ɡ�·���߸���һ��
һ�����ˮ������Ϊ�˷�ֹ·�ϻ�ˮ���ڵģ�������֮ʱҲ����
��·���ߵ�ũ����ˮ������һ�����á�·�����������������У�
��ʱ��һ�������ɳ۶���������һ·���̡�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"k_s02",
  "east" : "/d/kaifeng/out_kaifeng_w",
]));

	setup();
	set("outdoors", "shaolin");
	replace_program(ROOM);
}
