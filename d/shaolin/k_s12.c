// Room: /wiz/uudd/path2/k_s12.c

inherit ROOM;

void create()
{
	set("short", "����·��");
	set("long", @LONG
���Ǵ���Ĳ�·�ڣ���ʱ�д��������������߹���������
������һ��ʯ��С·��������һ��С������Ҳ��һ��ʯ·��Լ
���Կ���·����һ���ҵ��̡�������Կ���һ��С�ӻ��̡�
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"temple",
  "east" : __DIR__"k_s11",
  "south" : __DIR__"k_s15",
  "north" : __DIR__"k_s13",
]));
	set("outdoors", "shaolin");

	setup();
	replace_program(ROOM);
}
