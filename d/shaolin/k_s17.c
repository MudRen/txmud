// Room: /wiz/uudd/path2/k_s17.c

inherit ROOM;

void create()
{
	set("short", "ʯ��·");
	set("long", @LONG
����һ��ʯ��С·��·�Ϻܸɾ���·�����м����˼ҡ�·��
�����ĵģ�û��ʲô�ˡ�Զ����ʱ������֪��ʲô�����Ľ�����
�㲻�ɼӿ��˽Ų���
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"k_s18",
  "north" : __DIR__"k_s16",
]));

	setup();
	set("outdoors", "shaolin");
	replace_program(ROOM);
}
