// Room: /d/shaolin/tulu1.c

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
  "east" : __DIR__"tulu2",
  "northwest" : __DIR__"xiaolu4",
]));

	setup();
	replace_program(ROOM);
}
