// Room: /wiz/uudd/path2/k_s24.c

inherit ROOM;

void create()
{
	set("short", "�յ�");
	set("long", @LONG
������һƬ�յأ���������������������ĺ�ȥ��������
�������һ����·�ˡ���ӿ��˽Ų����
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : "/d/shaolin/tulu3",
  "southeast" : __DIR__"k_s23",
]));

	setup();
	set("outdoors", "shaolin");
	replace_program(ROOM);
}
