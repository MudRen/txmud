// Room: /wiz/uudd/path2/k_s15.c

inherit ROOM;

void create()
{
	set("short", "ʯ��·");
	set("long", @LONG
������һ��ʯ��·�ϣ���·���Կ�ȥ��ֻ��·����һ��ľ��
�̣������ſڹ���һ�����ӣ�����д��һЩ����ľ���ļ۸�ʲô
�ģ�����ǰ����ż�����û�����õ����ӹ��ӣ�·��������һ��
�˼ҡ�
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"minjv02",
  "east" : __DIR__"woodshop",
  "south" : __DIR__"k_s16",
  "north" : __DIR__"k_s12",
]));

	setup();
	set("outdoors", "shaolin");
	replace_program(ROOM);
}
