// Room: /wiz/uudd/path2/k_s20.c

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
  "west" : __DIR__"k_s21",
  "northeast" : __DIR__"k_s19",
]));

	setup();
	set("outdoors", "shaolin");
	replace_program(ROOM);
}
