// Room: /wiz/uudd/path2/k_s22.c

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
	set("exits", ([ /* sizeof() == 3 */
  "northwest" : __DIR__"k_s23",
  "east" : __DIR__"k_s21",
]));
	set("outdoors", "shaolin");

	setup();
	replace_program(ROOM);
}
