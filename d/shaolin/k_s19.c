// Room: /wiz/uudd/path2/k_s19.c

inherit ROOM;

void create()
{
	set("short", "��·");
	set("long", @LONG
һ���ӿ����ݵ���·����������죬���򱱱߿�ȥ����һ��
С��ׯ����������Ǳߣ����ǰ������Ǽ���ũ��м���ũ��
���ڸ����š�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"k_s20",
  "north" : __DIR__"k_s18",
]));

	setup();
	set("outdoors", "shaolin");
	replace_program(ROOM);
}
