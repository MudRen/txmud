// Room: /wiz/uudd/path2/k_s23.c

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
	set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"k_s24",
  "southeast" : __DIR__"k_s22",
]));

	setup();
	set("outdoors", "shaolin");
	replace_program(ROOM);
}
