// Room: /u/w/wangs/b/kai177.c

inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
���������ǿ�������������ض���Ȼ�������һ����ɫ��
ɫ�ľ�����ױ̨��ǰ��������ź�ľԲ�Ρ��Ҳ�ǽ���Ϲ���һ��
��Ů����ͼ���������м��бʼ����������С�֣��ڲ�����һ��
��ɫ��ᣴ��ҵĵͰ�ľ齡�
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"kai176",
]));

	setup();
	replace_program(ROOM);
}
