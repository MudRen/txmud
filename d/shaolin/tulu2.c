// Room: /d/shaolin/tulu2.c

inherit ROOM;

void create()
{
	set("short", "��·");
	set("long", @LONG
һ���ӿ����ݵ���·������������ţ������õ�ʱ��������
��Ļ�����������ʱ��������Ţ�����������Ĵ���û��Ǯ����·��
ֻ�ôպ���������
LONG
	);

	set("outdoors", "shaolin");

	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"tulu3",
  "west" : __DIR__"tulu1",
]));

	set("objects",([
	__DIR__"npc/stiaofu" : 1,
]));

	setup();
	replace_program(ROOM);
}
